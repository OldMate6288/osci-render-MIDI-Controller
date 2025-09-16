#Add sources from ui directory
file(GLOB_RECURSE SRC_UI ${CMAKE_SOURCE_DIR} "ui/*.c" "ui/screens/*c" "ui/screens/*h")

idf_component_register(SRCS "main.c" "midi_control.c" ${SRC_UI}
                    INCLUDE_DIRS "." "ui")
