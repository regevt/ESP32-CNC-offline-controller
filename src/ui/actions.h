#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif


enum {
    ACTION_X_RIGHT_CLICKED_PROPERTY_TEST,
};
extern void action_x_right_clicked(lv_event_t * e);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/