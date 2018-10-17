#include "structData.h"
#define DEFAULT_NAME "Default Name"


status_t takeArgs(int argc, char *argv[], char **name){
	int i, c;
	*name = DEFAULT_NAME;

	for (i = 1; i < argc; i++){
		//se fija si el argumento empieza con -
		if (*argv[i] == '-'){
			c = *(argv[i]+1);
			switch (c){
				case 'h':
					return ST_HELP;
				case 'n':
					*name = argv[i+1];
					break;
				case 'f':

			}
		}

	}
	return ST_OK;
}

void print_help(){
	printf("HELP\n");
}

bool cargarFecha(char *s, struct fecha *date)