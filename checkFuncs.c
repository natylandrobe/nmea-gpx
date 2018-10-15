#include "check.h"
#define CHECK "$GPGGA,"
#define CANT_CSUM 2
#define ASTERISCO '*'

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