/*
 * adc_hw.c
 *
 *  Created on: 9/04/2020
 *      Author: vatin
 */

#include "MK64F12.h"
#include "adc_hw.h"

int adc_result;


void adc_hw_init(void) {
	SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
}

void adc_hw_config(void) {
	ADC0->CFG1 = ADC_CFG1_ADICLK(0) |   //0 = BUS CLOCK
			ADC_CFG1_ADIV(2) |			//2 =  divisor = 4
			ADC_CFG1_ADLPC(0) |			//0 = Configuración normal energia
			ADC_CFG1_ADLSMP(1) |		//1 = Long Sample
			ADC_CFG1_MODE(3);			//3 = 16 bits

	ADC0->CFG2 = ADC_CFG2_ADACKEN(0) |	//clock asincrónico apagado
			ADC_CFG2_ADHSC(0) |			//conversión normal
			ADC_CFG2_ADLSTS(3) |		//tiempo de muestro corto  //MODIFICAR Y OBSERVAR
			ADC_CFG2_MUXSEL(0);			//Canal A

	ADC0->SC2 = ADC_SC2_ACFE(0) |		//comparador desabilitado
			ADC_SC2_ACFGT(0) |			//comparador en menor que
			ADC_SC2_ACREN(0) |			//habilita una comparación de ventana
			ADC_SC2_ADTRG(0) |			//inicio conversión por software
			ADC_SC2_DMAEN(0) |			//uso de DMA deshabilitado
			ADC_SC2_REFSEL(0);			//referencia en pines VREFH y VREFL

	ADC0->SC3 = ADC_SC3_ADCO(0) |		//Conversion continua desabilitada
			ADC_SC3_AVGE(0) |			//Promedio desabilitado
			ADC_SC3_AVGS(3) |			//promedio de 32
			ADC_SC3_CAL(0);				//No calibrar
	return;
}


void adc_hw_convertir(char channel, char conInt) {
	ADC0->SC1[0] = channel | ADC_SC1_AIEN(conInt);  //Inicia la conversión
	return;
}

void adc_hw_Blockwait(void) {
	while((ADC0->SC1[0] & ADC_SC1_COCO_MASK)==0); //espera a que la conversion termine
	return;
}

char adc_hw_esFin(void) {
	return ((ADC0->SC1[0] & ADC_SC1_COCO_MASK)!=0?1:0);  //indica si la conversión ya terminó
}

int adc_hw_readResult(void) {
	adc_result=ADC0->R[0];				//copia el resultado de la conversión y lo retorna
	return adc_result;
}

__attribute__((interrupt)) void ADC0_IRQHandle(void) {
	adc_result=ADC0->R[0];				//retorna el resultadod e la conversión
}

