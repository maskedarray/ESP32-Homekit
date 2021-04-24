#include "HomeSpan.h" 
#include "DEV_LED.h"     
#include "DEV_Identify.h"       
void setup() {
  Serial.begin(115200);
  homeSpan.begin(Category::Bridges,"HomeSpan Bridge");
  new SpanAccessory();  
    new DEV_Identify("Bridge #1","HomeSpan","123-ABC","HS Bridge","0.9",3);
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
  new SpanAccessory();                                                          
    new DEV_Identify("RGB LED","HomeSpan","123-ABC","20mA LED","0.9",0);
    new DEV_RgbLED(1,2,3,32,22,23);                                                      //  32,22,23
}
void loop(){
  homeSpan.poll();
} 