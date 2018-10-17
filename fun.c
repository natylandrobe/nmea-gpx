/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RANG_A 2018
#define MIN_RANG_A 1997
#define MAX_RANG_MES 12
#define MIN_RANG_MES 1
#define MAX_RANG_DIA 31
#define MIN_RANG_DIA 1

#define MSJ_ERR_FUERA_RANGO_A "Esta fuera de rango el año ingresado"
#define MSJ_ERR_FUERA_RANGO_M "Esta fuera de rango el mes ingresado"
#define MSJ_ERR_FUERA_RANGO_D "Esta fuera de rango el dia ingresado"


typedef enum estado{st_ing_valor,st_err,st_err_fuera_rango,st_pide_ayuda,st_err_nomb}status_t;

int main(int argc, char *argv[]){
    status_t st;
    long anio=0,mes=0,dia=0;
	char nom[20];
	char aux_str[5];        
    size_t i=1;
    while(argv[i]!=NULL){
        if (strcmp(argv[i],"-h")==0 || strcmp(argv[i],"--help")==0){
	        st=st_pide_ayuda;
			printf("LA ayuda es ");
		}
        if (strcmp(argv[i],"-n")==0 || strcmp(argv[i],"--name")==0){
        	strcpy(nom,argv[i+1]);
			if (argv[i+1]==NULL){
				st=st_err_nomb;
			}
			puts(nom);
        	st=st_ing_valor;
		}

		if (strcmp(argv[i],"-f")==0 || strcmp(argv[i],"--format")==0){
 			//para pasar la fecha a año,mes y dia
        	aux_str[0]=argv[i+1][0];
        	aux_str[1]=argv[i+1][1];
        	aux_str[2]=argv[i+1][2];
        	aux_str[3]=argv[i+1][3];
        	aux_str[4]='\0';
        	anio=atol(aux_str);

        	aux_str[0]=argv[i+1][4];
        	aux_str[1]=argv[i+1][5];
        	aux_str[2]='\0';
        	mes=atol(aux_str);

        	aux_str[0]=argv[i+1][6];
        	aux_str[1]=argv[i+1][7];
        	aux_str[2]='\0';
        	dia=atol(aux_str);
   
		}
        if (strcmp(argv[i],"-Y")==0 || strcmp(argv[i],"-year")==0){
			anio=atoi(argv[i+1]);
		}
        if(strcmp(argv[i],"-m")==0 || strcmp(argv[i],"--month")==0){
        	mes=atoi(argv[i+1]);
		}
        if (strcmp(argv[i],"-d")==0 || strcmp(argv[i],"--day")==0){
        	dia=atoi(argv[i+1]);
		}
        i+=2;
	}
	if (mes<MIN_RANG_MES ||mes>MAX_RANG_MES) {
		fprintf(stderr,"%s",MSJ_ERR_FUERA_RANGO_M);
		st=st_err_fuera_rango;
	}
	if (anio<MIN_RANG_A || anio>MAX_RANG_A) {
		fprintf(stderr,"%s",MSJ_ERR_FUERA_RANGO_A);
		st=st_err_fuera_rango;
	}
	if  (dia<MIN_RANG_DIA || dia >MAX_RANG_DIA){
		fprintf(stderr,"%s",MSJ_ERR_FUERA_RANGO_D);
        st=st_err_fuera_rango;
    }

	st=st_ing_valor;
	printf("%li %li %li",anio,mes,dia); //para verificar si funciona
	printf("%d",st);
}
*/