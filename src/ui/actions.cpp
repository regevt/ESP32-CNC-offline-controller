#include <Arduino.h>
#include <lvgl.h>
#include "actions.h"

#include "../Libs/FileManager/FileManager.h"

void action_x_right_clicked(lv_event_t *e)
{
    if (e->code == lv_event_code_t::LV_EVENT_CLICKED)
    {
        // listDir(SD, "/", 0);

        // readFile(SD, "/Nnyy50x50.nc");

        ESP.restart();
    }
}
