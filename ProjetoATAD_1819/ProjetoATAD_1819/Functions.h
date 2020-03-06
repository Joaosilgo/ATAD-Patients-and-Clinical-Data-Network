#pragma once
#include "List.h"
#include "Map.h"
#include "Queue.h"
#include "ListT.h"



int getAge(int d1, int m1, int y1, int d2, int m2, int y2);




//SORT
	 //By date
int compareDates(Date d1, Date d2);
void bubbleSortDate(PtList list);
void sortByDate(PtList originalList);

	//By Hospital Name
		//Desempate por Data
int compareHospital(char hospital1[], char hospital2[]);
void bubbleSortHospital(PtList list);
void sortByHospital(PtList originalList);

	//By District Name
		//Desempate por Hospital
int compareDistrict(char hospital1[], char hospital2[]);
void bubbleSortDistrict(PtList list);
void sortByDistrict(PtList originalList);

//AVG
PtList averageClinicalData(PtList patients, PtMap map);
PtMap sumVals(PtList list, PtMap map);
PtMap avgVals(PtMap map);

//NORM
//PtList normalizeClinicalData(PtList patients);
PtList normalizeStatistics(PtList list, int k);

//QUEUE
void Queue(PtList list, PtQueue queue);
void commandQueue(PtQueue queue);

//NORMT
PtListT normalizePatientTrain(PtListT list);
int normalizeK();

//AVGT
PtListT averageClinicalDataT(PtListT listT,PtMap map);
PtMap sumValsT(PtListT newList, PtMap map);
PtMap avgValsT(PtMap map);
