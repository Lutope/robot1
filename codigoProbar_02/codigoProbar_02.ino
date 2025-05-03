#include "Pines.h"
#include <QTRSensors.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Fallo de Bluethooth
#endif

BluetoothSerial SerialBT;


QTRSensors sigueLineas;
#define BOTON 12

const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];
uint16_t sensorUmbrales[SensorCount];

const int freq = 5000;
const int resolution = 8;




/*int desicion = 0;
int inter = 0;
int laser = 0;
*/

void setup() {
  QTRSetup();
  inicializarMotores();
  for (uint16_t i = 0; i < 400; i++) {

    sigueLineas.calibrate();
  }
  for (int i = 0; i< SensorCount; i++) {

    sensorUmbrales[i] = (sigueLineas.calibrationOn.minimum[i] + sigueLineas.calibrationOn.maximum[i]) / 2;
  }
  if (sensorValues[0] > sensorUmbrales[0])

    SerialBT.begin("robot1");
}

void loop() {
  // put your main code here, to run repeatedly:
  sigueLineas.read(sensorValues);
  int posicion = sigueLineas.readLineBlack(sensorValues);

  posicion = map(posicion, 0, 7000, -255, 255);

  Serial.println(posicion);
  delay(250);
  //gap --> BBBB

  //
}
