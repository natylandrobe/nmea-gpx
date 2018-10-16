
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

bool cargarStruct(char *s, struct data * new);

int main (int argc, char *argv[]){
	char linea[MAX_LINE];
	struct data newS;
	
	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea) && cargarStruct(linea, &newS)){
			/*Aprox todo el programa va aca */
			//prueban que funcionan las funciones de convertir lat y lon
			printf("lat = %f\n", newS.lat); 
			printf("lon = %f\n", newS.lon);
			printf("ele = %f\nhdop = %f\n", newS.ele, newS.hdop);
			printf("sep = %f\ncal = %d\n", newS.separacion, newS.calidad);
			printf("cant = %d\n", newS.cantSat);
		}
	}

	return EXIT_SUCCESS;
}


bool cargarStruct(char *s, struct data * new){
	char *str;
	char *tokens[CANT_TOKEN];
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
	if(!checkLat(lat) || !checkLon(lon))
		return false;
	//new.fecha = ver parametros de funcion
	(*new).lat = lat;
	(*new).lon = lon;
	(*new).calidad = atoi(tokens[6]);
	(*new).cantSat = atoi(tokens[7]);
	(*new).hdop = atof(tokens[8]);
	(*new).ele = atof(tokens[9]);
	(*new).separacion = atof(tokens[11]);

	
	return true;
}




