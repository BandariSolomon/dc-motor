#include "config.h"

#ifdef LCD_EN

void lcd_init()
{
  lcd.begin();

  lcd.backlight();  

  lcd.clear();
  // lcd.setCursor(0, ROW1);
  // lcd.print(F("Hello Mona"));
}

void lcd_print(int16_t x, int16_t y, String buff, bool clear)
{
  if(clear)
    lcd.clear();
  lcd.setCursor(x, y);
  lcd.print(buff);
}

void scroll_right()
{
  lcd.scrollDisplayRight();
}

void scroll_left()
{
  lcd.scrollDisplayLeft();
}
#endif //LCD_EN
