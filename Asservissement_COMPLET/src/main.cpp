#include <Arduino.h>
#include "ENCODER.h"
#include "MOTOR.h"
#include "ASSERV.H"
const int sampleTime=10;
double oldTime=0;
double currentT;
          
 void setup() {    
 Serial.begin(115200);      
  analogSetWidth(9);   
  pinMode(pinInput2, OUTPUT);   
  pinMode(pinInput1, OUTPUT );
  pinMode(pinInput22, OUTPUT);   
  pinMode(pinInput12, OUTPUT );
  pinMode(pinRegulator,OUTPUT);
  pinMode(pinRegulator2,OUTPUT);
  //we must initialize rorary encoder 
  rotaryEncoder1.begin();
  rotaryEncoder1.setup([]{rotaryEncoder1.readEncoder_ISR();});
  rotaryEncoder2.begin();
  rotaryEncoder2.setup([]{rotaryEncoder2.readEncoder_ISR();});
  // rotaryEncoder2.begin();
	// rotaryEncoder2.setup([]{rotaryEncoder2.readEncoder_ISR();});
  //optionally we can set boundaries and if values should cycle or not
  rotaryEncoder1.setBoundaries(-10000, 10000, false);
  rotaryEncoder2.setBoundaries(-10000, 10000, false);
  }
 void loop()
 {  
rotary_loop_1();
rotary_loop_2();
  double newTime=millis();
 if(newTime-oldTime>=sampleTime)
 { 
    speedControl(10000 , 0);
 oldTime=newTime;

}

}
 







 


 