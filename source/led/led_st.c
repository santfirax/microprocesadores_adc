/*
 * led_st.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "led_hw.h"
#include "led_st.h"



char estado_led=kLED_APAGADO;
char trigger_led=0;
char transicion_led=0;

void led_trigger_set(char var) {
	trigger_led=var;
}

void led_st_init(void) {
	led_hw_init();
}

char led_st_leer(void) {
	return estado_led;
}

/*	off-off		0x01
 * 	off-on		0x02
 * 	on-on		0x04
 * 	on-off		0x08
 */


char led_transicion_leer(void) {
	return transicion_led;
}



void led_estados(void){
	switch(estado_led) {
	case kLED_APAGADO:
		transicion_led=0x01;
		if (trigger_led==ENCENDER_LED) {
			transicion_led=0x02;
			trigger_led=0;
			led_hw_on();
			estado_led=kLED_PRENDIDO;
		}
		break;

	case kLED_PRENDIDO:
		transicion_led=0x04;
		if (trigger_led==APAGAR_LED) {
			transicion_led=0x08;
			trigger_led=0;
			led_hw_off();
			estado_led=kLED_APAGADO;
		}
		break;

	default:
		led_hw_init();
		estado_led=kLED_APAGADO;
		led_hw_off();
	}
}
