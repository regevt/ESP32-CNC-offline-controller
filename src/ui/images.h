#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_0_1_button;
extern const lv_img_dsc_t img_0_01_button;
extern const lv_img_dsc_t img_1_button;
extern const lv_img_dsc_t img_10_button;
extern const lv_img_dsc_t img_arrow_xright_button;
extern const lv_img_dsc_t img_arrow_ydown_button;
extern const lv_img_dsc_t img_arrow_yup_button;
extern const lv_img_dsc_t img_arrow_zdown_button;
extern const lv_img_dsc_t img_arrow_zup_button;
extern const lv_img_dsc_t img_auto_button;
extern const lv_img_dsc_t img_back_button;
extern const lv_img_dsc_t img_cancel_button;
extern const lv_img_dsc_t img_cmd_button;
extern const lv_img_dsc_t img_delete_button;
extern const lv_img_dsc_t img_home_button;
extern const lv_img_dsc_t img_info_button;
extern const lv_img_dsc_t img_mill_button;
extern const lv_img_dsc_t img_more_button;
extern const lv_img_dsc_t img_move_button;
extern const lv_img_dsc_t img_next_button;
extern const lv_img_dsc_t img_pause_button;
extern const lv_img_dsc_t img_previous_button;
extern const lv_img_dsc_t img_reset_button;
extern const lv_img_dsc_t img_resume_button;
extern const lv_img_dsc_t img_sdcard_button;
extern const lv_img_dsc_t img_see_gcode_button;
extern const lv_img_dsc_t img_set_wcs_button;
extern const lv_img_dsc_t img_setup_button;
extern const lv_img_dsc_t img_set_x_button;
extern const lv_img_dsc_t img_set_xyz_button;
extern const lv_img_dsc_t img_set_y_button;
extern const lv_img_dsc_t img_set_z_button;
extern const lv_img_dsc_t img_stop_pc_button;
extern const lv_img_dsc_t img_telnet_button;
extern const lv_img_dsc_t img_tool_button;
extern const lv_img_dsc_t img_unlock_button;
extern const lv_img_dsc_t img_up_button;
extern const lv_img_dsc_t img_usb_button;
extern const lv_img_dsc_t img_arrow_xleft_button;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[39];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/