#ifndef DL3416_H
#define DL3416_H

#include <Arduino.h>

class DL3416
{
private:
    int clr, addr0, addr1, wr, bl, d0, d1, d2, d3, d4, d5, d6;

    byte asciiToDL3416(char c);
    void selectAddr(byte segment);
    void setDataPins(byte data);

public:
    DL3416(int clr, int addr0, int addr1, int wr, int bl, int d0, int d1, int d2,
           int d3, int d4, int d5, int d6);

    void begin();
    void displayChar(char c);
    void displayText(const char message[4]);
    void clear();
    void blink(int blinkDelay);
    void scrollText(char message[], int scrollSpeed);
};

#endif