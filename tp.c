/*Es solo para empezar, lee el archivo nma y lo imprime.
	Se ejecuta despues de compilar como: $ cat ejemplo.nma | ./<nombre_de_compilacion>*/
#include<stdio.h>
#include<stdlib.h>
int main (int argc, char *argv[]){
	char linea[100];
	
	while (fgets(linea,100,stdin)!=NULL){
	printf("%s",linea);
	}

	return EXIT_SUCCESS;
}
