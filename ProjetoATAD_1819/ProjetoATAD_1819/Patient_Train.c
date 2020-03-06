#include "Patient_Train.h"
#include <Windows.h>

Patient_Train createPatient_Train(int id, Date birthdate, char gender, char hospital[], char district[])
{
	Patient_Train patient;

	patient.id = id;
	patient.birthdate = birthdate;
	patient.gender = gender;

	strcpy_s(patient.hospital, strlen(hospital) + 1, hospital);
	strcpy_s(patient.district, strlen(district) + 1, district);

	patient.clinicalData_Train = createClinicalData_Train();

	return patient;
}

void printPatient_Train(PtPatient_Train _this)
{
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
	printf("Patient %3d: %-10s | %s | %02d/%02d/%02d | %c \n", _this->id, _this->hospital, _this->district, _this->birthdate.day, _this->birthdate.month, _this->birthdate.year, _this->gender);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 7);
	printClinicalData_Train(&_this->clinicalData_Train);
}