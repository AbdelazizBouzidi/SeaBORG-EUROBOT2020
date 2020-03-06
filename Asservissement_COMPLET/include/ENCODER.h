#include <AiEsp32RotaryEncoder.h>
#define encoder1stCanal 34
#define encoder2ndCanal 35
#define encoder21stCanal 22
#define encoder22ndCanal 23
int nbTicksVit1 = 0;
int nbTicksPos1 = 0;
int nbTicksVit2 = 0;
int nbTicksPos2 = 0;
AiEsp32RotaryEncoder rotaryEncoder1 = AiEsp32RotaryEncoder(encoder1stCanal, encoder2ndCanal, -1, -1);
AiEsp32RotaryEncoder rotaryEncoder2 = AiEsp32RotaryEncoder(encoder21stCanal, encoder22ndCanal, -1, -1);
void rotary_loop_1(); 
void rotary_loop_2();