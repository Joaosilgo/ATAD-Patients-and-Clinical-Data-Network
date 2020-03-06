#include "Patient.h"
#include <Windows.h>

Patient createPatient(int id, Date birthdate, char gender, char hospital[], char district[])
{
	Patient patient;

	patient.id = id;
	patient.birthdate = birthdate;
	patient.gender = gender;

	strcpy_s(patient.hospital, strlen(hospital) + 1, hospital);
	strcpy_s(patient.district, strlen(district) + 1, district);

	patient.clinicalData = createClinicalData();

	return patient;
}

void printPatient(PtPatient _this)
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
	//System()
	printf("Patient %3d: %-10s | %s | %02d/%02d/%02d | %c \n",_this->id, _this->hospital, _this->district, _this->birthdate.day, _this->birthdate.month, _this->birthdate.year, _this->gender);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7);
	printClinicalData(&_this->clinicalData);
}