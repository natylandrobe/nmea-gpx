#include <stdbool.h>
#include "check.h"
#include "print.h"
#define DELIM ","
#define CANT_TOKEN 15
#define MAX_LINE 300
#define MSJ_ERR_INV "Ingrese un dato valido"
#define INDEX_LAT 2
#define INDEX_LAT_CARD 3
#define INDEX_LON 4
#define INDEX_LON_CARD 5
#define INDEX_CAL 6
#define INDEX_CANT 7
#define INDEX_HDOP 8
#define INDEX_ELE 9
#define INDEX_SEP 11
#define END_STR '\0'


bool cargarStruct(char *s, struct data * new, struct fecha date);
status_t takeArgs(int argc, char *argv[], char **name, struct fecha *date);

int main (int argc, char *argv[]){

	char linea[MAX_LINE], *name;
	struct data track;	
	struct fecha date;
	status_t st;

	if((st = takeArgs(argc, argv, &name, &date)) == ST_HELP){
		printHelp();
		return EXIT_SUCCESS;
	}
	
	else if(st == ST_INV){
		fprintf(stderr, "%s\n", MSJ_ERR_INV);
		return EXIT_FAILURE;
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

	char *str, *check;
	char *tokens[CANT_TOKEN];
	double lat, lon, hdop, ele, sep;
	long int cal, cant;

	if(!s || !new){
		return false;
	}

	str = strtok(s, DELIM);
	int i = 0;
	while(str != NULL){
		tokens[i] = str;
		str = strtok(NULL, DELIM);
		i++;
	}
	
	cant = strtol(tokens[INDEX_CANT], &check, 10);

	if(*check != END_STR){
		return false;
	}

	hdop = strtod(tokens[INDEX_HDOP], &check);

	if(*check != END_STR){
		return false;
	}

	ele = strtod(tokens[INDEX_ELE], &check);

	if(*check != END_STR){
		return false;
	}

	sep = strtod(tokens[INDEX_SEP], &check);

	if(*check != END_STR){
		return false;
	}

	cal = strtol(tokens[INDEX_CAL], &check, 10);

	if(*check != END_STR){
		return false;
	}

	cal = convertirCal(cal);
	lat = convertirLat(tokens[INDEX_LAT], tokens[INDEX_LAT_CARD]);
	lon = convertirLon(tokens[INDEX_LON], tokens[INDEX_LON_CARD]);

	if(!checkMembers(lat, lon, cal, cant)){
		return false;
	}

	new->f = date;
	new->lat = lat;
	new->lon = lon;
	new->calidad = cal;
	new->cantSat = cant;
	new->hdop = hdop;
	new->ele = ele;
	new->separacion = sep;
	
	return true;
}