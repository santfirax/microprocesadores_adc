/*
 * adc_api.h
 *
 *  Created on: 10/04/2020
 *      Author: vatin
 */

#ifndef ADC_ADC_API_H_
#define ADC_ADC_API_H_

void Init_adc(void);
void Start_adc(void);
char Convert_adc(int channel);
char IsResult_adc(void);
int Read_adc_result(void);
void Reset_adc(void);
void Stop_adc(void);
void ADC_OPS(void);

#endif /* ADC_ADC_API_H_ */
