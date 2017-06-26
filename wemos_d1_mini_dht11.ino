//Ejemplo de uso DHT11 con wemos D1 mini
//Libraries
#include <DHT.h>;
#include <ESP8266WiFi.h>
#include <CayenneMQTTESP8266.h>;

//Constants
#define CAYENNE_PRINT Serial
#define DHTPIN D4         // * pin usado DHT11 en wemos D1 mini shield
#define DHTTYPE DHT11      // o DHT22
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT sensor for normal 16mhz Arduino

// WiFi network info.
char ssid[] = "ssid";    
char wifiPassword[] = "pass"; 

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "MQTT Usernane";
char password[] = "MQTT Password";
char clientID[] = "Client ID";

unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  dht.begin();
}

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void loop(){
    Cayenne.loop();
    delay(2000);
    //Read data and store it to variables hum and temp
    hum = dht.readHumidity();
    temp= dht.readTemperature();
    Cayenne.celsiusWrite(2, temp);
    Cayenne.virtualWrite(1, hum);
}