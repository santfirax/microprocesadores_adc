/*
 * led_hw.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */
#include "MK64F12.h"


#define BIT_LED		6
#define MASK_LED	(1<<BIT_LED)


void led_hw_init(void) {
	//inicializar el led
}

void led_hw_on(void) {
	//PCOR = MASK_LED
}

void led_hw_off(void) {
	//PSOR = MASK_LED
}

