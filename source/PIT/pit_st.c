/*
 * pit_st.c
 *
 *  Created on: 5/04/2020
 *      Author: vatin
 */

#include "pit_hw.h"
#include "pit_st.h"

char pit_enabled[4];
char pit_estado[4];
char pit_evento[4];
int pit_valor[4];

#define PIT_HABILITADO		pit_enabled[i]
#define PIT_ESTADO			pit_estado[i]
#define PIT_EVENTO			pit_evento[i]
#define PIT_VALOR			pit_valor[i]


void init_st_pit(void) {
	int i;
	init_hw_pit();
	pit_enabled[0]=0;
	pit_enabled[1]=0;
	pit_enabled[2]=0;
	pit_enabled[3]=0;
	clr_pit_bandera(0);
	clr_pit_bandera(0);
	clr_pit_bandera(0);
	clr_pit_bandera(0);
	for(i=0;i<4;i++) PIT_ESTADO=kPIT_STOP;
}


char get_pit_estado(int pit) {
	return pit_estado[pit];
}

void set_pit_enabled(int pit) {
	pit_enabled[pit]=1;
}

void clear_pit_enabled(int pit) {
	pit_enabled[pit]=1;
}

void set_pit_evento(int pit,char evento) {
	pit_evento[pit]=evento;
}

void set_pit_valor(int pit,int valor) {
	pit_valor[pit]=valor;
}


void pit_estados(void) {
	int i;
	for(i=0;i<4;i++) {
		if (PIT_HABILITADO) {
			switch(PIT_ESTADO) {
			case kPIT_STOP:
				if (PIT_EVENTO==kPIT_EV_START) {
					set_hw_pit_timer(i, PIT_VALOR);
					PIT_ESTADO=kPIT_RUN;
				}
				break;

			case kPIT_RUN:
				if (PIT_EVENTO==kPIT_EV_STOP) {
					stop_hw_pit_timer(i);
					PIT_ESTADO=kPIT_STOP;
					break;
				}
				if (get_pit_bandera(i)!=0) {
					clr_pit_bandera(i);
					PIT_ESTADO=kPIT_FLAG;
				}
				break;

			case kPIT_FLAG:
				if (PIT_EVENTO==kPIT_EV_STOP) {
					stop_hw_pit_timer(i);
					PIT_ESTADO=kPIT_STOP;
					break;
				}
				if (PIT_EVENTO==kPIT_EV_CLEAR) {
					PIT_ESTADO=kPIT_RUN;
				}
				break;
			}
			PIT_EVENTO=0;
		}
	}
}



