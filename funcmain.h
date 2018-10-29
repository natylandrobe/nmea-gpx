#ifndef FUNCMAIN_H
#define FUNCMAIN_H

#include "print.h"
#include "check.h"

#define MAX_LINE 300 //
#define MSJ_ERR_INV "Ingrese un dato valido" //

bool cargarStruct(char *s, struct data * new, struct fecha date);
status_t takeArgs(int argc, char *argv[], char **name, struct fecha *date);

#endif
