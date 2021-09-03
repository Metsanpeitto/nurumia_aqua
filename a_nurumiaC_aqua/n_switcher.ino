void switcher(){
     //states = 0b00000000;
     //states = 0b01011111;
     
     //   IN1                                                                  IN6
     //pumpState, valveInState, valveOutState, lampState, airHeaterState, waterHeaterState
     //    0           1             2             3             4               5           


     if(states != statesLast  ){    
     
        for(byte i=0;i<=6;i++){
             bitWrite(statesLast, i, bitRead(states,i));
             delay(40);
             if(i == 0){ digitalWrite(pump,bitRead(states,i));}
             if(i == 1){ digitalWrite(valveIn,bitRead(states,i));}
             if(i == 2){ digitalWrite(valveOut,bitRead(states,i));}
             if(i == 3){ digitalWrite(lamp,bitRead(states,i));}
             if(i == 4){ digitalWrite(airHeater,bitRead(states,i));}
             if(i == 5){ digitalWrite(waterHeater,bitRead(states,i));}           
          }

          jsonParser('c');
      } 

    if((alarms != alarmsLast) || (alarms2  != alarmsLast2)){
      jsonParser('a');
      alarmsLast   = alarms;
      alarmsLast2  = alarmsLast;     
     }          
  }
