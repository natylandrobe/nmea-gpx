#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

unsigned char nmea_checksum(const char * s);
bool checkLine(char *s);
double convertirLon(const char lon[], char * cardinal);
double convertirLat(const char lat[], char * cardinal);
bool checkMembers(double lat, double lon, int cal, int cant);
