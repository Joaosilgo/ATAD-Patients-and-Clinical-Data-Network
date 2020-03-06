#include "map.h"
#include "Map.h"
#include <stdio.h>
#include <stdlib.h>
//
///*
//Definicao de um registo auxiliar (tuplo) para guardar
//um mapeamento chave/valor
//*/
//typedef struct keyValue {
//	MapKey key;
//	MapValue value;
//} KeyValue;
//
//
//typedef struct mapImpl {
//	KeyValue *elements;
//	unsigned int size;
//	unsigned int capacity;
//} MapImpl;
//
//
///*
//Definicao de funcao auxiliar de pesquisa de uma key.
//Algoritmo de pesquisa sequencial. Assume que map != NULL
//*/
//int findKeyIndex(PtMap map, MapKey key) {
//
//	for (int i = 0; i < map->size; i++) {
//		if (mapKeyEquals(key, map->elements[i].key)) {
//			return i;
//		}
//	}
//
//	return -1;
//}
//
//
///*
//Cria uma nova instância da Map.
//Recebe:
//initialCapacity - capacidade inicial (se aplicável)
//Retorno:
//referência da instância ou;
//NULL no caso de inexistência de memória.
//*/
//PtMap mapCreate(unsigned int initialCapacity) {
//	PtMap newMap = (PtMap)malloc(sizeof(MapImpl));
//	if (newMap == NULL) return NULL;
//
//	newMap->elements = (KeyValue*)calloc(initialCapacity,
//		sizeof(KeyValue));
//
//	if (newMap->elements == NULL) {
//		free(newMap);
//		return NULL;
//	}
//
//	newMap->size = 0;
//	newMap->capacity = initialCapacity;
//
//	return newMap;
//}
//
///*
//Destroi uma instância, libertando a memória associada.
//Argumentos:
//ptMap - endereço da referência da instância;
//Retorno:
//MAP_NULL se a referência recebida for NULL, ou;
//MAP_OK em caso de sucesso;
//*/
//int mapDestroy(PtMap *ptMap) {
//	PtMap map = (*ptMap);
//
//	if (map == NULL) return MAP_NULL;
//
//	free(map->elements);
//	free(map);
//
//	*ptMap = NULL;
//
//	return MAP_OK;
//}
//
///*
//Adiciona um mapeamento numa dada instância. Se a chave
//já existir, atualiza o valor mapeado.
//Argumentos:
//map - referência da instância;
//key - chave do mapeamento;
//value - valor mapeado;
//Retorno:
//MAP_NULL se a referência recebida for NULL, ou;
//MAP_FULL caso o mapa esteja cheio, ou;
//MAP_NO_MEMORY caso nao haja memória para guardar o elemento, ou;
//MAP_OK em caso de sucesso;
//*/
//int mapPut(PtMap map, MapKey key, MapValue value) {
//	if (map == NULL) return MAP_NULL;
//	if (map->size == map->capacity) return MAP_FULL;
//
//	int index = findKeyIndex(map, key);
//	if (index != -1) {
//		//ja existe a chave; subsituir valor
//		map->elements[index].value = value;
//	}
//	else {
//		//adicionar ao mapa o novo mapeamento
//		KeyValue entry;
//		entry.key = key;
//		entry.value = value;
//		map->elements[map->size++] = entry;
//	}
//
//	return MAP_OK;
//}
//
///*
//Remove um mapeamento de uma dada instância.
//Argumentos:
//map - referência da instância;
//key - chave do mapeamento;
//ptValue - valor removido (retorno por referência);
//Retorno:
//MAP_NULL se a referência recebida for NULL, ou;
//MAP_EMPTY caso o mapa esteja vazio, ou;
//MAP_UNKNOWN_KEY caso a chave não exista no mapa, ou;
//MAP_OK em caso de sucesso;
//*/
//int mapRemove(PtMap map, MapKey key, MapValue *ptValue) {
//	if (map == NULL) return MAP_NULL;
//	if (map->size == 0) return MAP_EMPTY;
//
//	int index = findKeyIndex(map, key);
//	if (index == -1) return MAP_UNKNOWN_KEY;
//
//	*ptValue = map->elements[index].value;
//	//substituir pelo ultimo e decrementar tamanho
//	map->elements[index] = map->elements[map->size - 1];
//	map->size--;
//
//	return MAP_OK;
//}
//
///*
//Obtem um valor mapeado de uma dada instância.
//Argumentos:
//map - referência da instância;
//key - chave do mapeamento;
//ptValue - valor mapeado (retorno por referência);
//Retorno:
//MAP_NULL se a referência recebida for NULL, ou;
//MAP_EMPTY caso o mapa esteja vazio, ou;
//MAP_UNKNOWN_KEY caso a chave não exista no mapa, ou;
//MAP_OK em caso de sucesso;
//*/
//int mapGet(PtMap map, MapKey key, MapValue *ptValue) {
//	if (map == NULL) return MAP_NULL;
//	if (map->size == 0) return MAP_EMPTY;
//
//	int index = findKeyIndex(map, key);
//	if (index == -1) return MAP_UNKNOWN_KEY;
//
//	*ptValue = map->elements[index].value;
//
//	return MAP_OK;
//
//}
//
///*
//Verifica se uma chave faz parte do mapa.
//Argumentos:
//map - referência da instância;
//key - chave do mapeamento;
//Retorno:
//1 se existir a chave;
//0 se não existir ou o mapa for NULL;
//*/
//int mapContains(PtMap map, MapKey key) {
//	if (map == NULL) return 0;
//
//	int index = findKeyIndex(map, key);
//	return (index != -1) ? 1 : 0;
//}
//
///*
//Quantos elementos estão armazenados numa instância.
//Argumentos:
//map - referência da instância;
//ptSize - número de elementos (retorno por referência);
//Retorno:
//MAP_NULL se a referência recebida for NULL, ou;
//MAP_OK em caso de sucesso;
//*/
//int mapSize(PtMap map, int *ptSize) {
//	if (map == NULL) return MAP_NULL;
//
//	*ptSize = map->size;
//
//	return MAP_OK;
//}
//
///*
//Verifica se a instância está vazia (não contém elementos)
//Argumentos:
//map - referência da instância;
//Retorno:
//1 caso esteja vazia ou a referência seja NULL, ou;
//0 caso não esteja vazia;
//*/
//int mapIsEmpty(PtMap map) {
//	if (map == NULL) return 1;
//
//	return (map->size == 0) ? 1 : 0;
//}
//
///*
//Limpa uma instância (remove todos os elementos)
//Argumentos:
//map - referência da instância;
//Retorno:
//MAP_NULL se a referência recebida for NULL, ou;
//MAP_OK em caso de sucesso;
//*/
//int mapClear(PtMap map) {
//	if (map == NULL) return MAP_NULL;
//
//	map->size = 0;
//
//	return MAP_OK;
//}
//
///*
//Mostra informação sobre uma instância
//Argumentos:
//map - referência da instância;*/
//
//void mapPrint(PtMap map) {
//	if (map == NULL) {
//		printf("MAP NULL \n");
//	}
//	else if (mapIsEmpty(map)) {
//		printf("MAP EMPTY \n");
//	}
//	else {
//		printf("Map key/values: \n");
//
//		for (int i = 0; i < map->size; i++) {
//			KeyValue entry = map->elements[i];
//			mapKeyPrint(entry.key);
//			printf("\t");
//			mapValuePrint(entry.value);
//		}
//
//		printf("--------------- \n");
//	}
//}



#include "map.h"
#include <stdio.h>
#include <stdlib.h>

/*
Definicao de um registo auxiliar (tuplo) para guardar
um mapeamento chave/valor
*/
typedef struct keyValue {
	MapKey key;
	MapValue value;
} KeyValue;


typedef struct mapImpl {
	KeyValue *elements;
	unsigned int size;
	unsigned int capacity;
} MapImpl;


/*
Definicao de funcao auxiliar de pesquisa de uma key.
Algoritmo de pesquisa sequencial. Assume que map != NULL
*/
int findKeyIndex(PtMap map, MapKey key) {

	for (unsigned int i = 0; i < map->size; i++) {
		if (mapKeyEquals(key, map->elements[i].key)) {
			return i;
		}
	}

	return -1;
}


/*
Cria uma nova instância da Map.
Recebe:
initialCapacity - capacidade inicial (se aplicável)
Retorno:
referência da instância ou;
NULL no caso de inexistência de memória.
*/
PtMap mapCreate(unsigned int initialCapacity) {
	PtMap newMap = (PtMap)malloc(sizeof(MapImpl));
	if (newMap == NULL) return NULL;

	newMap->elements = (KeyValue*)calloc(initialCapacity,
		sizeof(KeyValue));

	if (newMap->elements == NULL) {
		free(newMap);
		return NULL;
	}

	newMap->size = 0;
	newMap->capacity = initialCapacity;

	return newMap;
}

/*
Destroi uma instância, libertando a memória associada.
Argumentos:
ptMap - endereço da referência da instância;
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_OK em caso de sucesso;
*/
int mapDestroy(PtMap *ptMap) {
	PtMap map = (*ptMap);

	if (map == NULL) return MAP_NULL;

	free(map->elements);
	free(map);

	*ptMap = NULL;

	return MAP_OK;
}

/*
Adiciona um mapeamento numa dada instância. Se a chave
já existir, atualiza o valor mapeado.
Argumentos:
map - referência da instância;
key - chave do mapeamento;
value - valor mapeado;
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_FULL caso o mapa esteja cheio, ou;
MAP_NO_MEMORY caso nao haja memória para guardar o elemento, ou;
MAP_OK em caso de sucesso;
*/
int mapPut(PtMap map, MapKey key, MapValue value) {
	if (map == NULL) return MAP_NULL;
	if (map->size == map->capacity) return MAP_FULL;

	int index = findKeyIndex(map, key);
	if (index != -1) {
		//ja existe a chave; subsituir valor
		map->elements[index].value = value;
	}
	else {
		//adicionar ao mapa o novo mapeamento
		KeyValue entry;
		entry.key = key;
		entry.value = value;
		map->elements[map->size++] = entry;
	}

	return MAP_OK;
}

/*
Remove um mapeamento de uma dada instância.
Argumentos:
map - referência da instância;
key - chave do mapeamento;
ptValue - valor removido (retorno por referência);
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_EMPTY caso o mapa esteja vazio, ou;
MAP_UNKNOWN_KEY caso a chave não exista no mapa, ou;
MAP_OK em caso de sucesso;
*/
int mapRemove(PtMap map, MapKey key, MapValue *ptValue) {
	if (map == NULL) return MAP_NULL;
	if (map->size == 0) return MAP_EMPTY;

	int index = findKeyIndex(map, key);
	if (index == -1) return MAP_UNKNOWN_KEY;

	*ptValue = map->elements[index].value;
	//substituir pelo ultimo e decrementar tamanho
	map->elements[index] = map->elements[map->size - 1];
	map->size--;

	return MAP_OK;
}

/*
Obtem um valor mapeado de uma dada instância.
Argumentos:
map - referência da instância;
key - chave do mapeamento;
ptValue - valor mapeado (retorno por referência);
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_EMPTY caso o mapa esteja vazio, ou;
MAP_UNKNOWN_KEY caso a chave não exista no mapa, ou;
MAP_OK em caso de sucesso;
*/
int mapGet(PtMap map, MapKey key, MapValue *ptValue) {
	if (map == NULL) return MAP_NULL;
	if (map->size == 0) return MAP_EMPTY;

	int index = findKeyIndex(map, key);
	if (index == -1) return MAP_UNKNOWN_KEY;

	*ptValue = map->elements[index].value;

	return MAP_OK;

}

/*
Verifica se uma chave faz parte do mapa.
Argumentos:
map - referência da instância;
key - chave do mapeamento;
Retorno:
1 se existir a chave;
0 se não existir ou o mapa for NULL;
*/
int mapContains(PtMap map, MapKey key) {
	if (map == NULL) return 0;

	int index = findKeyIndex(map, key);
	return (index != -1) ? 1 : 0;
}


/*
Permite saber o conjunto de chaves contidas num map.
Argumentos:
map - referência da instância
Retorno:
NULL caso o map seja NULL ou a instancia esteja vazia
Um array (alocado dinamicamente) contendo todas as chaves atualmente
no mapa
*/
MapKey* mapKeys(PtMap map) {
	if (map == NULL || map->size == 0) return NULL;

	MapKey *keys = (MapKey*)malloc(map->size * sizeof(MapKey));

	for (unsigned int i = 0; i < map->size; i++) {
		keys[i] = map->elements[i].key;
	}

	return keys;
}

/*
Permite saber o conjunto de valores contidos num map.
Argumentos:
map - referência da instância
Retorno:
NULL caso o map seja NULL ou a instancia esteja vazia
Um array (alocado dinamicamente) contendo todas os valores atualmente
no mapa
*/
MapValue* mapValues(PtMap map) {
	if (map == NULL || map->size == 0) return NULL;

	MapValue *values = (MapValue*)malloc(map->size * sizeof(MapValue));

	for (unsigned int i = 0; i < map->size; i++) {
		values[i] = map->elements[i].value;
	}

	return values;
}

/*
Quantos elementos estão armazenados numa instância.
Argumentos:
map - referência da instância;
ptSize - número de elementos (retorno por referência);
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_OK em caso de sucesso;
*/
int mapSize(PtMap map, int *ptSize) {
	if (map == NULL) return MAP_NULL;

	*ptSize = map->size;

	return MAP_OK;
}

/*
Verifica se a instância está vazia (não contém elementos)
Argumentos:
map - referência da instância;
Retorno:
1 caso esteja vazia ou a referência seja NULL, ou;
0 caso não esteja vazia;
*/
int mapIsEmpty(PtMap map) {
	if (map == NULL) return 1;

	return (map->size == 0) ? 1 : 0;
}

/*
Limpa uma instância (remove todos os elementos)
Argumentos:
map - referência da instância;
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_OK em caso de sucesso;
*/
int mapClear(PtMap map) {
	if (map == NULL) return MAP_NULL;

	map->size = 0;

	return MAP_OK;
}

/*
Mostra informação sobre uma instância
Argumentos:
map - referência da instância;
*/
void mapPrint(PtMap map) {
	if (map == NULL) {
		printf("MAP NULL \n");
	}
	else if (mapIsEmpty(map)) {
		printf("MAP EMPTY \n");
	}
	else {
		printf("Map key/values: \n");

		for (unsigned int i = 0; i < map->size; i++) {
			KeyValue entry = map->elements[i];
			mapKeyPrint(entry.key);
			printf("\t");
			mapValuePrint(entry.value);
		}

		printf("--------------- \n");
	}
}



//A UNICA RAZÃO PARA ESTÁ FUNÇÃO ESTAR AQUI É PORQUE O KEYVALUE STRUCT ESTÁ DEFINIDO EM MAP.C
//PENSO NÃO HAVER PROBLEMA
void mapBubbleSortDistrict(PtMap map)
{
	int size;
	mapSize(map, &size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			
			KeyValue aux;

			if (strcmp(map->elements[j].key.district, map->elements[j+1].key.district) > 0) {//poderiamos usar aqui o int compareDistrict() que irá fazer a mesma coisa
				aux = map->elements[j];
				map->elements[j] = map->elements[j + 1];
				map->elements[j + 1] = aux;
		
			}
			
		}
	}
}