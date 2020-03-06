 #include <Arduino.h>
 #include "MOTOR.h"
 #include "ENCODER.h"
 #include "ASSERV.H"
 void speedControl( int targetTicks , int consigne_orientation)
{    
// float w = (float)(nbTicksPerSec)/980;
  error1 = targetTicks - nbTicksPos1; 
   error2 = RC*targetTicks - nbTicksPos2; 
  int orientation = abs(RC*nbTicksPos1)-abs(nbTicksPos2); 
  error = consigne_orientation - orientation;
  float CMD = kp*error + kd*(error-previous_error)+ ki*error_sum;
  error_sum = error_sum + error;
  previous_error = error;
if ( CMD > 100 )    CMD = 100;    
else if ( CMD < -100 )   CMD = -100;   
  int vitMoteur1 = kp1 * error1 + kd1 * (error1 - previous_error1) ;
   int vitMoteur2 = kp2 * error2 + kd2 * (error2 - previous_error2) ;
    previous_error1 = error1;
       previous_error2 = error2;
  //   double deltaTICKS = nbTicksPos-abs(nbTicksPos1); 
  // int CMD = kp*deltaTICKS + kd * (deltaTICKS- previous_error1);
  // previous_error1 = deltaTICKS;
  int  regulator1 = vitMoteur1  ;
  int  regulator2 = vitMoteur2 ;
// float WindUp= ki*error_sum;
// if((WindUp)> 255) { WindUp=255;}
// else if ((WindUp)<0) {WindUp=0;};
// regulator = kp*error + ki*error_sum + kd*(error-previous_error);
// previous_error=error;
if ( regulator1 > 200 )    regulator1 = 200;    
else if ( regulator1 < -200 )   regulator1 = -200;   
 if ( regulator2 > 200 )    regulator1 = 200;    
else if ( regulator2 < -200 )   regulator2 = -200;  
// regulator = 0.9795*regulator;
   regulator1 = regulator1+CMD ;
   regulator2 = regulator2-CMD ;
 Run (regulator1 , regulator2);//regulator1);  
 //Serial.print(RadPerSecDesired);
 //Serial.print(RadPerSec);     
 // Serial.print(" : "); 
 //Serial.print(w);  
 //Serial.print(" : ");
 //Serial.print(error1);   
 //Serial.print(" : "); 
Serial.print(nbTicksPos1);  
 Serial.print(" : "); 
 Serial.print(nbTicksPos2);  
 Serial.print(" : "); 
Serial.print(orientation);  
Serial.print(" : "); 
 Serial.print(regulator1);
 Serial.print(" : "); 
 Serial.print(regulator2);
 Serial.print(" : "); 
 Serial.println(CMD);

//  Serial.println(orientation);  

 }
 