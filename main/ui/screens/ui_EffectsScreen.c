#include "../ui.h"

lv_obj_t * ui_EffectsScreen = NULL;
lv_obj_t * ui_Container35 = NULL;
lv_obj_t * ui_Button6 = NULL;
lv_obj_t * ui_Label28 = NULL;
lv_obj_t * ui_Button3 = NULL;
lv_obj_t * ui_Container21 = NULL;
lv_obj_t * ui_BitCrushSwitch = NULL;
lv_obj_t * ui_Container47 = NULL;
lv_obj_t * ui_Container48 = NULL;
lv_obj_t * ui_Label17 = NULL;
lv_obj_t * ui_BitCrush = NULL;
lv_obj_t * ui_Container19 = NULL;
lv_obj_t * ui_BulgeSwitch = NULL;
lv_obj_t * ui_Container49 = NULL;
lv_obj_t * ui_Label15 = NULL;
lv_obj_t * ui_Bulge = NULL;
lv_obj_t * ui_Container3 = NULL;
lv_obj_t * ui_VectorSwitch = NULL;
lv_obj_t * ui_Container50 = NULL;
lv_obj_t * ui_Label3 = NULL;
lv_obj_t * ui_VectorCancelling = NULL;
lv_obj_t * ui_Container4 = NULL;
lv_obj_t * ui_SwirlSwitch = NULL;
lv_obj_t * ui_Container51 = NULL;
lv_obj_t * ui_Label4 = NULL;
lv_obj_t * ui_Swirl = NULL;
lv_obj_t * ui_Container22 = NULL;
lv_obj_t * ui_SmoothingSwitch = NULL;
lv_obj_t * ui_Container52 = NULL;
lv_obj_t * ui_Label18 = NULL;
lv_obj_t * ui_Smoothing = NULL;
lv_obj_t * ui_Container25 = NULL;
lv_obj_t * ui_WobbleSwitch = NULL;
lv_obj_t * ui_Container37 = NULL;
lv_obj_t * ui_Container2 = NULL;
lv_obj_t * ui_Label20 = NULL;
lv_obj_t * ui_WobbleAmount = NULL;
lv_obj_t * ui_Container23 = NULL;
lv_obj_t * ui_Label2 = NULL;
lv_obj_t * ui_WobblePhase = NULL;
lv_obj_t * ui_Container28 = NULL;
lv_obj_t * ui_DelaySwitch = NULL;
lv_obj_t * ui_Container45 = NULL;
lv_obj_t * ui_Container24 = NULL;
lv_obj_t * ui_Label22 = NULL;
lv_obj_t * ui_DelayDecay = NULL;
lv_obj_t * ui_Container26 = NULL;
lv_obj_t * ui_Label19 = NULL;
lv_obj_t * ui_DelayLength = NULL;
lv_obj_t * ui_Container29 = NULL;
lv_obj_t * ui_DashSwitch = NULL;
lv_obj_t * ui_Container53 = NULL;
lv_obj_t * ui_Label23 = NULL;
lv_obj_t * ui_DashLength = NULL;
lv_obj_t * ui_Container30 = NULL;
lv_obj_t * ui_LuaSwitch = NULL;
lv_obj_t * ui_Container54 = NULL;
lv_obj_t * ui_Label24 = NULL;
lv_obj_t * ui_LuaEffect = NULL;
lv_obj_t * ui_Container33 = NULL;
lv_obj_t * ui_TraceSwitch = NULL;
lv_obj_t * ui_Container46 = NULL;
lv_obj_t * ui_Container27 = NULL;
lv_obj_t * ui_Label26 = NULL;
lv_obj_t * ui_TraceStart = NULL;
lv_obj_t * ui_Container31 = NULL;
lv_obj_t * ui_Label21 = NULL;
lv_obj_t * ui_TraceLength = NULL;
// event funtions
void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_MainScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_MainScreen_screen_init);
    }
}

void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_PRESSED) {
        _ui_screen_change(&ui_ModifyScreen, LV_SCR_LOAD_ANIM_FADE_ON, 0, 0, &ui_ModifyScreen_screen_init);
    }
}

// build funtions

void ui_EffectsScreen_screen_init(void)
{

    ui_EffectsScreen = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(ui_EffectsScreen, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_dir(ui_EffectsScreen, LV_DIR_VER);
    lv_obj_set_flex_flow(ui_EffectsScreen, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_EffectsScreen, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);

    ui_Container35 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container35);
    lv_obj_set_width(ui_Container35, 1024);
    lv_obj_set_height(ui_Container35, 70);
    lv_obj_set_align(ui_Container35, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container35, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container35, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_END);
    lv_obj_remove_flag(ui_Container35, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button6 = lv_button_create(ui_Container35);
    lv_obj_set_width(ui_Button6, 80);
    lv_obj_set_height(ui_Button6, 50);
    lv_obj_set_align(ui_Button6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button6, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Button6, &ui_img_arrow_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui_Button6, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui_Button6, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button6, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button6, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button6, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label28 = lv_label_create(ui_Container35);
    lv_obj_set_width(ui_Label28, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label28, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label28, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label28, "Effects");
    lv_obj_set_style_text_color(ui_Label28, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label28, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label28, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button3 = lv_button_create(ui_Container35);
    lv_obj_set_width(ui_Button3, 80);
    lv_obj_set_height(ui_Button3, 50);
    lv_obj_set_align(ui_Button3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui_Button3, &ui_img_1101766569, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor(ui_Button3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui_Button3, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Button3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Button3, 155, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Button3, 3, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container21 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container21);
    lv_obj_set_width(ui_Container21, 800);
    lv_obj_set_height(ui_Container21, 50);
    lv_obj_set_align(ui_Container21, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container21, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container21, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container21, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container21, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container21, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container21, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container21, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BitCrushSwitch = lv_switch_create(ui_Container21);
    lv_obj_set_width(ui_BitCrushSwitch, 50);
    lv_obj_set_height(ui_BitCrushSwitch, 25);
    lv_obj_set_align(ui_BitCrushSwitch, LV_ALIGN_CENTER);

    ui_Container47 = lv_obj_create(ui_Container21);
    lv_obj_remove_style_all(ui_Container47);
    lv_obj_set_width(ui_Container47, 700);
    lv_obj_set_height(ui_Container47, 50);
    lv_obj_set_align(ui_Container47, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container47, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container47, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container47, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container48 = lv_obj_create(ui_Container47);
    lv_obj_remove_style_all(ui_Container48);
    lv_obj_set_width(ui_Container48, 700);
    lv_obj_set_height(ui_Container48, 50);
    lv_obj_set_align(ui_Container48, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container48, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container48, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container48, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label17 = lv_label_create(ui_Container48);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "Bit crush");

    ui_BitCrush = lv_slider_create(ui_Container48);
    lv_slider_set_value(ui_BitCrush, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_BitCrush) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_BitCrush, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_BitCrush, 500);
    lv_obj_set_height(ui_BitCrush, 10);
    lv_obj_set_align(ui_BitCrush, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_BitCrush, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_BitCrush, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BitCrush, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_BitCrush, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BitCrush, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_BitCrush, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BitCrush, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_BitCrush, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_BitCrush,
                                                                                               lv_obj_get_style_pad_right(ui_BitCrush, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container19 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container19);
    lv_obj_set_width(ui_Container19, 800);
    lv_obj_set_height(ui_Container19, 50);
    lv_obj_set_align(ui_Container19, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container19, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container19, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container19, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container19, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container19, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container19, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container19, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BulgeSwitch = lv_switch_create(ui_Container19);
    lv_obj_set_width(ui_BulgeSwitch, 50);
    lv_obj_set_height(ui_BulgeSwitch, 25);
    lv_obj_set_align(ui_BulgeSwitch, LV_ALIGN_CENTER);

    ui_Container49 = lv_obj_create(ui_Container19);
    lv_obj_remove_style_all(ui_Container49);
    lv_obj_set_width(ui_Container49, 700);
    lv_obj_set_height(ui_Container49, 50);
    lv_obj_set_align(ui_Container49, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container49, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container49, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container49, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label15 = lv_label_create(ui_Container49);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "Bulge");

    ui_Bulge = lv_slider_create(ui_Container49);
    lv_slider_set_value(ui_Bulge, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Bulge) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Bulge, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Bulge, 500);
    lv_obj_set_height(ui_Bulge, 10);
    lv_obj_set_align(ui_Bulge, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_Bulge, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_Bulge, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bulge, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Bulge, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bulge, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Bulge, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Bulge, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_Bulge, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_Bulge,
                                                                                            lv_obj_get_style_pad_right(ui_Bulge, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container3 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container3);
    lv_obj_set_width(ui_Container3, 800);
    lv_obj_set_height(ui_Container3, 50);
    lv_obj_set_align(ui_Container3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container3, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container3, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container3, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_VectorSwitch = lv_switch_create(ui_Container3);
    lv_obj_set_width(ui_VectorSwitch, 50);
    lv_obj_set_height(ui_VectorSwitch, 25);
    lv_obj_set_align(ui_VectorSwitch, LV_ALIGN_CENTER);

    ui_Container50 = lv_obj_create(ui_Container3);
    lv_obj_remove_style_all(ui_Container50);
    lv_obj_set_width(ui_Container50, 700);
    lv_obj_set_height(ui_Container50, 50);
    lv_obj_set_align(ui_Container50, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container50, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container50, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container50, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_Container50);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Vector cancelling");

    ui_VectorCancelling = lv_slider_create(ui_Container50);
    lv_slider_set_value(ui_VectorCancelling, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_VectorCancelling) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_VectorCancelling, 0,
                                                                                                     LV_ANIM_OFF);
    lv_obj_set_width(ui_VectorCancelling, 500);
    lv_obj_set_height(ui_VectorCancelling, 10);
    lv_obj_set_align(ui_VectorCancelling, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_VectorCancelling, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_VectorCancelling, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VectorCancelling, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_VectorCancelling, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VectorCancelling, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_VectorCancelling, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_VectorCancelling, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_VectorCancelling, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_VectorCancelling,
                                                                                                       lv_obj_get_style_pad_right(ui_VectorCancelling, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container4 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container4);
    lv_obj_set_width(ui_Container4, 800);
    lv_obj_set_height(ui_Container4, 50);
    lv_obj_set_align(ui_Container4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container4, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container4, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container4, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container4, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container4, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwirlSwitch = lv_switch_create(ui_Container4);
    lv_obj_set_width(ui_SwirlSwitch, 50);
    lv_obj_set_height(ui_SwirlSwitch, 25);
    lv_obj_set_align(ui_SwirlSwitch, LV_ALIGN_CENTER);

    ui_Container51 = lv_obj_create(ui_Container4);
    lv_obj_remove_style_all(ui_Container51);
    lv_obj_set_width(ui_Container51, 700);
    lv_obj_set_height(ui_Container51, 50);
    lv_obj_set_align(ui_Container51, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container51, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container51, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container51, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label4 = lv_label_create(ui_Container51);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Swirl");

    ui_Swirl = lv_slider_create(ui_Container51);
    lv_slider_set_value(ui_Swirl, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Swirl) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Swirl, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Swirl, 500);
    lv_obj_set_height(ui_Swirl, 10);
    lv_obj_set_align(ui_Swirl, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_Swirl, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_Swirl, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Swirl, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Swirl, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Swirl, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Swirl, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Swirl, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_Swirl, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_Swirl,
                                                                                            lv_obj_get_style_pad_right(ui_Swirl, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container22 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container22);
    lv_obj_set_width(ui_Container22, 800);
    lv_obj_set_height(ui_Container22, 50);
    lv_obj_set_align(ui_Container22, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container22, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container22, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container22, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container22, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container22, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container22, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container22, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SmoothingSwitch = lv_switch_create(ui_Container22);
    lv_obj_set_width(ui_SmoothingSwitch, 50);
    lv_obj_set_height(ui_SmoothingSwitch, 25);
    lv_obj_set_align(ui_SmoothingSwitch, LV_ALIGN_CENTER);

    ui_Container52 = lv_obj_create(ui_Container22);
    lv_obj_remove_style_all(ui_Container52);
    lv_obj_set_width(ui_Container52, 700);
    lv_obj_set_height(ui_Container52, 50);
    lv_obj_set_align(ui_Container52, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container52, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container52, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container52, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label18 = lv_label_create(ui_Container52);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label18, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label18, "Smoothing");

    ui_Smoothing = lv_slider_create(ui_Container52);
    lv_slider_set_value(ui_Smoothing, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_Smoothing) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_Smoothing, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_Smoothing, 500);
    lv_obj_set_height(ui_Smoothing, 10);
    lv_obj_set_align(ui_Smoothing, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_Smoothing, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_Smoothing, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Smoothing, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Smoothing, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Smoothing, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Smoothing, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Smoothing, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_Smoothing, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_Smoothing,
                                                                                                lv_obj_get_style_pad_right(ui_Smoothing, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container25 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container25);
    lv_obj_set_width(ui_Container25, 800);
    lv_obj_set_height(ui_Container25, 150);
    lv_obj_set_align(ui_Container25, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container25, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container25, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container25, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container25, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container25, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container25, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container25, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_WobbleSwitch = lv_switch_create(ui_Container25);
    lv_obj_set_width(ui_WobbleSwitch, 50);
    lv_obj_set_height(ui_WobbleSwitch, 25);
    lv_obj_set_align(ui_WobbleSwitch, LV_ALIGN_CENTER);

    ui_Container37 = lv_obj_create(ui_Container25);
    lv_obj_remove_style_all(ui_Container37);
    lv_obj_set_width(ui_Container37, 700);
    lv_obj_set_height(ui_Container37, 100);
    lv_obj_set_align(ui_Container37, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container37, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container37, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container37, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container2 = lv_obj_create(ui_Container37);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_width(ui_Container2, 700);
    lv_obj_set_height(ui_Container2, 50);
    lv_obj_set_align(ui_Container2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container2, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label20 = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "Wobble amount");

    ui_WobbleAmount = lv_slider_create(ui_Container2);
    lv_slider_set_value(ui_WobbleAmount, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_WobbleAmount) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_WobbleAmount, 0,
                                                                                                 LV_ANIM_OFF);
    lv_obj_set_width(ui_WobbleAmount, 500);
    lv_obj_set_height(ui_WobbleAmount, 10);
    lv_obj_set_align(ui_WobbleAmount, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_WobbleAmount, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_WobbleAmount, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WobbleAmount, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_WobbleAmount, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WobbleAmount, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_WobbleAmount, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WobbleAmount, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_WobbleAmount, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_WobbleAmount,
                                                                                                   lv_obj_get_style_pad_right(ui_WobbleAmount, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container23 = lv_obj_create(ui_Container37);
    lv_obj_remove_style_all(ui_Container23);
    lv_obj_set_width(ui_Container23, 700);
    lv_obj_set_height(ui_Container23, 50);
    lv_obj_set_align(ui_Container23, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container23, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container23, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container23, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label2 = lv_label_create(ui_Container23);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Wobble phase");

    ui_WobblePhase = lv_slider_create(ui_Container23);
    lv_slider_set_value(ui_WobblePhase, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_WobblePhase) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_WobblePhase, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_WobblePhase, 500);
    lv_obj_set_height(ui_WobblePhase, 10);
    lv_obj_set_align(ui_WobblePhase, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_WobblePhase, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_WobblePhase, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WobblePhase, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_WobblePhase, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WobblePhase, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_WobblePhase, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_WobblePhase, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_WobblePhase, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_WobblePhase,
                                                                                                  lv_obj_get_style_pad_right(ui_WobblePhase, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container28 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container28);
    lv_obj_set_width(ui_Container28, 800);
    lv_obj_set_height(ui_Container28, 150);
    lv_obj_set_align(ui_Container28, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container28, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container28, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container28, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container28, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container28, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container28, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container28, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DelaySwitch = lv_switch_create(ui_Container28);
    lv_obj_set_width(ui_DelaySwitch, 50);
    lv_obj_set_height(ui_DelaySwitch, 25);
    lv_obj_set_align(ui_DelaySwitch, LV_ALIGN_CENTER);

    ui_Container45 = lv_obj_create(ui_Container28);
    lv_obj_remove_style_all(ui_Container45);
    lv_obj_set_width(ui_Container45, 700);
    lv_obj_set_height(ui_Container45, 100);
    lv_obj_set_align(ui_Container45, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container45, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container45, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container45, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container24 = lv_obj_create(ui_Container45);
    lv_obj_remove_style_all(ui_Container24);
    lv_obj_set_width(ui_Container24, 700);
    lv_obj_set_height(ui_Container24, 50);
    lv_obj_set_align(ui_Container24, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container24, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container24, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container24, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label22 = lv_label_create(ui_Container24);
    lv_obj_set_width(ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label22, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label22, "Delay decay");

    ui_DelayDecay = lv_slider_create(ui_Container24);
    lv_slider_set_value(ui_DelayDecay, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_DelayDecay) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_DelayDecay, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_DelayDecay, 500);
    lv_obj_set_height(ui_DelayDecay, 10);
    lv_obj_set_align(ui_DelayDecay, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_DelayDecay, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_DelayDecay, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DelayDecay, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DelayDecay, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DelayDecay, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DelayDecay, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DelayDecay, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_DelayDecay, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_DelayDecay,
                                                                                                 lv_obj_get_style_pad_right(ui_DelayDecay, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container26 = lv_obj_create(ui_Container45);
    lv_obj_remove_style_all(ui_Container26);
    lv_obj_set_width(ui_Container26, 700);
    lv_obj_set_height(ui_Container26, 50);
    lv_obj_set_align(ui_Container26, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container26, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container26, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container26, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label19 = lv_label_create(ui_Container26);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, "Delay length");

    ui_DelayLength = lv_slider_create(ui_Container26);
    lv_slider_set_value(ui_DelayLength, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_DelayLength) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_DelayLength, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_DelayLength, 500);
    lv_obj_set_height(ui_DelayLength, 10);
    lv_obj_set_align(ui_DelayLength, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_DelayLength, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_DelayLength, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DelayLength, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DelayLength, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DelayLength, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DelayLength, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DelayLength, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_DelayLength, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_DelayLength,
                                                                                                  lv_obj_get_style_pad_right(ui_DelayLength, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container29 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container29);
    lv_obj_set_width(ui_Container29, 800);
    lv_obj_set_height(ui_Container29, 50);
    lv_obj_set_align(ui_Container29, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container29, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container29, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container29, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container29, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container29, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container29, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container29, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DashSwitch = lv_switch_create(ui_Container29);
    lv_obj_set_width(ui_DashSwitch, 50);
    lv_obj_set_height(ui_DashSwitch, 25);
    lv_obj_set_align(ui_DashSwitch, LV_ALIGN_CENTER);

    ui_Container53 = lv_obj_create(ui_Container29);
    lv_obj_remove_style_all(ui_Container53);
    lv_obj_set_width(ui_Container53, 700);
    lv_obj_set_height(ui_Container53, 50);
    lv_obj_set_align(ui_Container53, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container53, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container53, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container53, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label23 = lv_label_create(ui_Container53);
    lv_obj_set_width(ui_Label23, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label23, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label23, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label23, "Dash length");

    ui_DashLength = lv_slider_create(ui_Container53);
    lv_slider_set_value(ui_DashLength, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_DashLength) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_DashLength, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_DashLength, 500);
    lv_obj_set_height(ui_DashLength, 10);
    lv_obj_set_align(ui_DashLength, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_DashLength, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_DashLength, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DashLength, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DashLength, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DashLength, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_DashLength, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DashLength, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_DashLength, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_DashLength,
                                                                                                 lv_obj_get_style_pad_right(ui_DashLength, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container30 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container30);
    lv_obj_set_width(ui_Container30, 800);
    lv_obj_set_height(ui_Container30, 50);
    lv_obj_set_align(ui_Container30, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container30, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container30, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container30, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container30, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container30, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container30, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container30, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LuaSwitch = lv_switch_create(ui_Container30);
    lv_obj_set_width(ui_LuaSwitch, 50);
    lv_obj_set_height(ui_LuaSwitch, 25);
    lv_obj_set_align(ui_LuaSwitch, LV_ALIGN_CENTER);

    ui_Container54 = lv_obj_create(ui_Container30);
    lv_obj_remove_style_all(ui_Container54);
    lv_obj_set_width(ui_Container54, 700);
    lv_obj_set_height(ui_Container54, 50);
    lv_obj_set_align(ui_Container54, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container54, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container54, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container54, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label24 = lv_label_create(ui_Container54);
    lv_obj_set_width(ui_Label24, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label24, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label24, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label24, "Lua effect");

    ui_LuaEffect = lv_slider_create(ui_Container54);
    lv_slider_set_value(ui_LuaEffect, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_LuaEffect) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_LuaEffect, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_LuaEffect, 500);
    lv_obj_set_height(ui_LuaEffect, 10);
    lv_obj_set_align(ui_LuaEffect, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_LuaEffect, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_LuaEffect, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LuaEffect, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_LuaEffect, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LuaEffect, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_LuaEffect, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LuaEffect, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_LuaEffect, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_LuaEffect,
                                                                                                lv_obj_get_style_pad_right(ui_LuaEffect, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container33 = lv_obj_create(ui_EffectsScreen);
    lv_obj_remove_style_all(ui_Container33);
    lv_obj_set_width(ui_Container33, 800);
    lv_obj_set_height(ui_Container33, 150);
    lv_obj_set_align(ui_Container33, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container33, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container33, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container33, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_Container33, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Container33, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Container33, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Container33, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TraceSwitch = lv_switch_create(ui_Container33);
    lv_obj_set_width(ui_TraceSwitch, 50);
    lv_obj_set_height(ui_TraceSwitch, 25);
    lv_obj_set_align(ui_TraceSwitch, LV_ALIGN_CENTER);

    ui_Container46 = lv_obj_create(ui_Container33);
    lv_obj_remove_style_all(ui_Container46);
    lv_obj_set_width(ui_Container46, 700);
    lv_obj_set_height(ui_Container46, 100);
    lv_obj_set_align(ui_Container46, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container46, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container46, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container46, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container27 = lv_obj_create(ui_Container46);
    lv_obj_remove_style_all(ui_Container27);
    lv_obj_set_width(ui_Container27, 700);
    lv_obj_set_height(ui_Container27, 50);
    lv_obj_set_align(ui_Container27, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container27, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container27, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container27, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label26 = lv_label_create(ui_Container27);
    lv_obj_set_width(ui_Label26, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label26, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label26, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label26, "Trace start");

    ui_TraceStart = lv_slider_create(ui_Container27);
    lv_slider_set_value(ui_TraceStart, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_TraceStart) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_TraceStart, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_TraceStart, 500);
    lv_obj_set_height(ui_TraceStart, 10);
    lv_obj_set_align(ui_TraceStart, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_TraceStart, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_TraceStart, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraceStart, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TraceStart, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraceStart, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TraceStart, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraceStart, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_TraceStart, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_TraceStart,
                                                                                                 lv_obj_get_style_pad_right(ui_TraceStart, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_Container31 = lv_obj_create(ui_Container46);
    lv_obj_remove_style_all(ui_Container31);
    lv_obj_set_width(ui_Container31, 700);
    lv_obj_set_height(ui_Container31, 50);
    lv_obj_set_align(ui_Container31, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container31, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container31, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Container31, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label21 = lv_label_create(ui_Container31);
    lv_obj_set_width(ui_Label21, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label21, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label21, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label21, "Trace length");

    ui_TraceLength = lv_slider_create(ui_Container31);
    lv_slider_set_value(ui_TraceLength, 0, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_TraceLength) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(ui_TraceLength, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_TraceLength, 500);
    lv_obj_set_height(ui_TraceLength, 10);
    lv_obj_set_align(ui_TraceLength, LV_ALIGN_CENTER);
    lv_obj_remove_state(ui_TraceLength, LV_STATE_DISABLED);       /// States
    lv_obj_set_style_bg_color(ui_TraceLength, lv_color_hex(0x2ABE44), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraceLength, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TraceLength, lv_color_hex(0x2ABE44), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraceLength, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_TraceLength, lv_color_hex(0x177023), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TraceLength, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_TraceLength, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_TraceLength,
                                                                                                  lv_obj_get_style_pad_right(ui_TraceLength, LV_PART_MAIN) + 1, LV_PART_MAIN);
    lv_obj_add_event_cb(ui_Button6, ui_event_Button6, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button3, ui_event_Button3, LV_EVENT_ALL, NULL);
    
    // init MIDI CC inputs
    midi_setup_EffectsScreen();

}

void ui_EffectsScreen_screen_destroy(void)
{
    if(ui_EffectsScreen) lv_obj_del(ui_EffectsScreen);

    // NULL screen variables
    ui_EffectsScreen = NULL;
    ui_Container35 = NULL;
    ui_Button6 = NULL;
    ui_Label28 = NULL;
    ui_Button3 = NULL;
    ui_Container21 = NULL;
    ui_BitCrushSwitch = NULL;
    ui_Container47 = NULL;
    ui_Container48 = NULL;
    ui_Label17 = NULL;
    ui_BitCrush = NULL;
    ui_Container19 = NULL;
    ui_BulgeSwitch = NULL;
    ui_Container49 = NULL;
    ui_Label15 = NULL;
    ui_Bulge = NULL;
    ui_Container3 = NULL;
    ui_VectorSwitch = NULL;
    ui_Container50 = NULL;
    ui_Label3 = NULL;
    ui_VectorCancelling = NULL;
    ui_Container4 = NULL;
    ui_SwirlSwitch = NULL;
    ui_Container51 = NULL;
    ui_Label4 = NULL;
    ui_Swirl = NULL;
    ui_Container22 = NULL;
    ui_SmoothingSwitch = NULL;
    ui_Container52 = NULL;
    ui_Label18 = NULL;
    ui_Smoothing = NULL;
    ui_Container25 = NULL;
    ui_WobbleSwitch = NULL;
    ui_Container37 = NULL;
    ui_Container2 = NULL;
    ui_Label20 = NULL;
    ui_WobbleAmount = NULL;
    ui_Container23 = NULL;
    ui_Label2 = NULL;
    ui_WobblePhase = NULL;
    ui_Container28 = NULL;
    ui_DelaySwitch = NULL;
    ui_Container45 = NULL;
    ui_Container24 = NULL;
    ui_Label22 = NULL;
    ui_DelayDecay = NULL;
    ui_Container26 = NULL;
    ui_Label19 = NULL;
    ui_DelayLength = NULL;
    ui_Container29 = NULL;
    ui_DashSwitch = NULL;
    ui_Container53 = NULL;
    ui_Label23 = NULL;
    ui_DashLength = NULL;
    ui_Container30 = NULL;
    ui_LuaSwitch = NULL;
    ui_Container54 = NULL;
    ui_Label24 = NULL;
    ui_LuaEffect = NULL;
    ui_Container33 = NULL;
    ui_TraceSwitch = NULL;
    ui_Container46 = NULL;
    ui_Container27 = NULL;
    ui_Label26 = NULL;
    ui_TraceStart = NULL;
    ui_Container31 = NULL;
    ui_Label21 = NULL;
    ui_TraceLength = NULL;

}
