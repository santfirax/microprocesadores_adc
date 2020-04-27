/*
 * adc_st.c
 *
 *  Created on: 10/04/2020
 *      Author: vatin
 */


#include "adc_hw.h"
#include "adc_st.h"
#include "adc_defs.h"

char estado_adc;
char evento_adc;
char channel_adc;
int result_adc;


void adc_st_init(void) {
	adc_hw_init();
}

void adc_st_config(void) {
	adc_hw_config();
}

void set_adc_st_channel(char channel) {
	channel_adc=(channel & 0x1f);
}

void set_adc_st_event(char event) {
	evento_adc=event;
	return;
}

int get_adc_st_result(void) {
	return result_adc;
}

char get_adc_st_estado(void) {
	return estado_adc;
}


void adc_estados(void) {
	switch(estado_adc) {
	case kADC_NoInit:
		if (evento_adc==kADC_EV_Init) {
			estado_adc = kADC_Idle;
			adc_st_config();
		}
		break;

	case kADC_Idle:
		if (evento_adc==kADC_EV_Convert) {
			adc_hw_convertir(channel_adc, 1);
			estado_adc=kADC_Converting;
		}
		if (evento_adc==kADC_EV_ConvertSinInt) {
			adc_hw_convertir(channel_adc, 0);
			estado_adc=kADC_Converting;
		}
		if (evento_adc==kADC_EV_LowPower) {
			adc_hw_convertir(0x1f, 0);
			estado_adc=kADC_LowPower;
		}
		break;

	case kADC_Converting:
		if (adc_hw_esFin()!=0) {
			estado_adc=kADC_Result;
			result_adc=adc_hw_readResult();
		}
		break;

	case kADC_Result:
		if (evento_adc==kADC_EV_Idle) {
			estado_adc=kADC_Idle;
		}
		break;

	case kADC_LowPower:
		if (evento_adc==kADC_EV_Convert) {
			adc_hw_convertir(channel_adc, 1);
			estado_adc=kADC_Converting;
		}
		if (evento_adc==kADC_EV_ConvertSinInt) {
			adc_hw_convertir(channel_adc, 0);
			estado_adc=kADC_Converting;
		}

	}
	evento_adc=0;
}
