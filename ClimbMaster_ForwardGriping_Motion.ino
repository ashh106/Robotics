#include <Servo.h>

Servo lower_servo; // Servo object for motor connected to pin 9
Servo upper_servo; // Servo object for motor connected to pin 10

const int lower_servoPin = 9; // Pin for servo motor 1
const int upper_servoPin = 10; // Pin for servo motor 2

void setup() {
  lower_servo.attach(lower_servoPin); // Attaching lower_servo object to pin 9
  upper_servo.attach(upper_servoPin); // Attaching upper_servo object to pin 10
  lower_servo.write(85);
}
void loop() {
  upper_servo.write(90);
  delay(1000);
  lower_servo.write(80);
  delay(1000);
  upper_servo.write(0);
  delay(1000);
  lower_servo.write(45);
  delay(1000);
}
