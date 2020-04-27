/*
 * pulsador_api.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "pulsador_st.h"
#include "pulsador_api.h"


void PULSADOR_OPS(void) {
	pulsador_estados();
}

void Init_Pulsador(void) {
	pulsador_st_init();
}

char Leer_pulsador(void) {
	return pulsador_st_leer();
}

char Leer_evento_pulsador(void) {
	return pulsador_transicion_leer();
}


