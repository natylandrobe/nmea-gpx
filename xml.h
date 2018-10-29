#ifndef XML_H
#define XML_H

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
#define SPC  "  "
#define SPC2 "    "
#define SPC3 "      "
#define T "T"
#define Z "Z"
#define XML "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
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

#define HELP "Utilice en cualquier orden los siguientes argumentos:\n-n o --name para ingresar el nombre de la ruta\n-f o --format aaaammdd para ingresar el anio, mes y dia\n-y o --year para ingresar el anio con la centuria\n-m o --month para ingresar el numero de mes y\n-d o --day para ingresar el numero de dia del mes \n"

#endif

