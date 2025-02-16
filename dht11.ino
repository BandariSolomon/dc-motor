#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2


void read_dht11(){
  DHT.read(DHT11_PIN);
  #ifdef PRINT_EN
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  #endif //PRINT_EN
  delay(1000);

  char temp[16], hum[14];
  
  sprintf(temp, "Temp:%.2d*C", DHT.temperature);

  sprintf(hum, "Hum :%.2d\%RH", DHT.humidity);
  
  // oled_print(0, 16,  temp, false);
  // oled_print(0, 24, hum, false);

  // lcd_print(0, ROW1, temp, false);
  // lcd_print(0, ROW2, hum, false);
}