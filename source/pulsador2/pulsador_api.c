/*
 * pulsador_api.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "pulsador_st.h"
#include "pulsador_api.h"


void PULSADOR_OPS2(void) {
	pulsador_estados2();
}

void Init_Pulsador2(void) {
	pulsador_st_init2();
}

char Leer_pulsador2(void) {
	return pulsador_st_leer2();
}

char Leer_evento_pulsador2(void) {
	return pulsador_transicion_leer2();
}

void Reset_pulsador2(void) {
	pulsador_st_reset();
}


