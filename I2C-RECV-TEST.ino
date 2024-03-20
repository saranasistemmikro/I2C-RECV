#include <Wire.h>
uint8_t  I2CReady;
char     bufferI2C[30];
uint8_t  i2caddr =15;
// modified by Andi Ikhwan D/ SARANA SISTEM MIKRO
//  MARCH 20.2024

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println("reset");
    i2caddr =15;
    I2CReady=0;
    Wire.begin(i2caddr);                // join i2c bus with address #8nanti dikembalikan
    Wire.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (I2CReady)
    {
       Serial.print("I2C-Receiver : ");
      Serial.print(bufferI2C);
      I2CReady=0;
    }  

}

void receiveEvent(int howMany) {
  char s[30];
  byte i;
  i=0;
  while (1 < Wire.available()) 
  { // loop through all but the last
     char c = Wire.read(); // receive byte as a character
      if (i<27)   // maximum pengiriman =25
        {
          s[i]=c;
          i++;
        }
        
  }
      int x = Wire.read();    // receive byte as an integer
      if (i<27)
        {
           s[i]= (char) x;
           i++;
           s[i]= '\0';
        }


     strcpy(bufferI2C,s);
        
     I2CReady=1;
         
     
      
  
}
