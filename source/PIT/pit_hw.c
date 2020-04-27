/*
 * pit_hw.c
 *
 *  Created on: 5/04/2020
 *      Author: vatin
 */

#include "MK64F12.h"
#include "pit_hw.h"

char pit_bandera[4];


void init_hw_pit(void) {
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT->MCR = 0x01;  //se poara en debug
}

void set_hw_pit_timer(int pit, int value) {
	unsigned int ticks;
	unsigned int div2 = 2;
	ticks =	(unsigned int)(((double)( value / (div2))*(double)SystemCoreClock)/1000);
	clr_pit_bandera(pit);
	PIT->CHANNEL[pit].TCTRL = 0;
	PIT->CHANNEL[pit].LDVAL = ticks;
	PIT->CHANNEL[pit].TFLG = PIT_TFLG_TIF_MASK;
	PIT->CHANNEL[pit].TCTRL = PIT_TCTRL_TEN_MASK | PIT_TCTRL_TIE_MASK;
	NVIC_EnableIRQ(PIT0_IRQn+pit);
}


void stop_hw_pit_timer(int pit) {
	PIT->CHANNEL[pit].TCTRL = 0;
}

char get_pit_bandera(int pit) {
	return pit_bandera[pit];
}

void clr_pit_bandera(int pit) {
	pit_bandera[pit]=0;
}


__attribute__((interrupt)) void PIT0_IRQHandler(void) {
	PIT->CHANNEL[0].TFLG = PIT_TFLG_TIF_MASK;
	pit_bandera[0]=1;
}


__attribute__((interrupt)) void PIT1_IRQHandler(void) {
	PIT->CHANNEL[1].TFLG = PIT_TFLG_TIF_MASK;
	pit_bandera[1]=1;
}


__attribute__((interrupt)) void PIT2_IRQHandler(void) {
	PIT->CHANNEL[2].TFLG = PIT_TFLG_TIF_MASK;
	pit_bandera[2]=1;
}


__attribute__((interrupt)) void PIT3_IRQHandler(void) {
	PIT->CHANNEL[3].TFLG = PIT_TFLG_TIF_MASK;
	pit_bandera[3]=1;
}

