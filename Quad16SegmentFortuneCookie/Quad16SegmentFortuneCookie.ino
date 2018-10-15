//
// Fortune Cookie on a Quad 16 Segment Display
// by Hari Wiguna, Oct 2018
//

#include "Fortunes.h"

//=== GPIO MAPPING ===
const byte segP = PB11; // PB11, PB10, PB1, PB0, PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0, PC15, PC14, PC13
const byte segI = PB10;
const byte segJ = PB1;
const byte segC = PB0;
const byte segL = PA7;
const byte segH = PA6;
const byte segA = PA5;
const byte segK = PA4;
const byte col0 = PA3;
const byte col2 = PA2;
//const byte seg = PA1;
//const byte seg = PA0;
//const byte seg = PC15;
//const byte seg = PC14;
//const byte seg = PC13;
const byte segF = PB12; // PB12, PB13, PB14, PB15, PA8, PA9, PA10,
const byte segO = PB13;
const byte segN = PB14;
const byte segQ = PB15;
const byte segG = PA8;
const byte segM = PA9;
const byte segD = PA10;
//PA11, PA12, <-- USB+-
//PA15, PB3, PB4 <-- JTag?
const byte segE = PB5; // PB5, PB6, PB7, PB8, PB9
const byte segB = PB6;
const byte seg = PB7;
const byte col1 = PB8;
const byte col3 = PB9;

byte columns[] = {col0, col1, col2, col3};
byte segments[] = {segA, segB, segC, segD, segE, segF, segG, segH, segI, segJ, segK, segL, segM, segN, segO, segP, segQ};
int rate = 1000; // Lower = faster

const byte buttonPin = PA1;

//=== CHARACTER BITMAP ===
const byte bitmap[][2] = {
  // Test Pattern
  //ABCDEFGH   IJKLMNOP
  //  {B10000000, B00000000}, //
  //  {B01000000, B00000000}, //
  //  {B00100000, B00000000}, //
  //  {B00010000, B00000000}, //
  //  {B00001000, B00000000}, //
  //  {B00000100, B00000000}, //
  //  {B00000010, B00000000}, //
  //  {B00000001, B00000000}, //
  //  {B00000000, B10000000}, //
  //  {B00000000, B01000000}, //
  //  {B00000000, B00100000}, //
  //  {B00000000, B00010000}, //
  //  {B00000000, B00001000}, //
  //  {B00000000, B00000100}, //
  //  {B00000000, B00000010}, //
  //  {B00000000, B00000001}, //

  //ABCDEFGH   IJKLMNOP
  {B00000000, B00000000}, // ' '
  {B00111000, B00000000}, // !
  {B00000001, B01000000}, // "
  {B00000000, B00000000}, // #
  {B00000000, B00000000}, // $
  {B00000000, B00000000}, // %
  {B00000000, B00000000}, // &
  {B00000001, B00000000}, // '
  {B00000000, B00100000}, // (
  {B00000000, B00000000}, // )
  {B00000000, B00000000}, // *
  {B00000000, B00000000}, // +
  {B00001000, B00000000}, // , // HOW?
  {B00000000, B00010001}, // -
  {B00001000, B00000000}, // .
  {B00000000, B00100010}, // /

  //ABCDEFGH  IJKLMNOP
  {B01110111, B00000000}, // 0
  {B00110000, B00000000}, // 1
  {B01100110, B00010001}, // 2
  {B00000000, B00000000}, // 3
  {B00000000, B00000000}, // 4
  {B00000000, B00000000}, // 5
  {B00000000, B00000000}, // 6
  {B00000000, B00000000}, // 7
  {B00000000, B00000000}, // 8
  {B00000000, B00000000}, // 9
  {B00000000, B00000000}, // :
  {B00000000, B00000000}, // ;
  {B00000000, B00000000}, // <
  {B00000000, B00000000}, // =
  {B00000000, B00000000}, // >
  {B11100000, B00010100}, // ?
  {B00000000, B00000000}, // @
  {B11111011, B00010001}, // A
  {B11001111, B00101001}, // B
  {B11001111, B00000000}, // C
  {B11111100, B01000100}, // D
  {B11001111, B00010001}, // E
  {B11000011, B00010001}, // F
  {B11011111, B00010000}, // G
  {B10111011, B00010001}, // H
  {B00111000, B00000000}, // I
  {B00111110, B00000000}, // J
  {B00001011, B00101001}, // K
  {B10001111, B00000000}, // L
  {B10111011, B10100000}, // M
  {B10111011, B10001000}, // N
  {B01110111, B00000000}, // O
  {B11100011, B00010001}, // P
  {B11111111, B00001000}, // Q
  {B11101011, B00011001}, // R
  {B01010101, B00010001}, // S
  {B11000000, B01000100}, // T
  {B10110111, B00000000}, // U
  {B10000011, B00100010}, // V
  {B10111011, B00001010}, // W
  {B00000000, B10101010}, // X
  {B10111101, B00010001}, // Y
  {B11001100, B00100010}, // Z
  //ABCDEFGH   IJKLMNOP

  //  {B, B}, //
  //ABCDEFGH  IJKLMNOP

};
const int maxChars = sizeof(bitmap) / (sizeof(byte) * 2);

//=== SETUP ===
void setup() {
  randomSeed(analogRead(0));

  for (byte i = 0; i < 4; i++) {
    pinMode(columns[i], OUTPUT);  // HIGH = off
    digitalWrite(columns[i], HIGH);
  }
  for (byte i = 0; i < 17; i++) {
    pinMode(segments[i], OUTPUT);  // HIGH = off
    digitalWrite(segments[i], HIGH);
  }

  pinMode(buttonPin, INPUT);
}

//=== LOOP ===
void loop() {
  // AlphabetTest();
  // PrintAllFortunes()
  WaitForButton();
  PrintRandomFortune();
}

//=== METHODS ===
void PrintChar(byte col, char ch)
{
  // Turn off all segments first
  for (byte i = 0; i < 17; i++) digitalWrite(segments[i], HIGH); // HIGH = off

  // Turn on the correct column ONLY
  for (byte i = 0; i < 4; i++) digitalWrite(columns[i], i != col);    // HIGH = off

  // Turn on the appropriate segments
  char charIndex = ch - ' ';
  for (byte bitIndex = 0; bitIndex < 8; bitIndex++) digitalWrite(segments[bitIndex], !bitRead(bitmap[charIndex][0], 7 - bitIndex));
  for (byte bitIndex = 0; bitIndex < 8; bitIndex++) digitalWrite(segments[8 + bitIndex], !bitRead(bitmap[charIndex][1], 7 - bitIndex));
}

void PrintMessage(String str)
{
  str.toUpperCase();
  str = "    " + str + "    ";;
  int messageLength = str.length();
  for (int offset = 0; offset < (messageLength - 4); offset++)
  {
    int rptCount = 10; // Higher = slower scroll
    for (int rpt = 0; rpt < rptCount; rpt++) {
      for (int charIndex = 0; charIndex < 4; charIndex++) {
        int ch = str[offset + charIndex];
        PrintChar(charIndex, ch);
        delay(6); // Higher = brighter, but more flicker
      }
    }
  }
}

void AlphabetTest()
{
  for (int charIndex = 0 ; charIndex < maxChars; charIndex++)
  {
    PrintChar(0, ' ' + charIndex);
    delay(rate);
  }
}

void PrintAllFortunes()
{
  for (int fortuneIndex = 0; fortuneIndex < fortuneMax; fortuneIndex++) {
    PrintMessage(fortunes[fortuneIndex]);
    delay(1000);
  }
}


void PrintRandomFortune()
{
  int randomIndex = random(0, fortuneMax);
  PrintMessage(fortunes[randomIndex]);
  delay(500);
}

void WaitForButton()
{
  int checkRate = 50; // How often to check button
  int blinkRate = 500; // How often to blink the question mark
  unsigned long timeToCheck = 0;
  unsigned long timeToBlink = 0;
  bool isOn = false;
  bool isPressed = false;
  while (!isPressed)
  {
    if (millis() >= timeToCheck) {
      if (digitalRead(buttonPin) == LOW) isPressed = true;
      timeToCheck = millis() + checkRate;
    }
    if (millis() >= timeToBlink) {
      isOn = !isOn;
      if (isOn) PrintChar(1, '?'); else PrintChar(2, '?');
      timeToBlink = millis() + blinkRate;
    }
  }
}

