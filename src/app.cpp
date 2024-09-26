#include <Arduino.h>
#include <WiFi.h>
#include <lvgl.h>
#include <ESP_Panel_Library.h>
#include <ESP_IOExpander_Library.h>
#include <lvgl_port_v8.h>
#include "Libs/SerialCom/SerialCom.h"
#include "Libs/FileManager/FileManager.h"
#include "Libs/ExpanderWrapper/ExpanderWrapper.h"
#include "ui/ui.h"

ESP_IOExpander *expander = NULL;

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200);

    xTaskCreatePinnedToCore(SendGcodeTask, "SendGcodeTask", 10000, NULL, 2, &GcodeSenderTaskHandler, 1);

    ExpenderInit(expander);

    ESP_Panel *panel = new ESP_Panel();
    panel->init();
    panel->begin();

    lvgl_port_init(panel->getLcd(), panel->getTouch());

    InitSD(expander);
    ui_init();
}

void loop()
{
    ui_tick();
}
