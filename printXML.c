#include "structData.h"

#define TRK "<trk>"
#define TRK_C "</trk>"
#define TRKSEG "<trkseg>"
#define TRKSEG_C "</trkseg>"
#define TRKPT_START "<trackpt lat=\""
#define TRKPT_MID "\" lon=\""
#define TRKPT_FIN "\">"
#define ELE "<ele>"
#define ELE_C "</ele>"
#define TRKPT_C "</trkpt>"
#define SPC  "   "
#define SPC2 "      "
#define SPC3 "         "
#define GUION "-"
#define T "T"
#define Z "Z"
#define DOSPUNT ":"
#define XML "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define GPX "<gpx version=\"1.1\" creator=\"nmea-gpx\" xmlns=\"http://www.topografix.com/GPX/1/1\">"
#define GPX_C "</gpx>"

#define META "<metadata>"
#define META_C "</metadata>"
#define NAME "<name>"
#define NAME_C "</name>"
#define TIME "<time>"
#define TIME_C "</time>"
#define YEAR_DIFF 1900
#define MON_DIFF 1

void printMetadata(char *name){
	time_t rawtime;
   	struct tm *timeinfo;
   	time(&rawtime);
   	timeinfo = localtime(&rawtime);

	printf(XML "\n");
	printf(GPX "\n");
	printf(SPC META "\n"
			SPC2 NAME "%s" NAME_C "\n"
			SPC2 TIME "%d" GUION "%d" GUION "%d" T "%d" DOSPUNT "%d" DOSPUNT "%d" Z TIME_C "\n"
		    SPC META_C "\n"
		    SPC TRK "\n"
		    SPC2 TRKSEG "\n",
		name,
		(*timeinfo).tm_year + YEAR_DIFF,
		(*timeinfo).tm_mon + MON_DIFF,
		(*timeinfo).tm_mday,
		(*timeinfo).tm_hour,
		(*timeinfo).tm_min,
		(*timeinfo).tm_sec);



}

void printTrkC(void){
	printf(SPC2 TRKSEG_C "\n"
			SPC TRK_C    "\n"
				GPX_C    "\n");
}

void printStruct(struct data track){
	printf(SPC3 TRKPT_START "%f" TRKPT_MID "%f" TRKPT_FIN "\n"
			SPC3 SPC ELE "%f" ELE_C "\n"
			SPC3 SPC TIME "%d" GUION "%d" GUION "%d" T "%d" DOSPUNT "%d" DOSPUNT "SEG" Z TIME_C "\n"
			SPC3 TRKPT_C "\n",
		track.lat,
		track.lon,
		track.ele,
		track.f.anio,
		track.f.mes,
		track.f.dia,
		track.f.hora,
		track.f.minutos);
}