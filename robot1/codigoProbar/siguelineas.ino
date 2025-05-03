void sigueLineas(){
 
  if (sensorValues[2] <= umbral && sensorValues[3] <= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(0, 50);
  }
  //curva der --> nbb
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
  //intersección --> NNNN
  else if (sensorValues[2] >= umbral && sensorValues[3] >= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(50, 50);
  }
  //avanzar -->BNB
  else if (sensorValues[2] <= umbral && sensorValues[3] <= umbral && sensorValues[4] >= umbral && sensorValues[5] >= umbral) {
    Motor(50, 50);
  }
  for (int i = 0; i <= 7; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.println();
}
