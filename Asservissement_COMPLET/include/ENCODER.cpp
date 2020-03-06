#include "ENCODER.h"
void rotary_loop_1()
 {
    int16_t encoderValue=0;
    int16_t encoderDelta = rotaryEncoder1.encoderChanged();
   //optionally we can ignore whenever there is no change
    if (encoderDelta == 0) return;
    // if (encoderDelta2 == 0) return;
    if (encoderDelta!=0) {
    //now we need current value
    encoderValue = rotaryEncoder1.readEncoder();
    nbTicksVit1+=encoderValue;
    nbTicksPos1+=encoderValue;
    rotaryEncoder1.reset();
        //             Serial.print("nbpos:");

        // Serial.println(nbTicksPos);


    } 
 }
 void rotary_loop_2()
 {
    int16_t encoderValue=0;
    int16_t encoderDelta = rotaryEncoder2.encoderChanged();
   //optionally we can ignore whenever there is no change
    if (encoderDelta == 0) return;
    // if (encoderDelta2 == 0) return;
    if (encoderDelta!=0) {
    //now we need current value
    encoderValue = rotaryEncoder2.readEncoder();
    nbTicksVit2+=encoderValue;
    nbTicksPos2+=encoderValue;
    rotaryEncoder2.reset();
      // Serial.print("nbpos1:");
      // Serial.println(nbTicksPos1);

      }
    
 }