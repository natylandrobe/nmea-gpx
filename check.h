#ifndef CHECK_H
#define CHECK_H

#ifndef STRUCTDATA_H
#include "structData.h"
#endif

typedef enum {ST_INV, ST_HELP, ST_OK, ST_EPTNULL} status_t;

bool checkLine(char *s); 
bool checkDia(int dia); 
bool checkMes(int mes);
bool checkAnio(int anio);
bool checkNum(char *s);
bool checkMembers(double lat, double lon, cal_t cal, long int cant);

#endif
