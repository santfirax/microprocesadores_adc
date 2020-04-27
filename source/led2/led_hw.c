/*
 * led_hw.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */
#include "MK64F12.h"


#define BIT_LED2		6
#define MASK_LED2		(1<<BIT_LED)


void led_hw_init2(void) {
	//inicializar el led
}

void led_hw_on2(void) {
	//PCOR = MASK_LED
}

void led_hw_off2(void) {
	//PSOR = MASK_LED
}

