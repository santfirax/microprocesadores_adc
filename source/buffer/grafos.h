/*
 * grafos.h
 *
 *  Created on: 6/04/2020
 *      Author: vatin
 */

#ifndef BUFFER_GRAFOS_H_
#define BUFFER_GRAFOS_H_


struct GRAFO {
	char data[8];
	struct GRAFO *sig;
};


#endif /* BUFFER_GRAFOS_H_ */
