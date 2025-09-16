#pragma once
#include "lvgl.h"
#include "ui/ui.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "tinyusb.h"
#include "class/midi/midi_device.h"
#include <stdint.h>

// MIDI -> UI object map
typedef struct {
    uint8_t cc;
    lv_obj_t *obj;
    bool is_switch;
} midi_map_t;

typedef struct {
    uint8_t cc;
    uint8_t note;      // MIDI note number (0–127)
    uint8_t channel;
} midi_cfg_t;

// buffer struct
typedef struct {
    uint8_t value;
    bool    dirty;
} cc_state_t;

// UI -> DAW event callbacks
void midi_setup_MainScreen(void);
void midi_setup_ModifyScreen(void);
void midi_setup_EffectsScreen(void);
void midi_setup_GlobalObjs(void);
void midi_setup_DrumpadScreen(void);
void ui_event_drum_pad(lv_event_t * e);
void ui_event_slider_send_midi(lv_event_t * e);
void ui_event_switch_send_midi(lv_event_t * e);
void ui_event_play_send_midi(lv_event_t * e);
void ui_event_pause_send_midi(lv_event_t * e);

// DAW -> UI sync
void midi_task_start(void);
void midi_map_init(void);

void usb_init(void);