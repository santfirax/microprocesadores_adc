/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    Pulsador_led_estados.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "fsl_debug_console.h"
/* TODO: insert other include files here. */


#include "pulsador/pulsador_api.h"
#include "pulsador2/pulsador_api.h"
#include "led/led_api.h"
#include "buffer/circular.h"
#include "PIT/pit_api.h"
#include "adc/adc_api.h"

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */


void APP(void);
void led_admin(void);
void adc_admin(void);


char led_main=0;
int led_delay=0;
char adc_main=0;
int resultado_adc;

void led_admin(void) {
	char temp;
	switch(led_main) {
	case 0:
		temp=read_buffer();
		if (temp!=(char)(-1)) {
			led_main=1;
			led_delay=((int)temp)*10;
			printf("%dON",temp);
		}
		break;

	case 1:
		if ((Read_flag_pit(0)!=0)) {
			led_delay--;
			if (led_delay==0) {
				led_main=2;
				led_delay=50;
				printf("-OFF");
			}
		}
		break;
	case 2:
		if ((Read_flag_pit(0)!=0)) {
			led_delay--;
			if (led_delay==0) {
				led_main=0;
				printf("-END\n");
			}
		}
		break;
	}
}


void adc_admin(void) {
	char temp;
	switch(adc_main) {
	case 0:
		if (Read_flag_pit(0)!=0){
			temp=Convert_adc(0);
			if (temp!=-1) {
				adc_main++;
			}
		}
		break;

	case 1:
		if (IsResult_adc()) {
			resultado_adc = Read_adc_result();
			Reset_adc();
			adc_main++;
		}
		break;

	case 2:
		if (Read_flag_pit(0)!=0){
			resultado_adc=(resultado_adc >> 13)+1;
			adc_main=0;
		}
		break;
	}
}


void APP(void) {
	//static char cont=1;
	if (Leer_evento_pulsador()==INICIO_PRESS) {   //FIN_PRESS es otra opcion
		Alternar_led();
	}

	if (Leer_pulsador2()==kPULSADOR2_PRESS) {
		Reset_pulsador2();
		add_buffer(resultado_adc);
		//cont++;
		//if (cont==6) cont=1;
	}

	if (Read_flag_pit(0)!=0) {
		Clear_flag_pit(0);
		//printf("P\n");
	}
	led_admin();
	adc_admin();

}




int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    PRINTF("Hello World\n");


    Init_Led();
   // Init_Pulsador();
    Init_Pulsador2();
    Init_pit();
    Init_adc();
    Start_adc();
    Start_pit(0, 10);

    for(;;) {
    	//PULSADOR_OPS();
    	ADC_OPS();
    	PIT_OPS();
    	PULSADOR_OPS2();
    	APP();
    	LED_OPS();
    }


    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
