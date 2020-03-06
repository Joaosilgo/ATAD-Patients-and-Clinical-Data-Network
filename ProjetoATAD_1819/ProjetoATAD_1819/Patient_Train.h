#pragma once


#include "ClinicalData_Train.h"
#include "Date.h"

typedef struct patient_Train {
	int id;
	Date birthdate;
	char gender;
	char hospital[100];
	char district[50];
	ClinicalData_Train clinicalData_Train;
}Patient_Train;

typedef Patient_Train* PtPatient_Train;

Patient_Train createPatient_Train(int id, Date birthdate, char gender, char hospital[], char district[]);
void printPatient_Train(PtPatient_Train _this);