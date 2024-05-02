#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "stateMachine.h"
#include "switches.h"

int main() {
  configureClocks();

  switch_init();
  led_init();
  enableWDTInterrupts();
  buzzer_init();
  buzzer_set_period(7777);
  
  or_sr(0x18);
}

void __interrupt_vec(WDT_VECTOR) WDT(){ // 250 interrupts a second
  static char blink_count = 0;
  if(++blink_count == 250) {
    //state_advance();
    blink_count = 0;
  }
} 


void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES) {
    P1IFG &= ~SWITCHES;
    switch_interrupts();
  }
}
