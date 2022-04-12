#include "InterruptIn.h"
#include "PinNames.h"
#include "mbed.h"
#include <chrono>
#include <cstdio>

DigitalOut oled1(LED1);
InterruptIn ibutton1(BUTTON1);

static auto sleep_time = 1000ms;
int k = 0;

Ticker toggle_led_ticker;

void led_ticker()
{
    oled1 = !oled1;

}

void pressed()
{
    if (k < 2)
        k++;
    else
        k=0;
}

void mode(chrono::milliseconds thread_time,int i)
{
    if (k==i){
    ThisThread::sleep_for(thread_time);
    oled1 = 1;
    ThisThread::sleep_for(thread_time);
    oled1 = 0;
    }
}

int main()
{

    ibutton1.rise(&pressed);

    while (true) {
        mode(50ms,0);
        mode(100ms,1);
        mode(500ms,2);
    }
} 