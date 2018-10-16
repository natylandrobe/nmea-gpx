#include "check.h"
#define CHECK "$GPGGA,"
#define CANT_CSUM 2
#define ASTERISCO '*'
#define MAX_LAT 90.0
#define MAX_LON 180.0
#define MAX_CAL 8
#define MAX_CANT 12
#define MIN_CAL_CANT 0

bool checkLine(char *s){

	char checkSum[CANT_CSUM];
	checkSum[0] = *(strrchr(s, ASTERISCO) + 1);
	checkSum[1] = *(strrchr(s, ASTERISCO) + 2);

	if(strstr(s, CHECK) != NULL && nmea_checksum(s) == strtol(checkSum, NULL, 16))
		return true;
	return false;
}

unsigned char nmea_checksum(const char * s){
	unsigned char sum = 0;
	int i;

	for(i = 1; s[i] != ASTERISCO; i++)
		sum ^= s[i];


	return sum;
}

bool checkMembers(double lat, double lon, int cal, int cant){
	return !(lat  > MAX_LAT  || lat  < -MAX_LAT      ||
			 lon  > MAX_LON  || lon  < -MAX_LON      ||
			 cal  > MAX_CAL  || cal  <  MIN_CAL_CANT ||
			 cant > MAX_CANT || cant <  MIN_CAL_CANT);
}