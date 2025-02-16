#include <DFRobot_DS1307.h>

DFRobot_DS1307 DS1307;

void rtc_init()
{
    // Initialize sensor
  while( !(DS1307.begin()) ){
    Serial.println("Communication with device failed, please check connection");
    delay(3000);
  }
  Serial.println("Begin ok!");

  DS1307.start();

  // set_date_time(30, 21, 9, 1, 1, 12, 2024);  //sec, min, hour, dow, date, month, year

}

void date_time()
{
  uint16_t getTimeBuff[7] = {0};
  DS1307.getTime(getTimeBuff);

  char date[30], time[30], dow[10];
  
  #ifdef PRINT_EN
  char outputarr[128];
  sprintf(outputarr, "time: %.2d/%.2d/%.2d-%.2d %.2d:%.2d:%.2d\r\n",
            getTimeBuff[4],
            getTimeBuff[5],
            getTimeBuff[6],
            getTimeBuff[3],
            getTimeBuff[2],
            getTimeBuff[1],
            getTimeBuff[0]
            );

  Serial.println(outputarr);
  #endif PRINT_EN

  sprintf(date, "Date: %.2d/%.2d/%.2d",
            getTimeBuff[4],
            getTimeBuff[5],
            getTimeBuff[6]);

  sprintf(time, "Time: %.2d:%.2d:%.2d",
            getTimeBuff[2],
            getTimeBuff[1],
            getTimeBuff[0]);

  sprintf(dow, "Day : %d", getTimeBuff[3]);

  #ifdef OLED_EN
  oled_print(0, LINE2, date, 0);
  oled_print(0, LINE3, time, 0);
  oled_print(0, LINE4, dow, 0);
  #endif //OLED_EN

  /**
   *  Store the current time into EEPROM, which is used to set the time to the last saved one after powering off and restarting
   *  Call the interface when powering off and call setTimeFromEEPROM() to realize when restarting
   */
  DS1307.saveTimeToEEPROM();
}

void set_date_time(uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t date, uint8_t month, int year)
{
  /**
   *  According to the available array, set all the time
   *  setTimeBuff Array in the following format (type is uint16_t)
   *    setTimeBuff[0] for eSEC type, range: 00-59
   *    setTimeBuff[1] for eMIN type, range: 00-59
   *    setTimeBuff[2] for eHR type, range: 00-23
   *    setTimeBuff[3] for eDOW type, range: 01-07
   *    setTimeBuff[4] for eDATE type, range: 01-31
   *    setTimeBuff[5] for eMTH type, range: 01-12
   *    setTimeBuff[6] for eYR type, range: 2000-2099
   *  Note: Values out of range will result in a setting error
   */
  // uint16_t setTimeBuff[7] = {5, 43, 20, 6, 16, 11, 2024};
  uint16_t setTimeBuff[7] = {sec, min, hour, dow, date, month, year};

  DS1307.setTime(setTimeBuff);

  /**
   *  Store the current time into EEPROM, which can be used to set the time to the last saved one when powering off and restarting
   *  Call this interface when power off and call setTimeFromEEPROM() to realize when restarting
   */
  DS1307.saveTimeToEEPROM();

}
