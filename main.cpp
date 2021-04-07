#include "mbed.h"
#include "uLCD_4DGL.h"

DigitalIn Up(D10);
DigitalIn Down(D11);
DigitalIn Select(D12);
uLCD_4DGL uLCD(D1, D0, D2);
AnalogOut wave_out(D7);
AnalogIn sample_wave(A5);
Thread thread;
float ADCdata[500];

void sample(void)
{
    for(int i = 0; i < 500; i++) {          // Use about 1 seconds for sampling 500 times.
        ADCdata[i] = sample_wave;           // Thus, the average sampling rate is 500Hz.
        ThisThread::sleep_for(2ms);
    }
    for (int i = 0; i < 500; i++) {
        printf("%f\r\n", ADCdata[i]);
    }
}

int main()
{
    float srate = 0.125;
    int i, j;
    int T = 240, up_time, down_time, in_time;          // T means the period of wave.
                                                       // up_time means the time of the upward region of one period. 
    double amp;

    wave_out = 0;

    i = ((SIZE_X / 5) - 6) / 2 - 1;
    j = ((SIZE_Y / 7) - 1) / 2 - 1;

    uLCD.background_color(WHITE);
    uLCD.cls();
    uLCD.textbackground_color(WHITE);
    uLCD.color(BLACK);
    uLCD.set_font(FONT_5X7);
    uLCD.locate(i, j);
    uLCD.printf("%d / %d", 1, 8);

    while(1) {
        if (Up == 1) {
            if (srate < 1.0)
                srate = srate * 2;
            else
                srate = 1.0;
            uLCD.cls();
            uLCD.locate(i, j);
            if (srate == 0.125)
                uLCD.printf("%d / %d", 1, 8);
            else if (srate == 0.25)
                uLCD.printf("%d / %d", 1, 4);
            else if (srate == 0.5)
                uLCD.printf("%d / %d", 1, 2);
            else if (srate == 1.0)
                uLCD.printf("%d", 1);
            ThisThread::sleep_for(500ms);
        }
        else if (Down == 1) {
            if (srate > 0.125)
                srate = srate / 2;
            else
                srate = 0.125;
            uLCD.cls();
            uLCD.locate(i, j);
            if (srate == 0.125)
                uLCD.printf("%d / %d", 1, 8);
            else if (srate == 0.25)
                uLCD.printf("%d / %d", 1, 4);
            else if (srate == 0.5)
                uLCD.printf("%d / %d", 1, 2);
            else if (srate == 1.0)
                uLCD.printf("%d", 1);
            ThisThread::sleep_for(500ms);
        }
        if (Select == 1)
            break;
    }

    up_time = 80 * srate;
    down_time = 80 * srate;
    in_time = T - up_time - down_time;
    amp = 3 / 3.3;

    thread.start(sample);

    while(1) {
        for (float a = 0.0; a < amp; a += amp / (up_time / 0.0254))
            wave_out = a;
        ThisThread::sleep_for(in_time);
        for (float b = amp; b > 0; b -= amp / (down_time / 0.0254))
            wave_out = b;
    }
}