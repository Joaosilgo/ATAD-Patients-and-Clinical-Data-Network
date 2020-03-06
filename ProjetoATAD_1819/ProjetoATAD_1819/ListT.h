#pragma once



#define LIST_OK            0
#define LIST_NULL          1
#define LIST_NO_MEMORY     2
#define LIST_EMPTY         3
#define LIST_FULL          4
#define LIST_INVALID_RANK  5


#include"ListElemT.h" 

struct listImplT;
typedef struct listImplT *PtListT;

PtListT listCreateT(unsigned int initialCapacity);
int listDestroyT(PtListT *ptList);

int listAddT(PtListT list, int rank, ListElem_Train elem);
int listRemoveT(PtListT list, int rank, ListElem_Train *ptElem);
int listGetT(PtListT list, int rank, ListElem_Train *ptElem);
int listSetT(PtListT list, int rank, ListElem_Train elem, ListElem_Train *ptOldElem);
int listSizeT(PtListT list, int *ptSize);
int listIsEmptyT(PtListT list);
int listClearT(PtListT list);
void listPrintT(PtListT list);

