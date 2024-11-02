float humedad_bits;
float humedad_analog;

void setup() {
  Serial.begin(9600);
}

void loop() {
  humedad_bits = analogRead(A0);
  humedad_analog = map(humedad_bits, 0, 1023, 100, 0);

  Serial.print("Humedad del Suelo: ");
  Serial.print(humedad_bits);
  Serial.print(" - ");
  Serial.print("Porcentaje de humedad: ");
  Serial.println(humedad_analog);
  delay(5000);
}

