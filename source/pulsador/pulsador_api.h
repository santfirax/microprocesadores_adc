/*
 * pulsador_api.h
 *
 *  Created on: 20/09/2019
 *      Author: vatin
 */

#ifndef PULSADOR_PULSADOR_API_H_
#define PULSADOR_PULSADOR_API_H_

#define INICIO_PRESS 0x02
#define FIN_PRESS	0x08

void PULSADOR_OPS(void);
void Init_Pulsador(void);
char Leer_pulsador(void);
char Leer_evento_pulsador(void);
void PULSADOR_OPS(void);

#endif /* PULSADOR_PULSADOR_API_H_ */
