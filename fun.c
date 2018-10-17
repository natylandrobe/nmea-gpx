#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef enum estado{st_ing_valor,st_err,st_err_fuera_rango,st_pide_ayuda}status_t;

/*void conver_fecha(const char *str,long **a,long **m,long **d){
        char st1[5];

        st1[0]=str[0];
        st1[1]=str[1];
        st1[2]=str[2];
        st1[3]=str[3];
        st1[4]='\0';
        **a=atol(st1);

        st1[0]=str[4];
        st1[1]=str[5];
        st1[2]='\0';
        **m=atol(st1);

        st1[0]=str[6];
        st1[1]=str[7];
        st1[2]='\0';
        **d=atol(st1);
}*/
//statust_t  ayuda( char argv[],long *anio,long *mes,long *dia,char nom [20]);
int main(int argc, char *argv[]){
        status_t st;
        long anio=0,mes=0,dia=0;
	char nom[20];
/*	st=ayuda(argv,&anio,&mes,&dia,nom);
	switch (st){
	case st_err: printf("valor mal Ingresado");break;
	case st_err_fuera_rango: printf("fuera rango");break;
	case st_pide_ayuda: printf("La ayuda es");break;
	case st_ing_valor: printf("bien");break;
}
	return 0;
	}*/
//	statust_t  ayuda( char argv[],long *anio,long *mes,long *dia,char nom [20]){
	char st1[5];        
        size_t i=1;
        while(argv[i]!=NULL){

        if (strcmp(argv[i],"-h")==0 || strcmp(argv[i],"--help")==0){
        st=st_pide_ayuda;
}
          if (strcmp(argv[i],"-n")==0 || strcmp(argv[i],"--name")==0){
        strcpy(nom,argv[i+1]);
	if (argv[i+1]==NULL){
	st=st_err;}
	puts(nom);
        st=st_ing_valor;
}

       if (strcmp(argv[i],"-f")==0 || strcmp(argv[i],"--format")==0){
 //       conver_fecha(argv[i+1],&anio,&mes,&dia);


        st1[0]=argv[i+1][0];
        st1[1]=argv[i+1][1];
        st1[2]=argv[i+1][2];
        st1[3]=argv[i+1][3];
        st1[4]='\0';
        anio=atol(st1);

        st1[0]=argv[i+1][4];
        st1[1]=argv[i+1][5];
        st1[2]='\0';
        mes=atol(st1);

        st1[0]=argv[i+1][6];
        st1[1]=argv[i+1][7];
        st1[2]='\0';
        dia=atol(st1);
   
     printf("la fecha:%li %li %li\n",anio,mes,dia);
	 if (mes<1 ||mes>12 || anio<1997 || anio>2018 || dia<1 || dia >31){
        st=st_err_fuera_rango;}
	st=st_ing_valor;

}
         if (strcmp(argv[i],"-Y")==0 || strcmp(argv[i],"-year")==0){
        anio=atoi(argv[i+1]);
	 if ( anio<1997 || anio>2018 ){
        st=st_err_fuera_rango;}
	st=st_ing_valor;
}
        if(strcmp(argv[i],"-m")==0 || strcmp(argv[i],"--month")==0){
        mes=atoi(argv[i+1]);
	 if (mes<1 ||mes>12 || anio<1997 || anio>2018 || dia<1 || dia >31){
        st=st_err_fuera_rango;}
	st=st_ing_valor;
}
        if (strcmp(argv[i],"-d")==0 || strcmp(argv[i],"--day")==0){
        dia=atoi(argv[i+1]);
	 if ( dia<1 || dia >31){
        st=st_err_fuera_rango;}
        st=st_ing_valor;}
        i+=2;
}
	printf("%li %li %li",anio,mes,dia);
	printf("%d",st);
}
