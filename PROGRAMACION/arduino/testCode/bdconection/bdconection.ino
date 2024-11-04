#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

byte mac_addr[] = { 0x74, 0xD4, 0x35, 0x55, 0xC2, 0x2F };

IPAddress server_addr(127, 0, 0, 1);  // IP of the MySQL server
char user[] = "root";                 // MySQL user login username
char password[] = "Admin%123456";  

EthernetClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
  
  Serial.begin(9600);
  while (!Serial); // wait for serial port to connect
  Ethernet.begin(mac_addr);
  
  Serial.println(Ethernet.localIP());
  Serial.println(Ethernet.begin(mac_addr));

  Serial.println("Connecting...");

  if(client.connect(server_addr, 5050)){
    Serial.println("Conexión realizada con éxito");
  }else{
    Serial.println("Fallo en la conexión");
  }

  // if (conn.connect(server_addr, 3306, user, password)) {
  //   Serial.println("Conectado a MySQL");
  //   Serial.println(conn.version()); 
  //   // Aquí puedes ejecutar tus consultas
  // } else {
  //   Serial.println("Error al conectar a MySQL");
  //   int error_code = conn.connected(); 
  //   conn.show_error(error_code);
  // }
  // conn.close();

}

void loop() {
  // put your main code here, to run repeatedly:

}