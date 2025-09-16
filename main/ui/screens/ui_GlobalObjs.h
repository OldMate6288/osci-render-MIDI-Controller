#ifndef UI_GLOBALOBJS_H
#define UI_GLOBALOBJS_H

#ifdef __cplusplus
extern "C" {
#endif

extern void ui_event_Record(lv_event_t * e);
extern lv_obj_t * ui_GlobalObjContainer;
extern lv_obj_t * ui_Play;
extern lv_obj_t * ui_Pause;
extern lv_obj_t * ui_Record;
extern lv_obj_t * ui_Add;
extern lv_obj_t * ui_GlobalSettingsContainer;
extern void ui_event_Settings(lv_event_t * e);
extern lv_obj_t * ui_Settings;
extern void ui_event_Drumpad(lv_event_t * e);
extern lv_obj_t * ui_Drumpad;
extern void ui_event_Home(lv_event_t * e);
extern lv_obj_t * ui_Home;

void ui_global_events_init(void);
void init_global_objs(void);

LV_IMG_DECLARE(ui_img_play32px_png);    // assets/play32px.png
LV_IMG_DECLARE(ui_img_pause32px_png);    // assets/pause32px.png
LV_IMG_DECLARE(ui_img_2099277316);    // assets/rec-button.png
LV_IMG_DECLARE(ui_img_add_png);    // assets/add.png
LV_IMG_DECLARE(ui_img_settings_png);    // assets/settings.png
LV_IMG_DECLARE(ui_img_drumpad_png);    // assets/drumpad.png
LV_IMG_DECLARE(ui_img_1134109583);    // assets/home-button.png

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif