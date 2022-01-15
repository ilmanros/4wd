#include <HCSR04.h>
#include <PS2X_lib.h>
//hehehehe
HCSR04 hc(7, 8);

#define PS2_DAT        2  //   biru      data
#define PS2_CMD        3  //   oren      command
#define PS2_SEL        4  //   kuning    attetion
#define PS2_CLK        5  //   coklat    clock
//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

#define kaa   11
#define kab   10
#define kia   9
#define kib   6

int speeda  =190;
int speedb  =255;
int a=0;

PS2X ps2x; // PS2 Controller Class
int error = 0;
byte type = 3;
byte vibrate = 0;

void setup() {
  
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  type = ps2x.readType();
  type = 3;//
  
  
  pinMode(kaa,OUTPUT);
  pinMode(kab,OUTPUT);
  pinMode(kia,OUTPUT);
  pinMode(kib,OUTPUT);

//  pinMode(13,OUTPUT);
//  pinMode(12,OUTPUT);
  
  Serial.begin(9600);
  delay(100);
}

void loop() {
    ps2x.read_gamepad();
//if(type=3){
//analogWrite(12,130);

//      while(ps2x.Button(PSB_R1)){ //nos
//    speeda=190;
//    speedb=255;
//  }


  
    if(ps2x.Analog(PSS_LY) <= 110){
      analogWrite(kaa, speeda);
      analogWrite(kab, 0);
      analogWrite(kia, speedb);
      analogWrite(kib, 0);
    }

    else if(ps2x.Analog(PSS_LY) >= 148){
      analogWrite(kaa, 0);
      analogWrite(kab, speeda);
      analogWrite(kia, 0);
      analogWrite(kib, speedb);
    }

    else if(ps2x.Analog(PSS_RX)<=110){
      analogWrite(kaa, 0);
      analogWrite(kab, speeda);
      analogWrite(kia, speedb);
      analogWrite(kib, 0);
    }
    else if(ps2x.Analog(PSS_RX)>=148){
      analogWrite(kaa, speeda);
      analogWrite(kab, 0);
      analogWrite(kia, 0);
      analogWrite(kib, speedb);
    }
    
    else {
      analogWrite(kaa, 0);
      analogWrite(kab, 0);
      analogWrite(kia, 0);
      analogWrite(kib, 0);
//      ps2x.Analog(PSS_LY)=128&&ps2x.Analog(PSS_LX)&&ps2x.Analog(PSS_RY)&&ps2x.Analog(PSS_RX)=128;
      delayMicroseconds(100);
//      digitalWrite(13, 1);   // turn the LED on (HIGH is the voltage level)
//      delayMicroseconds(7000);                       // wait for a second
//      digitalWrite(13, 0);    // turn the LED off by making the voltage LOW
//      delayMicroseconds(7000);
    
//      speeda=100;
//      speedb=130;     
      
//      digitalWrite(12, LOW);

    }
    if(ps2x.Analog(PSS_LY) <= 110 && ps2x.Analog(PSS_RX)<=110){
      analogWrite(kaa, 0);
      analogWrite(kab, 0);
      analogWrite(kia, speedb);
      analogWrite(kib, 0);
    }
    else if(ps2x.Analog(PSS_LY) <= 110 && ps2x.Analog(PSS_RX)>=148){
      analogWrite(kaa, speeda);
      analogWrite(kab, 0);
      analogWrite(kia, 0);
      analogWrite(kib, 0);
    }
    else if(ps2x.Analog(PSS_LY) >= 148 && ps2x.Analog(PSS_RX)<=110){
      analogWrite(kaa, 0);
      analogWrite(kab, speeda);
      analogWrite(kia, 0);
      analogWrite(kib, 0);
    }
    else if(ps2x.Analog(PSS_LY) >= 148 && ps2x.Analog(PSS_RX)>=148){
      analogWrite(kaa, 0);
      analogWrite(kab, 0);
      analogWrite(kia, 0);
      analogWrite(kib, speedb);
    }
    
    while(ps2x.ButtonPressed(PSB_R1)){
      delay(50);
      analogWrite(kaa, 160);
      analogWrite(kab, 0);
      analogWrite(kia, 205);
      analogWrite(kib, 0);
      digitalWrite(13,1);
      a= hc.dist();
//            Serial.println(a);
      if(a<=25&&a>0){      
      digitalWrite(13,0);
      analogWrite(kaa, 0);
      analogWrite(kab, 0);
      analogWrite(kia, 0);
      analogWrite(kib, 0);break;}

    }
        
   
//      Serial.print(ps2x.Analog(PSS_LY));
//      Serial.print("  ");
//      Serial.print(ps2x.Analog(PSS_LX)); 
//      Serial.print("  ,  ");
//      Serial.print(ps2x.Analog(PSS_RY)); 
//      Serial.print("  ");
//      Serial.println(ps2x.Analog(PSS_RX)); 

//    if(ps2x.Button(PSB_PAD_UP)){Serial.println("Atas");}
//    else{Serial.print("");}
//    
//    if(ps2x.Button(PSB_PAD_DOWN)){Serial.println("Bawah");}
//    else{Serial.print("");}
//    
//    if(ps2x.Button(PSB_PAD_RIGHT)){Serial.println("Kanan");}
//    else{Serial.print("");}
//    
//    if(ps2x.Button(PSB_PAD_LEFT)){Serial.println("Kiri");}
//    else{Serial.print("");}


    
    }   
