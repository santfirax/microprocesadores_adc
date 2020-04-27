/*
 * adc_defs.h
 *
 *  Created on: 10/04/2020
 *      Author: vatin
 */

#ifndef ADC_ADC_DEFS_H_
#define ADC_ADC_DEFS_H_

enum {
	kADC_EV_Init=1,
	kADC_EV_Convert,
	kADC_EV_ConvertSinInt,
	kADC_EV_Idle,
	kADC_EV_LowPower,
};

enum {
	kADC_NoInit=0,
	kADC_Idle,
	kADC_Converting,
	kADC_Result,
	kADC_LowPower,
};


#endif /* ADC_ADC_DEFS_H_ */
