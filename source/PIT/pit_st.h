/*
 * pit_st.h
 *
 *  Created on: 5/04/2020
 *      Author: vatin
 */

#ifndef PIT_PIT_ST_H_
#define PIT_PIT_ST_H_

enum PIT_ESTADOS {
	kPIT_STOP=0,
	kPIT_RUN,
	kPIT_FLAG,
};

enum PIT_EVENTOS {
	kPIT_EV_START=1,
	kPIT_EV_CLEAR,
	kPIT_EV_STOP
};


void init_st_pit(void);
char get_pit_estado(int pit);
void set_pit_evento(int pit,char evento);
void set_pit_valor(int pit,int valor);
void pit_estados(void);
void set_pit_enabled(int pit);
void clear_pit_enabled(int pit);

#endif /* PIT_PIT_ST_H_ */
