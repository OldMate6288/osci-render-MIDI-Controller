#ifndef _OSCI_RENDER_MIDI_UI_H
#define _OSCI_RENDER_MIDI_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nvs_flash.h" // for saving/loading UI updates from flash
#include "nvs.h"
#include "bsp/esp32_p4_function_ev_board.h" // for display brightness
#include "midi_control.h"
#include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"


///////////////////// SCREENS ////////////////////

#include "screens/ui_BootScreen.h"
#include "screens/ui_MainScreen.h"
#include "screens/ui_ModifyScreen.h"
#include "screens/ui_EffectsScreen.h"
#include "screens/ui_SettingsScreen.h"
#include "screens/ui_DrumpadScreen.h"
#include "screens/ui_GlobalObjs.h"

///////////////////// VARIABLES ////////////////////

// NVS message struct
typedef struct {
    uint8_t brightness;
    uint8_t hide_player;
    uint8_t flip_objs;
} nvs_msg_t;

extern lv_anim_t * bootlogo_Animation(lv_obj_t * TargetObject, int delay);
extern lv_anim_t * fadein_Animation(lv_obj_t * TargetObject, int delay);

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE(ui_img_1031218279);    // assets/osci-wide.png
LV_IMG_DECLARE(ui_img_arrow_png);    // assets/arrow.png
LV_IMG_DECLARE(ui_img_1101766569);    // assets/right-arrow.png
LV_IMG_DECLARE(ui_img_left_png);    // assets/left.png
LV_IMG_DECLARE(ui_img_right_png);    // assets/right.png

// UI INIT
void ui_init(void);
void ui_destroy(void);
void save_settings_ui(uint8_t brightness);
void save_settings_objs(uint8_t hide_player, uint8_t flip_objs);
void NVS_init(void);
void NVS_UI_update(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
