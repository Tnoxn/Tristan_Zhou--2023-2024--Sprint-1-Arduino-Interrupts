const byte ledPin = 6;
const byte blinker = 9;
const byte interruptPin1 = 18;
const byte interruptPin2 = 19;
const byte interruptPin3 = 20;
const byte interruptPin4 = 21;
volatile byte state = LOW;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin1, INPUT);
  pinMode(interruptPin2, INPUT);
  pinMode(interruptPin3, INPUT);
  pinMode(interruptPin4, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), blink, RISING);
  attachInterrupt(digitalPinToInterrupt(interruptPin4), blink, RISING);

  Serial.begin(9600);
}

void loop() {
  Serial.println("loop");
    digitalWrite(blinker, HIGH);
    delay(100);
    digitalWrite(blinker, LOW);
    delay(100);
  
}

void blink() {
  state = !state;
  digitalWrite(ledPin, state);
  Serial.println("blink");
}
