#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLguNuseYP"
#define BLYNK_DEVICE_NAME "dht11project"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           // including the library of DHT11 temperature and humidity sensor

#define DHTTYPE DHT11      // DHT 11

#define dht_dpin D4
DHT dht(dht_dpin, DHTTYPE); 


char auth[] = "EmozZT2uvSeOb0tPuQ16f5UP3_pgWIhe";            // You should get Auth Token in the Blynk App.
char ssid[] = "Anjay";    // Your WiFi credentials.
char pass[] = "kepobangetluh";  // Set password to "" for open networks.
float t;                                   // Declare the variables 
float h;


void setup()
{
    Serial.begin(9600);// Debug console
    Blynk.begin(auth, ssid, pass);
    dht.begin();
}

void sendUptime()
{
  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  
}

void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 
  if (isnan(h) || isnan(t))
  {
    Serial.println("Failed to read from DHT Sensor!!");
    return;
  }
  Blynk.run();
  delay(1000);
}