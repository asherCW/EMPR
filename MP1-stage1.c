#include "lpc17xx_gpio.h"
#include "lpc_types.h"

//Define constants for LPC17xx lines:
#define LED1 0x00040000	//LINE 18
#define LED2 0x00100000	//LINE 20
#define LED3 0x00200000	//LINE 21
#define LED4 0x00800000	//LINE 23

uint32_t total = LED1^LED2^LED3^LED4;

void delay(int wait);

void flash(uint32_t led);

int main (void) {
	int i=0;	

	GPIO_SetDir(1, total, 1);
	
	for (i; i<2; i++) { 
		flash(LED1);
		flash(LED2);
		flash(LED3);
		flash(LED4);
	}

	return (0);
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
