#include <stdbool.h>
#include "check.h"
#include "print.h"
#define COMA ","
#define CANT_TOKEN 15
#define MAX_LINE 300
#define MSJ_ERR_INV "Ingrese un dato valido"



bool cargarStruct(char *s, struct data * new, struct fecha date);
status_t takeArgs(int argc, char *argv[], char **name, struct fecha *date);

int main (int argc, char *argv[]){
	char linea[MAX_LINE], *name;
	struct data track;	
	struct fecha date;
	status_t st;

	if((st = takeArgs(argc, argv, &name, &date)) == ST_HELP){
		printHelp();
		return 0;
	}
	
	else if(st == ST_INV){
		fprintf(stderr, "%s\n", MSJ_ERR_INV);
		return 0;
	}

	printMetadata(name);

	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea) && cargarStruct(linea, &track, date)){
			printStruct(track);
		}
	}
	printTrkC();
	return EXIT_SUCCESS;
}


bool cargarStruct(char *s, struct data * new, struct fecha date){
	char *str;
	char *tokens[CANT_TOKEN];
	double lat, lon;
	int cal, cant;

	str = strtok(s, COMA);
	int i = 0;
	while(str != NULL){
		tokens[i] = str;
		str = strtok(NULL, COMA);
		i++;
	}

	lat = convertirLat(tokens[2], tokens[3]);
	lon = convertirLon(tokens[4], tokens[5]);
	cal = atoi(tokens[6]);
	cal = convertirCal(cal);
	cant = atoi(tokens[7]);
	if(!checkMembers(lat, lon, cal, cant))
		return false;
	(*new).f = date;
	(*new).lat = lat;
	(*new).lon = lon;
	(*new).calidad = cal;
	(*new).cantSat = cant;
	(*new).hdop = atof(tokens[8]);
	(*new).ele = atof(tokens[9]);
	(*new).separacion = atof(tokens[11]);

	
	return true;
}