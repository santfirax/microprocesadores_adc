/*
 * pit_hw.h
 *
 *  Created on: 5/04/2020
 *      Author: vatin
 */

#ifndef PIT_PIT_HW_H_
#define PIT_PIT_HW_H_

void init_hw_pit(void);
void set_hw_pit_timer(int pit, int value);
void stop_hw_pit_timer(int pit);
char get_pit_bandera(int pit);
void clr_pit_bandera(int pit);

#endif /* PIT_PIT_HW_H_ */
