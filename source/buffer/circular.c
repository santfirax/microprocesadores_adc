/*
 * circular.c
 *
 *  Created on: 7/04/2020
 *      Author: vatin
 */

#define SIZE 16

char buffer[SIZE];
int write=0;
int read=0;


void add_buffer(char dato) {
	buffer[write]=dato;
	write++;
	if (write==read) {
		write--;
	}
	if (write>=SIZE) {
		write=0;
	}
}


char read_buffer(void) {
	char temp;
	if (read!=write) {
		temp=buffer[read];
	} else {
		return -1;
	}
	read++;
	if (read>=SIZE) {
		read=0;
	}
	return temp;
}
