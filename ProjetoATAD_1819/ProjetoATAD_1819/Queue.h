#pragma once


#define QUEUE_OK            0
#define QUEUE_NULL          1
#define QUEUE_NO_MEMORY     2
#define QUEUE_EMPTY         3
#define QUEUE_FULL          4


#include "QueueElem.h"

struct queueImpl;
typedef struct queueImpl *PtQueue;

/*

*/
PtQueue queueCreate(unsigned int initialCapacity);

/*

*/
int queueDestroy(PtQueue *ptQueue);

/*

*/
int queueEnqueue(PtQueue queue, QueueElem elem);

/*

*/
int queueDequeue(PtQueue queue, QueueElem *ptElem);

/*

*/
int queuePeek(PtQueue queue, QueueElem *ptElem);

/*

*/
int queueSize(PtQueue queue, int *ptSize);

/*

*/
int queueIsEmpty(PtQueue queue);

/*

*/
int queueClear(PtQueue queue);

/*

*/
void queuePrint(PtQueue queue);
