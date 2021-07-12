#include "DHT.h"

#define DHTPIN A0     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
int LED_Pin = 13;
int vibr_pin =3;

void setup() {
  Serial.begin(9600);
 
  pinMode(LED_Pin, OUTPUT);
  pinMode(vibr_pin, INPUT); //set vibr_Pin input for measurment
  Serial.begin(9600); //init serial 9600


  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
 

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
   
   
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
   int val;
  val=digitalRead(vibr_pin);
   
  
 Serial.print(" Vibration: ");
  Serial.print(val);
  Serial.print(" Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("C ");
  Serial.print(f);
  Serial.print("F  Heat index: ");
  Serial.print(hic);
  Serial.print("C ");
  Serial.print(hif);
  Serial.println("F");
   delay(500);
  
}
