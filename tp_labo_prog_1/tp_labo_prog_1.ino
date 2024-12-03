#include <stdlib.h>

#define POTE_ROJO A0
#define POTE_VERDE A1
#define POTE_AZUL A2

#define BOTON_INICIO 3
#define BOTON_PISTA 2

#define PIN_LED_R 11
#define PIN_LED_A 10
#define PIN_LED_V 9

#define TIEMPO_PISTA 2000
#define TIEMPO_PRESENTACION 3000


unsigned long tiempo_juego;
int margen;

unsigned long cronometro;
unsigned long pista;
unsigned long tiempo_cero;
unsigned long tiempo_pista;

int rojo_obj;
int verde_obj;
int azul_obj;

int nivel;

bool win = false;


void setup() {

  pinMode(POTE_ROJO, INPUT);
  pinMode(POTE_VERDE, INPUT);
  pinMode(POTE_AZUL, INPUT);

  pinMode(BOTON_PISTA, INPUT);
  pinMode(BOTON_INICIO, INPUT);

  pinMode(PIN_LED_R, OUTPUT);
  pinMode(PIN_LED_A, OUTPUT);
  pinMode(PIN_LED_V, OUTPUT);

  randomSeed(analogRead(4));


  Serial.begin(9600);
  
}

void loop() {

  nivel = 1;

  analogWrite(PIN_LED_R, 255);
  analogWrite(PIN_LED_V, 0);
  analogWrite(PIN_LED_A, 255);

  int inicio = digitalRead(BOTON_INICIO);

  if (inicio == 1) {

    while (nivel < 4) {

      rojo_obj = random(255);
      azul_obj = random(255);
      verde_obj = random(255);

      presentacion();

      Serial.println(rojo_obj);
      Serial.println(azul_obj);
      Serial.println(verde_obj);

      juego();

      if (win == true) {

        cronometro = 0;
        tiempo_cero = 0;

        ganar();
        nivel += 1;


      } else {

        perder();
        break;
      }
    }
    if (nivel >= 4) {

      fiestita();

    }
  }
}

void presentacion() {


  switch (nivel) {

    case 1:

      for (int i = 0; i < 10; i++) {

        if ((i % 2) == 0) {

          analogWrite(PIN_LED_R, 0);
          analogWrite(PIN_LED_A, 255);
          analogWrite(PIN_LED_V, 255);
          delay(500);

        } else {

          analogWrite(PIN_LED_R, 0);
          analogWrite(PIN_LED_A, 0);
          analogWrite(PIN_LED_V, 0);
          delay(500);
        }
      }

      tiempo_juego = 60000;
      margen = 40;
      break;

    case 2:

      for (int i = 0; i < 10; i++) {

        if ((i % 2) == 0) {

          analogWrite(PIN_LED_R, 0);
          analogWrite(PIN_LED_A, 255);
          analogWrite(PIN_LED_V, 255);
          delay(300);

        } else {

          analogWrite(PIN_LED_R, 0);
          analogWrite(PIN_LED_A, 0);
          analogWrite(PIN_LED_V, 0);
          delay(300);
        }
      }

      tiempo_juego = 50000;
      margen = 30;
      break;

    case 3:

      for (int i = 0; i < 10; i++) {

        if ((i % 2) == 0) {

          analogWrite(PIN_LED_R, 0);
          analogWrite(PIN_LED_A, 255);
          analogWrite(PIN_LED_V, 255);
          delay(200);

        } else {

          analogWrite(PIN_LED_R, 0);
          analogWrite(PIN_LED_A, 0);
          analogWrite(PIN_LED_V, 0);
          delay(200);
        }
      }

      tiempo_juego = 40000;
      margen = 25;
      break;
  }

  tiempo_cero = millis();

  while (cronometro < TIEMPO_PRESENTACION) {


    cronometro = millis() - tiempo_cero;

    analogWrite(PIN_LED_R, rojo_obj);
    analogWrite(PIN_LED_A, azul_obj);
    analogWrite(PIN_LED_V, verde_obj);
  }
}


bool juego() {

  win = false;

  Serial.println(tiempo_juego);
  Serial.println(margen);

  tiempo_cero = millis();

  while (cronometro < tiempo_juego) {

    cronometro = millis() - tiempo_cero;

    int boton = digitalRead(BOTON_PISTA);

    int rojo = map(analogRead(POTE_ROJO), 0, 1023, 0, 255);
    int azul = map(analogRead(POTE_AZUL), 0, 1023, 0, 255);
    int verde = map(analogRead(POTE_VERDE), 0, 1023, 0, 255);

    analogWrite(PIN_LED_R, rojo);
    analogWrite(PIN_LED_A, azul);
    analogWrite(PIN_LED_V, verde);

    if ((abs(rojo - rojo_obj)) < margen) {
      if ((abs(azul - azul_obj)) < margen) {
        if ((abs(verde - verde_obj)) < margen) {

          return win = true;

        }
      }
    }

    if (boton == 1) {

      tiempo_pista = millis();

      while (pista < TIEMPO_PISTA) {

        pista = millis() - tiempo_pista;

        analogWrite(PIN_LED_R, rojo_obj);
        analogWrite(PIN_LED_A, azul_obj);
        analogWrite(PIN_LED_V, verde_obj);

      }

      pista = 0;

    }
  }
}

void ganar() {

  for (int i = 0; i < 10; i++) {

    if ((i % 2) == 0) {

      analogWrite(PIN_LED_R, 0);
      analogWrite(PIN_LED_A, 0);
      analogWrite(PIN_LED_V, 255);
      delay(500);

    } else {

      analogWrite(PIN_LED_R, 0);
      analogWrite(PIN_LED_A, 0);
      analogWrite(PIN_LED_V, 0);
      delay(500);
    }
  }
}

void perder() {

  for (int i = 0; i < 10; i++) {

    if ((i % 2) == 0) {


      analogWrite(PIN_LED_R, 255);
      analogWrite(PIN_LED_A, 0);
      analogWrite(PIN_LED_V, 0);
      delay(500);

    } else {

      analogWrite(PIN_LED_R, 0);
      analogWrite(PIN_LED_A, 0);
      analogWrite(PIN_LED_V, 0);
      delay(500);
    }
  }
}

void fiestita() {

  for (int i = 0; i < 25; i++) {

    analogWrite(PIN_LED_R, random(255));
    delay(200);
    analogWrite(PIN_LED_A, random(255));
    delay(200);
    analogWrite(PIN_LED_V, random(255));
    delay(200);
  }
}