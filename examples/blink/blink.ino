#include <DL3416.h>

#define CLR 2
#define ADDR0 3
#define ADDR1 4
#define WR 5
#define BL 6
#define D0 7
#define D1 8
#define D2 9
#define D3 10
#define D4 11
#define D5 12
#define D6 13

DL3416 display(CLR, ADDR0, ADDR1, WR, BL, D0, D1, D2, D3, D4, D5, D6);

void setup()
{
    display.begin();
}

void loop()
{
    display.displayText("HELO");
    display.blink(1000);
}