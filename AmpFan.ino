// hardcoded without hardware
int currentTemp = 59;
bool fanStatus = false;
int upperThreshold = 60;
int lowerThreshold = 40;
int overHeatingThreshold = 70;
int fan = 5;
int green = 9;
int amber = 10;
int red = 11;

void setup() {
  pinMode (fan, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (amber, OUTPUT);
  pinMode (red, OUTPUT);
}

void loop() {
//  thermal sensor will be connected to A0 input
//  Serial.println(analogRead(A0));
//  currentTemp = analogRead(A0); 
  reactToTemperatureChange();
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
