
#include<stdio.h>
#include"check.h"
#include<time.h>

#define COMA ","
#define CANT_TOKEN 15
#define MAX_LINE 300

#define META "<metadata>"
#define META_C "</metadata>"
#define NAME "<name>"
#define NAME_C "</name>"
#define TIME "<time>"
#define TIME_C "</time>"
#define YEAR_DIFF 1900


#define TRK "<trk>"
#define TRK_C "</trk>"
#define TRKSEG "<trkseg>"
#define TRKSEG_C "</trkseg>"
#define TRKPT_START "<trackpt lat=\""
#define TRKPT_MID "\" lon=\""
#define TRKPT_FIN "\">"
#define ELE "<ele>"
#define ELE_C "</ele>"
#define TRKPT_C "</trkpt>"
#define SPC  "   "
#define SPC2 "      "
#define SPC3 "         "
#define XML "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define GPX "<gpx version=\"1.1\" creator=\"nmea-gpx\" xmlns=\"http://www.topografix.com/GPX/1/1\">"
#define GPX_C "</gpx>"




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
void printMetadata(char *name);
void printTrkC(void);
void printStruct(struct data track);

int main (int argc, char *argv[]){
	char linea[MAX_LINE];
	struct data track;
	
	printMetadata("Ejemplo");

	while (fgets(linea, MAX_LINE, stdin) != NULL){

		if(checkLine(linea) && cargarStruct(linea, &track)){
			/*Aprox todo el programa va aca */
			//prueban que funcionan las funciones de convertir lat y lon
			
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


void printMetadata(char *name){
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	timeinfo = *(localtime(&rawtime));

	printf(XML "\n");
	printf(GPX "\n");
	printf(SPC META "\n"
			SPC2 NAME "%s" NAME_C "\n"
			SPC2 TIME "%d-%d-%dT%d:%d:%dZ" TIME_C "\n"
		    SPC META_C "\n"
		    SPC TRK "\n"
		    SPC2 TRKSEG "\n",
		name,
		timeinfo.tm_year + YEAR_DIFF,
		timeinfo.tm_mon,
		timeinfo.tm_mday,
		timeinfo.tm_hour,
		timeinfo.tm_min,
		timeinfo.tm_sec);



}

void printTrkC(void){
	printf(SPC2 TRKSEG_C "\n"
			SPC TRK_C    "\n"
				GPX_C    "\n");
}

void printStruct(struct data track){
	printf(SPC3 TRKPT_START "%f" TRKPT_MID "%f" TRKPT_FIN "\n"
			SPC3 SPC ELE "%f" ELE_C "\n"
			SPC3 SPC TIME "???" TIME_C "\n"
			SPC3 TRKPT_C "\n",
		track.lat,
		track.lon,
		track.ele);
}