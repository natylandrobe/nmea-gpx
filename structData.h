#include <stdio.h>
#include <time.h>

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

