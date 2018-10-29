#include "check.h"
#include <string.h>
#include <sys/time.h>


#define DELIM ","
#define CANT_TOKEN 15
#define INDEX_LAT 2
#define INDEX_LAT_CARD 3
#define INDEX_LON 4
#define INDEX_LON_CARD 5
#define INDEX_CAL 6
#define INDEX_CANT 7
#define INDEX_HDOP 8
#define INDEX_ELE 9
#define INDEX_SEP 11
#define END_STR '\0'

#define MICROSEC 1000000.0 
#define YEAR_DIFF 1900 
#define MON_DIFF 1 
#define DIG_ANIO 10000 
#define DIG_MES 100 
#define CANT_DIG_FECHA 8 

double convertirLon(const char lon[], char * cardinal);
double convertirLat(const char lat[], char * cardinal);
cal_t convertirCal(long int cal);

