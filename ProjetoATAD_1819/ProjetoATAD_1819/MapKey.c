#include "MapKey.h"


District createDistrict(char district[])
{
	District d;

	
	strcpy_s(d.district, strlen(district) + 1, district);
	

	return d;
}