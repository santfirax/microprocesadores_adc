#include "collections.h"
#include "stdio.h"
//use milivoltios mejor
double minVoltage = 3300;
double maxVoltage = 0;
double deltaVoltage = 0;

/**
 *
 */
void findMaxVoltage(double voltageReceived) {
	if (voltageReceived > maxVoltage) {
		maxVoltage = voltageReceived;
		printf("min voltage in mV:%f", maxVoltage);
	}
}
void findMinVoltage(double voltageReceived) {
	if (voltageReceived < minVoltage) {
		printf("max voltage in mV:%f", maxVoltage);
		minVoltage = voltageReceived;
	}
}
/**
 * dado que los valores de voltaje minimo y maximo se encuentran en el mismo file no es necesario recibirlos como parametro
 * si se cambia las funciones de arriba para que devuelvan el valor si toca recibir los parametros de minimo y maximo
 */
void calculateDeltaVoltage() {
	deltaVoltage = maxVoltage - minVoltage;
	printf("delta voltage in mV:%f", deltaVoltage);
}
