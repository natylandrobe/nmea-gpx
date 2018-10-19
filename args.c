#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "check.h"
#include "print.h"


#define DEFAULT_NAME "Default Name"
#define YEAR_DIFF 1900
#define MON_DIFF 1
#define DIG_ANIO 10000
#define DIG_MES 100
#define CANT_DIG_FECHA 8
#define ARG_YEAR "--year"
#define ARG_MONTH "--month"
#define ARG_DAY "--day"
#define ARG_HELP "--help"
#define ARG_NAME "--name"
#define ARG_FORMAT "--format"
#define MICROSEC 1000000.0

bool cargarFecha(char *s, struct fecha *date);
void defaultFecha(struct fecha *def);
bool checkNum(char *s);

status_t takeArgs(int argc, char *argv[], char **name, struct fecha *date){
	int i, c;
	*name = DEFAULT_NAME;
	defaultFecha(date);
	int mes, dia, anio;

	for (i = 1; i < argc; i++){
		//se fija si el argumento empieza con -
		if (*argv[i] == '-'){
			c = *(argv[i]+1);
			if(c == 'h' || c == 'H' || !strcmp(argv[i], ARG_HELP))
				return ST_HELP;
			else if(argc > i + 1){
				switch (c){
					case 'n':
					case 'N':
						*name = argv[i+1];
						break;
					case 'f':
					case 'F':
						if(!cargarFecha(argv[i+1], date))
							return ST_INV;
						break;
					case 'y':
					case 'Y':
						if(checkNum(argv[i+1]) && checkAnio(anio = atoi(argv[i+1])))
							(*date).anio = anio;
						else
							return ST_INV;
						break;
					case 'm':
					case 'M':
						if(checkNum(argv[i+1]) && checkMes(mes = atoi(argv[i+1])))
							(*date).mes = mes;
						else
							return ST_INV;
						break;
					case 'd':
					case 'D':
						if(checkNum(argv[i+1]) && checkDia(dia = atoi(argv[i+1])))
							(*date).dia = dia;
						else
							return ST_INV;
						break;
					case '-':
						if(!strcmp(argv[i], ARG_NAME))
							*name = argv[i+1];
						else if(!strcmp(argv[i], ARG_FORMAT)){
							if(!cargarFecha(argv[i+1], date))
								return ST_INV;
						}
								
						else if(checkNum(argv[i+1])){
							if(!strcmp(argv[i], ARG_YEAR) && checkAnio(anio = atoi(argv[i+1])))
								(*date).anio = anio;
							else if(!strcmp(argv[i], ARG_MONTH) && checkMes(mes = atoi(argv[i+1])))
								(*date).mes = mes;
							else if(!strcmp(argv[i], ARG_DAY) && checkDia(dia = atoi(argv[i+1])))
								(*date).dia = dia;
							else
								return ST_INV;
						}
						else
							return ST_INV;
				}
			}
		}
	}
	return ST_OK;
}



bool cargarFecha(char *s, struct fecha *date){
	int fecha, mes, dia, anio;
	if(!(checkNum(s)) || strlen(s) != CANT_DIG_FECHA)
		return false;
	fecha = atoi(s);

	anio = fecha / DIG_ANIO;
	mes = (fecha % DIG_ANIO) / DIG_MES;
	dia = ((fecha % DIG_ANIO) % DIG_MES);

	(*date).anio = anio;
	if(checkMes(mes))
		(*date).mes = mes;
	if(checkDia(dia))
		(*date).dia = dia;

	return true;
}

void defaultFecha(struct fecha *def){
	time_t rawtime;
   	struct tm *info;
   	struct timeval millisec;
   	time(&rawtime);
	gettimeofday(&millisec, NULL);

   	info = localtime(&rawtime);

	(*def).anio = (*info).tm_year + YEAR_DIFF;
	(*def).mes = (*info).tm_mon + MON_DIFF;
	(*def).dia = (*info).tm_mday;
	(*def).hora = (*info).tm_hour;
	(*def).minutos = (*info).tm_min;
	(*def).segundos = (*info).tm_sec + (millisec.tv_usec / MICROSEC);
}

bool checkNum(char *s){
	size_t i;
	for(i = 0; i < strlen(s); i++)
		if(!(s[i] >= '0' && s[i] <= '9'))
			return false;
	return true;
}