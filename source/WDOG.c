

#include "MK64F12.h"



void wdog_init(void){
	WDOG->UNLOCK = WDOG_UNLOCK_WDOGUNLOCK(0xC520); //para poder escribir
	WDOG->UNLOCK = WDOG_UNLOCK_WDOGUNLOCK(0xD928); //para poder ecribir
	WDOG->STCTRLH = WDOG_STCTRLH_WAITEN_MASK |
			WDOG_STCTRLH_STOPEN_MASK |		//permite que funcione en stop
			WDOG_STCTRLH_DBGEN_MASK | 		//permitir que funcione cuando debug. En debug se pausa y no hace reset
			WDOG_STCTRLH_ALLOWUPDATE_MASK | //SIEMPRE premitir que se pueda hacer unlock
			WDOG_STCTRLH_CLKSRC(0) |  //contar con el LPO a 1khz
			WDOG_STCTRLH_BYTESEL(0x00) | //solo para test
			WDOG_STCTRLH_WDOGEN_MASK | //Encender el WATCHDOG
			WDOG_STCTRLH_WINEN(0) |  //NO en modo ventana
			0x0100U;		//un bit que esta RESERVADO pero que esta en 1 y no sabemos que hace
}

void wdog_refresh(void) {  //esta funcion se llama periodicamente en el código
	//0xA602 followed by 0xB480
	WDOG->REFRESH = WDOG_REFRESH_WDOGREFRESH(0xA602);
	WDOG->REFRESH = WDOG_REFRESH_WDOGREFRESH(0xB480);
}
