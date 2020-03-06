#pragma once
#pragma once

//#define MAP_OK            0
//#define MAP_NULL          1
//#define MAP_NO_MEMORY     2
//#define MAP_EMPTY         3
//#define MAP_FULL          4
//#define MAP_UNKNOWN_KEY	  5
//
//#include "mapElem.h"
//
//struct mapImpl;
//typedef struct mapImpl *PtMap;
//
//PtMap mapCreate(unsigned int initialCapacity);
//int mapDestroy(PtMap *ptMap);
//int mapPut(PtMap map, MapKey key, MapValue value);
//int mapRemove(PtMap map, MapKey key, MapValue *ptValue);
//int mapGet(PtMap map, MapKey key, MapValue *ptValue);
//int mapContains(PtMap map, MapKey key);
//int mapSize(PtMap map, int *ptSize);
//int mapIsEmpty(PtMap map);
//int mapClear(PtMap map);
//void mapPrint(PtMap map);








#pragma once

#define MAP_OK            0
#define MAP_NULL          1
#define MAP_NO_MEMORY     2
#define MAP_EMPTY         3
#define MAP_FULL          4
#define MAP_UNKNOWN_KEY	  5

/* Contem definição do tipo a guardar na map */
#include "MapElem.h"

/* Forward declaration do registo (representação dos dados)
da map.
Tem de estar definida em concreto num ficheiro *.c aquando
da compilação do programa.
*/
struct mapImpl;

/* Definicao de referência para uma instância de map */
typedef struct mapImpl *PtMap;

/*
Cria uma nova instância da Map.
Recebe:
initialCapacity - capacidade inicial (se aplicável)
Retorno:
referência da instância ou;
NULL no caso de inexistência de memória.
*/
PtMap mapCreate(unsigned int initialCapacity);

/*
Destroi uma instância, libertando a memória associada.
Argumentos:
ptMap - endereço da referência da instância;
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_OK em caso de sucesso;
*/
int mapDestroy(PtMap *ptMap);

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
int mapPut(PtMap map, MapKey key, MapValue value);

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
int mapRemove(PtMap map, MapKey key, MapValue *ptValue);

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
int mapGet(PtMap map, MapKey key, MapValue *ptValue);

/*
Verifica se uma chave faz parte do mapa.
Argumentos:
map - referência da instância;
key - chave do mapeamento;
Retorno:
1 se existir a chave;
0 se não existir ou o mapa for NULL;
*/
int mapContains(PtMap map, MapKey key);

/*
Permite saber o conjunto de chaves contidas num map.
Argumentos:
map - referência da instância
Retorno:
NULL caso o map seja NULL ou a instancia esteja vazia
Um array (alocado dinamicamente) contendo todas as chaves atualmente
no mapa
*/
MapKey* mapKeys(PtMap map);

/*
Permite saber o conjunto de valores contidos num map.
Argumentos:
map - referência da instância
Retorno:
NULL caso o map seja NULL ou a instancia esteja vazia
Um array (alocado dinamicamente) contendo todas os valores atualmente
no mapa
*/
MapValue* mapValues(PtMap map);

/*
Quantos elementos estão armazenados numa instância.
Argumentos:
map - referência da instância;
ptSize - número de elementos (retorno por referência);
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_OK em caso de sucesso;
*/
int mapSize(PtMap map, int *ptSize);

/*
Verifica se a instância está vazia (não contém elementos)
Argumentos:
map - referência da instância;
Retorno:
1 caso esteja vazia ou a referência seja NULL, ou;
0 caso não esteja vazia;
*/
int mapIsEmpty(PtMap map);

/*
Limpa uma instância (remove todos os elementos)
Argumentos:
map - referência da instância;
Retorno:
MAP_NULL se a referência recebida for NULL, ou;
MAP_OK em caso de sucesso;
*/
int mapClear(PtMap map);

/*
Mostra informação sobre uma instância
Argumentos:
map - referência da instância;
*/
void mapPrint(PtMap map);

int findKeyIndex(PtMap map, MapKey key);
/*

//SEM COMENTÁRIOS - USO PEDAGÓGICO

#define MAP_OK            0
#define MAP_NULL          1
#define MAP_NO_MEMORY     2
#define MAP_EMPTY         3
#define MAP_FULL          4
#define MAP_UNKNOWN_KEY	  5

#include "mapElem.h"

struct mapImpl;
typedef struct mapImpl *PtMap;

PtMap mapCreate(unsigned int initialCapacity);
int mapDestroy(PtMap *ptMap);
int mapPut(PtMap map, MapKey key, MapValue value);
int mapRemove(PtMap map, MapKey key, MapValue *ptValue);
int mapGet(PtMap map, MapKey key, MapValue *ptValue);
int mapContains(PtMap map, MapKey key);
int mapSize(PtMap map, int *ptSize);
int mapIsEmpty(PtMap map);
int mapClear(PtMap map);
void mapPrint(PtMap map);

*/
void mapBubbleSortDistrict(PtMap map);