/*Es solo para empezar, lee el archivo nma y lo imprime.
	Se ejecuta despues de compilar como: $ cat ejemplo.nma | ./<nombre_de_compilacion>*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define COMA ","
#define CANT_TOKEN 15
#define MAX_LINE 300
//pasar a header <check.h>
#define CHECK "$GPGGA,"
#define CANT_CSUM 2
#define ASTERISCO '*'


//typedef struct fecha {int dia; int mes; int anio; int hora; int minutos; float segundos;};

struct data {
	//struct fecha f;
	float lat;
	float lon;
	float ele;
	float hdop;
	float separacion;
	int calidad;
	int cantSat;
};



bool checkLine(char *s);
unsigned char nmea_checksum(const char * s);
struct data createStructure(char *s);




int main (int argc, char *argv[]){
	char linea[MAX_LINE];
	
	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea)){
			printf("%s", linea);
			/*Aprox todo el programa va aca */

			struct data hola = createStructure(linea);
			printf("%d\n", hola.calidad);

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



struct data createStructure(char *s){
	char *str;
	char *tokens[CANT_TOKEN];
	struct data new;

	str = strtok(s, COMA);
	int i = 0;
	while(str != NULL){
		tokens[i] = str;
		str = strtok(NULL, COMA);
		
		i++;
	}
	//new.fecha = ver parametros de funcion
	//new.lat = convertirLat(tokens[2],tokens[3]);
	//new.lon = convertirLon(tokens[4],tokens[5]);
	new.calidad = atoi(tokens[6]);
	new.cantSat = atoi(tokens[7]);
	new.hdop = atof(tokens[8]);
	new.ele = atof(tokens[9]);
	new.separacion = atof(tokens[11]);

	return new;
}


