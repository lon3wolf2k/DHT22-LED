//Libraries
#include "DHT.h"

//Define Sensor Pins and Type
#define DHTPIN 12     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

//Define LED pins
const int LED1_Pin = 8;
const int LED2_Pin = 9;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED1_Pin, OUTPUT);
  pinMode(LED2_Pin, OUTPUT);

}

void loop() {

  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(5000); //Delay 5 sec.
    if (temp > 28)
  {
    digitalWrite(LED1_Pin, LOW);
    digitalWrite(LED2_Pin, HIGH);
  }
  else
  {
    digitalWrite(LED1_Pin, HIGH);
    digitalWrite(LED2_Pin, LOW);  }
}
