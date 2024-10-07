#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

// byte mac_addr[] = { 0xBC, 0x6E, 0x93, 0x47, 0xB2, 0x6E };
byte mac_addr[] = { 0x74, 0xD4, 0x35, 0x55, 0xC2, 0x2F };

IPAddress server_addr(127, 0, 0, 1);  // IP of the MySQL server
char user[] = "root";                 // MySQL user login username
char password[] = "Admin%123456";             // MySQL user login password

// Sample query
char INSERT_DATA[] = "INSERT INTO bdhumedad.humedad_humedad (humedad_bits, humedad_analog) VALUES ('%s',%d)";

char query[128];
char humedad[10];
char humedad_b[10];
float humedad_bits;
float humedad_analog;

EthernetClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect
  Ethernet.begin(mac_addr);
  Serial.println("Connecting...");
  if (conn.connect(server_addr, 8000, user, password)) {
    delay(1000);
    
    // Initiate the query class instance
    MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

    // Save
    // dtostrf(50.125, 1, 1, humedad);
    // sprintf(query, INSERT_DATA, "Test sensor", 24, humedad);
    
    // Execute the query
    cur_mem->execute(query);

    // Note: since there are no results, we do not need to read any data
    // Deleting the cursor also frees up memory used
    delete cur_mem;

    Serial.println("Data recorded.");
  }
  else {
    Serial.println("Connection failed.");
  }
  conn.close();
}

void loop() {
  // 
  humedad_bits = analogRead(A0);
  humedad_analog = map(humedad_bits, 0, 1023, 0, 100);
  Serial.print("Humedad del Suelo: ");
  Serial.print(humedad_bits);
  // Serial.print(" - ");
  // Serial.print("Porcentaje de humedad: ");
  Serial.println(humedad_analog);
  delay(5000);

  // Initiate the query class instance
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);

  // Save
  dtostrf(humedad_analog, 1, 1, humedad);
  dtostrf(humedad_bits, 1, 1, humedad_b);
  sprintf(query, INSERT_DATA, humedad, humedad_b);

  // Execute the query
  cur_mem->execute(query);

  // Note: since there are no results, we do not need to read any data
  // Deleting the cursor also frees up memory used
  delete cur_mem;
}
