#ifndef SERIAL_COM_H
#define SERIAL_COM_H

#include <Arduino.h>
#include <SD.h>
#include "FreeRTOS.h"
#include "message_buffer.h"

extern MessageBufferHandle_t messageBufferHandle;
extern TaskHandle_t GcodeSenderTaskHandler;

extern void SendGcodeTask(void *args);
extern void checkSD();
extern void openFileSD();
extern void emptySerialBuf();
extern void waitSerial();
extern String getSerial();
extern String sendGcode(String command);
extern void sendGcode();
extern void fileError();
extern String readLine(File f);

#endif