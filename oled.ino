#include "config.h"

#ifdef OLED_EN

void oled_init()
{
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))  // Address 0x3C for most of these displays, if doesn't work try 0x3D 
  { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);                                      // Don't proceed, loop forever
  } 
  display.setTextSize(1);             
  display.setTextColor(SSD1306_WHITE);            // Draw white text
  display.clearDisplay();
  // display.setCursor(0,0);
  // display.println(F("Hello Mona"));
  // display.display(); 
}

void oled_print(int16_t x, int16_t y, String buff, bool clear)
{
  if(clear)
    display.clearDisplay();
  display.setCursor(x,y);
  display.setTextColor(WHITE, BLACK);
  display.print(buff);
  display.display();
}
#endif //OLED_EN
