/*
 * led_st.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef LED_LED_ST2_H_
#define LED_LED_ST2_H_


#define ENCENDER_LED	0x01
#define APAGAR_LED		0x02

enum {
	kLED_APAGADO=0,
	kLED_PRENDIDO,
	kLED_INIT,
};


void led_st_init2(void);
void led_trigger_set2(char var);
void led_estados2(void);
char led_st_leer2(void);
char led_transicion_leer2(void);

#endif /* LED_LED_ST_H_ */
