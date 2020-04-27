/*
 * pulsador_st.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef PULSADOR_PULSADOR_ST_H_
#define PULSADOR_PULSADOR_ST_H_

enum {
	kPULSADOR_NOPRESS=0,
	kPULSADOR_PRESS,
};

char pulsador_st_leer(void);
char pulsador_transicion_leer(void);
void pulsador_st_init(void);
void pulsador_estados(void);

#endif /* PULSADOR_PULSADOR_ST_H_ */
