#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>

WiFiClient client;
HTTPClient http;

#define DHT11PIN 19 //Tenpertaure sensor 
#define DO_PIN 23 // Flame sensor
//#define fire 16
#define GREEN 4 // Green led
#define RED 2 // Red led
#define buzzer 32 // buzzer
#define AO_PIN 34 // MQ2
DHT dht(DHT11PIN, DHT11);
int fire_Val = 0;

const char* ssid = "iPhoneeee"; // Replace with your WiFi SSID
const char* password = "tunde102"; // Replace with your WiFi password
//////////harris for thingspeak log-in/////////////////
String url;
String API = "TGYGC49LPOSOSF87";
String FieldNo = "1";

String url1;
String API1 = "TGYGC49LPOSOSF87";
String FieldNo2 = "2";

HardwareSerial mySerial(1); // You can use Serial1 or Serial2

void setup()
{
  Serial.begin(115200);
  delay(10);

  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  pinMode(DO_PIN, INPUT);
  pinMode(AO_PIN, INPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  //Serial2.begin(115200);
  // delay(3000);
  //test_sim800_module();
  //  send_SMS();
}

void loop()
{
  updateSerial();
  int flame_state = digitalRead(DO_PIN);
  int gasValue = analogRead(AO_PIN);
  if (flame_state == HIGH) {
    flame1();
  }
  else {
    flame2();
  }


  Serial.print("MQ2 sensor value: ");
  Serial.println(gasValue);
  float h = dht.readHumidity(); // Read humidity
  float t = dht.readTemperature(); // Read temperature in Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  url = "http://api.thingspeak.com/update?api_key=";
  url += API;
  url += "&field" + FieldNo;
  url += "=";
  url += t;

  url1 = "http://api.thingspeak.com/update?api_key=";
  url1 += API1;
  url1 += "&field" + FieldNo2;
  url1 += "=";
  url1 += gasValue;

  http.begin(client, url);
  Serial.println("waiting for response");
  int httpcode = http.GET();
  if (httpcode > 0) {
    Serial.println(h);
    Serial.println("-data sent successfully");
  } else {
    Serial.println("Error sending data");
  }
  http.end();
  delay(300);

  http.begin(client, url1);
  Serial.println("waiting for response");
  int httpcode1 = http.GET();
  if (httpcode1 > 0) {
    Serial.println(t);
    Serial.println("-data sent successfully");
  } else {
    Serial.println("Error sending data");
  }
  http.end();
  delay(300);

  Serial.print("Temperature: ");
  Serial.print(t);
  delay(1000);
  Serial.print("ºC ");
  Serial.print("Humidity: ");
  Serial.println(h);
  delay(1000);
}



void flame1() {
  Serial.println("The fire is NOT detected");
  //delay(1000);
  digitalWrite(GREEN, HIGH);
  digitalWrite(RED, LOW);
  //delay(200);

}

void flame2() {
  Serial.println("The fire is detected");
  digitalWrite(RED, HIGH);
  //delay(6000);
  digitalWrite(GREEN, LOW);
  buzzer_sound();
  // send_SMS();
  call_fire();

}

void buzzer_sound() {
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  delay(200);
}
////////////////////////////
/*void mySensor()
  {
  fire_Val = digitalRead(fire);
  if (fire_Val == LOW)
  {
    Blynk.logEvent("fire_alert");
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
    digitalWrite(buzzer, HIGH);
    //Blynk.virtualWrite(V0, 1);
    Serial.print("fIRE Level: ");
    Serial.println(fire_Val);
    led.on();
  }
  else
  {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    digitalWrite(buzzer, LOW);
    //Blynk.virtualWrite(V0, 0);
    Serial.print("fIRE Level: ");
    Serial.println(fire_Val);
    led.off();
  }
  }

*/

void test_sim800_module()
{
  Serial2.println("AT");
  updateSerial();
  Serial.println();
  Serial2.println("AT+CSQ");
  updateSerial();
  Serial2.println("AT+CCID");
  updateSerial();
  Serial2.println("AT+CREG?");
  updateSerial();
  Serial2.println("ATI");
  updateSerial();
  Serial2.println("AT+CBC");
  updateSerial();
}


void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    Serial2.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (Serial2.available())
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
  }
}


void send_SMS()
{
  Serial2.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  Serial2.println("AT+CMGS=\"+2348052452379\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  Serial2.print("FIRE DETECTED, CALL THE FIRE SERVICE!!!"); //text content
  updateSerial();
  Serial.println();
  Serial.println("Message Sent");
  Serial2.write(26);
}

void call_fire()
{
  //Begin serial communication with Arduino IDE (Serial Monitor)
  Serial2.begin(115200);

  //Begin serial communication with ESP32 and SIM800L
  mySerial.begin(9600, SERIAL_8N1, 16, 17); // Change GPIO 16, 17 to the pins you are using for Rx, Tx

  Serial2.println("Initializing...");
  delay(1000);

  mySerial.println("AT"); // Once the handshake test is successful, it will respond with OK
  updateSerial();

  mySerial.println("ATD+2348052452379;"); // Dialing the Nigerian number
  // Change ZZ with country code and xxxxxxxxxxx with phone number to dial
  updateSerial();

  delay(20000); // Wait for 20 seconds...

  mySerial.println("ATH"); // Hang up
  updateSerial();
}
