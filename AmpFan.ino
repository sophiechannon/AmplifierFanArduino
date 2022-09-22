#include "max6675.h"

int currentTemp;
bool fanStatus = false;
int upperThreshold = 30;
int lowerThreshold = 25;
int overHeatingThreshold = 32;
int fan = 3;
int green = 9;
int amber = 10;
int red = 11;
int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);
  pinMode (fan, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (amber, OUTPUT);
  pinMode (red, OUTPUT);
  delay(500);
}

void loop() {
//  thermal sensor will be connected to A0 input
  Serial.print(thermocouple.readCelsius());
  Serial.println(" c");
  currentTemp = thermocouple.readCelsius(); 
  reactToTemperatureChange();
  delay(1000);
}

void turnOnFan() {
  digitalWrite (fan, HIGH);
  digitalWrite (green, LOW);
  digitalWrite (amber, HIGH);
  digitalWrite (red, LOW);
  fanStatus = true;
}

void turnOffFan() {
  digitalWrite (fan, LOW);
  digitalWrite (green, HIGH);
  digitalWrite (amber, LOW);
  digitalWrite (red, LOW);
  fanStatus = false;
}

void overHeatAction() {
  digitalWrite (fan, HIGH);
  digitalWrite (green, LOW);
  digitalWrite (amber, LOW);
  digitalWrite (red, HIGH);
  fanStatus = true;
}

void reactToTemperatureChange() {
  if (currentTemp >= overHeatingThreshold) {
    overHeatAction();
  } else if (currentTemp >= upperThreshold) {
      turnOnFan();
  } else if (currentTemp <= lowerThreshold) {
      turnOffFan();
  } else if ((currentTemp <= upperThreshold) && fanStatus) {
      turnOnFan();
  } else {
     turnOffFan();
  }
}
