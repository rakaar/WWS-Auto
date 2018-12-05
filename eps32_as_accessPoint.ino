/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP32     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <WiFi.h>

void setup()
{
Serial.begin(9600);

  delay(1000);//TO PREVENT GARBAGE Values getting printed
  WiFi.softAP("abc","123");//CONVERT INTO ACCESS POINT
  Serial.println((WiFi.softAPIP()));//print local ip

}


void loop()
{

    Serial.println((WiFi.softAPgetStationNum()));//to know the no. of stations connected
    delay(300);

}
