/*
 * adc_hw.h
 *
 *  Created on: 9/04/2020
 *      Author: vatin
 */

#ifndef ADC_ADC_HW_H_
#define ADC_ADC_HW_H_

void adc_hw_init(void);
void adc_hw_config(void);
void adc_hw_convertir(char channel, char conInt);
char adc_hw_esFin(void);
int adc_hw_readResult(void);

#endif /* ADC_ADC_HW_H_ */
