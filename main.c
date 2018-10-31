#include "funcmain.h"

int main (int argc, char *argv[]){

	char linea[MAX_LINE], *name;
	struct data track;	
	struct fecha date;
	status_t st;

	if((st = takeArgs(argc, argv, &name, &date)) == ST_HELP){

		printHelp();
		return EXIT_SUCCESS;
	}
	
	else if(st == ST_INV){

		fprintf(stderr, "%s\n", MSJ_ERR_INV);
		return EXIT_FAILURE;
	}

	else if(st == ST_EPTNULL){

		return EXIT_FAILURE;
	}

	if(!printMetadata(name)){

		return EXIT_FAILURE;
	}

	while (fgets(linea, MAX_LINE, stdin) != NULL){
		
		if(checkLine(linea) && cargarStruct(linea, &track, date)){
			
			printStruct(track);
		}
	}

	printTrkC();
	return EXIT_SUCCESS;
}
