#include "config.h"
#include "motor.h"


#ifdef MOTORA_EN

void motorA_init()
{
  pinMode(x_axis, INPUT);
  pinMode(MOTORA_IN1,OUTPUT);
  pinMode(MOTORA_IN2,OUTPUT);
}

void motorA_forward(uint8_t *speed)
{
  motorA_speedcotrol(speed);
  digitalWrite(MOTORA_IN1, HIGH);
  digitalWrite(MOTORA_IN2, LOW);
}

void motorA_backward(uint8_t *speed)
{
  motorA_speedcotrol(speed);
  digitalWrite(MOTORA_IN1, LOW);
  digitalWrite(MOTORA_IN2, HIGH);
}

void motorA_stop()
{
  digitalWrite(MOTORA_IN1, LOW);
  digitalWrite(MOTORA_IN2, LOW);
}

void motorA_speedcotrol(uint8_t *speed)
{
  analogWrite(MOTORA_SPEED_PIN, *speed);
}

#endif //MOTORA_EN

#ifdef MOTORB_EN

void motorB_init()
{
  pinMode(y_axis, INPUT);
  pinMode(MOTORB_IN1,OUTPUT);
  pinMode(MOTORB_IN1,OUTPUT);
}

void motorB_forward(uint8_t *speed)
{
    *speed = 255 - *speed;
  #ifdef LCD_EN
    lcd.clear();
    lcd.setCursor(0, ROW2);
    lcd.print(F("Mtr B FRWD: "));
    lcd.print(*speed);
  #endif //LCD_EN
  motorB_speedcotrol(speed);
  digitalWrite(MOTORB_IN1, HIGH);
  digitalWrite(MOTORB_IN2, LOW);
}

void motorB_backward(uint8_t *speed)
{
    *speed = 0 + *speed;
  #ifdef LCD_EN
    lcd.clear();
    lcd.setCursor(0, ROW2);
    lcd.print(F("Mtr B BKWD: "));
    lcd.print(*speed);
  #endif //LCD_EN

  motorB_speedcotrol(speed);
  digitalWrite(MOTORB_IN1, LOW);
  digitalWrite(MOTORB_IN2, HIGH);
}

void motorB_stop()
{
  #ifdef LCD_EN
    lcd.clear();
    lcd.setCursor(0, ROW2);
    lcd.print(F("Mtr B Stop"));
  #endif //LCD_EN

  digitalWrite(MOTORB_IN1, LOW);
  digitalWrite(MOTORB_IN2, LOW);
}

void motorB_speedcotrol(uint8_t *speed)
{
  analogWrite(MOTORB_SPEED_PIN, *speed);
}
#endif //MOTORB_EN
