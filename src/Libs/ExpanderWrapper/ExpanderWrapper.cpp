#include <Arduino.h>
#include "ExpanderWrapper.h"

void ExpenderInit(ESP_IOExpander *expander)
{
    expander = new ESP_IOExpander_CH422G(
        (i2c_port_t)I2C_NUM_0, ESP_IO_EXPANDER_I2C_CH422G_ADDRESS_000,
        SCL, SDA);

    expander->init();
    expander->begin();

    expander->multiPinMode(TP_RST | LCD_BL | LCD_RST | SD_CS | USB_SEL, OUTPUT);
    expander->multiDigitalWrite(TP_RST | LCD_BL | LCD_RST | USB_SEL, HIGH);

    expander->digitalWrite(SD_CS, LOW);
}