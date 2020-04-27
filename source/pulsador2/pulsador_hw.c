/*
 * pulsador_hw.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#include "fsl_port.h"		//para usar las constantes de puerto
#include "pulsador_hw.h"
#include "MK64F12.h"

#define BIT_PULSADOR		6
#define MASK_PULSADOR	(1<<BIT_PULSADOR)


char pulsador2_press=NOPRESS;

void pulsador_hw_init2(void) {
	SIM->SCGC5 |=SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[BIT_PULSADOR] = PORT_PCR_MUX(1) | PORT_PCR_PE(1) | PORT_PCR_PS(1);
//configura irq
	PORTC->PCR[BIT_PULSADOR] |= PORT_PCR_IRQC(kPORT_InterruptFallingEdge);
//limpiar la bandera
	PORTC->PCR[BIT_PULSADOR] |= PORT_PCR_ISF_MASK;  //una forma
	PORTC->ISFR = (MASK_PULSADOR);					//otra forma igual

	NVIC_EnableIRQ(PORTC_IRQn);
}

char get_pulsador2_event(void) {
	return pulsador2_press;
}

void reset_pulsador2_event(void) {
	pulsador2_press = NOPRESS;
}


__attribute__((interrupt)) void PORTC_IRQHandler(void) {
	if ((PORTC->ISFR & MASK_PULSADOR)!=0) {
		//es este pin
		pulsador2_press=PRESS;
		PORTC->ISFR = (MASK_PULSADOR);  //limpiar la badera

	}

}
