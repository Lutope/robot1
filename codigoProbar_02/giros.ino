void giroDer() {
  Motor(0, 0);
  delay(100);
  Motor(-80, 100);
  delay(1650);
  Motor(0, 0);
  delay(700);
  Motor(70, 70);
  delay(100);
}
void giroIzq() {
  Motor(0, 0);
  delay(100);
  Motor(100, -80);
  delay(1650);
  Motor(0, 0);
  delay(700);
  Motor(70, 70);
  delay(100);
}