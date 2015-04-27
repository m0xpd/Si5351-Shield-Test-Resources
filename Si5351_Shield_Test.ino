/*
Si5351_Shield_Test

Simple Test Sketch for the 
Kanga / m0xpd Si5351 RF Generation System 

m0xpd
April 2015
 
Available from Kanga-UK:
http://www.kanga-products.co.uk/

=======================================================
LIBRARY Includes...
You MUST have installed
Jason Milldrum, nt7s' Si5351 library, which is available here:
https://github.com/etherkit/Si5351Arduino

========================================================
*/

#include<stdlib.h>
#include <Wire.h>
#include "si5351.h" 

// Instantiate the Si5351...
Si5351 si5351; 
  int f;

void setup() {
  // Initialize the Si5351
  si5351.init(SI5351_CRYSTAL_LOAD_8PF);  
  si5351.set_pll(SI5351_PLL_FIXED, SI5351_PLLA);
  // set up CLK 0,1 and 2 for Demo...
  // Set CLK0 to output 14 MHz with a fixed PLL frequency
  si5351.set_pll(SI5351_PLL_FIXED, SI5351_PLLA);
  si5351.set_freq(14000000, SI5351_PLL_FIXED, SI5351_CLK0);
  // Set CLK1 to output 7 MHz
  si5351.set_freq(7000000, 0, SI5351_CLK1);
  // Initialise a simple, grainy "sweep" on CLK 2
  f=1;
  si5351.set_freq(f*1000000, SI5351_PLL_FIXED, SI5351_CLK2); 
}

void loop() {
  delay(1000);
  f=f+1;
  if(f>10){
  f=1;
  }
  si5351.set_freq(f*1000000, SI5351_PLL_FIXED, SI5351_CLK2);
}
