int pins[] = {PB11, PB10, PB1, PB0, PA7, PA6, PA5, PA4, PA3, PA2, PA1, PA0, PC15, PC14, PC13,
              PB12, PB13, PB14, PB15, PA8, PA9, PA10, 
              //PA11, PA12, <-- USB+- 
              //PA15, PB3, PB4 <-- JTag?
              PB5, PB6, PB7, PB8, PB9};
int numPins = sizeof(pins)/sizeof(int);

void setup() {                
  for (int i=0; i<numPins; i++) pinMode(pins[i], OUTPUT);     
}

void loop() {
  for (int i=0; i<numPins; i++) {
  digitalWrite(pins[i], LOW); // ON
  delay(100);
  digitalWrite(pins[i], HIGH);// OFF
  delay(50);
  }
}
