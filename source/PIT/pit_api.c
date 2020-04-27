/*
 * pit_api.c
 *
 *  Created on: 5/04/2020
 *      Author: vatin
 */


#include "pit_st.h"
#include "pit_api.h"



void Init_pit(void) {
	init_st_pit();
}

void Start_pit(int pit,int tiempo) {
	set_pit_valor(pit, tiempo);
	set_pit_evento(pit, kPIT_EV_START);
	set_pit_enabled(pit);
}

void Stop_pit(int pit) {
	set_pit_evento(pit, kPIT_EV_STOP);
}

void Disable_pit(int pit) {
	clear_pit_enabled(pit);
}

void Clear_flag_pit(int pit) {
	set_pit_evento(pit, kPIT_EV_CLEAR);
}

char Read_flag_pit(int pit) {
	return (get_pit_estado(pit) == kPIT_FLAG);
}

void PIT_OPS(void) {
	pit_estados();
}

char Blocking_delay(int pit,int cicles) {
	if (get_pit_estado(pit)==kPIT_STOP) {
		return -1;
	}
	do {
		PIT_OPS();
		if (get_pit_estado(pit)==kPIT_FLAG) {
			Clear_flag_pit(pit);
			cicles--;
		}
	} while(cicles);
	return 0;
}
