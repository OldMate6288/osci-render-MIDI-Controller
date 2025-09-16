#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_anim_t * bootlogo_Animation(lv_obj_t * TargetObject, int delay);
lv_anim_t * fadein_Animation(lv_obj_t * TargetObject, int delay);

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
lv_anim_t * bootlogo_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t * out_anim;
    ui_anim_user_data_t * PropertyAnimation_1_user_data = lv_malloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_1_user_data->target = TargetObject;
    PropertyAnimation_1_user_data->val = -1;
    lv_anim_t PropertyAnimation_1;
    lv_anim_init(&PropertyAnimation_1);
    lv_anim_set_time(&PropertyAnimation_1, 1000);
    lv_anim_set_user_data(&PropertyAnimation_1, PropertyAnimation_1_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_1, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_1, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_1, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_1, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_1, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_1, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_1, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_1, 0);
    lv_anim_set_early_apply(&PropertyAnimation_1, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_1, &_ui_anim_callback_get_opacity);
    out_anim = lv_anim_start(&PropertyAnimation_1);

    return out_anim;
}
lv_anim_t * fadein_Animation(lv_obj_t * TargetObject, int delay)
{
    lv_anim_t * out_anim;
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_malloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_ease_in);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, false);
    lv_anim_set_get_value_cb(&PropertyAnimation_0, &_ui_anim_callback_get_opacity);
    out_anim = lv_anim_start(&PropertyAnimation_0);

    return out_anim;
}

///////////////////// FUNCTIONS ////////////////////

#define TAG "UI"

static QueueHandle_t nvs_q = NULL;

// helper to build a full message with current known values
static void enqueue_save(uint8_t b, uint8_t hide, uint8_t flip)
{
    if (!nvs_q) return;
    nvs_msg_t msg = {
        .brightness = b,
        .hide_player = hide,
        .flip_objs = flip
    };
    xQueueSend(nvs_q, &msg, 0);
}

void save_settings_ui(uint8_t brightness)
{
    uint8_t hide = ui_HidePlayerSW && lv_obj_has_state(ui_HidePlayerSW, LV_STATE_CHECKED);
    uint8_t flip = ui_FlipGlobalObjsSW && lv_obj_has_state(ui_FlipGlobalObjsSW, LV_STATE_CHECKED);
    enqueue_save(brightness, hide, flip);
}

void save_settings_objs(uint8_t hide_player, uint8_t flip_objs)
{
    // read current brightness from the slider so we don’t lose it
    uint8_t b = ui_DisplayBrightness ? lv_slider_get_value(ui_DisplayBrightness) : 100;
    enqueue_save(b, hide_player, flip_objs);
}

static void nvs_writer_task(void *arg)
{
    nvs_msg_t msg;
    while (1) {
        if (xQueueReceive(nvs_q, &msg, portMAX_DELAY) == pdTRUE) {
            nvs_handle_t h;
            esp_err_t err = nvs_open("ui_settings", NVS_READWRITE, &h);
            if (err == ESP_OK) {
                uint8_t safe_b = (msg.brightness == 0) ? 1 : msg.brightness;
                nvs_set_u8(h, "brightness", safe_b);
                nvs_set_u8(h, "hide_player", msg.hide_player);
                nvs_set_u8(h, "flip_objs", msg.flip_objs);
                nvs_commit(h);
                nvs_close(h);
                ESP_LOGI(TAG, "NVS saved b=%u hide=%u flip=%u",
                         msg.brightness, msg.hide_player, msg.flip_objs);
            } else {
                ESP_LOGW(TAG, "nvs_open failed: %s", esp_err_to_name(err));
            }
        }
    }
}

// Safe NVS init helper
static esp_err_t safe_nvs_init(void)
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_LOGW(TAG, "NVS needs erase, erasing...");
        esp_err_t erase_ret = nvs_flash_erase();
        if (erase_ret != ESP_OK) {
            ESP_LOGE(TAG, "nvs_flash_erase failed: %s", esp_err_to_name(erase_ret));
            return erase_ret;
        }
        ret = nvs_flash_init();
    }
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "nvs_flash_init failed: %s", esp_err_to_name(ret));
    }
    return ret;
}

// Read ui_settings file from flash
static void read_ui_settings_from_nvs(nvs_msg_t *out)
{
    if (!out) return;
    nvs_handle_t h;
    esp_err_t err = nvs_open("ui_settings", NVS_READONLY, &h);
    if (err != ESP_OK) {
        ESP_LOGI(TAG, "No NVS settings, using defaults");
        out->brightness = 100;
        out->hide_player = 0;
        out->flip_objs = 0;
        return;
    }

    uint8_t b = 100, hide = 0, flip = 0;
    nvs_get_u8(h, "brightness", &b);
    nvs_get_u8(h, "hide_player", &hide);
    nvs_get_u8(h, "flip_objs", &flip);
    nvs_close(h);

    if (b == 0) b = 1;                 // never let brightness reach 0

    out->brightness  = b;
    out->hide_player = hide;
    out->flip_objs   = flip;

    ESP_LOGI(TAG, "Loaded NVS b=%u hide=%u flip=%u", b, hide, flip);
}

// Apply settings on LVGL thread
static void apply_ui_settings_on_lvgl_thread(void *arg)
{
    nvs_msg_t *s = (nvs_msg_t *)arg;
    if (!s) return;

    // Defensive checks: ensure widgets exist
    if (ui_DisplayBrightness) {
        bsp_display_brightness_set(s->brightness);
        lv_slider_set_value(ui_DisplayBrightness, s->brightness, LV_ANIM_OFF);
    }

    if (ui_HidePlayerSW) {
        if (s->hide_player) lv_obj_add_state(ui_HidePlayerSW, LV_STATE_CHECKED);
        else                lv_obj_clear_state(ui_HidePlayerSW, LV_STATE_CHECKED);
        
    lv_obj_t *active = lv_scr_act();

    if (active == ui_BootScreen) {
        // Always hide global objects on boot screen
        _ui_flag_modify(ui_GlobalSettingsContainer, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_GlobalObjContainer, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
    } else {
        // On all other screens, respect NVS hide_player value
        if (s->hide_player) {
            _ui_flag_modify(ui_GlobalObjContainer, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        } else {
            _ui_flag_modify(ui_GlobalObjContainer, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        }
      }
    }

    if (ui_FlipGlobalObjsSW) {
        if (s->flip_objs) lv_obj_add_state(ui_FlipGlobalObjsSW, LV_STATE_CHECKED);
        else              lv_obj_clear_state(ui_FlipGlobalObjsSW, LV_STATE_CHECKED);

        if (s->flip_objs) {
            lv_obj_set_align(ui_GlobalObjContainer, LV_ALIGN_TOP_RIGHT);
            lv_obj_set_align(ui_GlobalSettingsContainer, LV_ALIGN_TOP_LEFT);
        } else {
            lv_obj_set_align(ui_GlobalObjContainer, LV_ALIGN_TOP_LEFT);
            lv_obj_set_align(ui_GlobalSettingsContainer, LV_ALIGN_TOP_RIGHT);
        }
    }

    free(s);
}

void NVS_init(void)
{
    // Start NVS writer queue/task BEFORE UI callbacks will be used
    esp_err_t ret = safe_nvs_init();
    if (ret != ESP_OK) {
        ESP_LOGW(TAG, "Continuing without NVS");
    }

    nvs_q = xQueueCreate(4, sizeof(nvs_msg_t));
    if (nvs_q) {
        xTaskCreatePinnedToCore(nvs_writer_task, "nvs_writer", 4096, NULL, 5, NULL, 0);
    } else {
        ESP_LOGE(TAG, "Failed to create NVS queue");
    }
}

void NVS_UI_update(void)
{
    // Read settings from NVS (safe) and schedule apply on LVGL thread
    nvs_msg_t *s = malloc(sizeof(nvs_msg_t));
    if (s) {
        read_ui_settings_from_nvs(s);
        lv_async_call(apply_ui_settings_on_lvgl_thread, s);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_display_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    init_global_objs();
    ui_BootScreen_screen_init();
    ui_MainScreen_screen_init();
    ui_ModifyScreen_screen_init();
    ui_EffectsScreen_screen_init();
    ui_SettingsScreen_screen_init();
    ui_DrumpadScreen_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_BootScreen);
}

void ui_destroy(void)
{
    ui_BootScreen_screen_destroy();
    ui_MainScreen_screen_destroy();
    ui_ModifyScreen_screen_destroy();
    ui_EffectsScreen_screen_destroy();
    ui_SettingsScreen_screen_destroy();
    ui_DrumpadScreen_screen_destroy();
}
