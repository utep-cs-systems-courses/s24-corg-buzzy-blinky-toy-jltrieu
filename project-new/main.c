// the previous project made me really mad bc it was a huge pain to bounce between files in emacs
// so i am going to do the infinitely worse thing of stuffing all of the code into a single file
// with the exception of state machine code which will be written in ASM
#include <msp430.h>
#include "libTimer.h"

// LED DEFINES
#define LED_RED BIT6 //P1.6
#define LED_GREEN BIT0 //P1.0
#define LEDS (LED_RED | LED_GREEN)

int main(void)
{
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  or_sr(0x18); // CPU off, GIE on
}
