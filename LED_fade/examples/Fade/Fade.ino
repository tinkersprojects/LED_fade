#include <LED_fade.h>

LED_fade LED(10);

void setup() 
{
   LED.SetFade(255,10000);
}

void loop() 
{
   LED.run();
}