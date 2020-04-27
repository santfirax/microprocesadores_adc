/*
 * pulsador_hw.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef PULSADOR_PULSADOR2_HW_H_
#define PULSADOR_PULSADOR2_HW_H_

#define NOPRESS		1
#define PRESS		2


void pulsador_hw_init2(void);
char pulsador_hw_leer2(void);

char get_pulsador2_event(void);
void reset_pulsador2_event(void);

#endif /* PULSADOR_PULSADOR_HW_H_ */
