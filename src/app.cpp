#include <Arduino.h>
#include <WiFi.h>
#include <ESP_Panel_Library.h>
#include <ESP_IOExpander_Library.h>
#include <lvgl.h>
#include "Libs/SerialCom/SerialCom.h"
#include "Libs/FileManager/FileManager.h"
#include "Libs/ExpanderWrapper/ExpanderWrapper.h"
#include "Screens/MainScreen/MainScreen.h"

ESP_IOExpander *expander = NULL;

void setup()
{
    Serial.begin(115200);

    ExpenderInit(expander);

    ESP_Panel *panel = new ESP_Panel();
    panel->init();
    panel->begin();

    lvgl_port_init(panel->getLcd(), panel->getTouch());

    MainScreen();

    InitSD(expander);
}

void loop()
{
}
