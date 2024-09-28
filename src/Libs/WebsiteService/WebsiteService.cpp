#include "WebsiteService.h"

WebServer server(80);
// This functions returns a String of content type
String getContentType(String filename)
{
    if (server.hasArg("download"))
    { // check if the parameter "download" exists
        return "application/octet-stream";
    }
    else if (filename.endsWith(".htm"))
    { // check if the string filename ends with ".htm"
        return "text/html";
    }
    else if (filename.endsWith(".html"))
    {
        return "text/html";
    }
    else if (filename.endsWith(".css"))
    {
        return "text/css";
    }
    else if (filename.endsWith(".js"))
    {
        return "application/javascript";
    }
    else if (filename.endsWith(".png"))
    {
        return "image/png";
    }
    else if (filename.endsWith(".gif"))
    {
        return "image/gif";
    }
    else if (filename.endsWith(".jpg"))
    {
        return "image/jpeg";
    }
    else if (filename.endsWith(".ico"))
    {
        return "image/x-icon";
    }
    else if (filename.endsWith(".xml"))
    {
        return "text/xml";
    }
    else if (filename.endsWith(".pdf"))
    {
        return "application/x-pdf";
    }
    else if (filename.endsWith(".zip"))
    {
        return "application/x-zip";
    }
    else if (filename.endsWith(".gz"))
    {
        return "application/x-gzip";
    }
    return "text/plain";
}

void handleRoot()
{
    String path = "/site" + server.uri(); // saves the to a string server uri ex.(192.168.100.110/edit server uri is "/edit")
    Serial.print("path ");
    Serial.println(path);

    // To send the index.html when the serves uri is "/"
    if (path.endsWith("/"))
    {
        path += "index.html";
    }

    // gets the extension name and its corresponding content type
    String contentType = getContentType(path);
    Serial.print("contentType ");
    Serial.println(contentType);
    File file = SD.open(path, "r");                     // Open the File with file name = to path with intention to read it. For other modes see <a href="https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html" style="font-size: 13.5px;"> https://arduino-esp8266.readthedocs.io/en/latest/...</a>
    size_t sent = server.streamFile(file, contentType); // sends the file to the server references from <a href="https://github.com/espressif/arduino-esp32/blob/master/libraries/WebServer/src/WebServer.h" style="font-size: 13.5px;"> https://arduino-esp8266.readthedocs.io/en/latest/...</a>
    file.close();                                       // Close the file
}

void WebsiteServiceInit()
{
    WiFi.mode(WIFI_STA);
    WiFi.setHostname("CNC_Controller");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    Serial.print("Connecting to ");
    Serial.print(WIFI_SSID);
    Serial.print(" with ");
    Serial.println(WIFI_PASSWORD);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());

    server.onNotFound(handleRoot); // Calls the function handleRoot regardless of the server uri ex.(192.168.100.110/edit server uri is "/edit")

    server.begin();
}