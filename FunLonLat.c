#include <stdio.h>

#define GRADO_MIN  100
#define LATITUD_MAX 9000.000
#define LATITUD_MIN 0
#define MIN_POR_GRADO 60
#define CARD_SUR "S"
#define CARD_NORTE "N"
//#define CARD_ESTE "E"
//#define CARD_OESTE "W"
//#define LONG_MIN
//#define LONG_MAX
#define VALOR_S_W -1
#define VALOR_N_E 1

float convertirLat(const char lat[],const char cardinal);

int main(void){
char card;
float latitud;	
char s[8];
	fgets(s,8, stdin);
	card == getschar();
	latitud = convertirLat(s, card);
	printf("%f",latitud);

	return 0;
}

/*float convertirLon( const char lon[], const char cardinal){

longitud = atoif(lon);

if(longitud < LONG_MIN || longitud > LONG_MAX)
	return NULL;

if( cardinal != CARD_ESTE && != CARD_OESTE){
	return NULL;
}else if( cardinal == CARD_OESTE){
	longitud = longitud * VALOR_S_W;
}else{
	longitud = longitud * VALOR_N_E;
}

return (int)longitud/LONG_MIN + (longitud%LONG_MIN)/MIN_POR_GRADO;
}
*/

float convertirLat( const char lat[], const char cardinal){
float latitud;
latitud=atof(lat);

if(latitud < LATITUD_MIN || latitud > LATITUD_MAX)
	return 0;

if (cardinal != CARD_NORTE && cardinal != CARD_SUR){
	return 0;

}else if(cardinal == CARD_SUR){
	latitud= latitud*VALOR_S_W;

}else{
	latitud = latitud * VALOR_N_E;
}

return (int)(latitud/GRADO_MIN) + (float)(latitud%GRADO_MIN)/MIN_POR_GRADO;
}