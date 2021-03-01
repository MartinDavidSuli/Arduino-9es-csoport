


#include <IRremote.h>
#include <Keyboard.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  Keyboard.begin();
}

void loop() {
  if (irrecv.decode()) 
  {
   
                  
      switch(results.value)
      {
                        
        case 0x9A650707:  Keyboard.press(KEY_LEFT_ARROW); //left key
                         delay(100);
                         Keyboard.releaseAll();
                         break;
    
        case 0x9D620707:  Keyboard.press(KEY_RIGHT_ARROW); //right  key
                         delay(100);
                         Keyboard.releaseAll();
                         break;  
       
        case 0x9E610707:  Keyboard.write(32);//space bar operation
                         delay(100);
                         Keyboard.releaseAll();
                         break; 
      
                 
      }  
    irrecv.resume(); // Receive the next value
  }
}
