#include <motor_control.h>
#include <Servo.h>
#include <HC_SR04.h>

#define SERVO_PIN 9
#define TRIG_PIN 10
#define ECHO_PIN 2
#define ECHO_INT 0
#define CENTER 90
#define DESIRED_DISTANCE 30

int x = 200;
Servo actuator;
HC_SR04 dist_sensor(TRIG_PIN, ECHO_PIN, ECHO_INT);
// Current distance to closest object
int distance; 

void setup() {
  Serial.begin(9600);

  //Attach servo to servo pin, and rotate to point sensor forward
  actuator.attach(SERVO_PIN);
  actuator.write(90);

  //Initialize distance sensor and start pinging for distances
  dist_sensor.begin();
  dist_sensor.start();

}

void loop() {
  // Gets distance
  if(dist_sensor.isFinished()) {
    distance = dist_sensor.getRange();
    dist_sensor.start();
  }

  Serial.println(distance);

  // Stops motor if within DESIRED_DISTANCE, otherwise drives
  if(distance <= DESIRED_DISTANCE){
    raw_motor_control(0,0);
  } else {
    raw_motor_control(9*x/8,-x);
  }
}
