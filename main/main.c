/*
 * osci-render MIDI controller using ESP32-P4, TinyUSB and LVGL 9.3.0
 * Created by - https://github.com/oldmate6288
 * 
 * (My YouTube channels, will post tutorials for things I make on one of them)
 * https://www.youtube.com/@BigOrse
 * https://www.youtube.com/@EmbeddedNoob
 * 
 * Get osci-render here: https://osci-render.com/ (Created by James H Ball)
 * https://www.youtube.com/@JamesHBall
 *
 * DEPENDENCIES:
 * 
 * LVGL 9.3.0 [idf.py add-dependency "lvgl/lvgl^9.3.0"]:
 * Uses 2 buffers for pixel transactions with a 10ms refresh rate (130 DPI) [NO V-SYNC]
 * RGB565 16bit colour format
 * LV_MEM_SIZE doubled to 128kb with 64kb expansion
 * All pinouts, protocols and LVGL initialization relating to the screen are handled by the Espressif BSP (more info below)
 * NOTE: you can enable VYSNC and increase/decrease buffers within your BSP settings in menuconfig (under components), but this will drastically decrease performance/increase CPU load...
 * 
 * TinyUSB [idf.py add-dependency "espressif/tinyusb^0.18.0~4"]:
 * All the descriptors for the MIDI device setup and initializers are located in midi_control.c, these have been copied over from the TUSB_example
 * 
 * esp32_p4_function_ev_board [idf.py add-dependency "espressif/esp32_p4_function_ev_board^5.0.1"]:
 * This is the Board Support Package for the official Espressif ESP32-P4 devkit (Revision 1.0).
 * As mentioned above, it includes all setup files relating to the devkit's display and so forth.
 * 
 * All image assets in this project (besides the osci-render logo) come from: https://www.flaticon.com/
 * 
 * NOTE: Partition table is 3mb factory app, 5kb NVS (for ui_settings file)
 * 
 */

#include <stdlib.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "tinyusb.h"
#include "esp_timer.h"
#include "bsp/esp32_p4_function_ev_board.h"
#include "lvgl.h"
#include "ui/ui.h"
#define TAG "ESP-EXAMPLE"

// *INDENT-OFF*
void app_lvgl_display(void)
{
    bsp_display_lock(0);

    ui_init();

    bsp_display_unlock();
}

void app_main(void)
{

    // Initialize Tiny USB
    usb_init();

    /* Initialize I2C (for touch) */
    bsp_i2c_init();

    /* Initialize display and LVGL */
    bsp_display_start();

    /* Turn on display backlight */
    bsp_display_backlight_on();

    // these cause the FPS to drastically decrease and I cannot find a good balance, so I'm keeping them disabled in SDKCONFIG for now.
    #if CONFIG_BSP_DISPLAY_LVGL_AVOID_TEAR
    ESP_LOGI(TAG, "Avoid lcd tearing effect");
    #if CONFIG_BSP_DISPLAY_LVGL_FULL_REFRESH
        ESP_LOGI(TAG, "LVGL full-refresh");
    #elif CONFIG_BSP_DISPLAY_LVGL_DIRECT_MODE
        ESP_LOGI(TAG, "LVGL direct-mode");
    #endif
    #endif

    // Initialize NVS+task queue
    NVS_init();

    /* Add and show objects on display */
    app_lvgl_display();

    midi_map_init(); // map MIDI inputs
    // Read received MIDI packets
    ESP_LOGI(TAG, "UI initialization done.");
    ESP_LOGI(TAG, "MIDI listner init");
    midi_task_start();

    // reads and updates UI changes from flash
    NVS_UI_update();
}
