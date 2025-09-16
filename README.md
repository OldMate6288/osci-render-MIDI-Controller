# osci-render MIDI Controller

A **MIDI controller** for [osci-render](https://osci-render.com), built with the **ESP32-P4 Devkit** using [LVGL](https://lvgl.io/) + **TinyUSB**.

[<img width="1280" height="720" alt="Untitled" src="https://github.com/user-attachments/assets/fb49a7b0-c60a-4ee2-b3dd-0fd29101aab7" />](https://www.youtube.com/watch?v=a-7x3LHUfTs)

This started as a weekend project (which then turned into a week long project), it is designed to be an example to help people that want to use MIDI alongside LVGL for UI updates/interactability in their own projects.

The reason it is based on osci-render is because I have been messing around with my oscilliscope for fun and wanted to make something more portable to control it with, but honestly it is not really practical and would better suit physical hardware (maybe I'll make a physical version in the future).

---

## Features:
- 49 Mappable CC toggles
- 8 Mappable MIDI notes + octave toggles

---

## Requirements:

| Item | Version / Link |
|------|----------------|
| ESP32-P4 Devkit | [AliExpress link](https://www.aliexpress.com/item/1005007259059322.html) |
| ESP-IDF | v5.5 |
| osci-render | [Official site](https://osci-render.com) |
| DAW with VST3 support | Any |

## HOW TO INSTALL/SETUP:

- Open the project in ESP-IDF, plug your cable into the ESP32 UART port, select your COM port and flash the build to your device
  
  > the SDKCONFIG, components and partitions have already been setup but feel free to edit them and rebuild if you want

- Unplug your cable from the UART port and plug it into the OTG port

  <img width="774" height="569" alt="Screenshot 2025-09-16 180049" src="https://github.com/user-attachments/assets/30af7808-8e2c-4fe8-82f2-7c97774f898f" />
  
  > the device should show up as "osci-render MIDI controller"

- Open your DAW and map the MIDI inputs to the correct inputs in the osci-render plugin

  > if you are using Ableton Live 11 or up, open the midisetup project and the MIDI mappings should automatically apply

- I also recommend turning off output sync in your DAW's MIDI settings otherwise the UI updates might be a bit delayed (only if you want to)

  <img width="377" height="377" alt="Screenshot 2025-09-16 180431" src="https://github.com/user-attachments/assets/d9e8e403-586a-4863-a25e-2e43aa4d41c9" />
  
  > Recommended MIDI settings

---

You can find all the UI design files in the "squareline_project" folder.

I have tried to structure the code neatly and left comments explaining things where I feel important, if you have any problems feel free to make an issue and I'll do my best to fix it for you.

---

**Known Issues**
- UI CC updates can be delayed at high BPMs
- Slider knobs get visually cut-off due to their flex arrangement
- `ui_MIDIEnabled` switch changes style when CC value updates for some weird reason and causes CPU to panic (has been removed)

---
<h3>Shoutout to James H Ball for creating osci-render, it is a really cool piece of software.</h3>

https://www.youtube.com/@JamesHBall
