#include <msp430.h>
#include "led.h"

unsigned char red_on = 0, green_on = 0, led_changed = 0;

static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS; //sets these bits to output mode
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];

    P1OUT &= (0xff^LEDS) | ledFlags; // clear bits for off leds (ignore on leds)
    P1OUT |= ledFlags; // set bits for on leds
    led_changed = 0;
  }
}
