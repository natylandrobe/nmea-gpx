#include <stdio.h>
#include <time.h>

typedef enum {ST_INV, ST_HELP, ST_OK, ST_EPTNULL} status_t;
typedef enum{invalido, fix_GPS, fix_DGPS, fix_PPS, real_time_kinematic, float_rtk, estimada, manual, simulacion} cal_t;

struct fecha {
	int dia;
	int mes;
	int anio;
	int hora;
	int minutos;
	float segundos;
};

struct data {
	struct fecha f;
	double lat;
	double lon;
	double ele;
	double hdop;
	double separacion;
	cal_t calidad;
	long int cantSat;
};

