
#ifndef LED_fade_h
#define LED_fade_h

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#include <wiring.h>
#endif


class LED_fade
{
    public:
        // SETUP 
        LED_fade(int pin);

        // SET  
        void SetFade(int value,int speedValue);
        void SetFade(int value);
        void SetSpeed(int speedValue);
        void SetValue(int value);
        void Setinverted(bool inverted);

        bool isFinished();
        // COMMANDS 
        void run();
        void runFor(unsigned long delayValue);

        // FUNCTIONS
        void writeOutput();

    private:
        int Pin = -1;
        bool invertedPin;

        int Last_value;
        int Current_value;
        int Future_value;
        unsigned long starting_time;
        unsigned long Speed = 2000;
};

#endif 
