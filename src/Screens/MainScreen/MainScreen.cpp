
#include "MainScreen.h"
#include "../../Libs/FileManager/FileManager.h"
#include "../components/button.h"
#include "../../Assets/icons/icons.h"

lv_obj_t *label;
lv_obj_t *btn1;
lv_obj_t *btn2;

static void event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        LV_LOG_USER("Clicked");
        Serial.println("Clicked");
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    {
        LV_LOG_USER("Toggled");
        Serial.println("Toggled");
        listDir(SD, "/", 0);
    }
}

void yAxisUp(lv_event_t *e)
{
    if (isClickEvent(e))
    {
        log_i("yAxisUp");
    }
}

void MainScreen()
{
    lvgl_port_lock(-1);
    makeImageButton(yAxisUp, &arrow_Xleft_button, 52, 0);

    btn1 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    btn2 = lv_btn_create(lv_scr_act());
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);

    lvgl_port_unlock();
}