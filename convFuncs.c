
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "structData.h"
#include "xml.h"

double convertirLon(const char lon[], const char * cardinal){

	double longitud = atof(lon);


	if(longitud < GRADO_MIN || longitud > LONG_MAX){
		return ERR_LATLON;
	}
	if(*cardinal != CARD_ESTE && *cardinal != CARD_OESTE){
		return ERR_LATLON;
	}

	longitud = floor(longitud/ DIGITO_GRADO) + fmod(longitud, DIGITO_GRADO) / MIN_POR_GRADO;
	
	if(*cardinal == CARD_OESTE){
		longitud *= VALOR_SW;
	}
	
	return longitud;
}

double convertirLat(const char lat[], const char * cardinal){

	double latitud = atof(lat);

	if(latitud < GRADO_MIN || latitud > LAT_MAX){
		return ERR_LATLON;
	}
	if (*cardinal != CARD_NORTE && *cardinal != CARD_SUR){
		return ERR_LATLON;
	}

	latitud = floor(latitud / DIGITO_GRADO) + fmod(latitud, DIGITO_GRADO) / MIN_POR_GRADO;
	
	if (*cardinal == CARD_SUR){
		latitud *= VALOR_SW;
	}
	
	return latitud;
}


cal_t convertirCal(long int cal){
	switch (cal){
		case 0: 
			cal = invalido;
			break;
		case 1:
			cal = fix_GPS;
			break;
		case 2: 
			cal = fix_DGPS;
			break;
		case 3:
			cal = fix_PPS;
			break;
		case 4: 
			cal = real_time_kinematic;
			break;
		case 5:
			cal = float_rtk;
			break;
		case 6:
			cal = estimada;
			break;
		case 7: 
			cal = manual;
			break;
		case 8:
			cal = simulacion;
			break;
		
	}
	return cal;
}