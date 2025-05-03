#include "Pines.h"
#include <QTRSensors.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Fallo de Bluethooth
#endif

BluetoothSerial SerialBT;


QTRSensors sigueLineas;

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

const int freq = 5000;
const int resolution = 8;

int umbral = 2500;


void setup() {
  QTRSetup();
  inicializarMotores();

  while (digitalRead(BOTON) == 0) {
  }
  SerialBT.begin("robot1");
}

void loop() {
  // put your main code here, to run repeatedly:
  sigueLineas.read(sensorValues);

  //curva izq --> bbnn
  if (sensorValues[2] <= umbral && sensorValues[3] <= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(0, 50);
  }
  //curva der --> nnbb
  else if (sensorValues[2] >= umbral && sensorValues[3] >= umbral && sensorValues[4] <= umbral && sensorValues[5] <= umbral) {
    Motor(50, 0);
  }
  //giroIZQ --> NNBB (solo laterales)
  else if (sensorValues[0] >= umbral && sensorValues[1] >= umbral && sensorValues[6] <= umbral && sensorValues[7] <= umbral) {
    giroIzq();
  }
  //giro der -->BBNN (solo laterales)
  else if (sensorValues[0] <= umbral && sensorValues[1] <= umbral && sensorValues[6] >= umbral && sensorValues[7] >= umbral) {
    giroDer();
  }
  //gap --> BBBB
  else if (sensorValues[2] >= umbral && sensorValues[3] >= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(30, 30);
  }
  //intersección --> NNNN
  else if (sensorValues[2] >= umbral && sensorValues[3] >= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(50, 50);
  }
  //avanzar -->BNB
  else if (sensorValues[2] <= umbral && sensorValues[3] <= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(50, 50);
  }
  for (int i = 0; i <= 7; i++) {
    SerialBT.print(sensorValues[i]);
    SerialBT.print(" ");
  }
  SerialBT.println();
}
