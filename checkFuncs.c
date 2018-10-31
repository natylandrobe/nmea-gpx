#include "defCheck.h"

bool checkLine(char *s){

	char checkSum[CANT_CSUM];

	if(!s){
		
		return false;
	}
	/* Asumimos que todas las lineas traen '*' */
	checkSum[0] = *(strrchr(s, ASTERISCO) + 1);
	checkSum[1] = *(strrchr(s, ASTERISCO) + 2);

	if(strstr(s, CHECK) != NULL && nmea_checksum(s) == strtol(checkSum, NULL, 16)){
	
		return true;
	}
	return false;
}

unsigned char nmea_checksum(const char * s){

	unsigned char sum = 0;
	int i;

	for(i = 1; s[i] != ASTERISCO; i++){
		
		sum ^= s[i];
	}

	return sum;
}

bool checkMembers(double lat, double lon, cal_t cal, long int cant){

	return !(lat  > MAX_LAT  || lat  < -MAX_LAT      ||
			 lon  > MAX_LON  || lon  < -MAX_LON      ||
			 cal  > MAX_CAL  || cal  <  MIN_CAL_CANT ||
			 cant > MAX_CANT || cant <  MIN_CAL_CANT);
}

bool checkDia(int dia){

	return !(dia < MIN_ANIOMESDIA || dia > MAX_DIA);
}

bool checkMes(int mes){

	return !(mes < MIN_ANIOMESDIA || mes > MAX_MES);
}

bool checkAnio(int anio){
	
	return !(anio < MIN_ANIOMESDIA || anio > MAX_ANIO);
}

bool checkNum(char *s){

	int i;

	if(!s){

		return false;
	}

	for(i = 0; i < strlen(s); i++){

		if(!(s[i] >= MIN_DIG && s[i] <= MAX_DIG)){
			
			return false;
		}
	}
	return true;
}