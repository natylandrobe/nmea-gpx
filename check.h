#ifndef CHECK_H
#define CHECK_H

#include <stdbool.h>
#include "structData.h"

typedef enum {ST_INV, ST_HELP, ST_OK, ST_EPTNULL} status_t;

bool checkLine(char *s); //la usa main.c
bool checkDia(int dia); //la usa args.c
bool checkMes(int mes);//la usa args.c
bool checkAnio(int anio);//la usa args.c
bool checkNum(char *s);//la usa args.c
bool checkMembers(double lat, double lon, cal_t cal, long int cant); //la usa cargarStruct

#endif
