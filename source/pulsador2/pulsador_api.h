/*
 * pulsador_api.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef PULSADOR_PULSADOR_API2_H_
#define PULSADOR_PULSADOR_API2_H_

#define INICIO_PRESS 0x02
#define FIN_PRESS	0x08

#define kPULSADOR2_PRESS	2


void PULSADOR_OPS2(void);

void Init_Pulsador2(void);
char Leer_pulsador2(void);
char Leer_evento_pulsador2(void);
void Reset_pulsador2(void);

#endif /* PULSADOR_PULSADOR_API_H_ */
