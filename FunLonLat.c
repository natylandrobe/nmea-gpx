
#include<stdlib.h>
#include <math.h>
#include <stdio.h>

#define DIGITO_GRADO  100.0
#define LAT_MAX 9000.000
#define GRADO_MIN 0
#define MIN_POR_GRADO 60
#define CARD_SUR 'S'
#define CARD_NORTE 'N'
#define CARD_ESTE 'E'
#define CARD_OESTE 'W'
#define LONG_MAX 18000
#define VALOR_SW -1
#define ERR_LATLON 181

double convertirLon(const char lon[], const char * cardinal){

	double longitud = atof(lon);

	if(longitud < GRADO_MIN || longitud > LONG_MAX)
		return ERR_LATLON;
	if(*cardinal != CARD_ESTE && *cardinal != CARD_OESTE)
		return ERR_LATLON;

	longitud = floor(longitud/ DIGITO_GRADO) + fmod(longitud, DIGITO_GRADO) / MIN_POR_GRADO;
	
	if(*cardinal == CARD_OESTE)
		longitud *= VALOR_SW;
	
	return longitud;
}

double convertirLat(const char lat[], const char * cardinal){

	double latitud = atof(lat);

	if(latitud < GRADO_MIN || latitud > LAT_MAX)
		return ERR_LATLON;
	if (*cardinal != CARD_NORTE && *cardinal != CARD_SUR)
		return ERR_LATLON;

	latitud = floor(latitud / DIGITO_GRADO) + fmod(latitud, DIGITO_GRADO) / MIN_POR_GRADO;
	
	if (*cardinal == CARD_SUR)
		latitud *= VALOR_SW;
	
	return latitud;
}