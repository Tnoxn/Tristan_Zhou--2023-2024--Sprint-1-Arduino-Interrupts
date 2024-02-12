#include <Arduino.h>
 #define pinLED1 4
 #define pinLED2 8
 #define pinINT0 3
 #define pinINT1 2
 #define pinINT2 7
 #define pinINT3 21
 #define pinINT4 20
   // external interrupt source
                   // put function declarations here:
 #define intTest INT1

void blink();


volatile byte state = LOW;


  



void setup() {
  // put your setup code here, to run once:
  
Serial.begin(19200);

  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED1, OUTPUT);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  
  pinMode(pinINT0, INPUT_PULLUP);
  pinMode(pinINT1, INPUT_PULLUP);
  pinMode(pinINT2, INPUT_PULLUP);
  pinMode(pinINT3, INPUT_PULLUP);
  pinMode(pinINT4, INPUT_PULLUP);
  

  attachInterrupt(pinINT0, blink, RISING);
  attachInterrupt(pinINT1, blink, RISING);
  attachInterrupt(pinINT2, blink, RISING);
  attachInterrupt(pinINT3, blink, RISING);
  attachInterrupt(pinINT4, blink, RISING);
  
  
  
  Serial.println("Setup");
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
attachInterrupt(pinINT0, blink, RISING);
  attachInterrupt(pinINT1, blink, RISING);
  attachInterrupt(pinINT2, blink, RISING);
  attachInterrupt(pinINT3, blink, RISING);
  attachInterrupt(pinINT4, blink, RISING);

    digitalWrite(pinLED1, HIGH);
    delay(250);
    digitalWrite(pinLED1, LOW);
    delay(250);
    if (digitalRead(pinINT3) == HIGH){
      Serial.println("HIGH");
    }
}


void blink() {
  
  state = !state;

  digitalWrite(pinLED2, state);
  Serial.println("blink");
  
  
}