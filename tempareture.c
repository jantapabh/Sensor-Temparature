#include "DHT.h"

 

#define DHTPIN 2

#define DHTTYPE DHT11

 

DHT dht(DHTPIN, DHTTYPE);

 

void setup() {

   Serial.begin(9600); 

   Serial.println("DHTxx test!");

 

   dht.begin();

}

 

void loop() {

   float h = dht.readHumidity();

   float t = dht.readTemperature();

   float f = dht.readTemperature(true);

 

   if (isnan(h) || isnan(t) || isnan(f)) {

     Serial.println("Failed to read from DHT sensor!");

      return;

   }

 

   float hi = dht.computeHeatIndex(f, h);

 

   Serial.print("Humidity: "); 

   Serial.print(h);

   Serial.print(" %\t");

   Serial.print("Temperature: "); 

   Serial.print(t);

   Serial.print(" *C ");

   Serial.print(f);

   Serial.print(" *F\t");

   Serial.print("Heat index: ");

   Serial.print(hi);

   Serial.println(" *F");

  

   delay(2000);

}