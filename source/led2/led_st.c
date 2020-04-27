/*
 * led_st.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "led_hw.h"
#include "led_st.h"



char estado_led2=kLED_APAGADO;
char trigger_led2=0;
char transicion_led2=0;

void led_trigger_set2(char var) {
	trigger_led2=var;
}

void led_st_init2(void) {
	led_hw_init2();
}

char led_st_leer2(void) {
	return estado_led2;
}

/*	off-off		0x01
 * 	off-on		0x02
 * 	on-on		0x04
 * 	on-off		0x08
 */


char led_transicion_leer2(void) {
	return transicion_led2;
}



void led_estados2(void){
	switch(estado_led2) {
	case kLED_APAGADO:
		transicion_led2=0x01;
		if (trigger_led2==ENCENDER_LED) {
			transicion_led2=0x02;
			trigger_led2=0;
			led_hw_on2();
			estado_led2=kLED_PRENDIDO;
		}
		break;

	case kLED_PRENDIDO:
		transicion_led2=0x04;
		if (trigger_led2==APAGAR_LED) {
			transicion_led2=0x08;
			trigger_led2=0;
			led_hw_off2();
			estado_led2=kLED_APAGADO;
		}
		break;

	default:
		led_hw_init2();
		estado_led2=kLED_APAGADO;
		led_hw_off2();
	}
}
