#include <stdio.h>
#include <time.h>

typedef enum {ST_OK, ST_HELP, ST_INV} status_t;
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
	float ele;
	float hdop;
	float separacion;
	cal_t calidad;
	int cantSat;
};

