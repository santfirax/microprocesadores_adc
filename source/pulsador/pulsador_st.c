/*
 * pulsador_st.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#include "pulsador_hw.h"
#include "pulsador_st.h"


char estado_pulsador = kPULSADOR_NOPRESS;
char transicion_pulsador = 0;


char pulsador_st_leer(void) {
	return estado_pulsador;
}

/*	off-off		0x01
 * 	off-on		0x02
 * 	on-on		0x04
 * 	on-off		0x08
 */

char pulsador_transicion_leer(void) {
	return transicion_pulsador;
}


void pulsador_st_init(void) {
	pulsador_hw_init();
}


void pulsador_estados(void) {
	switch(estado_pulsador) {
	case kPULSADOR_NOPRESS:
		transicion_pulsador=0x01;
		if (pulsador_hw_leer()==PRESS) {
			estado_pulsador = kPULSADOR_PRESS;
			transicion_pulsador=0x02;
		}
		break;

	case kPULSADOR_PRESS:
		transicion_pulsador=0x04;
		if (pulsador_hw_leer()==NOPRESS) {
			estado_pulsador = kPULSADOR_NOPRESS;
			transicion_pulsador=0x08;
		}
		break;
	}
}
