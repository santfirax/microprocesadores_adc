/*
 * pulsador_hw.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef PULSADOR_PULSADOR_HW_H_
#define PULSADOR_PULSADOR_HW_H_

#define NOPRESS		1
#define PRESS		0


void pulsador_hw_init(void);
char pulsador_hw_leer(void);

#endif /* PULSADOR_PULSADOR_HW_H_ */
