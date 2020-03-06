#pragma once
#include "List.h"
#include "ListT.h"
#include "Map.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

//COMMAND LOAD
void LOAD(PtList list);
//COMMAND CLEAR
void CLEAR(PtList list);
//COMMAND SHOW
void SHOW(PtList list);
//COMMAND SORT
void SORT(PtList list);
//COMMAND AVG
void AVG(PtList list);
//COMMAND NORM
void NORM(PtList list);
//COMMAND CHECKDISTRICT
void CHECKDISTRICT(PtList list);
//COMMAND QUEUE
void QUEUE(PtList list);
//COMMAND LOADT
void LOADT(PtListT listT);
//SHOWT(OPTIONAL)
void SHOWT(PtListT listT);
//COMMANDAVGT
void AVGT(PtListT listT);
//COMMAND NORMT
void NORMT(PtListT listT);
//COMMAND NEURALNET
void NEURALNET();




//AUXILIARES
char** split(char *str, int nFields, const char *delim);
void avg(PtList list);
void avgT(PtListT listT);