#include "ClinicalData.h"

ClinicalData createClinicalDataArg(float age, float bmi, float glucose, float insulin, float mcp1, int disease_type, int clinicalDataCount)
{
	ClinicalData clinicalData;

	clinicalData.age = age;
	clinicalData.bmi = bmi;
	clinicalData.glucose = glucose;
	clinicalData.insulin = insulin;
	clinicalData.mcp1 = mcp1;
	clinicalData.disease_type = disease_type;
	clinicalData.clinicalDataCount = clinicalDataCount;


	return clinicalData;
}



ClinicalData createClinicalData()
{
	ClinicalData newClinicalData;

	newClinicalData.age = 0.0;

	newClinicalData.bmi = 0.0;

	newClinicalData.glucose = 0.0;

	newClinicalData.insulin = 0.0;

	newClinicalData.mcp1 = 0.0;

	newClinicalData.disease_type = 0;

	newClinicalData.clinicalDataCount = 0;

	return newClinicalData;
}

void printClinicalData(PtClinicalData _this)
{
	printf("\n Age: %f \n BMI: %f \n Glucose: %.4f \n Insulin: %.4f \n Mcp1: %.4f \n Disease_type: %d \n ClinicalDataCount: %d \n",
		_this->age, _this->bmi , _this->glucose, _this->insulin, _this->mcp1, _this->disease_type, _this->clinicalDataCount);
}