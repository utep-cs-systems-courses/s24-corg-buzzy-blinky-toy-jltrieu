#ifndef switches_included
#define switches_included

#define SWB BIT3 /* p1.3 */
#define SW1 1 /* second board switches */
#define SW2 2
#define SW3 4
#define SW4 8

#define SWITCHES 15

extern char switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense();
void switch_init();
void switch_interrupts();

#endif
