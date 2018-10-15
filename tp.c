/*Es solo para empezar, lee el archivo nma y lo imprime.
	Se ejecuta despues de compilar como: $ cat ejemplo.nma | ./<nombre_de_compilacion>*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LINE 300
#define COMA ','
#define CHECK "$GPGGA,"
#define CANT_CSUM 2
#define ASTERISCO '*'

bool checkLine(char *s);
unsigned char nmea_checksum(const char * s);

int main (int argc, char *argv[]){
	char linea[MAX_LINE];
	
	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea)){
			printf("%s", linea);
			/*Aprox todo el programa va aca */

		}
	}

	return EXIT_SUCCESS;
}

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

