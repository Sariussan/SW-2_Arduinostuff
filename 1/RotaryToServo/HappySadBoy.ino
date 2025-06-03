// use one of these analog sensors from your Grove Kit
// https://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/
// https://wiki.seeedstudio.com/Grove-Light_Sensor/
// 

// use servo from your Grove Kit
// https://wiki.seeedstudio.com/Grove-Servo/

// servo library
#include <Servo.h>

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = 0; // or A0  // digital input pin that the sensor is attached to
const int servoPin = 7; // digital pin that servor motor is attahced to
const int digitalOutPinSad = 6; // LED light sad
const int digitalOutPinHappy = 8; // LED light happy

int sensorValue = 0;        // value read from sensor
int servoValue = 0;           // value used to drive servo motor
int direction = 0;

Servo servoMotor;  // create servo object to control a servo

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  // for analog input no initialization as an input needed !

  // attaches the servo on servo pin to the servo object
  servoMotor.attach(servoPin);
}

void loop() {

  // read the analog pin
  sensorValue = analogRead(analogInPin);

  // map value (sensor value to servo value)
  // sensor: 0-1023
  if(sensorValue < 130) {
    direction = 1;
    servoValue = 175;
    digitalWrite(digitalOutPinSad, HIGH);
    digitalWrite(digitalOutPinHappy, LOW);
  } else if (sensorValue > 130) {
    direction = 0;
    servoValue = 5;
    digitalWrite(digitalOutPinSad, LOW);
    digitalWrite(digitalOutPinHappy, HIGH);
  }
  // servo: 0-180
  //servoValue = map(sensorValue, 60, 200, 5, 175); // change range for sensor value for different sensors (rotary, light, ...)
  

  // print the results to the Serial Monitor:
  Serial.println(sensorValue); // if you use a rotary angly sensor (potentiometer) you should get values between '0' or '1023'

  // tell servo to go to position
  servoMotor.write(servoValue);


}