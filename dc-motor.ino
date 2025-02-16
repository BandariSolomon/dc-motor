#include"config.h"
#include "motor.h"

volatile uint8_t speed,slow_flag = false, curr_speed, prev_speed, state;

#define  _stop 0
#define  _forward 1
#define  _backward 2

#define MIN_SPEED 128
#define MAX_SPEED MIN_SPEED + 10

#ifdef PRINT_EN
#define PRNT(x)   Serial.print(x)
#define PRNTln(x) Serial.println(x)
#else
#define PRNT(x)   
#define PRNTln(x) 
#endif //PRINT_EN

void setup() {
  Serial.begin(115200);

#ifdef OLED_EN
  oled_init();
#endif //OLED_EN
#ifdef LCD_EN
  lcd_init();
#endif//LCD_EN

#ifdef RTC_EN
  rtc_init();
#endif //RTC_EN

  // put your setup code here, to run once:
#ifdef MOTORA_EN
  motorA_init();
#endif //MOTORA_EN

#ifdef MOTORB_EN
  motorB_init();
#endif //MOTORB_EN
}

void loop() {
  #ifdef RTC_EN
  date_time();
  #endif //RTC_EN

  #ifdef DHT11_EN
  read_dht11();
  #endif //DHT11_EN

  #ifdef MOTORA_EN
  int x_data = analogRead(x_axis);
  delay(100);
  uint8_t x_speed_val = map(x_data, 0, 1023, 0, 255);
  Serial.print("x_speed_val: ");Serial.println(x_speed_val);
  if((x_speed_val>MIN_SPEED)&&(x_speed_val<MAX_SPEED))
  { 
    if(state != _stop)
    {
      PRNTln("Stop");
#ifdef OLED_EN
      oled_print(0, 0, "Mtr A Stop", true);
#endif // OLED_EN

#ifdef LCD_EN
    lcd_print(0, ROW1, "Mtr A Stop", true);
#endif //LCD_EN
    }
    motorA_stop();
    state = _stop;
  }
  else if((x_speed_val>=0) && (x_speed_val<MIN_SPEED))
  {
      x_speed_val = 255 - x_speed_val;
      curr_speed = x_speed_val;
    if(curr_speed != prev_speed)
      prev_speed = curr_speed;

    if((state != _forward) || (curr_speed == prev_speed))
    {
      PRNTln("forward");
#ifdef OLED_EN
      oled_print(0, 0, "Mtr A FRWD: " ,true);
      oled_print(72, 0, (String ) x_speed_val, false);
#endif //OLED_EN

  #ifdef LCD_EN
    lcd_print(0, ROW1, "Mtr A FRWD: ", true);
    lcd_print(12, ROW1, (String) x_speed_val, false);
  #endif //LCD_EN
    }
    motorA_forward(&x_speed_val);
    state = _forward;
  }
  else if(x_speed_val>MAX_SPEED)
  {
    x_speed_val = 0 + x_speed_val;
    curr_speed = x_speed_val;
    if(curr_speed != prev_speed)
      prev_speed = curr_speed;

    if((state != _backward) || (curr_speed == prev_speed))
    {
      PRNTln("backward");
#ifdef OLED_EN
      oled_print(0, 0, "Mtr A BKWD: ", true);
      oled_print(72, 0, (String ) x_speed_val, false);
#endif //OLED_EN

#ifdef LCD_EN
      lcd_print(0, ROW1, "Mtr A BKWD: ", true);
      lcd_print(12, ROW1, (String) x_speed_val, false);
#endif //LCD_EN
    }
    motorA_backward(&x_speed_val);
    state = _backward;
  }
 #endif //MOTORA_EN

  #ifdef MOTORB_EN
  int y_data = analogRead(y_axis);
  delay(100);
  PRNT("y_data: ");  PRNTln(y_data);
  uint8_t y_speed_val = map(y_data, 0, 1023, 0, 255);
  PRNT("y_speed_val: ");  PRNTln(y_speed_val);
  
  if((y_speed_val>125)&&(y_speed_val<135))
  { 
    PRNTln("Stop");
    motorB_stop();
  }
  else if((y_speed_val>=0) && (y_speed_val<125))
  {
    PRNTln("forward");
    motorB_forward(&y_speed_val);
  }
  else if(y_speed_val>135)
  {
    PRNTln("backward");
    motorB_backward(&y_speed_val);
  }
 #endif //MOTORB_EN
                    // wait for a second
}
