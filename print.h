#ifndef PRINT_H
#define PRINT_H

#ifndef STRUCTDATA_H
#include "structData.h"
#endif

bool printMetadata(char *name);
void printTrkC(void);
void printStruct(struct data track);
void printHelp(void);

#endif
