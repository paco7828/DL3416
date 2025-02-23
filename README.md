DL3416 Arduino Library

A simple custom library for controlling the vintage DL3416 display using an Arduino Uno. This library provides basic functionality to write characters to the display and includes two example sketches: blink and scroll.

Wiring
|---------------------------------------------------------|
| DL3416 Pin |          Function        | Arduino Uno Pin |
|------------|--------------------------|-----------------|
| 1          | CE1 Chip Enable          | 5V              |
| 2          | CE2 Chip Enable          | 5V              |
| 3          | CE3 Chip Enable (~)      | GND             |
| 4          | CE4 Chip Enable (~)      | GND             |
| 5          | CLR Clear (~)            | 2               |
| 6          | VCC                      | 5V              |
| 7          | A0 Digit Select          | 3               |
| 8          | A1 Digit Select          | 4               |
| 9          | WR Write (~)             | 5               |
| 10         | CU Cursor Select (~)     | Not Connected   |
| 11         | CUE Cursor Enables       | Not Connected   |
| 12         | GND                      | GND             |
| 13         | NC (Not Connected)       | -               |
| 14         | BL Blanking (~)          | 6               |
| 15         | NC (Not Connected)       | -               |
| 16         | D0 Data Input            | 7               |
| 17         | D1 Data Input            | 8               |
| 18         | D2 Data Input            | 9               |
| 19         | D3 Data Input            | 10              |
| 20         | D4 Data Input            | 11              |
| 21         | D5 Data Input            | 12              |
| 22         | D6 Data Input            | 13              |
|---------------------------------------------------------|
