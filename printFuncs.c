#include "structData.h"
#include "xml.h"


bool printMetadata(char *name){

	time_t rawtime;
   	struct tm *timeinfo;

   	if(!name){
   		
   		return false;
   	}

   	time(&rawtime);
   	timeinfo = localtime(&rawtime);

   	printf("%s\n", XML);
	printf("%s\n", GPX);
	printf("%s%s\n%s%s%s%s\n%s%s%d-%d-%d%s%d:%d:%s%s%d\n%s%s\n%s%s\n%s%s\n",
		SPC,META,
		SPC2,NAME,name,NAME_C,
		SPC2,TIME,
		timeinfo->tm_year + YEAR_DIFF,
		timeinfo->tm_mon + MON_DIFF,
		timeinfo->tm_mday,
		T,
		timeinfo->tm_hour,
		timeinfo->tm_min,
		Z,
		TIME_C,
		timeinfo->tm_sec,
		SPC,META_C,
		SPC,TRK,
		SPC2,TRKSEG);

	return true;
}

void printTrkC(void){

	printf("%s%s\n%s%s\n%s\n",
			SPC2,TRKSEG_C,
			SPC, TRK_C,
			GPX_C);
}

void printStruct(struct data track){

	printf("%s%s%f%s%f%s\n%s%s%s%f%s\n%s%s%s%d-%d-%d%s%d:%d:%.3f%s%s\n%s%s\n",
		SPC3, TRKPT_START,
		track.lat,
		TRKPT_MID,
		track.lon,
		TRKPT_FIN,
		SPC3, SPC, ELE,
		track.ele,
		ELE_C,
		SPC3, SPC, TIME,track.f.anio, track.f.mes, track.f.dia,
		T,track.f.hora,track.f.minutos,track.f.segundos,
		Z, TIME_C,
		SPC3, TRKPT_C);
}

void printHelp(void){

	printf("%s\n", HELP);
}