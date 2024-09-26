#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *x_left_btn;
    lv_obj_t *x_left_btn_1;
    lv_obj_t *x_left_btn_2;
    lv_obj_t *x_left_btn_3;
    lv_obj_t *x_left_btn_4;
    lv_obj_t *x_left_btn_5;
    lv_obj_t *x_left_btn_6;
    lv_obj_t *x_left_btn_7;
    lv_obj_t *x_pos_value;
    lv_obj_t *y_pos_value;
    lv_obj_t *z_pos_value;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/