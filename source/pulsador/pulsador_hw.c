/*
 * pulsador_hw.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "pulsador_hw.h"

#define BIT_PULSADOR		4
#define MASK_PULSADOR	(1<<BIT_PULSADOR)

void pulsador_hw_init(void) {
	//init del pulsador PORTA,4
}

char pulsador_hw_leer(void) {
	if (1) {	//if (PDIR  & MASK_PULSADOR) !=0
		return NOPRESS;	//
	}
	return PRESS;
}
