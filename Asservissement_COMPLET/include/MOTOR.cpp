#include "MOTOR.h"
void Run( int powerRate , int powerRate2 ) 
{  
if (powerRate >= 0 && powerRate2 >=0 )
{ 
digitalWrite(pinInput1,LOW);  
digitalWrite(pinInput2, HIGH);  
analogWrite(pinRegulator,powerRate);
digitalWrite(pinInput12,LOW);  
digitalWrite(pinInput22, HIGH);   
analogWrite(pinRegulator2,powerRate2);
}
else if (powerRate <= 0 && powerRate2 <= 0)
{
digitalWrite(pinInput1,HIGH);  
digitalWrite(pinInput2, LOW); 
analogWrite(pinRegulator,-powerRate);
digitalWrite(pinInput12,HIGH);  
digitalWrite(pinInput22, LOW);   
analogWrite(pinRegulator2,-powerRate2);
}
else if(powerRate > 0 && powerRate2 < 0) {
digitalWrite(pinInput1,LOW);  
digitalWrite(pinInput2, HIGH);  
analogWrite(pinRegulator,powerRate);
digitalWrite(pinInput12,HIGH);  
digitalWrite(pinInput22, LOW);   
analogWrite(pinRegulator2,-powerRate2);
}
else if(powerRate < 0 && powerRate2 > 0) {
digitalWrite(pinInput1,HIGH);  
digitalWrite(pinInput2, LOW); 
analogWrite(pinRegulator,-powerRate);
digitalWrite(pinInput12,LOW);  
digitalWrite(pinInput22, HIGH);   
analogWrite(pinRegulator2,powerRate2);
}
}