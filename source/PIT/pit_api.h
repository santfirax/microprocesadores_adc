/*
 * pit_api.h
 *
 *  Created on: 5/04/2020
 *      Author: vatin
 */

#ifndef PIT_PIT_API_H_
#define PIT_PIT_API_H_

enum PIT_ESTADOS_API {
	kST_PIT_STOP=0,
	kST_PIT_RUN,
	kST_PIT_FLAG,
};

void Init_pit(void);
void Start_pit(int pit,int tiempo);
void Stop_pit(int pit);
void Clear_flag_pit(int pit);
char Read_flag_pit(int pit);
void PIT_OPS(void);
char Blocking_delay(int pit,int cicles);

#endif /* PIT_PIT_API_H_ */
