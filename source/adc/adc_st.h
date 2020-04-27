/*
 * adc_st.h
 *
 *  Created on: 10/04/2020
 *      Author: vatin
 */

#ifndef ADC_ADC_ST_H_
#define ADC_ADC_ST_H_

void adc_st_init(void);
void set_adc_st_channel(char channel);
void set_adc_st_event(char event);
int get_adc_st_result(void);
char get_adc_st_estado(void);
void adc_estados(void);

#endif /* ADC_ADC_ST_H_ */
