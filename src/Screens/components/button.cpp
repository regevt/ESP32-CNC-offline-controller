#include <lvgl.h>
#include "lvgl_port_v8.h"

bool isClickEvent(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    return event_code == LV_EVENT_CLICKED;
}

void makeImageButton(lv_obj_t *parent, lv_event_cb_t event_cb, const lv_img_dsc_t *src, int32_t x, int32_t y)
{
    lv_obj_t *btn = lv_btn_create(parent);
    lv_obj_set_width(btn, 50);
    lv_obj_set_height(btn, 50);
    lv_obj_set_pos(btn, x, y);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_add_event_cb(btn, event_cb, LV_EVENT_ALL, NULL);

    lv_obj_t *image = lv_img_create(btn);
    lv_obj_set_style_bg_color(btn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_img_set_src(image, src);
    lv_obj_set_height(image, 50);
    lv_obj_set_width(image, 50);

    // lv_obj_set_height(image, LV_SIZE_CONTENT);
    lv_obj_set_align(image, LV_ALIGN_CENTER);
    // lv_img_set_inner_align(image, LV_IMAGE_ALIGN_CENTER);

    // lv_image_set_scale(image, 170);
    // lv_obj_set_style_bg_image_opa(image, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_image_recolor(image, lv_color_hex(0xFFFF00), LV_PART_MAIN | LV_STATE_DEFAULT);
}

// ui_lblMilliseconds = lv_label_create(ui_pnlMain);
// lv_obj_set_width(ui_lblMilliseconds, LV_SIZE_CONTENT);  /// 1
// lv_obj_set_height(ui_lblMilliseconds, LV_SIZE_CONTENT); /// 1
// lv_label_set_text(ui_lblMilliseconds, "Milliseconds:\n");

// static void slider_event_cb(lv_event_t * e);
// static lv_obj_t * slider_label;

/**
 * A default slider with a label displaying the current value
 */
// void lv_example_slider_1(void)
// {
//     /*Create a slider in the center of the display*/
//     lv_obj_t * slider = lv_slider_create(lv_screen_active());
//     lv_obj_center(slider);
//     lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

//     lv_obj_set_style_anim_duration(slider, 2000, 0);
//     /*Create a label below the slider*/
//     slider_label = lv_label_create(lv_screen_active());
//     lv_label_set_text(slider_label, "0%");

//     lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
// }

// static void slider_event_cb(lv_event_t * e)
// {
//     lv_obj_t * slider = lv_event_get_target(e);
//     char buf[8];
//     lv_snprintf(buf, sizeof(buf), "%d%%", (int)lv_slider_get_value(slider));
//     lv_label_set_text(slider_label, buf);
//     lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
// }