/*
 * pulsador_st.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef PULSADOR_PULSADOR2_ST_H_
#define PULSADOR_PULSADOR2_ST_H_

enum {
	kPULSADOR_NOPRESS=1,
	kPULSADOR_PRESS,
};

#define kPULSADOR2_RESET	1

char pulsador_st_leer2(void);
void pulsador_st_reset(void);
char pulsador_transicion_leer2(void);
void pulsador_st_init2(void);
void pulsador_estados2(void);

#endif /* PULSADOR_PULSADOR_ST_H_ */
