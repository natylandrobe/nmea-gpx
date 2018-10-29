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



