#ifndef FUNCMAIN_H
#define FUNCMAIN_H

#define DELIM ","
#define CANT_TOKEN 15
#define MAX_LINE 300
#define MSJ_ERR_INV "Ingrese un dato valido"
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

bool cargarStruct(char *s, struct data * new, struct fecha date);
status_t takeArgs(int argc, char *argv[], char **name, struct fecha *date);

#endif
