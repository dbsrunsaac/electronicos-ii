// CONSTANTES
const int TIEMPO_MUESTREO = 10;

// VARIABLES
int humedad, humedadPorcentual;
int humedadFiltro, muestraFiltro, humedadPorcentualFiltro, correlacion;

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Sensado sin filtro
  humedad = analogRead(A0); // Salida en bits
  humedadPorcentual = map(humedad, 0, 1023, 100, 0); // Salida porcentual analógica
  Serial.print("Humedad SF: ");
  Serial.println(humedad);

  // Sensando mediante el algoritmo de muestreo doble correlacionado
  humedadFiltro = analogRead(A1); // Salida en bits
  delayMicroseconds(TIEMPO_MUESTREO);
  muestraFiltro = analogRead(A1);
  
  // Filtrado de la señal
  correlacion = abs(humedadFiltro - muestraFiltro);
  humedadPorcentualFiltro = map(correlacion, 0, 1023, 100, 0);

  Serial.print("Humedad MDC: ");
  Serial.println(correlacion);

  delay(3000);
}


// Función para el filtrado
/*
  Recibe como parámetro la humedad medida
*/
void filtrarSensor(float humedadFiltro){

}











