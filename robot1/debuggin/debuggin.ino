#include <QTRSensors.h>

#define NUM_SENSORS 6  // Número de sensores QTR
#define TIMEOUT 2500   // Tiempo de espera para los sensores en microsegundos
#define BOTON 12       // Pin de control del emisor

QTRSensorsAnalog qtra((unsigned char[]){ A0, A1, A2, A3, A4, A5 }, NUM_SENSORS, TIMEOUT, EMITTER_PIN);
unsigned int sensorValues[NUM_SENSORS];

void setup() {
  Serial.begin(9600);
  // Calibrar los sensores
  for (int i = 0; i < 400; i++) {
    qtra.calibrate();
    delay(20);
  }
  Serial.println("Calibracion completa");
}

void loop() {
  // Leer los valores de los sensores
  qtra.read(sensorValues);

  // Imprimir los valores de los sensores
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(250);
}