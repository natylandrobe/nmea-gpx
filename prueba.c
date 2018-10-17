#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RANG_A 2018
#define MIN_RANG_A 1997
#define MAX_RANG_MES 12
#define MIN_RANG_MES 1
#define MAX_RANG_DIA 31
#define MIN_RANG_DIA 1

#define MSJ_ERR "ERROR"
#define MSJ_ERR_FUERA_RANGO_A "Esta fuera de rango el año ingresado\n"
#define MSJ_ERR_FUERA_RANGO_M "Esta fuera de rango el mes ingresado\n"
#define MSJ_ERR_FUERA_RANGO_D "Esta fuera de rango el dia ingresado\n"
#define MSJ_AYUDA "Los datos deben ser ingresados de la siguiente manera:\n"
#define MSJ_AYUDA_FECHA "Ingrese -f o --format seguido del año,mes y dia, sin dejar espacios\n"
#define MSJ_AYUDA_A "Escriba -Y o --year seguido del año\n"	
#define MSJ_AYUDA_M "Escriba -m o --month seguido del mes\n"
#define MSJ_AYUDA_D "Escriba -d o --day seguido del dia\n"
#define MSJ_AYUDA_NOM "Escriba -n o --name seguido de su nombre\n"
#define MSJ_AYUDA_NO_ING_DATOS "En caso de no ser ingresados los valores de la fecha se tomara la del sistema\nSi se ingresa primero -d o -m o -Y y luego -f:se reinscribiran los valores por los ingresados despues de -f,y viceversa si primero se ingreso los datos de -f\n  En caso de no ingresar el nombre sera .... \n"//no se que nobre



typedef enum estado{st_ok_argm,st_err_fuera_rango_mes,st_err_fuera_rango_dia,st_err_fuera_rango_anio,st_pide_ayuda,st_err_nomb}status_t;

status_t ayuda (long *anio,long *mes,long *dia,char **t,char **c,char *nom){
	char aux_str[5];
	if (strcmp(*t,"-h")==0 || strcmp(*t,"--help")==0){
	return st_pide_ayuda;
}
        if(strcmp(*t,"-n")==0 || strcmp(*t,"--name")==0){
        strcpy(nom,*c);}
        if (*c==NULL){
        return st_err_nomb;}
        if (strcmp(*t,"-f")==0 || strcmp(*t,"--format")==0){
 //para pasar la fecha a año,mes y dia
     
  	 aux_str[0]=*(*c+0);
         aux_str[1]=*(*c+1);
         aux_str[2]=*(*c+2);
         aux_str[3]=*(*c+3);
         aux_str[4]='\0';
         *anio=atol(aux_str);

        aux_str[0]=*(*c+4);
        aux_str[1]=*(*c+5);
        aux_str[2]='\0';
        *mes=atol(aux_str);

        aux_str[0]=*(*c+6);
        aux_str[1]=*(*c+7);
        aux_str[2]='\0';
        *dia=atol(aux_str);
}


	if (strcmp(*t,"-Y")==0 || strcmp(*t,"--year")==0){
        *anio=atol(*c);
}
        if(strcmp(*t,"-m")==0 || strcmp(*t,"--month")==0){
        *mes=atol(*c);
}
       if (strcmp(*t,"-d")==0 || strcmp(*c,"--day")==0){
        *dia=atol(*c);
}

	if (*mes<MIN_RANG_MES ||*mes>MAX_RANG_MES) {
        return st_err_fuera_rango_mes;
}
        if (*anio<MIN_RANG_A || *anio>MAX_RANG_A) {
        return st_err_fuera_rango_anio;}
        if (*dia<MIN_RANG_DIA || *dia >MAX_RANG_DIA){
        return st_err_fuera_rango_dia;}
       
	return st_ok_argm;
}

int main(int argc, char *argv[]){
	long anio=0,mes=0,dia=0;
	int i=1;
	char *r;
	char *t;
	char nom[20];
	status_t st;
	while (argv[i]!=NULL){
	r=argv[i];
	t=argv[i+1];
	st=ayuda(&anio,&mes,&dia,&r,&t,nom);
	switch (st){
	case st_pide_ayuda: printf("%s %s %s %s %s %s %s",MSJ_AYUDA,MSJ_AYUDA_NOM,MSJ_AYUDA_FECHA,MSJ_AYUDA_A,MSJ_AYUDA_M,MSJ_AYUDA_D,MSJ_AYUDA_NO_ING_DATOS);break;
	case st_err_fuera_rango_mes: fprintf(stderr,"%s:%s",MSJ_ERR,MSJ_ERR_FUERA_RANGO_M);break;
	case st_err_fuera_rango_anio: fprintf(stderr,"%s:%s",MSJ_ERR,MSJ_ERR_FUERA_RANGO_A);break;
	case st_err_fuera_rango_dia:  fprintf(stderr,"%s:%s",MSJ_ERR,MSJ_ERR_FUERA_RANGO_D);break;
	case st_err_nomb:printf("%d",2);break;// en este caso se deberia tomar el nombre por default
	case st_ok_argm: printf("%li %li %li",anio,mes,dia);break;
}	
	
	i+=2;
}	
	return 0;
}
