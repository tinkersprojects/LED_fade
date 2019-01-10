/**********************************************************************************************
 * Arduino LED Func Library - Version 1.0
 * by William Bailes <williambailes@gmail.com> http://tinkersprojects.com/
 *
 * This Library is licensed under a GPLv3 License
 **********************************************************************************************/

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "LED_fade.h"

/******************* SETUP *******************/

LED_fade::LED_fade(int pin)
{
    Pin = pin;
    pinMode(Pin, OUTPUT);
}

/******************* SET *******************/

void LED_fade::SetFade(int value,int speedValue)
{
    this->SetSpeed(speedValue);
    this->SetFade(value);
}

void LED_fade::SetFade(int value)
{
    Last_value = Current_value;
    Future_value = value;
    starting_time = millis();
}

void LED_fade::SetSpeed(int speedValue)
{
    Speed = speedValue;
}

void LED_fade::SetValue(int value)
{
    Last_value = value;
    Current_value = value;
    Future_value = value;
    writeOutput();
}

void LED_fade::Setinverted(bool inverted)
{
    invertedPin = inverted;
}

bool LED_fade::isFinished()
{
    if(millis()>starting_time+Speed) return true;
    
    return false;
}


/******************* COMMANDS *******************/

void LED_fade::run()
{
    unsigned long diff = millis()-starting_time;
    float PercentFade = double(diff)/double(Speed);
    if(PercentFade>1)
    {
        //FollowMaster = true;
        PercentFade=1;
    }

    Current_value = ((Future_value - Last_value)* PercentFade)+Last_value;
    
    writeOutput();
}

void LED_fade::runFor(unsigned long delayValue)
{
    unsigned long currentLocalTime = millis();
    while(currentLocalTime+delayValue>millis())
    {
        this->run();
    }
}




/******************* FUNCTIONS *******************/

void LED_fade::writeOutput()
{
    if(invertedPin == true)
    {
        analogWrite(Pin,255-Current_value);
    }
    else
    {
        analogWrite(Pin,Current_value);
    }
}
