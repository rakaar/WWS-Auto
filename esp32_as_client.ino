/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

void setup()
{
Serial.begin(9600);

  WiFi.disconnect();
  delay(1000);
  WiFi.begin("Kaushik");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);

  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println((WiFi.localIP()));

  }

}


void loop()
{


}