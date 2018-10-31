#include "structData.h"
#include "defConv.h"

double convertirLon(const char lon[], const char * cardinal){

	char *check;

	if(!cardinal){

		return ERR_LATLON;
	}

	double longitud = strtod(lon, &check);

	if(*check != END_STR){

		return ERR_LATLON;
	}

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

	char *check;

	if(!cardinal){

		return ERR_LATLON;
	}

	double latitud = strtod(lat, &check);

	if(*check != END_STR){

		return ERR_LATLON;
	}

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
			return invalido;
		case 1:
			return fix_GPS;
		case 2: 
			return fix_DGPS;
		case 3:
			return fix_PPS;
		case 4: 
			return real_time_kinematic;
		case 5:
			return float_rtk;
		case 6:
			return estimada;
		case 7: 
			return manual;
		case 8:
			return simulacion;	
		default:
			return ERR_CAL;	
	}
}