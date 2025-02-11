#define RST 2
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
#define SCROLL_SPEED 300

/*
Connections (DL3416 -> arduino):
  1 - VCC
  2 - VCC
  3 - GND
  4 - GND
  5 - 2
  6 - VCC
  7 - 3
  8 - 4
  9 - 5
  10 - NC
  11 - NC
  12 - GND
  13 - NC
  14 - 6
  15 - NC
  16 - 7
  17 - 8
  18 - 9
  19 - 10
  20 - 11
  21 - 12
  22 - 13
*/

const char message[] = "    HELLO WORLD!    ";
const int messageLength = sizeof(message) - 1;

void setup() {
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }

  digitalWrite(RST, HIGH);
  digitalWrite(BL, HIGH);
  digitalWrite(WR, HIGH);
}

void loop() {
  for (int i = 0; i <= messageLength - 1; i++) {  
    clearDisplay();
    for (int j = 0; j < 4; j++) {
      int charIndex = i + j;
      if (charIndex < messageLength) {
        selectAddr(j + 1);
        writeChar(message[charIndex]);
      }
    }
    delay(SCROLL_SPEED);
  }
}

void clearDisplay() {
  digitalWrite(RST, LOW);
  delay(15);
  digitalWrite(RST, HIGH);
}

void writeChar(char c) {
  byte data = asciiToDL3416(c);
  setDataPins(data);
  digitalWrite(WR, LOW);
  digitalWrite(WR, HIGH);
}

void setDataPins(byte data) {
  digitalWrite(D0, data & 0x01);
  digitalWrite(D1, data & 0x02);
  digitalWrite(D2, data & 0x04);
  digitalWrite(D3, data & 0x08);
  digitalWrite(D4, data & 0x10);
  digitalWrite(D5, data & 0x20);
  digitalWrite(D6, data & 0x40);
}

void selectAddr(byte segment) {
  switch (segment) {
    case 1: digitalWrite(ADDR0, HIGH); digitalWrite(ADDR1, HIGH); break;
    case 2: digitalWrite(ADDR0, LOW);  digitalWrite(ADDR1, HIGH); break;
    case 3: digitalWrite(ADDR0, HIGH); digitalWrite(ADDR1, LOW);  break;
    case 4: digitalWrite(ADDR0, LOW);  digitalWrite(ADDR1, LOW);  break;
  }
}

byte asciiToDL3416(char c) {
  if (c >= ' ' && c <= '_') {
    return c;
  } else {
    return 0x20;
  }
}
