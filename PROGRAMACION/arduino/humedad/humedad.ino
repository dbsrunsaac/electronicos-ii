// CONSTANTES
const float TIEMPO_MUESTREO = 0.001;

// VARIABLES
float humedad, humedadPorcentual;
float humedadFiltro, humedadPorcentualFiltro, muestraFiltro, correlacion;

void setup() {
  // Iniciar la comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Sensado sin filtro
  humedad = analogRead(A0); // Salida en bits
  // humedadPorcentual = map(humedad, 0, 1023, 100, 0); // Salida porcentual analógica
  humedadPorcentual = analogToPorcentual(humedad);
  // Sensado de la Humedad sin Filtro
  Serial.print("Humedad SF: ");
  Serial.println(humedad);

  // Sensando mediante el algoritmo de muestreo doble correlacionado
  humedadFiltro = analogRead(A1); // Salida en bits
  delayMicroseconds(TIEMPO_MUESTREO);
  muestraFiltro = analogRead(A1);
  
  // Filtrado de la señal
  correlacion = humedadFiltro - abs(humedadFiltro - muestraFiltro);
  // humedadPorcentualFiltro = map(correlacion, 0, 1023, 100, 0);
  humedadPorcentualFiltro = analogToPorcentual(correlacion);

  Serial.print("Humedad MDC: ");
  Serial.println(correlacion);

  delay(5000);
}


// Función para el filtrado
/*
  Recibe como parámetro la humedad medida
*/
float analogToPorcentual(float humedadSensor){
  float humedadPorcentual;
  humedadPorcentual = -100*(humedadSensor-1023)/1023;
  return humedadPorcentual;
}











