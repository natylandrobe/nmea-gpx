
#include<stdio.h>
#include"check.h"

#define COMA ","
#define CANT_TOKEN 15
#define MAX_LINE 300


//typedef struct fecha {int dia; int mes; int anio; int hora; int minutos; float segundos;};

struct data {
	//struct fecha f;
	double lat;
	double lon;
	float ele;
	float hdop;
	float separacion;
	int calidad;
	int cantSat;
};

struct data createStructure(char *s);

int main (int argc, char *argv[]){
	char linea[MAX_LINE];
	
	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea)){
			printf("%s", linea);
			/*Aprox todo el programa va aca */

			struct data hola = createStructure(linea);
			//prueban que funcionan las funciones de convertir lat y lon
			printf("lat= %f\n", hola.lat); 
			printf("lon= %f\n", hola.lon);

		}
	}

	return EXIT_SUCCESS;
}





struct data createStructure(char *s){
	char *str;
	char *tokens[CANT_TOKEN];
	struct data new;
	double lat, lon;

	str = strtok(s, COMA);
	int i = 0;
	while(str != NULL){
		tokens[i] = str;
		str = strtok(NULL, COMA);
		i++;
	}

	lat = convertirLat(tokens[2], tokens[3]);
	lon = convertirLon(tokens[4], tokens[5]);
	//new.fecha = ver parametros de funcion
	new.lat = lat;
	new.lon = lon;
	new.calidad = atoi(tokens[6]);
	new.cantSat = atoi(tokens[7]);
	new.hdop = atof(tokens[8]);
	new.ele = atof(tokens[9]);
	new.separacion = atof(tokens[11]);

	if(checkLat(lat) && checkLon(lon))
		return new;
	
}


