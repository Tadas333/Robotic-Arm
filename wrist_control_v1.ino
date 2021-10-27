//
//#include <Servo.h>
//
//Servo myservo;  // create servo object to control a servo
//// twelve servo objects can be created on most boards
//
//int pos = 0;    // variable to store the servo position
//
//void setup() {
//  Serial.begin(115200);
//  myservo.attach(29);  // attaches the servo on pin 9 to the servo object
//}
//
//void loop() {
// // goes from 0 degrees to 180 degrees
//   myservo.write(60);
//   delay(2000); 
//   Serial.println("no loop");
//for(int i = 0;i<3;i++){
//
//    myservo.write(-200);              // tell servo to go to position in variable 'pos'
//    delay(1000);    
//    Serial.println("loop");// waits 15ms for the servo to reach the position
//
//
//    //myservo.write(200);              // tell servo to go to position in variable 'pos'
//    //delay(1000);    
//     
//}
//
//}

#include <Servo.h>

Servo myservo;
Servo myservo1;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 50;    // variable to store the servo position

void setup() {
  myservo.attach(29);
  myservo1.attach(28);// attaches the servo on pin 9 to the servo object
}

//void loop() {
//  for (pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);
//    myservo1.write(pos); // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 0; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);
//    myservo1.write(pos); // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  
//}

void loop() {
  for (pos = 0; pos <= 20; pos++) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);
    myservo1.write(pos); // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 20; pos > 0; pos--) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);
    myservo1.write(pos); // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15ms for the servo to reach the position
  }
  
}
