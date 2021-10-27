#include <PIDController.h>
//#include "PinChangeInterrupt.h"
#include <Servo.h>

volatile long int encoder1_pos = 0;


PIDController pos1_pid;



int motor1_value = 255;


int b1 = A0;
int b2 = A1;


int p1=0;


int pos = 50;



void setup() {

  Serial.begin(115200);

  


  //m1
  pinMode(10, INPUT);
  pinMode(4, INPUT);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  

  attachInterrupt(10, encoder1, RISING);



  pos1_pid.begin(); 


   
  pos1_pid.tune(100, 0, 3000);

  
  pos1_pid.limit(-255, 255);

}

void loop(){

    move(*m1, 500, 0, p1);
        
 }
 

void encoder1(){
  if(digitalRead(4) == LOW){
    encoder1_pos++;
  }else{
    encoder1_pos--;
  }
}




void m1(){
  motor1_value = pos1_pid.compute(encoder1_pos);
  pos1_pid.setpoint(p1);
  if(motor1_value > 0){
           if(motor1_value > 5){
              analogWrite(49,motor1_value);
              digitalWrite(48, LOW);
        
          }else{
              digitalWrite(48, LOW);
              digitalWrite(49, LOW);
        
          }
  }else{
    
          if(abs(motor1_value) > 5){
            analogWrite(48, abs(motor1_value));
            digitalWrite(49, LOW);
      
          }else{
            digitalWrite(48, LOW);
            digitalWrite(49, LOW);
          }
      }
  
}


void move(void (*motor), int dist, int timee, int add){
      for(int i = 0; i<dist;i++){    
                  motor;
                  add++;
                  delay(timee);  
                  }           
  
}



void read1(){

 //Serial.println(millis()/60);

            Serial.println(" ");
//            Serial.print("e = ");
//            Serial.print(encoder1_pos);
//            Serial.print("  ");
//            Serial.print("m = ");
//            Serial.print(motor1_value);
//            Serial.print("  ");
            
//            Serial.print("e1 = ");
//            Serial.print(encoder1_pos);
//            Serial.print("  ");
//            Serial.print("m1 = ");
//            Serial.print(motor1_value);
//            Serial.print("  ");
//
//            Serial.print("e2 = ");
//            Serial.print(encoder2_pos);
//            Serial.print("  ");
//            Serial.print("m2 = ");
//            Serial.print(motor2_value);
//            Serial.print("  ");
//
//            Serial.print("e3 = ");
//            Serial.print(encoder3_pos);
//            Serial.print("  ");
//            Serial.print("m3 = ");
//            Serial.print(motor3_value);
//            Serial.print("  ");

            
//            Serial.print("e4 = ");
//            Serial.print(encoder4_pos);
//            Serial.print("  ");
//            Serial.print("m4 = ");
//            Serial.print(motor4_value);
//            Serial.print("  ");
//
//            
//            Serial.print("e5 = ");
//            Serial.print(encoder5_pos);
//            Serial.print("  ");
//            Serial.print("m5 = ");
//            Serial.print(motor5_value);
//            Serial.print("  ");


}
