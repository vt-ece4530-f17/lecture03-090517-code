#include "omsp_system.h"

void delay( ) {
  volatile int k;
  for (k=0; k<500; k++)
    ;
}

int main(void) {
  P1DIR = 0xFF;              
  WDTCTL = WDTPW | WDTHOLD;

  P1OUT = 0xFF;
  while (1) {
    delay();
    P1OUT = ~P1OUT;
  }

  return 0;
}
