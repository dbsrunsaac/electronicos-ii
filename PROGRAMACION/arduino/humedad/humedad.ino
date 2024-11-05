// CONSTANTES
const float TIEMPO_MUESTREO = 1;

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
  Serial.println(humedadPorcentual);

  // Sensando mediante el algoritmo de muestreo doble correlacionado
  humedadFiltro = analogRead(A1); // Salida en bits
  delayMicroseconds(TIEMPO_MUESTREO);
  muestraFiltro = analogRead(A1);
  
  // Filtrado de la señale
  correlacion = humedadFiltro - abs(humedadFiltro - muestraFiltro);
  humedadPorcentualFiltro = map(correlacion, 0, 1023, 100, 0);

  Serial.print("Humedad MDC: ");
  Serial.println(humedadPorcentualFiltro);

  delay(3000);
}


// Función para el filtrado
/*
  Recibe como parámetro la humedad medida
*/
float analogToPorcentual(float humedadSensor){
  float humedadPorcentual;
  // return humedadPorcentual = 100*humedadSensor/1023;
}











