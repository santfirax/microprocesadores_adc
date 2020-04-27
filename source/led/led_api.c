/*
 * led_api.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "led_st.h"
#include "led_api.h"

void Encender_led(void) {
	led_trigger_set(ENCENDER_LED);
}

void Apagar_led(void) {
	led_trigger_set(APAGAR_LED);
}

void Alternar_led(void) {
	if (led_st_leer()==kLED_PRENDIDO) {
		Apagar_led();
	} else {
		Encender_led();
	}
}

void LED_OPS(void) {
	led_estados();
}

void Init_Led(void) {
	led_st_init();
}
