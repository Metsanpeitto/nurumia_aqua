// setupFlags = 0b00000100;

// states 
//pumpState, valveInState, valveOutState, lampState, airHeaterState, waterHeaterState, fanState;
     

// alarms
//     0                    1                2            3             4          5          6      7         
//waterLevelTooHigh, waterLevelTooLow, lightOnNoOff, lightOffNoOn, motionStart, motionStop, airHot,airCold,


//alarms2
//    0         1        2         3        4       5        6
//  airMoist,airDry, waterHot, waterCold, phHigh, phLow, waterDetect;

// 27 -  maxWaterTemp  -aw
// 28 -  minWaterTemp  -iw
    
void waterTemp(void) {
  //  call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  /********************************************************************/
   waterSensors.requestTemperatures(); // Send the command to get temperature readings
  /********************************************************************/
   waterTemperature = (waterSensors.getTempCByIndex(0));
  
  
   if (waterTemperature < -15)          // This error  happens sometimes
      {
        waterTemperature = -14;
      //  lcd.clear();
      //  lcd.print(F("Water temp Error"));
      //  delay(500);
       }

   if ((waterTemperature <= -5) && (waterTemperature >= -15))
      {
        waterSensors.requestTemperatures();    // In case of extreme cold
    /*    lcd.clear();//Clean the screen
        lcd.print(F("  Water temp:"));
        lcd.setCursor(6, 2);
        lcd.print(waterSensors.getTempCByIndex(0));
     */ 
        waterTemperature = (int)(waterSensors.getTempCByIndex(0));
        bitWrite(states,2,0);                  // Sets 0 the pin to switchOn waterheaterState
        
        bitWrite(alarms2,3,1);                 // Set alarm airCold alarm as true
        bitWrite(alarms2,2,0);                  // Set alarm airHot alarm as false
    //    delay(1500);
       }

    if (waterTemperature <= EEPROM.read(28) && waterTemperature >= -5)     // eeprom 28 is minimumWaterTemperature
       {    
         bitWrite(states,2,0);                   // Sets 0 the pin to switchOn waterheaterState
         bitWrite(alarms2,3,1);                  // Set alarm airCold alarm as true
         bitWrite(alarms2,2,0);                  // Set alarm airHot alarm as false
        }



    if (waterTemperature > EEPROM.read(28) && waterTemperature < EEPROM.read(27))   // read(27) maximum temp and read(28) minimum temp
       {
       //  lcd.clear();//Clean the screen
      //   lcd.print(F(" Water ideal temp"));
         bitWrite(states,2,1);                  // Sets 1 the pin to switchOff waterheaterState
         bitWrite(alarms2,3,0);                  // Set alarm airCold alarm as false
         bitWrite(alarms2,2,0);                  // Set alarm airHot alarm as false
       //  delay(500);
        }

  
    if (waterTemperature > 24)          // This error  happens sometimes
       {
         waterTemperature = -14;
       //  lcd.clear();
       //  lcd.print(F("Water too Hot !"));
         bitWrite(states,2,1);                  // Sets 1 the pin to switchOff waterheaterState
         bitWrite(alarms2,3,0);                  // Set alarm airCold alarm as false
         bitWrite(alarms2,2,1);                  // Set alarm airHot alarm as true

       //  delay(500);
       }
}
