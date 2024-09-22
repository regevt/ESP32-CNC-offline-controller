
#include <SD.h>

#include <Arduino.h>

void checkSD();

void openFileSD();

void emptySerialBuf();

void waitSerial();

String getSerial();

String sendGcode(String command);

void sendGcode();

void fileError();

String readLine(File f);