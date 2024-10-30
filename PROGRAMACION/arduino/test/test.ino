void setup() {
  // Inicializa el pin 13 como salida
  pinMode(13, OUTPUT);
}

void loop() {
  // Enciende el LED
  digitalWrite(13, HIGH);
  // Espera 1.5 segundos
  delay(1500);
  // Apaga el LED
  digitalWrite(13, LOW);
  // Espera 1.5 segundos
  delay(1500);
}
