#include "Pines.h"
#include <QTRSensors.h>

QTRSensors sigueLineas;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

const int freq = 5000;
const int resolution = 8;


void setup() {
  QTRSetup();
  inicializarMotores();
  calibra();
  while (digitalRead(BOTON) == 0) {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sigueLineas.read(sensorValues);
  Motor(50, 50);
  delay(1500);
  Motor(-50, -50);
  delay(1500);
  Motor(50, 0);  //girar izq
  delay(1500);
  Motor(0, 50);
  delay(1500);  //girar der
}
