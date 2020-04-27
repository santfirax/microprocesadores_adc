/*
 * pulsador_st.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#include "pulsador_hw.h"
#include "pulsador_st.h"


char estado_pulsador2 = kPULSADOR_NOPRESS;
char transicion_pulsador2 = 0;
char evento_pulsador2 = 0;


char pulsador_st_leer2(void) {
	return estado_pulsador2;
}

void pulsador_st_reset(void) {
	evento_pulsador2=kPULSADOR2_RESET;
}

/*	off-off		0x01
 * 	off-on		0x02
 * 	on-on		0x04
 * 	on-off		0x08
 */

char pulsador_transicion_leer2(void) {
	return transicion_pulsador2;
}


void pulsador_st_init2(void) {
	pulsador_hw_init2();
}


void pulsador_estados2(void) {
	switch(estado_pulsador2) {
	case kPULSADOR_NOPRESS:
		transicion_pulsador2=0x01;
		if (get_pulsador2_event()==PRESS) {
			estado_pulsador2 = kPULSADOR_PRESS;
			transicion_pulsador2=0x02;
		}
		break;

	case kPULSADOR_PRESS:
		transicion_pulsador2=0x04;
		if (evento_pulsador2==kPULSADOR2_RESET) {
			reset_pulsador2_event();
			estado_pulsador2 = kPULSADOR_NOPRESS;
			transicion_pulsador2=0x08;
		}
		break;
	}
}
