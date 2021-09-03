// setupFlags = 0b00000100;
//pumpState, valveInState, valveOutState, lampState, airHeaterState, waterHeaterState, fanState;
//    0            1             2             3            4                5             6

// Save ramdom global booleans in this byte
// 0- flushing
// byte randomBooleans = 0b00000000;  


// alarms
//     0                    1                2            3             4          5          6      7         
//waterLevelTooHigh, waterLevelTooLow, lightOnNoOff, lightOffNoOn, motionStart, motionStop, airHot,airCold,


//alarms2
//    0         1        2         3        4       5        6
//  airMoist,airDry, waterHot, waterCold, phHigh, phLow, waterDetect;



void waterLevel() {               //test it with the final water repository
  byte duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  //This is the optimun level of water.Keep here until flushing
  if (distance < 20 && distance > 15 && bitRead(randomBooleans,0)) {  // Flushing bool in bit 0
       /*lcd.clear();
       lcd.print(F("Pump Working"));
       lcd.setCursor(0, 2);
       lcd.print(F("Valve-In Close"));
       delay(500);
   */    
       bitWrite(states,0,0);   // Turns On the water pump
       bitWrite(states,1,1);   // Turns On the walveWatereIn
       bitWrite(states,2,1);   // Turns On the walveWatereOut
       
       bitWrite(alarms,0,0);   // Water Level Too High Alarm is false
       bitWrite(alarms,1,0);   // Water Level Too Low Alarm is false       
       //alarm[1] = false;
       //alarm[2] = false;
       //lcd.clear();                     // This happens when nothing must to be done.
       //lcd.print(F("Valve-Out Close"));
       //lcd.setCursor(0, 2);
       //lcd.print(F("Valve-In Close"));
       //delay(500);
  }
// 50 cms means empty and 15 too full.
  if (distance < 50 && distance > 20 && bitRead(randomBooleans,0)) {  // Flushing bool in bit 0
      //lcd.clear();
      //lcd.print(F("Pump Working"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-In Open"));
      //delay(500);
      bitWrite(states,0,0);   // Turns On the water pump
      bitWrite(states,1,0);   // Turns On the walveWatereIn
      bitWrite(states,2,1);   // Turns On the walveWatereOut

      bitWrite(alarms,0,0);   // Water Level Too High Alarm is false
      bitWrite(alarms,1,0);   // Water Level Too Low Alarm is false  
     
     // alarm[1] = false;
     // alarm[2] = false;
      //lcd.clear();                     // This happens when refilling the tank.
      //lcd.print(F("Valve-Out Close"));
      //lcd.setCursor(0, 2);
     // lcd.print(F("Valve-In Open"));
      //delay(500);
  }

  if (distance < 50 && distance > 15 && bitRead(randomBooleans,1)) {  // Flushing bool in bit 0
      //lcd.clear();
      //lcd.print(F("Pump Working"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-In Close"));
      //delay(500);
      bitWrite(states,0,0);   // Turns On the water pump
      bitWrite(states,1,1);   // Turns On the walveWatereIn
      bitWrite(states,2,0);   // Turns On the walveWatereOut
      
      bitWrite(alarms,0,0);   // Water Level Too High Alarm is false
      bitWrite(alarms,1,0);   // Water Level Too Low Alarm is false  
      //alarm[1] = false;
      //alarm[2] = false;
      //lcd.clear();
      //lcd.print(F("Valve-In Close"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-Out Open"));
  }

  if (distance > 50 ) {
      //lcd.clear();
      //lcd.print(F("Pump Stopped"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-In Open"));
      //delay(500);
      bitWrite(states,0,1);      // Turns Off the water pump
      bitWrite(states,1,0);      // Turns On the walveWatereIn
      bitWrite(states,2,1);      // Turns Off the walveWatereOut
      bitRead(randomBooleans,0); // Sets flushing bit to 0
      
      bitWrite(alarms,0,0);   // Water Level Too High Alarm is false
      bitWrite(alarms,1,1);   // Water Level Too Low Alarm is true  
      //lcd.clear();
      //lcd.print(F("Valve-In Open"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-Out Close"));
      //delay(500);
     // alarm[2] = true;                       // I only know to change them in this way.
  }

  if (distance < 15) {
      //lcd.clear();
      //lcd.print(F("Pump Stopped"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-In Close"));
      //delay(500);
      bitWrite(states,0,1);   // Turns Off the water pump
      bitWrite(states,1,1);   // Turns Off the walveWatereIn
      bitWrite(states,2,0);   // Turns On the walveWatereOut

      bitWrite(alarms,0,1);   // Water Level Too High Alarm is true
      bitWrite(alarms,1,0);   // Water Level Too Low Alarm is false  
    
      //lcd.clear();                           // An alarm is reported to the AlarmHandler.
      //lcd.print(F("Valve-In Close"));
      //lcd.setCursor(0, 2);
      //lcd.print(F("Valve-Out Open"));
      //delay(500);
      // alarm[1] = true;                       // I only know to change them in this way.   
  }


  // If distance is minor than 0 there is some error
  if(distance < 0 ){
      distance = 1;
      //alarm[1] = true;                       // Report Alarm
    }

}
