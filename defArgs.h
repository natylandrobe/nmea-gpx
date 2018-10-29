#ifndef DEFARGS_H
#define DEFARGS_H

#include <ctype.h>
//#include <stdbool.h>
#include <string.h>
#include "check.h"

#define DEFAULT_NAME "Default Name"
#define ARG_YEAR "--year"
#define ARG_MONTH "--month"
#define ARG_DAY "--day"
#define ARG_HELP "--help"
#define ARG_NAME "--name"
#define ARG_FORMAT "--format"
#define HELP_C 'h'
#define NAME_C 'n'
#define FORMAT_C 'f'
#define YEAR_C 'y'
#define MONTH_C 'm'
#define DAY_C 'd'
#define ARG_C '-'
#define SPACE ' '

bool cargarFecha(char *s, struct fecha *date);
status_t defaultFecha(struct fecha *def);


#endif
