// Removed disabled states and switch events

#include "../ui.h"

lv_obj_t * ui_ModifyScreen = NULL;
lv_obj_t * ui_Container36 = NULL;
lv_obj_t * ui_Button7 = NULL;
lv_obj_t * ui_Label29 = NULL;
lv_obj_t * ui_Button4 = NULL;
lv_obj_t * ui_Container44 = NULL;
lv_obj_t * ui_ScaleSwitch = NULL;
lv_obj_t * ui_ScaleContainer = NULL;
lv_obj_t * ui_Container40 = NULL;
lv_obj_t * ui_Label35 = NULL;
lv_obj_t * ui_ScaleX = NULL;
lv_obj_t * ui_Container41 = NULL;
lv_obj_t * ui_Label32 = NULL;
lv_obj_t * ui_ScaleY = NULL;
lv_obj_t * ui_Container42 = NULL;
lv_obj_t * ui_Label33 = NULL;
lv_obj_t * ui_ScaleZ = NULL;
lv_obj_t * ui_Container43 = NULL;
lv_obj_t * ui_DistortSwitch = NULL;
lv_obj_t * ui_DistortContainer = NULL;
lv_obj_t * ui_Container5 = NULL;
lv_obj_t * ui_Label34 = NULL;
lv_obj_t * ui_DistortX = NULL;
lv_obj_t * ui_Container8 = NULL;
lv_obj_t * ui_Label5 = NULL;
lv_obj_t * ui_DistortY = NULL;
lv_obj_t * ui_Container9 = NULL;
lv_obj_t * ui_Label6 = NULL;
lv_obj_t * ui_DistortZ = NULL;
lv_obj_t * ui_Container16 = NULL;
lv_obj_t * ui_RotateSwitch = NULL;
lv_obj_t * ui_RotateContainer = NULL;
lv_obj_t * ui_Container11 = NULL;
lv_obj_t * ui_Label13 = NULL;
lv_obj_t * ui_RotateX = NULL;
lv_obj_t * ui_Container13 = NULL;
lv_obj_t * ui_Label9 = NULL;
lv_obj_t * ui_RotateY = NULL;
lv_obj_t * ui_Container14 = NULL;
lv_obj_t * ui_Label11 = NULL;
lv_obj_t * ui_RotateZ = NULL;
lv_obj_t * ui_Container20 = NULL;
lv_obj_t * ui_TranslateSwitch = NULL;
lv_obj_t * ui_TranslateContainer = NULL;
lv_obj_t * ui_Container15 = NULL;
lv_obj_t * ui_Label16 = NULL;
lv_obj_t * ui_TranslateX = NULL;
lv_obj_t * ui_Container17 = NULL;
lv_obj_t * ui_Label12 = NULL;
lv_obj_t * ui_TranslateY = NULL;
lv_obj_t * ui_Container18 = NULL;
lv_obj_t * ui_Label14 = NULL;
lv_obj_t * ui_TranslateZ = NULL;
lv_obj_t * ui_Container12 = NULL;
lv_obj_t * ui_RippleSwitch = NULL;
lv_obj_t * ui_RippleContainer = NULL;
lv_obj_t * ui_Container6 = NULL;
lv_obj_t * ui_Label10 = NULL;
lv_obj_t * ui_RippleDepth = NULL;
lv_obj_t * ui_Container7 = NULL;
lv_obj_t * ui_Label7 = NULL;
lv_obj_t * ui_RipplePhase = NULL;
lv_obj_t * ui_Container10 = NULL;
lv_obj_t * ui_Label8 = NULL;
lv_obj_t * ui_RippleAmount = NULL;
// event funtions
void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_EffectsScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_EffectsScreen_screen_init);
    }
}

void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_MainScreen_screen_init);
    }
}

// build funtions

void ui_ModifyScreen_screen_init(void)
{

    ui_ModifyScreen = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(ui_ModifyScreen, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_ModifyScreen, LV_DIR_VER);
    lv_obj_set_flex_flow(ui_ModifyScreen, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_ModifyScreen, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);

    ui_Container36 = lv_obj_create(ui_ModifyScreen);
    lv_obj_remove_style_all(ui_Container36);
    lv_obj_set_width(ui_Container36, 1024);
    lv_obj_set_height(ui_Container36, 70);
    lv_obj_set_align(ui_Container36, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container36, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container36, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END);
    lv_obj_remove_flag(ui_Container36, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button7 = lv_button_create(ui_Container36);
    lv_obj_set_width(ui_Button7, 80);
    lv_obj_set_height(ui_Button7, 50);
    lv_obj_set_align(ui_Button7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button7, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Button7, &ui_img_arrow_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui_Button7, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui_Button7, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button7, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button7, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button7, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label29 = lv_label_create(ui_Container36);
    lv_obj_set_width(ui_Label29, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label29, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label29, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label29, "Modify");
    lv_obj_set_style_text_color(ui_Label29, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label29, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label29, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button4 = lv_button_create(ui_Container36);
    lv_obj_set_width(ui_Button4, 80);
    lv_obj_set_height(ui_Button4, 50);
    lv_obj_set_align(ui_Button4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button4, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Button4, &ui_img_1101766569, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui_Button4, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui_Button4, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button4, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button4, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button4, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container44 = lv_obj_create(ui_ModifyScreen);
    lv_obj_remove_style_all(ui_Container44);
    lv_obj_set_width(ui_Container44, 800);
    lv_obj_set_height(ui_Container44, 150);
    lv_obj_set_align(ui_Container44, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container44, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container44, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container44, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container44, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container44, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container44, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container44, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScaleSwitch = lv_switch_create(ui_Container44);
    lv_obj_set_width(ui_ScaleSwitch, 50);
    lv_obj_set_height(ui_ScaleSwitch, 25);
    lv_obj_set_align(ui_ScaleSwitch, LV_ALIGN_CENTER);

    ui_ScaleContainer = lv_obj_create(ui_Container44);
    lv_obj_remove_style_all(ui_ScaleContainer);
    lv_obj_set_width(ui_ScaleContainer, 700);
    lv_obj_set_height(ui_ScaleContainer, 150);
    lv_obj_set_align(ui_ScaleContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_ScaleContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_ScaleContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_ScaleContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container40 = lv_obj_create(ui_ScaleContainer);
    lv_obj_remove_style_all(ui_Container40);
    lv_obj_set_width(ui_Container40, 700);
    lv_obj_set_height(ui_Container40, 50);
    lv_obj_set_align(ui_Container40, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container40, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container40, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container40, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label35 = lv_label_create(ui_Container40);
    lv_obj_set_width(ui_Label35, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label35, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label35, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label35, "Scale X");

    ui_ScaleX = lv_slider_create(ui_Container40);
    lv_slider_set_value(ui_ScaleX, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScaleX) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ScaleX, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScaleX, 500);
    lv_obj_set_height(ui_ScaleX, 10);
    lv_obj_set_align(ui_ScaleX, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_ScaleX, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_ScaleX, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleX, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScaleX, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleX, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScaleX, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleX, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_ScaleX, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_ScaleX,
                                                                                             lv_obj_get_style_pad_right(ui_ScaleX, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container41 = lv_obj_create(ui_ScaleContainer);
    lv_obj_remove_style_all(ui_Container41);
    lv_obj_set_width(ui_Container41, 700);
    lv_obj_set_height(ui_Container41, 50);
    lv_obj_set_align(ui_Container41, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container41, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container41, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container41, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label32 = lv_label_create(ui_Container41);
    lv_obj_set_width(ui_Label32, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label32, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label32, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label32, "Scale Y");

    ui_ScaleY = lv_slider_create(ui_Container41);
    lv_slider_set_value(ui_ScaleY, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScaleY) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ScaleY, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScaleY, 500);
    lv_obj_set_height(ui_ScaleY, 10);
    lv_obj_set_align(ui_ScaleY, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_ScaleY, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_ScaleY, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleY, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScaleY, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleY, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScaleY, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleY, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_ScaleY, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_ScaleY,
                                                                                             lv_obj_get_style_pad_right(ui_ScaleY, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container42 = lv_obj_create(ui_ScaleContainer);
    lv_obj_remove_style_all(ui_Container42);
    lv_obj_set_width(ui_Container42, 700);
    lv_obj_set_height(ui_Container42, 50);
    lv_obj_set_align(ui_Container42, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container42, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container42, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container42, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label33 = lv_label_create(ui_Container42);
    lv_obj_set_width(ui_Label33, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label33, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label33, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label33, "Scale Z");

    ui_ScaleZ = lv_slider_create(ui_Container42);
    lv_slider_set_value(ui_ScaleZ, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScaleZ) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_ScaleZ, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScaleZ, 500);
    lv_obj_set_height(ui_ScaleZ, 10);
    lv_obj_set_align(ui_ScaleZ, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_ScaleZ, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_ScaleZ, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleZ, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScaleZ, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleZ, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ScaleZ, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScaleZ, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_ScaleZ, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_ScaleZ,
                                                                                             lv_obj_get_style_pad_right(ui_ScaleZ, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container43 = lv_obj_create(ui_ModifyScreen);
    lv_obj_remove_style_all(ui_Container43);
    lv_obj_set_width(ui_Container43, 800);
    lv_obj_set_height(ui_Container43, 150);
    lv_obj_set_align(ui_Container43, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container43, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container43, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container43, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container43, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container43, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container43, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container43, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DistortSwitch = lv_switch_create(ui_Container43);
    lv_obj_set_width(ui_DistortSwitch, 50);
    lv_obj_set_height(ui_DistortSwitch, 25);
    lv_obj_set_align(ui_DistortSwitch, LV_ALIGN_CENTER);

    ui_DistortContainer = lv_obj_create(ui_Container43);
    lv_obj_remove_style_all(ui_DistortContainer);
    lv_obj_set_width(ui_DistortContainer, 700);
    lv_obj_set_height(ui_DistortContainer, 150);
    lv_obj_set_align(ui_DistortContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_DistortContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_DistortContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_DistortContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container5 = lv_obj_create(ui_DistortContainer);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, 700);
    lv_obj_set_height(ui_Container5, 50);
    lv_obj_set_align(ui_Container5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container5, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container5, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label34 = lv_label_create(ui_Container5);
    lv_obj_set_width(ui_Label34, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label34, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label34, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label34, "Distort X");

    ui_DistortX = lv_slider_create(ui_Container5);
    lv_slider_set_value(ui_DistortX, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_DistortX) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_DistortX, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_DistortX, 500);
    lv_obj_set_height(ui_DistortX, 10);
    lv_obj_set_align(ui_DistortX, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_DistortX, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_DistortX, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortX, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DistortX, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortX, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DistortX, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortX, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_DistortX, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_DistortX,
                                                                                               lv_obj_get_style_pad_right(ui_DistortX, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container8 = lv_obj_create(ui_DistortContainer);
    lv_obj_remove_style_all(ui_Container8);
    lv_obj_set_width(ui_Container8, 700);
    lv_obj_set_height(ui_Container8, 50);
    lv_obj_set_align(ui_Container8, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container8, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container8, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container8, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label5 = lv_label_create(ui_Container8);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "Distort Y");

    ui_DistortY = lv_slider_create(ui_Container8);
    lv_slider_set_value(ui_DistortY, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_DistortY) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_DistortY, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_DistortY, 500);
    lv_obj_set_height(ui_DistortY, 10);
    lv_obj_set_align(ui_DistortY, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_DistortY, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_DistortY, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortY, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DistortY, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortY, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DistortY, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortY, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_DistortY, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_DistortY,
                                                                                               lv_obj_get_style_pad_right(ui_DistortY, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container9 = lv_obj_create(ui_DistortContainer);
    lv_obj_remove_style_all(ui_Container9);
    lv_obj_set_width(ui_Container9, 700);
    lv_obj_set_height(ui_Container9, 50);
    lv_obj_set_align(ui_Container9, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container9, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container9, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container9, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label6 = lv_label_create(ui_Container9);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "Distort Z");

    ui_DistortZ = lv_slider_create(ui_Container9);
    lv_slider_set_value(ui_DistortZ, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_DistortZ) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_DistortZ, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_DistortZ, 500);
    lv_obj_set_height(ui_DistortZ, 10);
    lv_obj_set_align(ui_DistortZ, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_DistortZ, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_DistortZ, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortZ, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DistortZ, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortZ, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DistortZ, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DistortZ, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_DistortZ, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_DistortZ,
                                                                                               lv_obj_get_style_pad_right(ui_DistortZ, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container16 = lv_obj_create(ui_ModifyScreen);
    lv_obj_remove_style_all(ui_Container16);
    lv_obj_set_width(ui_Container16, 800);
    lv_obj_set_height(ui_Container16, 150);
    lv_obj_set_align(ui_Container16, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container16, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container16, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container16, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container16, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container16, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container16, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container16, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RotateSwitch = lv_switch_create(ui_Container16);
    lv_obj_set_width(ui_RotateSwitch, 50);
    lv_obj_set_height(ui_RotateSwitch, 25);
    lv_obj_set_align(ui_RotateSwitch, LV_ALIGN_CENTER);

    ui_RotateContainer = lv_obj_create(ui_Container16);
    lv_obj_remove_style_all(ui_RotateContainer);
    lv_obj_set_width(ui_RotateContainer, 700);
    lv_obj_set_height(ui_RotateContainer, 150);
    lv_obj_set_align(ui_RotateContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_RotateContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_RotateContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_RotateContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container11 = lv_obj_create(ui_RotateContainer);
    lv_obj_remove_style_all(ui_Container11);
    lv_obj_set_width(ui_Container11, 700);
    lv_obj_set_height(ui_Container11, 50);
    lv_obj_set_align(ui_Container11, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container11, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container11, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container11, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label13 = lv_label_create(ui_Container11);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "Rotate X");

    ui_RotateX = lv_slider_create(ui_Container11);
    lv_slider_set_value(ui_RotateX, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_RotateX) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_RotateX, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RotateX, 500);
    lv_obj_set_height(ui_RotateX, 10);
    lv_obj_set_align(ui_RotateX, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_RotateX, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_RotateX, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateX, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RotateX, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateX, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RotateX, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateX, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_RotateX, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_RotateX,
                                                                                              lv_obj_get_style_pad_right(ui_RotateX, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container13 = lv_obj_create(ui_RotateContainer);
    lv_obj_remove_style_all(ui_Container13);
    lv_obj_set_width(ui_Container13, 700);
    lv_obj_set_height(ui_Container13, 50);
    lv_obj_set_align(ui_Container13, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container13, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container13, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container13, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label9 = lv_label_create(ui_Container13);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "Rotate Y");

    ui_RotateY = lv_slider_create(ui_Container13);
    lv_slider_set_value(ui_RotateY, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_RotateY) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_RotateY, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RotateY, 500);
    lv_obj_set_height(ui_RotateY, 10);
    lv_obj_set_align(ui_RotateY, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_RotateY, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_RotateY, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateY, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RotateY, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateY, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RotateY, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateY, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_RotateY, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_RotateY,
                                                                                              lv_obj_get_style_pad_right(ui_RotateY, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container14 = lv_obj_create(ui_RotateContainer);
    lv_obj_remove_style_all(ui_Container14);
    lv_obj_set_width(ui_Container14, 700);
    lv_obj_set_height(ui_Container14, 50);
    lv_obj_set_align(ui_Container14, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container14, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container14, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container14, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label11 = lv_label_create(ui_Container14);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "Rotate Z");

    ui_RotateZ = lv_slider_create(ui_Container14);
    lv_slider_set_value(ui_RotateZ, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_RotateZ) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_RotateZ, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RotateZ, 500);
    lv_obj_set_height(ui_RotateZ, 10);
    lv_obj_set_align(ui_RotateZ, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_RotateZ, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_RotateZ, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateZ, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RotateZ, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateZ, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RotateZ, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RotateZ, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_RotateZ, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_RotateZ,
                                                                                              lv_obj_get_style_pad_right(ui_RotateZ, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container20 = lv_obj_create(ui_ModifyScreen);
    lv_obj_remove_style_all(ui_Container20);
    lv_obj_set_width(ui_Container20, 800);
    lv_obj_set_height(ui_Container20, 150);
    lv_obj_set_align(ui_Container20, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container20, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container20, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container20, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container20, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container20, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container20, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container20, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TranslateSwitch = lv_switch_create(ui_Container20);
    lv_obj_set_width(ui_TranslateSwitch, 50);
    lv_obj_set_height(ui_TranslateSwitch, 25);
    lv_obj_set_align(ui_TranslateSwitch, LV_ALIGN_CENTER);

    ui_TranslateContainer = lv_obj_create(ui_Container20);
    lv_obj_remove_style_all(ui_TranslateContainer);
    lv_obj_set_width(ui_TranslateContainer, 700);
    lv_obj_set_height(ui_TranslateContainer, 150);
    lv_obj_set_align(ui_TranslateContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_TranslateContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_TranslateContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_TranslateContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container15 = lv_obj_create(ui_TranslateContainer);
    lv_obj_remove_style_all(ui_Container15);
    lv_obj_set_width(ui_Container15, 700);
    lv_obj_set_height(ui_Container15, 50);
    lv_obj_set_align(ui_Container15, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container15, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container15, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container15, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label16 = lv_label_create(ui_Container15);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "Translate X");

    ui_TranslateX = lv_slider_create(ui_Container15);
    lv_slider_set_value(ui_TranslateX, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_TranslateX) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_TranslateX, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_TranslateX, 500);
    lv_obj_set_height(ui_TranslateX, 10);
    lv_obj_set_align(ui_TranslateX, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_TranslateX, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_TranslateX, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateX, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TranslateX, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateX, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TranslateX, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateX, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_TranslateX, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_TranslateX,
                                                                                                 lv_obj_get_style_pad_right(ui_TranslateX, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container17 = lv_obj_create(ui_TranslateContainer);
    lv_obj_remove_style_all(ui_Container17);
    lv_obj_set_width(ui_Container17, 700);
    lv_obj_set_height(ui_Container17, 50);
    lv_obj_set_align(ui_Container17, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container17, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container17, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container17, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label12 = lv_label_create(ui_Container17);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "Translate Y");

    ui_TranslateY = lv_slider_create(ui_Container17);
    lv_slider_set_value(ui_TranslateY, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_TranslateY) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_TranslateY, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_TranslateY, 500);
    lv_obj_set_height(ui_TranslateY, 10);
    lv_obj_set_align(ui_TranslateY, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_TranslateY, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_TranslateY, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateY, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TranslateY, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateY, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TranslateY, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateY, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_TranslateY, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_TranslateY,
                                                                                                 lv_obj_get_style_pad_right(ui_TranslateY, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container18 = lv_obj_create(ui_TranslateContainer);
    lv_obj_remove_style_all(ui_Container18);
    lv_obj_set_width(ui_Container18, 700);
    lv_obj_set_height(ui_Container18, 50);
    lv_obj_set_align(ui_Container18, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container18, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container18, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container18, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label14 = lv_label_create(ui_Container18);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "Translate Z");

    ui_TranslateZ = lv_slider_create(ui_Container18);
    lv_slider_set_value(ui_TranslateZ, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_TranslateZ) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_TranslateZ, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_TranslateZ, 500);
    lv_obj_set_height(ui_TranslateZ, 10);
    lv_obj_set_align(ui_TranslateZ, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_TranslateZ, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_TranslateZ, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateZ, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TranslateZ, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateZ, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TranslateZ, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TranslateZ, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_TranslateZ, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_TranslateZ,
                                                                                                 lv_obj_get_style_pad_right(ui_TranslateZ, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container12 = lv_obj_create(ui_ModifyScreen);
    lv_obj_remove_style_all(ui_Container12);
    lv_obj_set_width(ui_Container12, 800);
    lv_obj_set_height(ui_Container12, 150);
    lv_obj_set_align(ui_Container12, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container12, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container12, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container12, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container12, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container12, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container12, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container12, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RippleSwitch = lv_switch_create(ui_Container12);
    lv_obj_set_width(ui_RippleSwitch, 50);
    lv_obj_set_height(ui_RippleSwitch, 25);
    lv_obj_set_align(ui_RippleSwitch, LV_ALIGN_CENTER);

    ui_RippleContainer = lv_obj_create(ui_Container12);
    lv_obj_remove_style_all(ui_RippleContainer);
    lv_obj_set_width(ui_RippleContainer, 700);
    lv_obj_set_height(ui_RippleContainer, 150);
    lv_obj_set_align(ui_RippleContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_RippleContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_RippleContainer, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_RippleContainer, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container6 = lv_obj_create(ui_RippleContainer);
    lv_obj_remove_style_all(ui_Container6);
    lv_obj_set_width(ui_Container6, 700);
    lv_obj_set_height(ui_Container6, 50);
    lv_obj_set_align(ui_Container6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container6, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container6, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container6, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label10 = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Ripple depth");

    ui_RippleDepth = lv_slider_create(ui_Container6);
    lv_slider_set_value(ui_RippleDepth, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_RippleDepth) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_RippleDepth, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RippleDepth, 500);
    lv_obj_set_height(ui_RippleDepth, 10);
    lv_obj_set_align(ui_RippleDepth, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_RippleDepth, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_RippleDepth, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RippleDepth, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RippleDepth, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RippleDepth, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RippleDepth, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RippleDepth, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_RippleDepth, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_RippleDepth,
                                                                                                  lv_obj_get_style_pad_right(ui_RippleDepth, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container7 = lv_obj_create(ui_RippleContainer);
    lv_obj_remove_style_all(ui_Container7);
    lv_obj_set_width(ui_Container7, 700);
    lv_obj_set_height(ui_Container7, 50);
    lv_obj_set_align(ui_Container7, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container7, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container7, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container7, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label7 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "Ripple phase");

    ui_RipplePhase = lv_slider_create(ui_Container7);
    lv_slider_set_value(ui_RipplePhase, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_RipplePhase) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_RipplePhase, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_RipplePhase, 500);
    lv_obj_set_height(ui_RipplePhase, 10);
    lv_obj_set_align(ui_RipplePhase, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_RipplePhase, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_RipplePhase, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RipplePhase, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RipplePhase, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RipplePhase, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RipplePhase, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RipplePhase, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_RipplePhase, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_RipplePhase,
                                                                                                  lv_obj_get_style_pad_right(ui_RipplePhase, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container10 = lv_obj_create(ui_RippleContainer);
    lv_obj_remove_style_all(ui_Container10);
    lv_obj_set_width(ui_Container10, 700);
    lv_obj_set_height(ui_Container10, 50);
    lv_obj_set_align(ui_Container10, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container10, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container10, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container10, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label8 = lv_label_create(ui_Container10);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "Ripple amount");

    ui_RippleAmount = lv_slider_create(ui_Container10);
    lv_slider_set_value(ui_RippleAmount, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_RippleAmount) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_RippleAmount, 0,
                                                                                                 LV_ANIM_OFF);
    lv_obj_set_width(ui_RippleAmount, 500);
    lv_obj_set_height(ui_RippleAmount, 10);
    lv_obj_set_align(ui_RippleAmount, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_RippleAmount, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_RippleAmount, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RippleAmount, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RippleAmount, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RippleAmount, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_RippleAmount, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RippleAmount, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_RippleAmount, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_RippleAmount,
                                                                                                   lv_obj_get_style_pad_right(ui_RippleAmount, LV_PART_MAIN) + 1, LV_PART_MAIN);
    lv_obj_add_event_cb(ui_Button7, ui_event_Button7, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button4, ui_event_Button4, LV_EVENT_ALL, NULL);

    midi_setup_ModifyScreen();

}

void ui_ModifyScreen_screen_destroy(void)
{
    if(ui_ModifyScreen) lv_obj_del(ui_ModifyScreen);

    // NULL screen variables
    ui_ModifyScreen = NULL;
    ui_Container36 = NULL;
    ui_Button7 = NULL;
    ui_Label29 = NULL;
    ui_Button4 = NULL;
    ui_Container44 = NULL;
    ui_ScaleSwitch = NULL;
    ui_ScaleContainer = NULL;
    ui_Container40 = NULL;
    ui_Label35 = NULL;
    ui_ScaleX = NULL;
    ui_Container41 = NULL;
    ui_Label32 = NULL;
    ui_ScaleY = NULL;
    ui_Container42 = NULL;
    ui_Label33 = NULL;
    ui_ScaleZ = NULL;
    ui_Container43 = NULL;
    ui_DistortSwitch = NULL;
    ui_DistortContainer = NULL;
    ui_Container5 = NULL;
    ui_Label34 = NULL;
    ui_DistortX = NULL;
    ui_Container8 = NULL;
    ui_Label5 = NULL;
    ui_DistortY = NULL;
    ui_Container9 = NULL;
    ui_Label6 = NULL;
    ui_DistortZ = NULL;
    ui_Container16 = NULL;
    ui_RotateSwitch = NULL;
    ui_RotateContainer = NULL;
    ui_Container11 = NULL;
    ui_Label13 = NULL;
    ui_RotateX = NULL;
    ui_Container13 = NULL;
    ui_Label9 = NULL;
    ui_RotateY = NULL;
    ui_Container14 = NULL;
    ui_Label11 = NULL;
    ui_RotateZ = NULL;
    ui_Container20 = NULL;
    ui_TranslateSwitch = NULL;
    ui_TranslateContainer = NULL;
    ui_Container15 = NULL;
    ui_Label16 = NULL;
    ui_TranslateX = NULL;
    ui_Container17 = NULL;
    ui_Label12 = NULL;
    ui_TranslateY = NULL;
    ui_Container18 = NULL;
    ui_Label14 = NULL;
    ui_TranslateZ = NULL;
    ui_Container12 = NULL;
    ui_RippleSwitch = NULL;
    ui_RippleContainer = NULL;
    ui_Container6 = NULL;
    ui_Label10 = NULL;
    ui_RippleDepth = NULL;
    ui_Container7 = NULL;
    ui_Label7 = NULL;
    ui_RipplePhase = NULL;
    ui_Container10 = NULL;
    ui_Label8 = NULL;
    ui_RippleAmount = NULL;

}
