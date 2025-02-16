#pragma once

// #define NODEMCU

// #define LCD_EN
#define MOTORA_EN
// #define MOTORB_EN
// #define OLED_EN
// #define RTC_EN
// #define DHT11_EN

// #define PRINT_EN

#ifdef OLED_EN
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#if (SCREEN_HEIGHT == 64)
#define LINE1       0
#define LINE2       8
#define LINE3       LINE2 + LINE2 //16
#define LINE4       LINE3 + LINE2 //24
#define LINE5       LINE4 + LINE2 //32
#define LINE6       LINE5 + LINE2 //40
#define LINE7       LINE6 + LINE2 //48
#define LINE8       LINE7 + LINE2 //56
#else
#define LINE1       0
#define LINE2       8
#define LINE3       LINE2 + LINE2 //16
#define LINE4       LINE3 + LINE2 //24
#endif

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3D ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
#endif//OLED_EN

#ifdef LCD_EN
#include <LCD_I2C.h>

#define ROWS    2
#define COLUMNS 16
#define ROW1  0
#define ROW2  1
LCD_I2C lcd(0x27, COLUMNS, ROWS);
#endif //LCD_EN
