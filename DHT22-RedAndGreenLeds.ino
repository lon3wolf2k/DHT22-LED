//Libraries
#include "DHT.h"

//Define Sensor Pins and Type
#define DHTPIN 12     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value

//Define LED pins
const int LED1_Green = 8;
const int LED2_Red = 9;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(LED1_Green, OUTPUT);
  pinMode(LED2_Red, OUTPUT);

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
  
    if (temp > 28) //Check if Temperature is higher than 28c
  {
    digitalWrite(LED1_Green, LOW);
    digitalWrite(LED2_Red, HIGH);
  }
  else
  {
    digitalWrite(LED1_Green, HIGH);
    digitalWrite(LED2_Red, LOW);  }
}
