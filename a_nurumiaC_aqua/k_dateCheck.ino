
/*This page will handle all the time related features. From the date when it started ,to calculate from it when to change to veg,to flo,to
end. // 17 -  daysInVeg
     // 18 -  hoursInVeg
     // 19 -  hourOnVeg
     // 20 -  hourOffVeg
     // 21 -  daysInFlo
     // 22 -  hoursInFlo
     // 23 -  hourOnFlo
     // 24 -  hourOffFlo
      // setupFlags = 0b00000100;
      // vegFlag, floFlag, endFlag, newSetupFlag, firstTimeFlag, firstDayFlag, foreverVeg, foreverFlo;  <- from right to left
      // 25 - startTime      Only this variable is needed . It stores a byte with an unsigned number    
      // 26 - firstDayBoolFlag(inByte)
*/

void postData() {
  
  String string = F("p t=");
  string += (String)temperature;
  string += F("&h=");
  string += (String)humidity ;  
  string += F("&wt=");
  string += (String)waterTemperature ;
  string += F("&wl=");
  string += (String)distance ;
  string += F("&wp=");
  string += (String)phValue ;
  string += F("&cp=");
  string += (String)bitRead(states,0) ; 
  string += F("&cwh=");
  string += (String)bitRead(states,5) ; 
  string += F("&cah=");
  string += (String)bitRead(states,4) ; 
  string += F("&cf=");
  string += (String)bitRead(states,7) ; 
  string += F("&cl=");
  string += (String)bitRead(states,3) ;      
  Serial.flush();
  lcd.clear();
  Serial.println(string);
  delay(1000);
  Serial.flush();
 /* 
 itoa(temperature, st,DEC);
  itoa(humidity,sh,DEC);
  itoa(waterTemperature,swt,DEC);
  itoa(distance,swl,DEC);
  itoa(phValue,sph,DEC);      
  itoa(bitRead(states,0),sp,DEC);        // gets the pumpState 
  itoa(bitRead(states,5),swh,DEC);       // gets the waterheater
  itoa(bitRead(states,4),sah,DEC);       // gets the airheater
  itoa(bitRead(states,7),sf,DEC);        // gets the fan state  ATTENTION this bit doesnt go to the relays
  itoa(bitRead(states,3),sl,DEC);        // gets the lamp state
*/
 //Serial.println("p t=21&h=12&wt=7&wl=22&wp=10&cp=1&cwh=1&cah=1&cf=1&cl=0");
}

void dateCheck() {
     DateTime now = RTC.now();
     countDaysSinceStart();         // Accounts the number of passed days
     vegOrFlowFlags();              // Watcdogs if it is in vegetative or flowering period
      
      // 26 - firstDayBoolFlag(inByte) and setupFlags,2 are both flags to know if its the first day
      if ((EEPROM.read(26) == 1) && (bitRead(setupFlags,2) == 1 )){   
          firstDay();
       }

     if(temperature != 0 && humidity != 0 ) {
         if (thisHour != now.hour() ) {
               thisHour = now.hour();                     
               postData();      
      }    
     }      

}

void countDaysSinceStart(){
      // Calculate a date which is 7 days and 30 seconds into the future
      DateTime now = RTC.now(); 
      unsigned long nowT = now.unixtime();  
      unsigned long lastT = now.unixtime();    
      lastT = EEPROM.get(25,lastT);        
      DateTime passed (nowT - lastT  );
      daysPassed = (passed.day(),DEC);   // Passes the days to daysPassed to be contrasted
      daysPassed = daysPassed / 86400L;  // The number of seconds / seconds in a day 
      thisDay = now.day();               // Lets synchronize days to keep the account
 
  }

void vegOrFlowFlags(){
   /* This functions check continuosly the state of the veg and flo flags*/
     if(daysPassed >= EEPROM.read(17)){   //if days are more than days in veg
        bitWrite(setupFlags,7,0);         // Sets vegFlag to 0
        bitWrite(setupFlags,6,1);         // Sets floFlag to 1 
      } else {
               bitWrite(setupFlags,7,1);  // Sets vegFlag to 0
               bitWrite(setupFlags,6,0);  // Sets floFlag to 1 
        }
  }  
