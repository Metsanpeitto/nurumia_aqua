
void firstDay() { // this will be the first time running the code .Comes from two flags firstTimeFlag = true-> firstDayFlag
  // This is really important function. Here er store now() in 4 bytes of uint32_t timeStamp = now()
  //then we store it in the eeprom and we access it always that need to calculate dates.

  
  //byte setupFlags=> vegFlag, floFlag, endFlag, newSetupFlag, firstTimeFlag, firstDayFlag, foreverVeg, foreverFlo;  
  
  //firstDayDay, firstDayMonth, daysInVeg, daysInFlo, lastDayOnDay, lastDayOnMonth, 
  //firstDayBoolean, hoursInVeg, hoursInFlo, hoursPassed,
  // 25 - startTime      Only this variable is needed . It stores a byte with an unsigned number    
  // 26 - firstDayBoolFlag(inByte)
 
  //lcd.clear();
  //lcd.print(F("firstDay !"));
  //delay(1000);
  
 // Store all elements needed to calculate dates 
 // It takes 6 bytes
  DateTime now = RTC.now(); 
  byte nowT = now.unixtime();   
  EEPROM.write(25,nowT); 
  delay(40);
  EEPROM.write(26,0);                    // Sets first day flag to false
  delay(400);

  bitWrite(setupFlags,7,1);             // Sets vegFlag to 1
  bitWrite(setupFlags,6,0);             // Sets floFlag to 0
  bitWrite(setupFlags,3,0);             // Sets firstTimeFlag to 0
  bitWrite(setupFlags,2,0);             // Sets firstDayFlag to 0 

}
