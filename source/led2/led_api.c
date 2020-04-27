/*
 * led_api.c
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */


#include "led_st.h"
#include "led_api.h"

void Encender_led2(void) {
	led_trigger_set2(ENCENDER_LED);
}

void Apagar_led2(void) {
	led_trigger_set2(APAGAR_LED);
}

void Alternar_led2(void) {
	if (led_st_leer2()==kLED_PRENDIDO) {
		Apagar_led2();
	} else {
		Encender_led2();
	}
}

void LED_OPS2(void) {
	led_estados2();
}

void Init_Led2(void) {
	led_st_init2();
}
