     //states = 0b00000000;
     //bitWrite(states, 5, 1);
     //pumpState, valveInState, valveOutState, lampState, airHeaterState, waterHeaterState, fanState;
     //    0           1             2             3             4               5             6
     // 9  maxTempDefault = 28;
     // 10 minTempDefault = 21;
     // 11 maxHumiDefault = 70;
     // 12 minHumiDefault = 30;

     
     // 29 -  maxAirTemp    -aa
     // 30 -  minAirTemp    -ia
     // 31 -  maxHumi       -ah
     // 32 -  minHumi       -ih

     
    // alarms
    //     0                    1                2            3             4          5          6      7         
    //waterLevelTooHigh, waterLevelTooLow, lightOnNoOff, lightOffNoOn, motionStart, motionStop, airHot,airCold,


    //alarms2
    //    0         1        2         3        4       5        6
    //  airMoist,airDry, waterHot, waterCold, phHigh, phLow, waterDetect;


void readDht (byte controlFieldMax , byte controlFieldMin, byte readField , char* field ) {
  //   lcd.clear();
  //   lcd.print(" ReadDht");    
  //   delay(1000);
     //lcd.clear();
     //lcd.print(controlFieldMax);
     //lcd.setCursor(0,2);
     //lcd.print(controlFieldMin);
     //delay(1000);
     //lcd.clear();
     //lcd.print(readField);
     //lcd.setCursor(0,2);
     //lcd.print(controlFieldMax < readField);
     //delay(1000);

  if (controlFieldMax < readField) {     // Temperature/Humidity too high.
      if (field == 't') {                // Detects if is temperature or humidity and starts proccesses.
          bitWrite(states,6,0);          // Switchs On the fan
          bitWrite(states,4,1);          // Switchs Off the airHeater

          bitWrite(alarms,6,1);          // Air hot alarm set as true
          bitWrite(alarms,7,0);          // Air cold alarm set as false
          //alarm[6] = true;
          //alarm[6] = true;
       
          //lcd.clear();
          //lcd.print("High temp");
          //delay(2000);
         } else { 
             bitWrite(states,6,0);          // Switchs On the fan  
             bitWrite(alarms2,0,1);          // Air moist alarm set as true
             bitWrite(alarms2,1,0);          // Air dry alarm set as false
        
             // Try to exhaust the moisted air (Can contradict the control minimun temperature !)
             // alarm[8] = true;            // Humidifier hasn't been implemented yet
             //lcd.clear();
             //lcd.print("High moist");
             //delay(1000);
    }
  }

  if (controlFieldMin > readField) {     // Temperature/Humidity too low.
      if (field == 't') {
           bitWrite(states,6,1);          // Switchs Offthe fan
           bitWrite(states,4,0);          // Switchs On the air heater
           
           bitWrite(alarms,7,1);          // Air cold alarm set as true
           bitWrite(alarms,6,0);          // Air hot alarm set as false
          //alarm[7] = true;    
          
          //lcd.clear();
          //lcd.print("Low Temp");
          //delay(1000);
         }  else {
                  // alarm[9] = true;           // Humidifier hasn't been implemented yet.
                   bitWrite(alarms2,1,1);       // Air dry alarm set as true
                   bitWrite(alarms2,0,0);       // Air moist alarm set as false
                   //lcd.clear();
                   //lcd.print("Low humi");
                   //delay(1000);
    }
  }

  if (controlFieldMax > readField && readField > controlFieldMin) {      // Temperature/Humidity ideal.
        if (field == 't') {
             bitWrite(states,6,0);          // Switchs On the fan
             bitWrite(states,4,1);          // Switchs Off the air heater
             // alarm[9] = false;           // Humidifier hasn't been implemented yet.
             bitWrite(alarms,6,0);          // Air hot alarm set as false  
             bitWrite(alarms,7,0);          // Air cold alarm set as false 
                    
             //lcd.clear();
             //lcd.print("Ideal conditions");
             //delay(1000);
    } else {
             bitWrite(alarms2,1,0);       // Air dry alarm set as true  
             bitWrite(alarms2,0,0);       // Air dry alarm set as true 
      }
  }
}



     // 9  maxTempDefault = 28;
     // 10 minTempDefault = 21;
     // 11 maxHumiDefault = 70;
     // 12 minHumiDefault = 30;

void climateControl () {
     
     // 29 -  maxAirTemp    -aa
     // 30 -  minAirTemp    -ia
     // 31 -  maxHumi       -ah
     // 32 -  minHumi       -ih
  tempCheck();                               // Reads the values from the sensor
  //        maxTemp        minTemp           temp       t
  readDht(EEPROM.read(29), EEPROM.read(30), temperature, 't');   // ReadDht is the control function
  //      maxHumi             minHumi          hum     h
  readDht(EEPROM.read(31), EEPROM.read(32), humidity, 'h');    // Give it the parameters and it will do the rest
}
