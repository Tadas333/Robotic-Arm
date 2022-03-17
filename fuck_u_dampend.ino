#include <PIDController.h>
#include "PinChangeInterrupt.h"
#include <Servo.h>


volatile long int encoder33_pos = 0;


PIDController pos33_pid;


int motor33_value = 255;


int p33 = 0;
int pos = 50;
int cont = 0;

int val = 0;
int damp = 0;
int dir = 0;

void setup() {

  Serial.begin(115200);
  //Serial.begin(2000000);
  //Serial.begin(9600);

  


  pinMode(10, INPUT);
  pinMode(11, INPUT);


  pinMode(A0, INPUT);
  //m33
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  



  attachInterrupt(digitalPinToInterrupt(3), encoder33, RISING);


  pos33_pid.begin(); 
  pos33_pid.tune(30, 0, 200);
  pos33_pid.limit(-255, 255);

}
//
// MAIN
//
//
//
//
//
//
//
void loop(){


  read1();
  //allM();
  Serial.print("bbbbb ");
  allM();

  if(digitalRead(A0) == HIGH){

          motor(val = 500, damp = 20, p33, dir = 0);
          delay(5);
          motor(val = 500, damp = 20, p33, dir = 1);
      
          read1();
          Serial.print("aaaaa ");
      
  
     }
  

}


//
//
//
//
//
//




void encoder33(){
  if(digitalRead(2) == LOW){
    encoder33_pos++;
  }else{
    encoder33_pos--;
  }
}








void m33(){
  motor33_value = pos33_pid.compute(encoder33_pos);
  pos33_pid.setpoint(p33);
  if(motor33_value > 0){
           if(motor33_value > 5){
              analogWrite(8, motor33_value);
              digitalWrite(9, LOW);
        
          }else{
              digitalWrite(9, LOW);
              digitalWrite(8, LOW);
        
          }
  }else{
    
          if(abs(motor33_value) > 5){
            analogWrite(9, abs(motor33_value));
            digitalWrite(8, LOW);
      
          }else{
            digitalWrite(9, LOW);
            digitalWrite(8, LOW);
          }
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
            Serial.print("e3 = ");
            Serial.print(encoder33_pos);
            Serial.print("  ");
            Serial.print("m33 = ");
            Serial.print(motor33_value);
            Serial.print("  ");
            Serial.print("p33 = ");
            Serial.print(p33);
            Serial.print("  ");


            
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

//            Serial.print("e11 = ");
//            Serial.print(encoder11_pos);
//            Serial.print("  ");
//            Serial.print("m11 = ");
//            Serial.print(motor11_value);
//            Serial.print("  ");
//            Serial.print("p11 = ");
//            Serial.print(p11);
//            Serial.print("  ");
}



void m33test(){

          motor(val = 400, damp = 0, p33, dir = 0);
          //delay(5);
          motor(val = 400, damp = 0, p33, dir = 1);
          
  
}
void allM(){
     
              m33(); 

}

//void motor(val,damp,int& p){
void motor(int& val, int& damp, int& p, int& dir){
          for(int i = 0; i<(val*0.05);i++){
           
                      //p33++;
                      if(dir == 0){
                       p++; 
                          }
                      if(dir == 1){
                       p--; 
                          }
                      //p++; 
                      allM();
                      read1(); 
                      delay(damp);
                      //damp--;

          }
          for(int i = 0; i<(val*0.05);i++){
           
                     // p33++; 
                      if(dir == 0){
                       p++; 
                          }
                      if(dir == 1){
                       p--; 
                          }
                      //p++;
                      allM();
                      read1(); 
                      delay(damp/2);
                      //damp++;

          }
          for(int i = 0; i<(val*0.8);i++){
           
                      //p33++; 
                      //p++;
                      if(dir == 0){
                       p++; 
                          }
                      if(dir == 1){
                       p--; 
                          }
                      allM();
                      read1(); 
                      delay(0);

          }
          for(int i = 0; i<(val*0.05);i++){
           
                     // p33++; 
                      if(dir == 0){
                       p++; 
                          }
                      if(dir == 1){
                       p--; 
                          }
                      //p++;
                      allM();
                      read1(); 
                      delay(damp/2);
                      //damp++;

          }
          for(int i = 0; i<(val*0.05);i++){
           
                     // p33++; 
                      if(dir == 0){
                       p++; 
                          }
                      if(dir == 1){
                       p--; 
                          }
                      //p++;
                      allM();
                      read1(); 
                      delay(damp);
                      //damp++;

          }

  
}
