#ifdef MOTORA_EN

#ifndef NODEMCU
#define MOTORA_IN1 2
#define MOTORA_IN2 3
#define MOTORA_SPEED_PIN 5
#define x_axis A4
#else
#define MOTORA_IN1 D5
#define MOTORA_IN2 D6
#define MOTORA_SPEED_PIN D7
#define x_axis A0
#endif 
#endif //MOTORA_EN

#ifdef MOTORB_EN
#define MOTORB_IN1 7
#define MOTORB_IN2 8
#define MOTORB_SPEED_PIN 6
#define y_axis A3
#endif //MOTORB_EN
