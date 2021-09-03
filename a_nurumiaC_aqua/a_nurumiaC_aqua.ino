#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <EEPROM.h>
#include <DHT11.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ArduinoJson.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
RTC_DS1307 RTC;

int dataPin = 8;    // Data pin of 74HC595 is connected to Digital pin 4
int latchPin = 9;   // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 10;  // Clock pin of 74HC595 is connected to Digital pin 6

#define trigPin 3
#define echoPin 4

byte distance;

byte leds = 11111111;    // Variable to hold the pattern of which LEDs are currently turned on or off

int value = 00000000;
int value2 = 00000000;

// Water Ph Measurement:
#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection 
#define Vs 5

OneWire oneWire(ONE_WIRE_BUS);
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature waterSensors(&oneWire);// This means that you need to connect the RX line from the esp to the Arduino's pin 2
// Temperature & humidity are air values

// Distance for water level
byte humidity,waterTemperature,distance,phValue;
