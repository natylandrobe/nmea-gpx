#include "cargarStructs.h" 

/* Separar en campos la sentencia, y cargar los datos procesados a la estructura */
bool cargarStruct(char *s, struct data * newS, struct fecha date){

	char *str, *check;
	char *tokens[CANT_TOKEN];
	double lat, lon, hdop, ele, sep;
	long int cal, cant;
	cal_t calidad;

	if(!s || !newS){
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

	calidad = convertirCal(cal);
	lat = convertirLat(tokens[INDEX_LAT], tokens[INDEX_LAT_CARD]);
	lon = convertirLon(tokens[INDEX_LON], tokens[INDEX_LON_CARD]);

	if(!checkMembers(lat, lon, calidad, cant)){
		return false;
	}

	newS->f = date;
	newS->lat = lat;
	newS->lon = lon;
	newS->calidad = calidad;
	newS->cantSat = cant;
	newS->hdop = hdop;
	newS->ele = ele;
	newS->separacion = sep;
	
	return true;
}

/* Verifica que la cadena tenga el formato adecuado, procesa los datos y los carga en la estrcutura */
bool cargarFecha(char *s, struct fecha *date){

	int fecha, mes, dia, anio;
	char *check;

	if(!s || !date || !(checkNum(s)) || strlen(s) != CANT_DIG_FECHA){

		return false;
	}

	fecha = strtol(s, &check, 10);

	if(*check != END_STR){
		return false;
	}

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

/* Carga la fecha del sistema a la estructura de tipo fecha */
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
