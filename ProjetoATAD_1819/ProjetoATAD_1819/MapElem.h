#pragma once
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "AvgDistrict.h"
#include "MapKey.h"
/* definicao do tipo da chave */
typedef  District MapKey;
/* definicao do tipo do valor*/
typedef AvgDistrict MapValue;

void mapKeyPrint(MapKey key);
void mapValuePrint(MapValue value);

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2);