//My IP address: 192.168.0.5.

#include <SPI.h>
#include <Ethernet.h>

//mac address of ethernet shield
byte mac[] = {
  0x90, 0x9A2, 0xDA, 0x0E, 0xF7, 0x35};

//ip addresss of ethernet shield that i set
IPAddress ip(192, 168, 0, 5);


//server port number that you set
int port = 3000;

int ledPin = 9;
boolean LED_ON = false;

//String Buffer for receive request String
String buffer;
EthernetServer server(80);

void setup() {
  Serial.begin(9600);
  Serial.println("Serial is Set");

  //Begin Server(Ethernet Shield)
  Ethernet.begin(mac, ip);
  Serial.println("Ethernet began");
  server.begin();

  //Check Server IP
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());

  pinMode(ledPin, OUTPUT);
}

void loop() {
  //Client = available client(browser);
  EthernetClient client = server.available();

  //if there is available client
  if (client) {
    Serial.println("new Client");

    //init buffer
    buffer = String("");
    boolean currentLineIsBlank = true;

    while(client.connected()) {
      //if there is something to read in stream
      if (client.available()) {
        char c = client.read();
        buffer.concat(c);

        if (c == '\n' && currentLineIsBlank) {
          if (buffer.indexOf("GET /L=0") > -1) {
            LED_ON = false;
            digitalWrite(ledPin, LOW); 
          }

          if (buffer.indexOf("GET /L=1") > -1) {
            LED_ON = true;
            digitalWrite(ledPin, HIGH); 
          }

          //send HTML page for response
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close\n");
          client.println("<!DOCTYPE HTML>\n");
          client.println("<html>");
          client.println("<body>");
          client.print("LED is");
          (LED_ON) ? client.print("ON") : client.print("OFF");
          client.println("<br>");
          client.print("Make it");
          client.println("<br>");
          (LED_ON) ? client.print("<a href='L=0'>OFF</a>") : client.print("<a href='L=1'>ON</a>");
          client.println("<br>");
          client.println("</body>");
          client.println("</html>");

          //break while loop
          break;
        }

        //some process for checking end of request string
        if (c =='\n') {
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          currentLineIsBlank = false; 
        }
      }
    }
    delay(1);
    client.stop();
    Serial.println("client disconnected"); 
  }
}

