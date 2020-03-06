#include "ClinicalData_Train.h"

ClinicalData_Train createClinicalDataArg_Train(float age, float bmi, float glucose, float insulin, float mcp1, int disease_type, float c1, float c2, float c3, float c4, int clinicalDataCount)
{
	ClinicalData_Train clinicalData_Train;

	clinicalData_Train.age = age;
	clinicalData_Train.bmi = bmi;
	clinicalData_Train.glucose = glucose;
	clinicalData_Train.insulin = insulin;
	clinicalData_Train.mcp1 = mcp1;
	clinicalData_Train.c1 = c1;
	clinicalData_Train.c2 = c2;
	clinicalData_Train.c3 = c3;
	clinicalData_Train.c4 = c4;
	clinicalData_Train.disease_type = disease_type;
	clinicalData_Train.clinicalDataCount = clinicalDataCount;


	return clinicalData_Train;
}



ClinicalData_Train createClinicalData_Train()
{
	ClinicalData_Train newClinicalData_Train;

	newClinicalData_Train.age = 0.0;

	newClinicalData_Train.bmi = 0.0;

	newClinicalData_Train.glucose = 0.0;

	newClinicalData_Train.insulin = 0.0;

	newClinicalData_Train.mcp1 = 0.0;

	newClinicalData_Train.disease_type = 0;

	newClinicalData_Train.c1 = 0.0;
	newClinicalData_Train.c2 = 0.0;
	newClinicalData_Train.c3 = 0.0;
	newClinicalData_Train.c4 = 0.0;

	newClinicalData_Train.clinicalDataCount = 0;

	return newClinicalData_Train;
}

void printClinicalData_Train(PtClinicalData_Train _this)
{
	printf("\n Age: %f \n BMI: %f \n Glucose: %.4f \n Insulin: %.4f \n Mcp1: %.4f \n Disease_type: %d \n c1: %.4f \n c2: %.4f \n c3: %.4f \n c4: %.4f \n ClinicalDataCount: %d \n",
		_this->age, _this->bmi, _this->glucose, _this->insulin, _this->mcp1, _this->disease_type, _this->c1, _this->c2, _this->c3, _this->c4, _this->clinicalDataCount);
}