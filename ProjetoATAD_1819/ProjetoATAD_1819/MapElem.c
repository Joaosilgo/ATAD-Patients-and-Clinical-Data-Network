#include "MapElem.h"
#include "AvgDistrict.h"
#include <stdio.h>

void mapKeyPrint(MapKey key) {
	printf("\n\n\n\n\nKEY: %s \n", key.district);
}

void mapValuePrint(MapValue value) {
	printf("VALUE: \n avgAgeDistrict: %.2f \n avgBMIDistrict: %.2f \n avgGlucoseDistrict: %.2f \n avgInsulinDistrict: %.2f \n avgMcp1District: %.2f \nCount %d \n",
		/*value.district,*/ value.avgAgeDistrict, value.avgBMIDistrict, value.avgGlucoseDistrict, value.avgInsulinDistrict , value.avgMcp1District , value.count);

}

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2) {
//	return (key1.district == key2);
	return (strcmp(key1.district, key2.district) == 0);
}