//       17         19         21        23            27                 28               29             30               31             32        33      34
//byte daysInVeg, hourOnV, daysInFlo, hourOnF, maxWaterTempCustom, minWaterTempCustom, maxTempCustom, minTempCustom, maxHumiCustom, minHumiCustom ,maxPh , minPh;
//byte daysInVeg, daysInFlo, hourOnV, hourOnF, maxWaterTempCustom, minWaterTempCustom, maxTempCustom, minTempCustom, maxHumiCustom, minHumiCustom ;
//byte setupValues[] = {0,0,0,0,0,0,0,0,0,0,0,0};


void jsonSetupIn(byte setupValues[]){
      maxTempCustom       = setupValues[0];
      maxHumiCustom       = setupValues[1]; 
      maxPh               = setupValues[2];
      maxWaterTempCustom  = setupValues[3];
      daysInFlo           = setupValues[4];
      daysInVeg           = setupValues[5];
      minTempCustom       = setupValues[6];  
      minHumiCustom       = setupValues[7];
      minPh               = setupValues[8];
      minWaterTempCustom  = setupValues[9];
      hourOnF             = setupValues[10];
      hourOnV             = setupValues[11];    
   

      EEPROM.write(17,daysInVeg);                    //  17 -  daysInVeg     -dv
      delay(100);
      EEPROM.write(19,hourOnV);                      //  19 -  hourOnV     -ov
      delay(100);
      EEPROM.write(21,daysInFlo);                    //  21 -  daysInFlo     -df
      delay(100);
      EEPROM.write(23,hourOnF );                     //  23 -  hourOnF     -of
      delay(100);  
      EEPROM.write(27,maxWaterTempCustom);           //  27 -  maxWaterTempCustom -aw
      delay(100);
      EEPROM.write(28,minWaterTempCustom);           //  28 -  minWaterTempCustom  -iw
      delay(100);
      EEPROM.write(29, maxTempCustom);               //  29 -  maxTempCustom    -aa  
      delay(100);  
      EEPROM.write(30,minTempCustom );               //  30 -  minTempCustom    -ia
      delay(100);  
      EEPROM.write(31,maxHumiCustom);                //  31 -  maxHumiCustom       -ah
      delay(100);  
      EEPROM.write(32,minHumiCustom);                //  32 -  minHumiCustom       -ih
      delay(100);  
      EEPROM.write(33,maxPh);                        //  33 -  maxPh         -ap
      delay(100);  
      EEPROM.write(34,minPh);                        //  34 -  minPh         -ap
      delay(100);    

  /*
      lcd.clear();
      lcd.print("days in veg");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(17));
      delay(3000);
      lcd.clear();
      lcd.print("hour veg");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(19));
        delay(3000);
       lcd.clear();
      lcd.print("dyas in flo");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(21));
        delay(3000);
       lcd.clear();
      lcd.print("hours in flo");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(23));
        delay(3000);
       lcd.clear();
      lcd.print("maxWaterTempCustom");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(27));
        delay(3000);
       lcd.clear();
      lcd.print("minWaterTempCustom");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(28));
        delay(3000);
       lcd.clear();
      lcd.print("maxTempCustom");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(29));
        delay(3000);
       lcd.clear();
      lcd.print("minTempCustom");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(30));
        delay(3000);
       lcd.clear();
      lcd.print("maxHumiCustom");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(31));
        delay(3000);
       lcd.clear();
      lcd.print("minHumiCustom");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(32));
        delay(3000);
       lcd.clear();
      lcd.print("maxPh");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(33));
        delay(3000);
       lcd.clear();
      lcd.print("minPh");
      lcd.setCursor(0,2);
      lcd.print( EEPROM.read(34));
        delay(3000);

    */    
  }
