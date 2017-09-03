#include "omsp_system.h"

extern unsigned char *k;

int main(void) {
  P1DIR = 0x00; // input
  WDTCTL = WDTPW | WDTHOLD;

  while (1)
    k[0]++;

  return 0;
}
