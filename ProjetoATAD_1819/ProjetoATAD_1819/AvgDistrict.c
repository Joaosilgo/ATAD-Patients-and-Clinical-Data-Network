#include "AvgDistrict.h"


AvgDistrict createAvgDistrict(int code,float avgAgeDistrict, float avgBMIDistrict, float avgGlucoseDistrict, float avgInsulinDistrict, float avgMcp1District)
{
	AvgDistrict avg;
	avg.code = code;
	avg.avgAgeDistrict = avgAgeDistrict;
	avg.avgBMIDistrict = avgBMIDistrict;
	avg.avgGlucoseDistrict = avgGlucoseDistrict;
	avg.avgInsulinDistrict = avgInsulinDistrict;
	avg.avgMcp1District = avgMcp1District;
	avg.c1 = 0;
	avg.c2 = 0;
	avg.c3 = 0;
	avg.c4 = 0;
	avg.count = 0;
	return avg;
}

void itemPrint(AvgDistrict *_this) {
	

	printf(" \n Code: %d \n avgAgeDistrict: %.2f \n avgBMIDistrict : %.2f \n avgGlucoseDistrict : %.2f \n avgInsulinDistrict : %.2f \n avgMcp1District : %.2f \n",
	_this->code	, _this->avgAgeDistrict, _this->avgBMIDistrict,_this->avgGlucoseDistrict,_this->avgInsulinDistrict, _this->avgMcp1District);
}