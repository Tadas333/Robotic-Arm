#include <PIDController.h>
//#include "PinChangeInterrupt.h"
#include <Servo.h>
#include <LiquidCrystal.h>

Servo myservo;
Servo myservo1;
volatile long int encoder1_pos = 0;
volatile long int encoder2_pos = 0;
volatile long int encoder3_pos = 0;
volatile long int encoder4_pos = 0;
volatile long int encoder5_pos = 0;
volatile long int encoder6_pos = 0;
volatile long int encoder7_pos = 0;
volatile long int encoder8_pos = 0;
volatile long int encoder9_pos = 0;
volatile long int encoder10_pos = 0;

volatile long int encoder11_pos = 0;
volatile long int encoder22_pos = 0;
volatile long int encoder33_pos = 0;

PIDController pos1_pid;
PIDController pos2_pid; 
PIDController pos3_pid; 
PIDController pos4_pid;
PIDController pos5_pid; 
PIDController pos6_pid;
PIDController pos7_pid;
PIDController pos8_pid;
PIDController pos9_pid;
PIDController pos10_pid;

PIDController pos11_pid;
PIDController pos22_pid;
PIDController pos33_pid;


int motor1_value = 255;
int motor2_value = 255;
int motor3_value = 255;
int motor4_value = 255;
int motor5_value = 255;
int motor6_value = 255;
int motor7_value = 255;
int motor8_value = 255;
int motor9_value = 255;
int motor10_value = 255;

int motor11_value = 255;
int motor22_value = 255;
int motor33_value = 255;

int b1 = A0;
int b2 = A1;


int p1=0;
int p2=0;
int p3=0;
int p4=0;
int p5=0;
int p6=0;
int p7=0;
int p8=0;
int p9=0;
int p10=0;

int p11=0;
int p22=0;
int p33=0;

int pos = 50;

int cont = 0;

LiquidCrystal lcd = LiquidCrystal(A2, A3, A4, A5, A6, A7);



void setup() {

  //Serial.begin(115200);
  Serial.begin(2000000);
  //Serial.begin(9600);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  //pinMode(12, OUTPUT);
  //pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  
  myservo.attach(29);
  myservo1.attach(28);

  myservo.write(0);  
  myservo1.write(0);


  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);

  //m1
  pinMode(10, INPUT);
  pinMode(4, INPUT);
  pinMode(49, OUTPUT);
  pinMode(48, OUTPUT);
  
  //m2
  pinMode(11, INPUT);
  pinMode(5, INPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);

  //m3
  pinMode(A9, INPUT);
  pinMode(6, INPUT);
  pinMode(45, OUTPUT);
  pinMode(44, OUTPUT);
  
  //m4
  pinMode(A8, INPUT);
  pinMode(7, INPUT);
  pinMode(43, OUTPUT);
  pinMode(42, OUTPUT);

  //m5
  pinMode(50, INPUT);
  pinMode(8, INPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);

  //m6
  pinMode(51, INPUT);
  pinMode(9, INPUT);
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);

  //m7
  pinMode(52, INPUT);
  pinMode(17, INPUT);
  pinMode(37, OUTPUT);
  pinMode(36, OUTPUT);

  //m8
  pinMode(53, INPUT);
  pinMode(16, INPUT);
  pinMode(35, OUTPUT);
  pinMode(34, OUTPUT);

  //m9
  pinMode(20, INPUT);
  pinMode(15, INPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);

  //m10
  pinMode(21, INPUT);
  pinMode(14, INPUT);
  pinMode(31, OUTPUT);
  pinMode(30, OUTPUT);

  //m11
  pinMode(2, INPUT);
  pinMode(A10, INPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);

  //m22
  pinMode(3, INPUT);
  pinMode(A11, INPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);

  //m33
  pinMode(DAC0, INPUT);
  pinMode(18, INPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);


  //attachInterrupt(digitalPinToInterrupt(10), encoder, RISING);
  attachInterrupt(10, encoder1, RISING);
  attachInterrupt(11, encoder2, RISING);
  attachInterrupt(digitalPinToInterrupt(A9), encoder3, RISING);
  attachInterrupt(digitalPinToInterrupt(A8), encoder4, RISING);
  attachInterrupt(50, encoder5, RISING);
  attachInterrupt(51, encoder6, RISING);
  attachInterrupt(52, encoder7, RISING);
  attachInterrupt(53, encoder8, RISING);
  attachInterrupt(digitalPinToInterrupt(20), encoder9, RISING);
  attachInterrupt(digitalPinToInterrupt(21), encoder10, RISING);
  attachInterrupt(digitalPinToInterrupt(2), encoder11, RISING);
  attachInterrupt(digitalPinToInterrupt(3), encoder22, RISING);
  attachInterrupt(digitalPinToInterrupt(18), encoder33, RISING);


  pos1_pid.begin(); 
  pos2_pid.begin();   
  pos3_pid.begin();  
  pos4_pid.begin();  
  pos5_pid.begin();  
  pos6_pid.begin(); 
  pos7_pid.begin(); 
  pos8_pid.begin(); 
  pos9_pid.begin(); 
  pos10_pid.begin();

  pos11_pid.begin(); 
  pos22_pid.begin(); 
  pos33_pid.begin(); 

   
  pos1_pid.tune(100, 0, 3000);
  pos2_pid.tune(100, 0, 3000);
  pos3_pid.tune(100, 0, 3000);
  pos4_pid.tune(100, 0, 3000);
  pos5_pid.tune(100, 0, 3000);
  pos6_pid.tune(100, 0, 3000);
  pos7_pid.tune(100, 0, 3000);
  pos8_pid.tune(100, 0, 3000);
  pos9_pid.tune(100, 0, 3000);
  pos10_pid.tune(100, 0, 3000);

  pos11_pid.tune(30, 0, 200);
  pos22_pid.tune(30, 0, 200);
  pos33_pid.tune(30, 0, 200);

  
  pos1_pid.limit(-255, 255);
  pos2_pid.limit(-255, 255);
  pos3_pid.limit(-255, 255);
  pos4_pid.limit(-255, 255);
  pos5_pid.limit(-255, 255);
  pos6_pid.limit(-255, 255);
  pos7_pid.limit(-255, 255);
  pos8_pid.limit(-255, 255);
  pos9_pid.limit(-255, 255);
  pos10_pid.limit(-255, 255);

  pos11_pid.limit(-255, 255);
  pos22_pid.limit(-255, 255);
  pos33_pid.limit(-255, 255);

  lcd.setCursor(2, 0);  
  lcd.print("Im Alive?");

  
  
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


digitalWrite(13, LOW);
digitalWrite(12, LOW);

allM();
Serial.println(cont);

if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);

    
}

if(digitalRead(b1) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);

    cont += 1;

    

//    lcd.setCursor(0, 0);  
//    lcd.print("                ");
//    lcd.setCursor(0, 1);  
//    lcd.print("                ");
//    
//    lcd.setCursor(0, 0);  
//    lcd.print("-");
//    
//    lcd.setCursor(1, 0);  
//    lcd.print("test fingers");
    //fucku();
    //m11test();
    //m22test();
    //m33test();
    //fingers();
    //m11test();
  }        

if(cont <20 & cont>1){

    lcd.setCursor(0, 0);  
    lcd.print("                ");
    lcd.setCursor(0, 1);  
    lcd.print("                ");
    
    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("test fingers");
    
    lcd.setCursor(1, 1);  
    lcd.print("test M11");

    if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);
    fingers();
    
    }

     


  
}

if(cont <40 & cont>20){

    
    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("test M11       ");

    lcd.setCursor(1, 1);  
    lcd.print("test M22       ");

    if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);
    m11test();
    
    }


  


}

if(cont <60 & cont>40){

    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("test M22       ");

    lcd.setCursor(1, 1);  
    lcd.print("test M33       ");

    if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);
    m22test();
    
    }


  
}

if(cont <80 & cont>60){

    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("test M33       ");

    lcd.setCursor(1, 1);  
    lcd.print("Fuck U         ");

    if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);
    m33test();
    
    }


  
}

if(cont <100 & cont>80){

    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("Fuck U         ");

    lcd.setCursor(1, 1);  
    lcd.print("bicept flex    ");

    if(digitalRead(b2) == HIGH){
      digitalWrite(13, HIGH); 
      digitalWrite(12, HIGH);
      fucku();
    
    }
}

if(cont <120 & cont>100){

    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("bicept flex    ");

    lcd.setCursor(1, 1);  
    lcd.print("gun            ");
    
    if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);
    biceptflex();
    
    }
    
  }

if(cont <140 & cont>120){

    lcd.setCursor(0, 0);  
    lcd.print("-");
    
    lcd.setCursor(1, 0);  
    lcd.print("gun            ");

    lcd.setCursor(1, 1);  
    lcd.print("               ");
    
    if(digitalRead(b2) == HIGH){
    digitalWrite(13, HIGH); 
    digitalWrite(12, HIGH);
    gun();
    
    }
    
  }

if(cont>140){

  cont = 1;
}


  



}


//
//
//
//
//
//


void encoder1(){
  if(digitalRead(4) == HIGH){
    encoder1_pos++;
  }else{
    encoder1_pos--;
  }
}

void encoder2(){
  if(digitalRead(5) == HIGH){
    encoder2_pos++;
  }else{
    encoder2_pos--;
  }
}

void encoder3(){
  if(digitalRead(6) == LOW){
    encoder3_pos++;
  }else{
    encoder3_pos--;
  }
}

void encoder4(){
  if(digitalRead(7) == LOW){
    encoder4_pos++;
  }else{
    encoder4_pos--;
  }
}

void encoder5(){
  if(digitalRead(8) == HIGH){
    encoder5_pos++;
  }else{
    encoder5_pos--;
  }
}

void encoder6(){
  if(digitalRead(9) == HIGH){
    encoder6_pos++;
  }else{
    encoder6_pos--;
  }
}

void encoder7(){
  if(digitalRead(17) == LOW){
    encoder7_pos++;
  }else{
    encoder7_pos--;
  }
}

void encoder8(){
  if(digitalRead(16) == HIGH){
    encoder8_pos++;
  }else{
    encoder8_pos--;
  }
}

void encoder9(){
  if(digitalRead(15) == HIGH){
    encoder9_pos++;
  }else{
    encoder9_pos--;
  }
}

void encoder10(){
  if(digitalRead(14) == HIGH){
    encoder10_pos++;
  }else{
    encoder10_pos--;
  }
}

void encoder11(){
  if(digitalRead(A10) == LOW){
    encoder11_pos++;
  }else{
    encoder11_pos--;
  }
}

void encoder22(){
  if(digitalRead(A11) == HIGH){
    encoder22_pos++;
  }else{
    encoder22_pos--;
  }
}

void encoder33(){
  if(digitalRead(DAC0) == LOW){
    encoder33_pos++;
  }else{
    encoder33_pos--;
  }
}






void m1(){
  motor1_value = pos1_pid.compute(encoder1_pos);
  pos1_pid.setpoint(p1);
  if(motor1_value > 0){
           if(motor1_value > 5){
              analogWrite(48,motor1_value);
              digitalWrite(49, LOW);
        
          }else{
              digitalWrite(49, LOW);
              digitalWrite(48, LOW);
        
          }
  }else{
    
          if(abs(motor1_value) > 5){
            analogWrite(49, abs(motor1_value));
            digitalWrite(48, LOW);
      
          }else{
            digitalWrite(49, LOW);
            digitalWrite(48, LOW);
          }
      }
  
}

void m2(){
  motor2_value = pos2_pid.compute(encoder2_pos);
  pos2_pid.setpoint(p2);
  if(motor2_value > 0){
           if(motor2_value > 5){
              analogWrite(46, motor2_value);
              digitalWrite(47, LOW);
        
          }else{
              digitalWrite(47, LOW);
              digitalWrite(46, LOW);
        
          }
  }else{
    
          if(abs(motor2_value) > 5){
            analogWrite(47, abs(motor2_value));
            digitalWrite(46, LOW);
      
          }else{
            digitalWrite(47, LOW);
            digitalWrite(46, LOW);
          }
      }

  
}

void m3(){
  motor3_value = pos3_pid.compute(encoder3_pos);
  pos3_pid.setpoint(p3);
  if(motor3_value > 0){
           if(motor3_value > 5){
              analogWrite(45, motor3_value);
              digitalWrite(44, LOW);
        
          }else{
              digitalWrite(44, LOW);
              digitalWrite(45, LOW);
        
          }
  }else{
    
          if(abs(motor3_value) > 5){
            analogWrite(44, abs(motor3_value));
            digitalWrite(45, LOW);
      
          }else{
            digitalWrite(44, LOW);
            digitalWrite(45, LOW);
          }
      }

  
}

void m4(){
  motor4_value = pos4_pid.compute(encoder4_pos);
  pos4_pid.setpoint(p4);
  if(motor4_value > 0){
           if(motor4_value > 5){
              analogWrite(43, motor4_value);
              digitalWrite(42, LOW);
        
          }else{
              digitalWrite(42, LOW);
              digitalWrite(43, LOW);
        
          }
  }else{
    
          if(abs(motor4_value) > 5){
            analogWrite(42, abs(motor4_value));
            digitalWrite(43, LOW);
      
          }else{
            digitalWrite(42, LOW);
            digitalWrite(43, LOW);
          }
      }

  
}

void m5(){
  motor5_value = pos5_pid.compute(encoder5_pos);
  pos5_pid.setpoint(p5);
  if(motor5_value > 0){
           if(motor5_value > 5){
              analogWrite(40, motor5_value);
              digitalWrite(41, LOW);
        
          }else{
              digitalWrite(41, LOW);
              digitalWrite(40, LOW);
        
          }
  }else{
    
          if(abs(motor5_value) > 5){
            analogWrite(41, abs(motor5_value));
            digitalWrite(40, LOW);
      
          }else{
            digitalWrite(41, LOW);
            digitalWrite(40, LOW);
          }
      }

  
}

void m6(){
  motor6_value = pos6_pid.compute(encoder6_pos);
  pos6_pid.setpoint(p6);
  if(motor6_value > 0){
           if(motor6_value > 5){
              analogWrite(38, motor6_value);
              digitalWrite(39, LOW);
        
          }else{
              digitalWrite(39, LOW);
              digitalWrite(38, LOW);
        
          }
  }else{
    
          if(abs(motor6_value) > 5){
            analogWrite(39, abs(motor6_value));
            digitalWrite(38, LOW);
      
          }else{
            digitalWrite(39, LOW);
            digitalWrite(38, LOW);
          }
      }

  
}


void m7(){
  motor7_value = pos7_pid.compute(encoder7_pos);
  pos7_pid.setpoint(p7);
  if(motor7_value > 0){
           if(motor7_value > 5){
              analogWrite(37, motor7_value);
              digitalWrite(36, LOW);
        
          }else{
              digitalWrite(36, LOW);
              digitalWrite(37, LOW);
        
          }
  }else{
    
          if(abs(motor7_value) > 5){
            analogWrite(36, abs(motor7_value));
            digitalWrite(37, LOW);
      
          }else{
            digitalWrite(36, LOW);
            digitalWrite(37, LOW);
          }
      }

  
}

void m8(){
  motor8_value = pos8_pid.compute(encoder8_pos);
  pos8_pid.setpoint(p8);
  if(motor8_value > 0){
           if(motor8_value > 5){
              analogWrite(34, motor8_value);
              digitalWrite(35, LOW);
        
          }else{
              digitalWrite(35, LOW);
              digitalWrite(34, LOW);
        
          }
  }else{
    
          if(abs(motor8_value) > 5){
            analogWrite(35, abs(motor8_value));
            digitalWrite(34, LOW);
      
          }else{
            digitalWrite(35, LOW);
            digitalWrite(34, LOW);
          }
      }

  
}

void m9(){
  motor9_value = pos9_pid.compute(encoder9_pos);
  pos9_pid.setpoint(p9);
  if(motor9_value > 0){
           if(motor9_value > 5){
              analogWrite(32, motor9_value);
              digitalWrite(33, LOW);
        
          }else{
              digitalWrite(33, LOW);
              digitalWrite(32, LOW);
        
          }
  }else{
    
          if(abs(motor9_value) > 5){
            analogWrite(33, abs(motor9_value));
            digitalWrite(32, LOW);
      
          }else{
            digitalWrite(33, LOW);
            digitalWrite(32, LOW);
          }
      }

  
}

void m10(){
  motor10_value = pos10_pid.compute(encoder10_pos);
  pos10_pid.setpoint(p10);
  if(motor10_value > 0){
           if(motor10_value > 5){
              analogWrite(30, motor10_value);
              digitalWrite(31, LOW);
        
          }else{
              digitalWrite(31, LOW);
              digitalWrite(30, LOW);
        
          }
  }else{
    
          if(abs(motor10_value) > 5){
            analogWrite(31, abs(motor10_value));
            digitalWrite(30, LOW);
      
          }else{
            digitalWrite(31, LOW);
            digitalWrite(30, LOW);
          }
      }

  
}

void m11(){
  motor11_value = pos11_pid.compute(encoder11_pos);
  pos11_pid.setpoint(p11);
  if(motor11_value > 0){
           if(motor11_value > 5){
              analogWrite(26, motor11_value);
              digitalWrite(27, LOW);
        
          }else{
              digitalWrite(27, LOW);
              digitalWrite(26, LOW);
        
          }
  }else{
    
          if(abs(motor11_value) > 5){
            analogWrite(27, abs(motor11_value));
            digitalWrite(26, LOW);
      
          }else{
            digitalWrite(27, LOW);
            digitalWrite(26, LOW);
          }
      }

  
}

void m22(){
  motor22_value = pos22_pid.compute(encoder22_pos);
  pos22_pid.setpoint(p22);
  if(motor22_value > 0){
           if(motor22_value > 5){
              analogWrite(25, motor22_value);
              digitalWrite(24, LOW);
        
          }else{
              digitalWrite(24, LOW);
              digitalWrite(25, LOW);
        
          }
  }else{
    
          if(abs(motor22_value) > 5){
            analogWrite(24, abs(motor22_value));
            digitalWrite(25, LOW);
      
          }else{
            digitalWrite(24, LOW);
            digitalWrite(25, LOW);
          }
      }

  
}

void m33(){
  motor33_value = pos33_pid.compute(encoder33_pos);
  pos33_pid.setpoint(p33);
  if(motor33_value > 0){
           if(motor33_value > 5){
              analogWrite(22, motor33_value);
              digitalWrite(23, LOW);
        
          }else{
              digitalWrite(23, LOW);
              digitalWrite(22, LOW);
        
          }
  }else{
    
          if(abs(motor33_value) > 5){
            analogWrite(23, abs(motor33_value));
            digitalWrite(22, LOW);
      
          }else{
            digitalWrite(23, LOW);
            digitalWrite(22, LOW);
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
            Serial.print(encoder3_pos);
            Serial.print("  ");
            Serial.print("m3 = ");
            Serial.print(motor3_value);
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

void fucku(){
              
   


      //elbow
              for(int i = 0; i<400;i++){
                    p33++;     
                    allM();
                    delay(3);  
                  }
      
      //wrists
              for (pos = 0; pos <= 55; pos++) { 
                    myservo.write(pos);       
                    allM();
                    delay(3);                       
                  }
              for (pos = 0; pos <= 55; pos++) { 
                    myservo1.write(pos);           
      
       
                    allM();;           
                    delay(3);                       
                  }
      
      //fingers
              for(int i = 0; i<400;i++){
                 
                  p4++;
                  p5++;
                  p6++;
                  p7++;
                  p8++;
                  p9++;
           
                  allM();
                       
                  delay(0);  
                  }
      
      //delay
               for(int i = 0; i<200;i++){    
      
                  allM();
                  delay(3);  
                  }
      
      
      //fingers undo
              for(int i = 0; i<400;i++){
                    
                  p4--;
                  p5--;
                  p6--;
                  p7--;
                  p8--;
                  p9--;
                            
                  allM();
                      //read1();  
      
                  delay(0);  
                  }
      //wrist undo
               for (pos = 55; pos > 0; pos--) { 
                    myservo1.write(pos);    
                    allM();                     
                    delay(3);                       
                  }
              
               for (pos = 55; pos > 0; pos--) { 
                    myservo.write(pos);          
                    allM();                     
                    delay(3);                       
                  }
      
      //elbow undo
               for(int i = 0; i<400;i++){
          
                  p33--;                            
                  allM();                    
                  delay(3);      
                  }
               
                    
}

void allM(){
              m1();
              m2();
              m3();
              m4();
              m5();
              m6();
              m7();
              m8();
              m9();
              m10(); 
                
              m11(); 
              m22();      
              m33(); 

}


void fingers(){

          for(int i = 0; i<400;i++){
          
                      p9 = p9+2; 
                      p10++;           
                        allM();          
                      delay(2);      
                      }  
          
          
          for(int i = 0; i<520;i++){
                      p1++;
                      p2++;
                      p3++;
                      p4++;
                      p5++;
                      p6++;
                      p7++;
                      p8++;
                   
                        allM();          
                      delay(2);      
                      }  
          
            
          for(int i = 0; i<500;i++){
          
                              
                        allM();          
                      delay(2);      
                      }  
           
          for(int i = 0; i<520;i++){
                      p1--;
                      p2--;
                      p3--;
                      p4--;
                      p5--;
                      p6--;
                      p7--;
                      p8--;
                                    
                        allM();         
                      delay(2);      
                      }
          for(int i = 0; i<400;i++){
          
                      p9 = p9-2; 
                      p10--;           
                        allM();          
                      delay(2);      
                      }    
         
}         

void m11test(){
          for(int i = 0; i<100;i++){
          
                      p11 = p11+3;
                      //p33++; 
                                 
                      allM();          
                      delay(4);      
                      }  
          for(int i = 0; i<400;i++){            
                      allM();          
                      delay(2);      
                      } 
          for(int i = 0; i<400;i++){
          
                      p11 = p11-3;
                      p33--; 
                                 
                      allM();          
                      delay(4);      
                      }  
          
  
}


void m22test(){
//          for(int i = 0; i<1600;i++){                 
//                      p22++; 
//                                 
//                      allM();          
//                      delay(2);      
//                      }  
//          for(int i = 0; i<400;i++){            
//                      allM();          
//                      delay(2);      
//                      } 
          for(int i = 0; i<20;i++){     
                      p22--; 
                                 
                      allM();          
                      delay(2);      
                      }  
          
  
}

void m33test(){
//          for(int i = 0; i<400;i++){                 
//                      p33++; 
//                                 
//                      allM();          
//                      delay(2);      
//                      }  
//          for(int i = 0; i<400;i++){            
//                      allM();          
//                      delay(2);      
//                      } 
          for(int i = 0; i<10;i++){     
                      p33--; 
                                 
                      allM();          
                      delay(2);      
                      }  
          
  
}

void biceptflex(){
              
      allM();                   
      


      //22
              for(int i = 0; i<1600;i++){
                    p22++;     
                    allM();
                    delay(0);  
                  }
      //11
              for(int i = 0; i<1300;i++){
                    p11--;     
                    allM();
                    delay(0);  
                  }
      //33
              for(int i = 0; i<400;i++){
                    p33++;     
                    allM();
                    delay(3);  
                  }

                  
     // wrists
              for (pos = 0; pos <= 55; pos++) { 
                    myservo.write(pos);       
                    allM();
                    delay(3);                       
                  }
              for (pos = 0; pos <= 55; pos++) { 
                    myservo1.write(pos);           
      
       
                    allM();;           
                    delay(3);                       
                  }
//      
//      //fingers
              for(int i = 0; i<450;i++){
                  p1++;
                  p2++;
                  p3++;
                  p4++;
                  p5++;
                  p6++;
                  p7++;
                  p8++;
                  p9 = p9 + 2;
                  p10++;
           
                  allM();
                       
                  delay(0);  
                  }
//      
      //delay
               for(int i = 0; i<600;i++){    
      
                  allM();
                  delay(3);  
                  }
//      
//      
//      //fingers undo
              for(int i = 0; i<450;i++){
                  p1--;
                  p2--;
                  p3--;  
                  p4--;
                  p5--;
                  p6--;
                  p7--;
                  p8--;
                  p9 = p9 - 2;
                  p10--;
                            
                  allM();
                      //read1();  
      
                  delay(0);  
                  }
      //wrist undo
               for (pos = 55; pos > 0; pos--) { 
                    myservo1.write(pos);    
                    allM();                     
                    delay(3);                       
                  }
              
               for (pos = 55; pos > 0; pos--) { 
                    myservo.write(pos);          
                    allM();                     
                    delay(3);                       
                  }
      //33 undo
               for(int i = 0; i<380;i++){
          
                  p33--;                            
                  allM();                    
                  delay(3);      
                  }
      //11 undo
               for(int i = 0; i<1300;i++){
          
                  p11++;                            
                  allM();                    
                  delay(0);      
                  }
      //22 undo
               for(int i = 0; i<1600;i++){
          
                  p22--;                            
                  allM();                    
                  delay(0);      
                  }
               
                    
}

void gun(){
              
      allM();                   
      


//      //22
//              for(int i = 0; i<400;i++){
//                    p22++;     
//                    allM();
//                    delay(2);  
//                  }
//      //33
//              for(int i = 0; i<400;i++){
//                    p33++;     
//                    allM();
//                    delay(2);  
//                  }
//
//                     
////      //fingers
//              for(int i = 0; i<520;i++){
//                  p5++;
//                  p6++;
//                  p7++;
//                  p8++;
//                  
//                  allM();      
//                  delay(0);  
//                  }
//
////delay
//               for(int i = 0; i<300;i++){    
//      
//                  allM();
//                  delay(1);  
//                  }
//                  
////shot
//              for(int i = 0; i<600;i++){
//                  p9++;
//     
//                  allM();     
//                  delay(0);  
//                  }
////shot undo
//              for(int i = 0; i<600;i++){
//                  p9--;
//     
//                  allM();     
//                  delay(0);  
//                  }
////      
//
////      
////      
//      //fingers undo
//              for(int i = 0; i<520;i++){
//                  p5--;
//                  p6--;
//                  p7--;
//                  p8--;
//                  
//                            
//                  allM();
//                      //read1();  
//      
//                  delay(0);  
//                  }
//
      //33 undo
               for(int i = 0; i<5;i++){
          
                  p33--;                            
                  allM();                    
                  delay(2);      
                  }

//      //22 undo
//               for(int i = 0; i<412;i++){
//          
//                  p22--;                            
//                  allM();                    
//                  delay(2);      
//                  }
//               
                    
}
