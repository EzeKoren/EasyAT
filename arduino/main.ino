#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

void throwError(String e)
{
    Serial.println("");
    Serial.println(e);
}

String connect(String ssid, String pass)
{
    WiFi.begin(ssid.c_str(), pass.c_str());
    Serial.print("Connecting to " + ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
        if (WiFi.status() == WL_CONNECT_FAILED)
        {
            throwError("Connection failed. Are the SSID and Password correct?");
            return ("ERROR");
        }
    }
    Serial.println("");
    Serial.println("CONNECTED");
    Serial.println("IP");
    delay(10);
    Serial.println(WiFi.localIP().toString());
    return ("OK");
};

String get(String path)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        throwError("Not connected to WiFi");
        return ("ERROR");
    }

    HTTPClient http;
    http.begin(path);
    int code = http.GET();
    Serial.println("HTTP GET request returned code " + String(code));
    String packet = http.getString();
    http.end();
    Serial.println("RESPONSE");
    Serial.println(packet);
    Serial.println("END");
    Serial.println("OK");
}

String post(String servername, String data)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        throwError("Not connected to WiFi. Run 'AT CONNECT' to connect to WiFi");
        return ("ERROR");
    }

    HTTPClient http;
    http.begin(servername);
    http.addHeader("Content-Type", "application/json; charset=utf-8");
    int code = http.POST(data.c_str());
    Serial.println("HTTP POST request returned code " + String(code));
    String packet = http.getString();
    http.end();
    Serial.println("RESPONSE");
    Serial.println(packet);
    Serial.println("END");
    return ("OK");
};

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
    }
    delay(10);
    Serial.println("Booting");
    Serial.println();
    Serial.println("OK");
}

void loop()
{
    if (Serial.available())
    {
        String command = Serial.readStringUntil('\n');
        Serial.println(command);
        if (command == "AT")
        {
            Serial.println("OK");
        }
        else if (command == "AT+CONNECT")
        {
            Serial.println("SSID");
            while (!Serial.available())
            {
            }
            String ssid = Serial.readStringUntil('\n');
            Serial.println(ssid);
            Serial.println("PASS");
            while (!Serial.available())
            {
            }
            String pass = Serial.readStringUntil('\n');
            Serial.println(pass);
            Serial.println(connect(ssid, pass));
        }
        else if (command == "AT+GET")
        {
            Serial.println("PATH");
            while (!Serial.available())
            {
            }
            String path = Serial.readStringUntil('\n');
            Serial.println(path);
            Serial.println(get(path));
        }
        else if (command == "AT+POST")
        {
            Serial.println("PATH");
            while (!Serial.available())
            {
            }
            String path = Serial.readStringUntil('\n');
            Serial.println(path);
            Serial.println("DATA");
            while (!Serial.available())
            {
            }
            String data = Serial.readStringUntil('\n');
            Serial.println(data);
            Serial.println(post(path, data));
        }

        else
        {
            throwError("Command " + command + " not recognized");
        }
    }
}