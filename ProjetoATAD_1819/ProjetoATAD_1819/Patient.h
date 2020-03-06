#pragma once
#include "ClinicalData.h"
#include "Date.h"


typedef struct patient {
	int id;
	Date birthdate;
	char gender;
	char hospital[100];
	char district[50];
	ClinicalData clinicalData;
}Patient;

typedef Patient* PtPatient;

Patient createPatient(int id, Date birthdate, char gender, char hospital[], char district[]);
void printPatient(PtPatient _this);