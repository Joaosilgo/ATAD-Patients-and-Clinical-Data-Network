#pragma once

typedef struct avgDistrict {

	int code;
	//char district[50];			
	float avgAgeDistrict;
	float avgBMIDistrict;		
	float avgGlucoseDistrict;		
	float avgInsulinDistrict;			
	float avgMcp1District;
	float c1;
	float c2;
	float c3;
	float c4;
	int count;
}AvgDistrict;

typedef AvgDistrict* PtAvgDistrict;

AvgDistrict createAvgDistrict(int code,float avgAgeDistrict, float avgBMIDistrict, float avgGlucoseDistrict, float avgInsulinDistrict, float avgMcp1District);

void itemPrint(AvgDistrict *_this);