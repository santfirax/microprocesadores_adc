/*
 * grafos.c
 *
 *  Created on: 6/04/2020
 *      Author: vatin
 */

#include "grafos.h"
#include <stdlib.h>



struct GRAFO *p;
struct GRAFO *inicio;

void init(void) {
	p=(struct GRAFO *) malloc(sizeof(struct GRAFO));
	inicio = p;
	p->data[0]='1';
	p->sig = (struct GRAFO *) malloc(sizeof(struct GRAFO *));
	p = p->sig;
	p->data[0]='2';
	p->sig = (struct GRAFO *) malloc(sizeof(struct GRAFO *));
	p = p->sig;
	p->data[0]='3';
}
