#include "lpc17xx_gpio.h"
#include "lpc_types.h"

//Define constants for LPC17xx lines:
#define LED1 0x00040000	//LINE 18
#define LED2 0x00100000	//LINE 20
#define LED3 0x00200000	//LINE 21
#define LED4 0x00800000	//LINE 23

//Implement a lookup table to prevent big calculations
uint32_t leds[16] =
{ 0x00000000, 0x00040000, 0x00100000, 0x00140000, 
  0x00200000, 0x00240000, 0x00300000, 0x00340000,
  0x00800000, 0x00840000, 0x00900000, 0x00940000,
  0x00A00000, 0x00A40000, 0x00B00000, 0x00B40000 } ;

uint32_t total = LED1^LED2^LED3^LED4;

void delay(int wait);

void flash(uint32_t led);

void showNumber(int number);

int main (void) {
	int i=0;	

	GPIO_SetDir(1, total, 1);
	
	for (i; i<16; i++) { 
		showNumber(i);
	}

	return (0);
}

void showNumber(int number) {
	number %= 16;
	flash(leds[number]);
}

void delay(int wait) {
	int i=0;
	for (i; i<wait; i++) {
		volatile int k=9999999;
		while (k>1) {
			k--;
		}
	}
}

void flash(uint32_t led) {
	GPIO_SetValue(1, led);
	delay(1);
	GPIO_ClearValue(1, led);
}
