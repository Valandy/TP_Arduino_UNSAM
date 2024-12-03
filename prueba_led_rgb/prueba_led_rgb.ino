#define PIN_LED_R 11
#define PIN_LED_A 10
#define PIN_LED_V 9

void setup() {


  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_A, OUTPUT);
  pinMode(PIN_LED_V, OUTPUT);

}

void loop() {
  
  analogWrite(PIN_LED_R, 255);
  delay(500);
  analogWrite(PIN_LED_R, 0);
  analogWrite(PIN_LED_A, 255);
  delay(500);
  analogWrite(PIN_LED_A, 0);
  analogWrite(PIN_LED_V, 255);
  delay(500);
  analogWrite(PIN_LED_V, 0);

}
