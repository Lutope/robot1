void giroIzq() {
  Motor(0, 0);
  delay(100);
  Motor(-70, 70);
  delay(700);
  Motor(0, 0);
  delay(700);
  Motor(70, 70);
  delay(100);
}
void giroDer() {
  Motor(0, 0);
  delay(100);
  Motor(70, -70);
  delay(700);
  Motor(0, 0);
  delay(700);
  Motor(70, 70);
  delay(100);
}