#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "structData.h"

unsigned char nmea_checksum(const char * s);
bool checkLine(char *s);
double convertirLon(const char lon[], char * cardinal);
double convertirLat(const char lat[], char * cardinal);
bool checkMembers(double lat, double lon, cal_t cal, long int cant);
bool checkDia(int dia);
bool checkMes(int mes);
bool checkAnio(int anio);
cal_t convertirCal(long int cal);
