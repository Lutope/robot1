#include "Pines.h"
#include <QTRSensors.h>

QTRSensors sigueLineas;

const uint8_t SensorCount = 8;
uint16_t sensorValues [SensorCount];

const int freq = 5000;
const int resolution = 8;

void setup() {
  QTRSetup();
  inicializarMotores();
  while (digitalRead(BOTON) == 0) {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sigueLineas.read(sensorValues);
  sigueLineas();
}

