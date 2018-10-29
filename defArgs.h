#include <ctype.h>

#define DEFAULT_NAME "Default Name"
#define YEAR_DIFF 1900
#define MON_DIFF 1
#define DIG_ANIO 10000
#define DIG_MES 100
#define CANT_DIG_FECHA 8
#define ARG_YEAR "--year"
#define ARG_MONTH "--month"
#define ARG_DAY "--day"
#define ARG_HELP "--help"
#define ARG_NAME "--name"
#define ARG_FORMAT "--format"
#define MICROSEC 1000000.0
#define MAX_DIG '9'
#define MIN_DIG '0'
#define HELP_C 'h'
#define NAME_C 'n'
#define FORMAT_C 'f'
#define YEAR_C 'y'
#define MONTH_C 'm'
#define DAY_C 'd'
#define ARG_C '-'
#define SPACE ' '
#define END_STR '\0'

bool cargarFecha(char *s, struct fecha *date);
status_t defaultFecha(struct fecha *def);
bool checkNum(char *s);
