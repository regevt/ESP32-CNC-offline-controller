
#include <SD.h>

#include <Arduino.h>

File myFile;
boolean restart = true;

// void setup(){

// 	Serial.begin(115200);
// 	Serial.begin(115200);
// }

// void loop(){

// 	checkSD();
// 	while(restart){
// 		openFileSD();
// 		sendGcode();
// 	}
// }

void waitSerial()
{
    // Wait for data on Serial
    // Argument serialNum for Serial number
    boolean serialAv = false;

    while (!serialAv)
    {
        if (Serial.available())
            serialAv = true;
    }
}

String getSerial()
{

    // Return String  from serial line reading
    // Argument serialNum for Serial number

    String inLine = "";
    waitSerial();

    while (Serial.available())
    {
        inLine += (char)Serial.read();
        delay(2);
    }
    return inLine;
}

void emptySerialBuf()
{
    while (Serial.available())
        Serial.read();
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
        Serial.println("Please insert SD card...\n");
        delay(1000);
    }

    Serial.println("SD card OK...\n");
    delay(1000);
}

void openFileSD()
{

    String fileName = "";
    char fileNameChar[100] = {0}; // char array for SD functions arguments

    Serial.println("Enter name for a gcode file on SD : \n");
    emptySerialBuf();
    fileName = getSerial();

    for (int i = 0; fileName.charAt(i) != '\n'; i++) // convert String in char array removing '\n'
        fileNameChar[i] = fileName.charAt(i);

    if (!SD.exists(fileNameChar))
    { // check if file already exists
        Serial.print("-- ");
        Serial.print(fileNameChar);
        Serial.print(" doesn't exists");
        Serial.println(" --");
        Serial.println("Please select another file\n");
        delay(200);
        openFileSD();
    }
    else
    {
        myFile = SD.open(fileNameChar, FILE_READ); // create a new file
        Serial.print("-- ");
        Serial.print("File : ");
        Serial.print(fileNameChar);
        Serial.print(" opened!");
        Serial.println(" --\n");
    }
}

void fileError()
{
    // For file open or read error
    Serial.println("\n");
    Serial.println("File Error !");
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
    Serial.print("\r\n\r\n"); // Wake up grbl
    delay(2);
    emptySerialBuf();
    Serial.print(command); // send to serials
    return getSerial();    // get grbl return on serial
}

void sendGcode()
{

    // READING GCODE FILE AND SEND ON SERIAL PORT TO GRBL

    // START GCODE SENDING PROTOCOL ON SERIAL 1

    String line = "";

    Serial.print("\r\n\r\n"); // Wake up grbl
    delay(2);
    emptySerialBuf();
    if (myFile)
    {
        while (myFile.available())
        {                              // until the file's end
            line = readLine(myFile);   // read line in gcode file
            Serial.print(line);        // send to serials
            Serial.print(getSerial()); // print grbl return on serial
        }
    }
    else
        fileError();

    myFile.close();
    Serial.println("Finish!!\n");
    delay(2000);
}
