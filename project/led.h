#ifndef led_included
#define led_included

#define LED_RED BIT6 //P1.6
#define LED_GREEN BIT0 //P1.0
#define LEDS (LED_RED | LED_GREEN)

extern unsigned char red_on, green_on, led_changed;

void led_init();
void led_update();

#endif
