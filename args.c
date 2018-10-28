#include <sys/time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "check.h"
#include "print.h"
#include "defArgs.h"

status_t takeArgs(int argc, char *argv[], char **name, struct fecha *date){
	int i, argumento, mes, dia, anio;

	if(!argc || !argv || !name || !date){
		return ST_EPTNULL;
	}

	*name = DEFAULT_NAME;
	if(defaultFecha(date) != ST_OK){
		return ST_EPTNULL;
	}

	for (i = 1; i < argc; i++){
		/*se fija si el argumento empieza con '-' */
		if (*argv[i] == ARG_C){

			argumento = *(argv[i]+1);
			if(argumento == HELP_C || argumento == toupper(HELP_C) || !strcmp(argv[i], ARG_HELP)){
				return ST_HELP;
			}
			else if(argc > i + 1){
				if(strlen(argv[i]) == 2){
					switch (tolower(argumento)){
						case NAME_C:
							if(*argv[i+1] == ARG_C){
								return ST_INV;
							}
							*name = argv[i+1];
							
							break;
						case FORMAT_C:
							if(!cargarFecha(argv[i+1], date)){
								return ST_INV;
							}
							break;
						case YEAR_C:
							if(checkNum(argv[i+1]) && checkAnio(anio = atoi(argv[i+1]))){
								date->anio = anio;
							}
							else{
								return ST_INV;
							}
							break;
						case MONTH_C:
							if(checkNum(argv[i+1]) && checkMes(mes = atoi(argv[i+1]))){
								date->mes = mes;
							}
							else{
								return ST_INV;
							}
							break;
						case DAY_C:
							if(checkNum(argv[i+1]) && checkDia(dia = atoi(argv[i+1]))){
								date->dia = dia;
							}

							else{
								return ST_INV;
							}
							break;
					}
				}
				else if(argumento == ARG_C){
					if(!strcmp(argv[i], ARG_NAME)){
						if(*argv[i+1] == ARG_C){
							return ST_INV;
						}
						*name = argv[i+1];
					}
					else if(!strcmp(argv[i], ARG_FORMAT)){
						if(!cargarFecha(argv[i+1], date)){
							return ST_INV;
						}
					}
								
					else if(checkNum(argv[i+1])){
						if(!strcmp(argv[i], ARG_YEAR) && checkAnio(anio = atoi(argv[i+1]))){
							date->anio = anio;
						}
						else if(!strcmp(argv[i], ARG_MONTH) && checkMes(mes = atoi(argv[i+1]))){
							date->mes = mes;
						}
						else if(!strcmp(argv[i], ARG_DAY) && checkDia(dia = atoi(argv[i+1]))){
							date->dia = dia;
						}
						else{
							return ST_INV;
						}
						
					}
					else{
						return ST_INV;
					}
				}
				else{
					return ST_INV;
				}
			}
		}
	}
	return ST_OK;
}



bool cargarFecha(char *s, struct fecha *date){

	int fecha, mes, dia, anio;

	if(!s || !date || !(checkNum(s)) || strlen(s) != CANT_DIG_FECHA){
		return false;
	}
	fecha = atoi(s);

	anio = fecha / DIG_ANIO;
	mes = (fecha % DIG_ANIO) / DIG_MES;
	dia = ((fecha % DIG_ANIO) % DIG_MES);

	(*date).anio = anio;
	if(checkMes(mes)){
		date->mes = mes;
	}
	if(checkDia(dia)){
		date->dia = dia;
	}

	return true;
}

status_t defaultFecha(struct fecha *def){

	time_t rawtime;
   	struct tm *info;
   	struct timeval millisec;

   	if(!def){
   		return ST_EPTNULL;
   	}

   	time(&rawtime);
	gettimeofday(&millisec, NULL);

   	info = localtime(&rawtime);

	def->anio = info->tm_year + YEAR_DIFF;
	def->mes = info->tm_mon + MON_DIFF;
	def->dia = info->tm_mday;
	def->hora = info->tm_hour;
	def->minutos = info->tm_min;
	def->segundos = info->tm_sec + (millisec.tv_usec / MICROSEC);

	return ST_OK;
}

bool checkNum(char *s){
	size_t i;
	for(i = 0; i < strlen(s); i++){
		if(!(s[i] >= MIN_DIG && s[i] <= MAX_DIG)){
			return false;
		}
	}
	return true;
}