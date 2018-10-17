
#include "check.h"
#include "structData.h"
#define COMA ","
#define CANT_TOKEN 15
#define MAX_LINE 300


void printMetadata(char *name);
void printTrkC(void);
void printStruct(struct data track);
bool cargarStruct(char *s, struct data * new);
status_t takeArgs(int argc, char *argv[], char **name);
void print_help();

int main (int argc, char *argv[]){
	char linea[MAX_LINE], *name;
	struct data track;	

	if(takeArgs(argc, argv, &name) == ST_HELP){
		print_help();
		return 0;
	}

	printMetadata(name);

	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea) && cargarStruct(linea, &track)){
			/*Aprox todo el programa va aca */
			
			printStruct(track);
		}
	}
	printTrkC();
	return EXIT_SUCCESS;
}


bool cargarStruct(char *s, struct data * new){
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
	cant = atoi(tokens[7]);
	if(!checkMembers(lat, lon, cal, cant))
		return false;
	//new.fecha = ver parametros de funcion
	(*new).lat = lat;
	(*new).lon = lon;
	(*new).calidad = cal;
	(*new).cantSat = cant;
	(*new).hdop = atof(tokens[8]);
	(*new).ele = atof(tokens[9]);
	(*new).separacion = atof(tokens[11]);

	
	return true;
}


