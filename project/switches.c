#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"

char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES); // switch up sense down
  P2IES &= (p2val | ~SWITCHES); // switch down sense up
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES; // enable resistors
  P2IE |= SWITCHES; // enable interrupts
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES; // set only switch bits for input

  // you can add P1.3 initialization here, if you want to
  
  switch_update_interrupt_sense();
}

//int switches = 0;

void switch_interrupts()
{
  char p2val = switch_update_interrupt_sense();
  //switches = ~p2val & SWITCHES;
  switch_state_down = (p2val & SW2) ? 0 : 1; // 0 when sw2 on booster board is up
  switch_state_changed = 1;
  state_advance();
}
