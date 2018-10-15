/*Es solo para empezar, lee el archivo nma y lo imprime.
	Se ejecuta despues de compilar como: $ cat ejemplo.nma | ./<nombre_de_compilacion>*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_LINE 300

int main (int argc, char *argv[]){
	char linea[MAX_LINE];
	
	while (fgets(linea, MAX_LINE, stdin) != NULL){
		printf("%s", linea);
	}

	return EXIT_SUCCESS;
}
