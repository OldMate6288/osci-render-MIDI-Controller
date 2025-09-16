#include "midi_control.h"

static const char *TAG = "midi_control";

/** Helper defines for TinyUSB**/

// Interface counter
enum interface_count {
#if CFG_TUD_MIDI
    ITF_NUM_MIDI = 0,
    ITF_NUM_MIDI_STREAMING,
#endif
    ITF_COUNT
};

// USB Endpoint numbers
enum usb_endpoints {
    // Available USB Endpoints: 5 IN/OUT EPs and 1 IN EP
    EP_EMPTY = 0,
#if CFG_TUD_MIDI
    EPNUM_MIDI,
#endif
};

/** TinyUSB descriptors **/

#define TUSB_DESCRIPTOR_TOTAL_LEN (TUD_CONFIG_DESC_LEN + CFG_TUD_MIDI * TUD_MIDI_DESC_LEN)

/**
 * @brief String descriptor
 */
static const char* s_str_desc[5] = {
    // array of pointer to string descriptors
    (char[]){0x09, 0x04},  // 0: is supported language is English (0x0409)
    "OldMate6288",             // 1: Manufacturer
    "osci-render MIDI controller",      // 2: Product
    "0000",              // 3: Serials, should use chip ID
    "osci-render MIDI controller", // 4: MIDI
};

/**
 * @brief Configuration descriptor
 *
 * This is a simple configuration descriptor that defines 1 configuration and a MIDI interface
 */
static const uint8_t s_midi_cfg_desc[] = {
    // Configuration number, interface count, string index, total length, attribute, power in mA
    TUD_CONFIG_DESCRIPTOR(1, ITF_COUNT, 0, TUSB_DESCRIPTOR_TOTAL_LEN, 0, 100),

    // Interface number, string index, EP Out & EP In address, EP size
    TUD_MIDI_DESCRIPTOR(ITF_NUM_MIDI, 4, EPNUM_MIDI, (0x80 | EPNUM_MIDI), 64),
};

#if (TUD_OPT_HIGH_SPEED)
/**
 * @brief High Speed configuration descriptor
 *
 * This is a simple configuration descriptor that defines 1 configuration and a MIDI interface
 */
static const uint8_t s_midi_hs_cfg_desc[] = {
    // Configuration number, interface count, string index, total length, attribute, power in mA
    TUD_CONFIG_DESCRIPTOR(1, ITF_COUNT, 0, TUSB_DESCRIPTOR_TOTAL_LEN, 0, 100),

    // Interface number, string index, EP Out & EP In address, EP size
    TUD_MIDI_DESCRIPTOR(ITF_NUM_MIDI, 4, EPNUM_MIDI, (0x80 | EPNUM_MIDI), 512),
};
#endif // TUD_OPT_HIGH_SPEED

void usb_init(void) 
{
    tinyusb_config_t const tusb_cfg = {
        .device_descriptor = NULL, // If device_descriptor is NULL, tinyusb_driver_install() will use Kconfig
        .string_descriptor = s_str_desc,
        .string_descriptor_count = sizeof(s_str_desc) / sizeof(s_str_desc[0]),
        .external_phy = false,
    #if (TUD_OPT_HIGH_SPEED)
            .fs_configuration_descriptor = s_midi_cfg_desc, // HID configuration descriptor for full-speed and high-speed are the same
            .hs_configuration_descriptor = s_midi_hs_cfg_desc,
            .qualifier_descriptor = NULL,
    #else
            .configuration_descriptor = s_midi_cfg_desc,
    #endif // TUD_OPT_HIGH_SPEED
    };
    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));

    ESP_LOGI(TAG, "USB initialization DONE");
}

// LVGL objects are not constants, they are created dynamically when ui_init() runs so the compiler can’t put their addresses into a static initializer.
// so yeah that's why there's 2 long lists, sorry...
static midi_map_t midi_map[] = {
    {10,  NULL, false},
    {11,  NULL, false},
    {12,  NULL, false},

    {0,   NULL, true},
    {1,   NULL, true},
    {2,   NULL, true},
    {3,   NULL, true},
    {4,   NULL, true},
    {5,   NULL, true},
    {6,   NULL, true},
    {7,   NULL, true},
    {8,   NULL, true},
    {9,   NULL, true},

    {13, NULL, false},
    {14, NULL, false},
    {15, NULL, false},
    {16, NULL, false},
    {17, NULL, false},
    {18, NULL, false},
    {19, NULL, false},
    {20, NULL, false},
    {21, NULL, false},
    {22, NULL, false},
    {23, NULL, false},
    {24, NULL, false},
    {25, NULL, false},

    {26, NULL, true},
    {27, NULL, true},
    {28, NULL, true},
    {29, NULL, true},
    {30, NULL, true},

    {31, NULL, false},
    {32, NULL, false},
    {33, NULL, false},
    {34, NULL, false},
    {35, NULL, false},
    {36, NULL, false},
    {37, NULL, false},
    {38, NULL, false},
    {39, NULL, false},
    {40, NULL, false},
    {41, NULL, false},
    {42, NULL, false},
    {43, NULL, false},
    {44, NULL, false},
    {45, NULL, false},
    {46, NULL, false},
    {47, NULL, false},
    {48, NULL, false},
    {49, NULL, false},
    //{50, NULL, false},
};

/* --- Call midi map initialization after ui_init() --- */
void midi_map_init(void)
{
    // MainScreen
    midi_map[0].obj  = ui_Frequency;
    midi_map[1].obj  = ui_Perspective;
    midi_map[2].obj  = ui_FocalLength;

    // EffectsScreen (switches)
    midi_map[3].obj  = ui_BitCrushSwitch;
    midi_map[4].obj  = ui_BulgeSwitch;
    midi_map[5].obj  = ui_VectorSwitch;
    midi_map[6].obj  = ui_SwirlSwitch;
    midi_map[7].obj  = ui_SmoothingSwitch;
    midi_map[8].obj  = ui_WobbleSwitch;
    midi_map[9].obj  = ui_DelaySwitch;
    midi_map[10].obj = ui_DashSwitch;
    midi_map[11].obj = ui_LuaSwitch;
    midi_map[12].obj = ui_TraceSwitch;

    // EffectsScreen (sliders)
    midi_map[13].obj = ui_BitCrush;
    midi_map[14].obj = ui_Bulge;
    midi_map[15].obj = ui_VectorCancelling;
    midi_map[16].obj = ui_Swirl;
    midi_map[17].obj = ui_Smoothing;
    midi_map[18].obj = ui_WobbleAmount;
    midi_map[19].obj = ui_WobblePhase;
    midi_map[20].obj = ui_DelayDecay;
    midi_map[21].obj = ui_DelayLength;
    midi_map[22].obj = ui_DashLength;
    midi_map[23].obj = ui_LuaEffect;
    midi_map[24].obj = ui_TraceStart;
    midi_map[25].obj = ui_TraceLength;

    // ModifyScreen (switches)
    midi_map[26].obj = ui_ScaleSwitch;
    midi_map[27].obj = ui_DistortSwitch;
    midi_map[28].obj = ui_RotateSwitch;
    midi_map[29].obj = ui_TranslateSwitch;
    midi_map[30].obj = ui_RippleSwitch;

    // ModifyScreen (sliders)
    midi_map[31].obj = ui_ScaleX;
    midi_map[32].obj = ui_ScaleY;
    midi_map[33].obj = ui_ScaleZ;
    midi_map[34].obj = ui_DistortX;
    midi_map[35].obj = ui_DistortY;
    midi_map[36].obj = ui_DistortZ;
    midi_map[37].obj = ui_RotateX;
    midi_map[38].obj = ui_RotateY;
    midi_map[39].obj = ui_RotateZ;
    midi_map[40].obj = ui_TranslateX;
    midi_map[41].obj = ui_TranslateY;
    midi_map[42].obj = ui_TranslateZ;
    midi_map[43].obj = ui_RippleDepth;
    midi_map[44].obj = ui_RipplePhase;
    midi_map[45].obj = ui_RippleAmount;
    midi_map[46].obj = ui_Play;
    midi_map[47].obj = ui_Pause;
    midi_map[48].obj = ui_Record;
    midi_map[49].obj = ui_Add;
    //midi_map[50].obj = ui_MIDIEnabled;
}

/* --- MIDI Sender helpers --- */
static bool send_midi_3bytes(uint8_t status, uint8_t d1, uint8_t d2)
{
    uint8_t msg[3] = { status, d1, d2 };
    uint32_t wrote = tud_midi_stream_write(0, msg, 3);

    if (wrote == 3) return true;

    ESP_LOGW(TAG, "MIDI write failed (%u bytes)", wrote);
    return false;
}

/* --- Event callbacks (UI -> DAW) --- */

// Generic drum pad callback using midi_cfg
void ui_event_drum_pad(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    midi_cfg_t *cfg = (midi_cfg_t*)lv_event_get_user_data(e);
    if(!cfg) return;

    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_PRESSED) {
        lv_obj_add_state(target, LV_STATE_CHECKED);
        send_midi_3bytes(0x90 | (cfg->channel & 0x0F), cfg->note, 127); // Note On
    }
    if(event_code == LV_EVENT_RELEASED || event_code == LV_EVENT_PRESS_LOST) {
        lv_obj_clear_state(target, LV_STATE_CHECKED);
        send_midi_3bytes(0x80 | (cfg->channel & 0x0F), cfg->note, 0);   // Note Off
    }

}

void ui_event_slider_send_midi(lv_event_t * e)
{
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) return;

    lv_obj_t * slider = lv_event_get_target(e);
    midi_cfg_t *cfg = (midi_cfg_t*) lv_event_get_user_data(e);
    if (!cfg) return;

    int val = lv_slider_get_value(slider);  // 0–100 range
    uint8_t midi_val = (uint8_t)((val * 127) / 100);

    send_midi_3bytes(0xB0 | (cfg->channel & 0x0F), cfg->cc, midi_val);
    ESP_LOGI(TAG, "Sent CC %u ch %u -> %u", cfg->cc, cfg->channel, midi_val);
}

void ui_event_switch_send_midi(lv_event_t * e)
{
    if (lv_event_get_code(e) != LV_EVENT_VALUE_CHANGED) return;

    lv_obj_t * sw = lv_event_get_target(e);
    midi_cfg_t *cfg = (midi_cfg_t *)lv_event_get_user_data(e);
    if (!cfg) return;

    uint8_t value = lv_obj_has_state(sw, LV_STATE_CHECKED) ? 127 : 0; // if checked value = 127, if unchecked value = 0
    send_midi_3bytes(0xB0 | cfg->channel, cfg->cc, value);
    ESP_LOGI(TAG, "Sent CC %u ch %u -> %u", cfg->cc, cfg->channel, value);
}

void ui_event_play_send_midi(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    midi_cfg_t *cfg = (midi_cfg_t *)lv_event_get_user_data(e);
    if (!cfg) return;

    if(event_code == LV_EVENT_PRESSED) {
        _ui_flag_modify(ui_Play, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Pause, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        uint8_t value = 127;
        send_midi_3bytes(0xB0 | cfg->channel, cfg->cc, value);
        ESP_LOGI(TAG, "Sent CC %u ch %u -> %u", cfg->cc, cfg->channel, value);
    }
}

void ui_event_pause_send_midi(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    midi_cfg_t *cfg = (midi_cfg_t *)lv_event_get_user_data(e);
    if (!cfg) return;

    if(event_code == LV_EVENT_PRESSED) {
        _ui_flag_modify(ui_Play, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Pause, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_state_modify(ui_Record, LV_STATE_CHECKED, _UI_MODIFY_STATE_REMOVE);
        uint8_t value = 127;
        send_midi_3bytes(0xB0 | cfg->channel, cfg->cc, value);
        ESP_LOGI(TAG, "Sent CC %u ch %u -> %u", cfg->cc, cfg->channel, value);
    }
}

/* --- DAW -> UI sync --- */
#define CC_RING_SIZE        64       // must be to the power of two

typedef struct { uint8_t cc, val; } cc_msg_t;
static cc_msg_t cc_ring[CC_RING_SIZE];
static volatile uint32_t cc_head = 0, cc_tail = 0;

static cc_state_t cc_table[128];
static SemaphoreHandle_t cc_mutex;

/* -------------------------------------------------- */
/* Ring-buffer helpers                                 */
/* -------------------------------------------------- */
static inline void ring_push(uint8_t cc, uint8_t val)
{
    uint32_t next = (cc_head + 1) & (CC_RING_SIZE - 1);
    if (next == cc_tail) {               // buffer full -> drop oldest
        cc_tail = (cc_tail + 1) & (CC_RING_SIZE - 1);
    }
    cc_ring[cc_head].cc  = cc;
    cc_ring[cc_head].val = val;
    cc_head = next;
}

/* -------------------------------------------------- */
/* LVGL-side helpers                                   */
/* -------------------------------------------------- */

// Called from dispatcher on LVGL thread
static void midi_dispatch(void *unused)
{
    while (cc_tail != cc_head) {
        uint8_t cc  = cc_ring[cc_tail].cc;
        uint8_t val = cc_ring[cc_tail].val;
        cc_tail = (cc_tail + 1) & (CC_RING_SIZE - 1);

        // Normal CC -> update mapped widget
        for (size_t i = 0; i < sizeof(midi_map)/sizeof(midi_map[0]); i++) {
            if (midi_map[i].cc == cc && midi_map[i].obj) {
                if (midi_map[i].is_switch) {
                    if (val > 63) lv_obj_add_state(midi_map[i].obj, LV_STATE_CHECKED);
                    else          lv_obj_clear_state(midi_map[i].obj, LV_STATE_CHECKED);
                } else {
                    int ui_val = (val * 100) / 127;
                    lv_slider_set_value(midi_map[i].obj, ui_val, LV_ANIM_OFF);
                }
                break;
            }
        }
    }
}

/* -------------------------------------------------- */
/* MIDI RX task                                        */
/* -------------------------------------------------- */
static void midi_task(void *arg)
{
    uint8_t packet[4];

    for (;;) {
        if (!tud_midi_available()) {
            vTaskDelay(pdMS_TO_TICKS(CONFIG_LV_DEF_REFR_PERIOD)); // must match screen refresh rate
            continue;
        }

        while (tud_midi_available()) {
            if (tud_midi_packet_read(packet)) {
                uint8_t status = packet[1];
                uint8_t d1     = packet[2];
                uint8_t d2     = packet[3];

                if ((status & 0xF0) == 0xB0 && d1 < 128) {
                    ring_push(d1, d2);
                    // Schedule one LVGL callback per batch
                    lv_async_call(midi_dispatch, NULL);
                }
            }
        }
    }
}

/* -------------------------------------------------- */
/* Startup                                            */
/* -------------------------------------------------- */
void midi_task_start(void)
{
    cc_head = cc_tail = 0;
    memset(cc_table, 0, sizeof(cc_table));
    cc_mutex = xSemaphoreCreateMutex();

    xTaskCreate(midi_task, "midi_rx", 4096, NULL, 20, NULL);
}

/* -------------------------------------------------- */
/* MIDI CC setup for UI objects                       */
/* -------------------------------------------------- */

// each screen gets it's own seperate initializer
void midi_setup_MainScreen(void)
{
    // MIDI setup for slider event callback (MainScreen)
    lv_event_cb_t SLcb = ui_event_slider_send_midi;
    static midi_cfg_t freq_cfg = { .cc = 10, .channel = 0 };
    lv_obj_add_event_cb(ui_Frequency, SLcb, LV_EVENT_VALUE_CHANGED, &freq_cfg);
    static midi_cfg_t perspective_cfg = { .cc = 11, .channel = 0 };
    lv_obj_add_event_cb(ui_Perspective, SLcb, LV_EVENT_VALUE_CHANGED, &perspective_cfg);
    static midi_cfg_t focal_cfg = { .cc = 12, .channel = 0 };
    lv_obj_add_event_cb(ui_FocalLength, SLcb, LV_EVENT_VALUE_CHANGED, &focal_cfg);
}

void midi_setup_ModifyScreen(void)
{
    // MIDI setup for switch event callback (ModifyScreen)
    lv_event_cb_t SWcb = ui_event_switch_send_midi;
    static midi_cfg_t scaleSW_cfg = { .cc = 26, .channel = 0 };
    lv_obj_add_event_cb(ui_ScaleSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &scaleSW_cfg);
    static midi_cfg_t distortSW_cfg = { .cc = 27, .channel = 0 };
    lv_obj_add_event_cb(ui_DistortSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &distortSW_cfg);
    static midi_cfg_t rotateSW_cfg = { .cc = 28, .channel = 0 };
    lv_obj_add_event_cb(ui_RotateSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &rotateSW_cfg);
    static midi_cfg_t translateSW_cfg = { .cc = 29, .channel = 0 };
    lv_obj_add_event_cb(ui_TranslateSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &translateSW_cfg);
    static midi_cfg_t rippleSW_cfg = { .cc = 30, .channel = 0 };
    lv_obj_add_event_cb(ui_RippleSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &rippleSW_cfg);

    // MIDI setup for slider event callback (ModifyScreen)
    lv_event_cb_t SLcb = ui_event_slider_send_midi;
    static midi_cfg_t scaleX_cfg = { .cc = 31, .channel = 0 };
    lv_obj_add_event_cb(ui_ScaleX, SLcb, LV_EVENT_VALUE_CHANGED, &scaleX_cfg);
    static midi_cfg_t scaleY_cfg = { .cc = 32, .channel = 0 };
    lv_obj_add_event_cb(ui_ScaleY, SLcb, LV_EVENT_VALUE_CHANGED, &scaleY_cfg);
    static midi_cfg_t scaleZ_cfg = { .cc = 33, .channel = 0 };
    lv_obj_add_event_cb(ui_ScaleZ, SLcb, LV_EVENT_VALUE_CHANGED, &scaleZ_cfg);
    static midi_cfg_t distX_cfg = { .cc = 34, .channel = 0 };
    lv_obj_add_event_cb(ui_DistortX, SLcb, LV_EVENT_VALUE_CHANGED, &distX_cfg);
    static midi_cfg_t distY_cfg = { .cc = 35, .channel = 0 };
    lv_obj_add_event_cb(ui_DistortY, SLcb, LV_EVENT_VALUE_CHANGED, &distY_cfg);
    static midi_cfg_t distZ_cfg = { .cc = 36, .channel = 0 };
    lv_obj_add_event_cb(ui_DistortZ, SLcb, LV_EVENT_VALUE_CHANGED, &distZ_cfg);
    static midi_cfg_t rotateX_cfg = { .cc = 37, .channel = 0 };
    lv_obj_add_event_cb(ui_RotateX, SLcb, LV_EVENT_VALUE_CHANGED, &rotateX_cfg);
    static midi_cfg_t rotateY_cfg = { .cc = 38, .channel = 0 };
    lv_obj_add_event_cb(ui_RotateY, SLcb, LV_EVENT_VALUE_CHANGED, &rotateY_cfg);
    static midi_cfg_t rotateZ_cfg = { .cc = 39, .channel = 0 };
    lv_obj_add_event_cb(ui_RotateZ, SLcb, LV_EVENT_VALUE_CHANGED, &rotateZ_cfg);
    static midi_cfg_t transX_cfg = { .cc = 40, .channel = 0 };
    lv_obj_add_event_cb(ui_TranslateX, SLcb, LV_EVENT_VALUE_CHANGED, &transX_cfg);
    static midi_cfg_t transY_cfg = { .cc = 41, .channel = 0 };
    lv_obj_add_event_cb(ui_TranslateY, SLcb, LV_EVENT_VALUE_CHANGED, &transY_cfg);
    static midi_cfg_t transZ_cfg = { .cc = 42, .channel = 0 };
    lv_obj_add_event_cb(ui_TranslateZ, SLcb, LV_EVENT_VALUE_CHANGED, &transZ_cfg);
    static midi_cfg_t rippleD_cfg = { .cc = 43, .channel = 0 };
    lv_obj_add_event_cb(ui_RippleDepth, SLcb, LV_EVENT_VALUE_CHANGED, &rippleD_cfg);
    static midi_cfg_t rippleP_cfg = { .cc = 44, .channel = 0 };
    lv_obj_add_event_cb(ui_RipplePhase, SLcb, LV_EVENT_VALUE_CHANGED, &rippleP_cfg);
    static midi_cfg_t rippleA_cfg = { .cc = 45, .channel = 0 };
    lv_obj_add_event_cb(ui_RippleAmount, SLcb, LV_EVENT_VALUE_CHANGED, &rippleA_cfg);
}

void midi_setup_EffectsScreen(void)
{
    // MIDI setup for switch event callback (EffectsScreen)
    lv_event_cb_t SWcb = ui_event_switch_send_midi;
    static midi_cfg_t bitcrushSW_cfg = { .cc = 0, .channel = 0 };
    lv_obj_add_event_cb(ui_BitCrushSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &bitcrushSW_cfg);
    static midi_cfg_t bulgeSW_cfg = { .cc = 1, .channel = 0 };
    lv_obj_add_event_cb(ui_BulgeSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &bulgeSW_cfg);
    static midi_cfg_t vectorSW_cfg = { .cc = 2, .channel = 0 };
    lv_obj_add_event_cb(ui_VectorSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &vectorSW_cfg);
    static midi_cfg_t swirlSW_cfg = { .cc = 3, .channel = 0 };
    lv_obj_add_event_cb(ui_SwirlSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &swirlSW_cfg);
    static midi_cfg_t smoothingSW_cfg = { .cc = 4, .channel = 0 };
    lv_obj_add_event_cb(ui_SmoothingSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &smoothingSW_cfg);
    static midi_cfg_t wobbleSW_cfg = { .cc = 5, .channel = 0 };
    lv_obj_add_event_cb(ui_WobbleSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &wobbleSW_cfg);
    static midi_cfg_t delaySW_cfg = { .cc = 6, .channel = 0 };
    lv_obj_add_event_cb(ui_DelaySwitch, SWcb, LV_EVENT_VALUE_CHANGED, &delaySW_cfg);
    static midi_cfg_t dashSW_cfg = { .cc = 7, .channel = 0 };
    lv_obj_add_event_cb(ui_DashSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &dashSW_cfg);
    static midi_cfg_t luaSW_cfg = { .cc = 8, .channel = 0 };
    lv_obj_add_event_cb(ui_LuaSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &luaSW_cfg);
    static midi_cfg_t traceSW_cfg = { .cc = 9, .channel = 0 };
    lv_obj_add_event_cb(ui_TraceSwitch, SWcb, LV_EVENT_VALUE_CHANGED, &traceSW_cfg);

    // MIDI setup for slider event callback (EffectsScreen)
    lv_event_cb_t SLcb = ui_event_slider_send_midi;
    static midi_cfg_t bitcrush_cfg = { .cc = 13, .channel = 0 };
    lv_obj_add_event_cb(ui_BitCrush, SLcb, LV_EVENT_VALUE_CHANGED, &bitcrush_cfg);
    static midi_cfg_t bulge_cfg = { .cc = 14, .channel = 0 };
    lv_obj_add_event_cb(ui_Bulge, SLcb, LV_EVENT_VALUE_CHANGED, &bulge_cfg);
    static midi_cfg_t vectorC_cfg = { .cc = 15, .channel = 0 };
    lv_obj_add_event_cb(ui_VectorCancelling, SLcb, LV_EVENT_VALUE_CHANGED, &vectorC_cfg);
    static midi_cfg_t swirl_cfg = { .cc = 16, .channel = 0 };
    lv_obj_add_event_cb(ui_Swirl, SLcb, LV_EVENT_VALUE_CHANGED, &swirl_cfg);
    static midi_cfg_t smoothing_cfg = { .cc = 17, .channel = 0 };
    lv_obj_add_event_cb(ui_Smoothing, SLcb, LV_EVENT_VALUE_CHANGED, &smoothing_cfg);
    static midi_cfg_t wobbleA_cfg = { .cc = 18, .channel = 0 };
    lv_obj_add_event_cb(ui_WobbleAmount, SLcb, LV_EVENT_VALUE_CHANGED, &wobbleA_cfg);
    static midi_cfg_t wobbleP_cfg = { .cc = 19, .channel = 0 };
    lv_obj_add_event_cb(ui_WobblePhase, SLcb, LV_EVENT_VALUE_CHANGED, &wobbleP_cfg);
    static midi_cfg_t delayD_cfg = { .cc = 20, .channel = 0 };
    lv_obj_add_event_cb(ui_DelayDecay, SLcb, LV_EVENT_VALUE_CHANGED, &delayD_cfg);
    static midi_cfg_t delayL_cfg = { .cc = 21, .channel = 0 };
    lv_obj_add_event_cb(ui_DelayLength, SLcb, LV_EVENT_VALUE_CHANGED, &delayL_cfg);
    static midi_cfg_t dash_cfg = { .cc = 22, .channel = 0 };
    lv_obj_add_event_cb(ui_DashLength, SLcb, LV_EVENT_VALUE_CHANGED, &dash_cfg);
    static midi_cfg_t lua_cfg = { .cc = 23, .channel = 0 };
    lv_obj_add_event_cb(ui_LuaEffect, SLcb, LV_EVENT_VALUE_CHANGED, &lua_cfg);
    static midi_cfg_t traceST_cfg = { .cc = 24, .channel = 0 };
    lv_obj_add_event_cb(ui_TraceStart, SLcb, LV_EVENT_VALUE_CHANGED, &traceST_cfg);
    static midi_cfg_t traceL_cfg = { .cc = 25, .channel = 0 };
    lv_obj_add_event_cb(ui_TraceLength, SLcb, LV_EVENT_VALUE_CHANGED, &traceL_cfg);
}

void midi_setup_GlobalObjs(void)
{
    lv_event_cb_t Play_cb = ui_event_play_send_midi;
    lv_event_cb_t Pause_cb = ui_event_pause_send_midi;
    lv_event_cb_t SWcb = ui_event_switch_send_midi;
    static midi_cfg_t play_cfg = { .cc = 46, .channel = 0 };
    lv_obj_add_event_cb(ui_Play, Play_cb, LV_EVENT_PRESSED, &play_cfg);
    static midi_cfg_t pause_cfg = { .cc = 47, .channel = 0 };
    lv_obj_add_event_cb(ui_Pause, Pause_cb, LV_EVENT_PRESSED, &pause_cfg);
    static midi_cfg_t record_cfg = { .cc = 48, .channel = 0 };
    lv_obj_add_event_cb(ui_Record, SWcb, LV_EVENT_VALUE_CHANGED, &record_cfg);
    static midi_cfg_t add_cfg = { .cc = 49, .channel = 0 };
    lv_obj_add_event_cb(ui_Add, SWcb, LV_EVENT_VALUE_CHANGED, &add_cfg);
}

//void midi_setup_DrumpadScreen(void)
//{
//    // MIDI setup for switch event callback (DrumpadScreen)
//    lv_event_cb_t SWcb = ui_event_switch_send_midi;
//    static midi_cfg_t MIDI_EN_cfg = { .cc = 50, .channel = 0 };
//    lv_obj_add_event_cb(ui_MIDIEnabled, SWcb, LV_EVENT_VALUE_CHANGED, &MIDI_EN_cfg);
//}