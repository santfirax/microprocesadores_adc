/*
 * adc_api.c
 *
 *  Created on: 10/04/2020
 *      Author: vatin
 */


#include "adc_st.h"
#include "adc_defs.h"

void Init_adc(void) {
	adc_st_init();
}

void Start_adc(void) {
	set_adc_st_event(kADC_EV_Init);
}


char Convert_adc(int channel) {
	if (get_adc_st_estado()!=kADC_NoInit) {
		set_adc_st_channel(channel);
		set_adc_st_event(kADC_EV_Convert);
	} else {
		return -1;
	}
}


char IsResult_adc(void) {
	return (get_adc_st_estado()==kADC_Result)?1:0;
}

int Read_adc_result(void) {
	set_adc_st_event(kADC_EV_Idle);
	return get_adc_st_result();
}

void Reset_adc(void) {
	set_adc_st_event(kADC_EV_Idle);
}

void Stop_adc(void) {
	set_adc_st_event(kADC_EV_LowPower);
}

void ADC_OPS(void) {
	adc_estados();
}
