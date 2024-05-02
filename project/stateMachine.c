#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"

char toggle()
{
  static char state = 0;

  state = switch_state_down;

  switch (state) {
  case 0:
    red_on = 1;
    green_on = 0;
    //state = 1;
    P2DIR &= ~BIT6;
    break;
  case 1:
    red_on = 0;
    green_on = 1;
    //state = 0;
    P2DIR |= BIT6;
    break;
  }

  return 1;
}

void state_advance()
{
  if(switch_state_changed) {
    toggle();
    led_changed = 1;
  }

  led_update();
  switch_state_changed = 0;
}
