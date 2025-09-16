#include "../ui.h"

lv_obj_t * ui_GlobalObjContainer = NULL;
lv_obj_t * ui_Play = NULL;
lv_obj_t * ui_Pause = NULL;
lv_obj_t * ui_Record = NULL;
lv_obj_t * ui_Add = NULL;
lv_obj_t * ui_GlobalSettingsContainer = NULL;
lv_obj_t * ui_Settings = NULL;
lv_obj_t * ui_Drumpad = NULL;
lv_obj_t * ui_Home = NULL;

void ui_event_Record(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);

    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED)) {
        _ui_flag_modify(ui_Play, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Pause, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
}

void ui_event_Settings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_flag_modify(ui_Settings, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Drumpad, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Home, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_GlobalObjContainer, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_screen_change(&ui_SettingsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_SettingsScreen_screen_init);
    }
}

void ui_event_Drumpad(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_flag_modify(ui_Settings, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Drumpad, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_Home, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_screen_change(&ui_DrumpadScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_DrumpadScreen_screen_init);
    }
}

void ui_event_Home(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_flag_modify(ui_Settings, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Drumpad, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_flag_modify(ui_Home, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
        _ui_flag_modify(ui_GlobalObjContainer, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_MainScreen_screen_init);
    }
}

void init_global_objs(void)
{
    lv_obj_t * globalOBJ = lv_layer_top(); // you can either set a name or just call lv_layer_top directly into your object

    if (ui_GlobalObjContainer) return;  // already created
    ui_GlobalObjContainer = lv_obj_create(globalOBJ);
    lv_obj_remove_style_all(ui_GlobalObjContainer);
    lv_obj_set_width(ui_GlobalObjContainer, 170);
    lv_obj_set_height(ui_GlobalObjContainer, 85);
    lv_obj_set_flex_flow(ui_GlobalObjContainer, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_GlobalObjContainer, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_GlobalObjContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags;
    lv_obj_move_foreground(ui_GlobalObjContainer);

    ui_Play = lv_button_create(ui_GlobalObjContainer);
    lv_obj_set_width(ui_Play, 50);
    lv_obj_set_height(ui_Play, 50);
    lv_obj_set_align(ui_Play, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Play, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Play, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Play, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Play, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Play, &ui_img_play32px_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui_Play, lv_color_hex(0x68F555), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui_Play, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Pause = lv_button_create(ui_GlobalObjContainer);
    lv_obj_set_width(ui_Pause, 50);
    lv_obj_set_height(ui_Pause, 50);
    lv_obj_set_align(ui_Pause, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Pause, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Pause, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Pause, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Pause, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Pause, &ui_img_pause32px_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui_Pause, lv_color_hex(0xFB4B4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui_Pause, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Record = lv_button_create(ui_GlobalObjContainer);
    lv_obj_set_width(ui_Record, 50);
    lv_obj_set_height(ui_Record, 50);
    lv_obj_set_align(ui_Record, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Record, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Record, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Record, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Record, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Record, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Record, &ui_img_2099277316, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Add = lv_button_create(ui_GlobalObjContainer);
    lv_obj_set_width(ui_Add, 50);
    lv_obj_set_height(ui_Add, 50);
    lv_obj_set_align(ui_Add, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Add, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Add, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Add, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Add, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Add, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Add, &ui_img_add_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    // settings
    if (ui_GlobalSettingsContainer) return;
    ui_GlobalSettingsContainer = lv_obj_create(globalOBJ);
    lv_obj_remove_style_all(ui_GlobalSettingsContainer);
    lv_obj_set_width(ui_GlobalSettingsContainer, 150);
    lv_obj_set_height(ui_GlobalSettingsContainer, 85);
    lv_obj_set_flex_flow(ui_GlobalSettingsContainer, LV_FLEX_FLOW_ROW_REVERSE);
    lv_obj_set_flex_align(ui_GlobalSettingsContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_GlobalSettingsContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_move_foreground(ui_GlobalSettingsContainer);

    ui_Settings = lv_button_create(ui_GlobalSettingsContainer);
    lv_obj_set_width(ui_Settings, 50);
    lv_obj_set_height(ui_Settings, 50);
    lv_obj_set_align(ui_Settings, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Settings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Settings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Settings, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Settings, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Settings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Settings, &ui_img_settings_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Drumpad = lv_button_create(ui_GlobalSettingsContainer);
    lv_obj_set_width(ui_Drumpad, 50);
    lv_obj_set_height(ui_Drumpad, 50);
    lv_obj_set_align(ui_Drumpad, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Drumpad, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Drumpad, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Drumpad, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Drumpad, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Drumpad, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Drumpad, &ui_img_drumpad_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Home = lv_button_create(ui_GlobalSettingsContainer);
    lv_obj_set_width(ui_Home, 50);
    lv_obj_set_height(ui_Home, 50);
    lv_obj_set_align(ui_Home, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Home, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Home, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Home, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Home, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Home, &ui_img_1134109583, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Record, ui_event_Record, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Settings, ui_event_Settings, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Drumpad, ui_event_Drumpad, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Home, ui_event_Home, LV_EVENT_ALL, NULL);

    midi_setup_GlobalObjs();
}