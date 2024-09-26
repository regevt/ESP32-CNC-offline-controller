
#include "SerialCom.h"

File myFile;
boolean restart = true;
MessageBufferHandle_t messageBufferHandle = xMessageBufferCreate(1000);
TaskHandle_t GcodeSenderTaskHandler;

void SendGcodeTask(void *args)
{
    char command[200];
    memset(command, 0, sizeof(command));
    for (;;) // A Task shall never return or exit.
    {
        xMessageBufferReceive(messageBufferHandle, &command, sizeof(command), portMAX_DELAY);
        if (command != "")
        {
            Serial.print("running task with command: ");
            Serial.println(command);
            String res = sendGcode(command);
            memset(command, 0, sizeof(command));
            Serial.print(res);
            Serial.println("ending task");
        }
        vTaskDelay(1);
    }
    vTaskDelete(GcodeSenderTaskHandler);
}

void waitSerial()
{
    // Wait for data on Serial
    // Argument serialNum for Serial number
    boolean serialAv = false;

    while (!serialAv)
    {
        if (Serial1.available())
            serialAv = true;
    }
}

String getSerial()
{

    // Return String  from serial line reading
    // Argument serialNum for Serial number

    String inLine = "";
    waitSerial();

    while (Serial1.available())
    {
        inLine += (char)Serial1.read();
        delay(2);
    }
    return inLine;
}

void emptySerialBuf()
{
    while (Serial1.available())
        Serial1.read();
}

void checkSD()
{

    // Check if SD card is OK

    // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
    // Note that even if it's not used as the CS pin, the hardware SS pin
    // (10 on most Arduino boards, 53 on the Mega) must be left as an output
    // or the SD library functions will not work.

    while (!SD.begin(53))
    {
        Serial1.println("Please insert SD card...\n");
        delay(1000);
    }

    Serial1.println("SD card OK...\n");
    delay(1000);
}

void openFileSD()
{

    String fileName = "";
    char fileNameChar[100] = {0}; // char array for SD functions arguments

    Serial1.println("Enter name for a gcode file on SD : \n");
    emptySerialBuf();
    fileName = getSerial();

    for (int i = 0; fileName.charAt(i) != '\n'; i++) // convert String in char array removing '\n'
        fileNameChar[i] = fileName.charAt(i);

    if (!SD.exists(fileNameChar))
    { // check if file already exists
        Serial1.print("-- ");
        Serial1.print(fileNameChar);
        Serial1.print(" doesn't exists");
        Serial1.println(" --");
        Serial1.println("Please select another file\n");
        delay(200);
        openFileSD();
    }
    else
    {
        myFile = SD.open(fileNameChar, FILE_READ); // create a new file
        Serial1.print("-- ");
        Serial1.print("File : ");
        Serial1.print(fileNameChar);
        Serial1.print(" opened!");
        Serial1.println(" --\n");
    }
}

void fileError()
{
    // For file open or read error
    Serial1.println("\n");
    Serial1.println("File Error !");
}

String readLine(File f)
{
    // return line from file reading
    char inChar;
    String line = "";

    do
    {
        inChar = (char)f.read();
        line += inChar;
    } while (inChar != '\n');

    return line;
}

String sendGcode(String command)
{
    // Serial1.print("\r\n\r\n"); // Wake up grbl
    // delay(2);
    emptySerialBuf();
    Serial1.println(command); // send to serials
    return getSerial();       // get grbl return on serial
}

void sendGcode()
{

    // READING GCODE FILE AND SEND ON SERIAL PORT TO GRBL

    // START GCODE SENDING PROTOCOL ON SERIAL 1

    String line = "";

    Serial1.print("\r\n\r\n"); // Wake up grbl
    delay(2);
    emptySerialBuf();
    if (myFile)
    {
        while (myFile.available())
        {                               // until the file's end
            line = readLine(myFile);    // read line in gcode file
            Serial1.print(line);        // send to serials
            Serial1.print(getSerial()); // print grbl return on serial
        }
    }
    else
        fileError();

    myFile.close();
    Serial1.println("Finish!!\n");
    delay(2000);
}
