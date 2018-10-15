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

byte columns[] = {col0,col1,col2,col3};
byte segments[] = {segA,segB,segC,segD,segE,segF,segG,segH,segI,segJ,segK,segL,segM,segN,segO,segP,segQ};
int rate = 100; // Lower = faster

void setup() {
  for (byte i = 0; i < 4; i++) { pinMode(columns[i], OUTPUT); digitalWrite(columns[i],HIGH);}    // HIGH = off
  for (byte i = 0; i < 17; i++) { pinMode(segments[i], OUTPUT); digitalWrite(segments[i],HIGH);} // HIGH = off
}

void loop() {
  digitalWrite(col0, LOW); // LOW=ON
  digitalWrite(segA, LOW); delay(rate); digitalWrite(segA, HIGH); 
  digitalWrite(segB, LOW); delay(rate); digitalWrite(segB, HIGH); 
  digitalWrite(segC, LOW); delay(rate); digitalWrite(segC, HIGH); 
  digitalWrite(segD, LOW); delay(rate); digitalWrite(segD, HIGH); 
  digitalWrite(segE, LOW); delay(rate); digitalWrite(segE, HIGH); 
  digitalWrite(segF, LOW); delay(rate); digitalWrite(segF, HIGH); 
  digitalWrite(segG, LOW); delay(rate); digitalWrite(segG, HIGH); 
  digitalWrite(segH, LOW); delay(rate); digitalWrite(segH, HIGH); 
  digitalWrite(segI, LOW); delay(rate); digitalWrite(segI, HIGH); 
  digitalWrite(segJ, LOW); delay(rate); digitalWrite(segJ, HIGH); 
  digitalWrite(segK, LOW); delay(rate); digitalWrite(segK, HIGH); 
  digitalWrite(segL, LOW); delay(rate); digitalWrite(segL, HIGH); 
  digitalWrite(segM, LOW); delay(rate); digitalWrite(segM, HIGH); 
  digitalWrite(segN, LOW); delay(rate); digitalWrite(segN, HIGH); 
  digitalWrite(segO, LOW); delay(rate); digitalWrite(segO, HIGH); 
  digitalWrite(segP, LOW); delay(rate); digitalWrite(segP, HIGH); 
  digitalWrite(segQ, LOW); delay(rate); digitalWrite(segQ, HIGH);
  digitalWrite(col0, HIGH); // LOW=ON
  
  digitalWrite(col1, LOW); // LOW=ON
  digitalWrite(segA, LOW); delay(rate); digitalWrite(segA, HIGH); 
  digitalWrite(segB, LOW); delay(rate); digitalWrite(segB, HIGH); 
  digitalWrite(segC, LOW); delay(rate); digitalWrite(segC, HIGH); 
  digitalWrite(segD, LOW); delay(rate); digitalWrite(segD, HIGH); 
  digitalWrite(segE, LOW); delay(rate); digitalWrite(segE, HIGH); 
  digitalWrite(segF, LOW); delay(rate); digitalWrite(segF, HIGH); 
  digitalWrite(segG, LOW); delay(rate); digitalWrite(segG, HIGH); 
  digitalWrite(segH, LOW); delay(rate); digitalWrite(segH, HIGH); 
  digitalWrite(segI, LOW); delay(rate); digitalWrite(segI, HIGH); 
  digitalWrite(segJ, LOW); delay(rate); digitalWrite(segJ, HIGH); 
  digitalWrite(segK, LOW); delay(rate); digitalWrite(segK, HIGH); 
  digitalWrite(segL, LOW); delay(rate); digitalWrite(segL, HIGH); 
  digitalWrite(segM, LOW); delay(rate); digitalWrite(segM, HIGH); 
  digitalWrite(segN, LOW); delay(rate); digitalWrite(segN, HIGH); 
  digitalWrite(segO, LOW); delay(rate); digitalWrite(segO, HIGH); 
  digitalWrite(segP, LOW); delay(rate); digitalWrite(segP, HIGH); 
  digitalWrite(segQ, LOW); delay(rate); digitalWrite(segQ, HIGH);
  digitalWrite(col1, HIGH); // LOW=ON
  
  digitalWrite(col2, LOW); // LOW=ON
  digitalWrite(segA, LOW); delay(rate); digitalWrite(segA, HIGH); 
  digitalWrite(segB, LOW); delay(rate); digitalWrite(segB, HIGH); 
  digitalWrite(segC, LOW); delay(rate); digitalWrite(segC, HIGH); 
  digitalWrite(segD, LOW); delay(rate); digitalWrite(segD, HIGH); 
  digitalWrite(segE, LOW); delay(rate); digitalWrite(segE, HIGH); 
  digitalWrite(segF, LOW); delay(rate); digitalWrite(segF, HIGH); 
  digitalWrite(segG, LOW); delay(rate); digitalWrite(segG, HIGH); 
  digitalWrite(segH, LOW); delay(rate); digitalWrite(segH, HIGH); 
  digitalWrite(segI, LOW); delay(rate); digitalWrite(segI, HIGH); 
  digitalWrite(segJ, LOW); delay(rate); digitalWrite(segJ, HIGH); 
  digitalWrite(segK, LOW); delay(rate); digitalWrite(segK, HIGH); 
  digitalWrite(segL, LOW); delay(rate); digitalWrite(segL, HIGH); 
  digitalWrite(segM, LOW); delay(rate); digitalWrite(segM, HIGH); 
  digitalWrite(segN, LOW); delay(rate); digitalWrite(segN, HIGH); 
  digitalWrite(segO, LOW); delay(rate); digitalWrite(segO, HIGH); 
  digitalWrite(segP, LOW); delay(rate); digitalWrite(segP, HIGH); 
  digitalWrite(segQ, LOW); delay(rate); digitalWrite(segQ, HIGH);
  digitalWrite(col2, HIGH); // LOW=ON
  
  digitalWrite(col3, LOW); // LOW=ON
  digitalWrite(segA, LOW); delay(rate); digitalWrite(segA, HIGH); 
  digitalWrite(segB, LOW); delay(rate); digitalWrite(segB, HIGH); 
  digitalWrite(segC, LOW); delay(rate); digitalWrite(segC, HIGH); 
  digitalWrite(segD, LOW); delay(rate); digitalWrite(segD, HIGH); 
  digitalWrite(segE, LOW); delay(rate); digitalWrite(segE, HIGH); 
  digitalWrite(segF, LOW); delay(rate); digitalWrite(segF, HIGH); 
  digitalWrite(segG, LOW); delay(rate); digitalWrite(segG, HIGH); 
  digitalWrite(segH, LOW); delay(rate); digitalWrite(segH, HIGH); 
  digitalWrite(segI, LOW); delay(rate); digitalWrite(segI, HIGH); 
  digitalWrite(segJ, LOW); delay(rate); digitalWrite(segJ, HIGH); 
  digitalWrite(segK, LOW); delay(rate); digitalWrite(segK, HIGH); 
  digitalWrite(segL, LOW); delay(rate); digitalWrite(segL, HIGH); 
  digitalWrite(segM, LOW); delay(rate); digitalWrite(segM, HIGH); 
  digitalWrite(segN, LOW); delay(rate); digitalWrite(segN, HIGH); 
  digitalWrite(segO, LOW); delay(rate); digitalWrite(segO, HIGH); 
  digitalWrite(segP, LOW); delay(rate); digitalWrite(segP, HIGH); 
  digitalWrite(segQ, LOW); delay(rate); digitalWrite(segQ, HIGH);
  digitalWrite(col3, HIGH); // LOW=ON
  
}
