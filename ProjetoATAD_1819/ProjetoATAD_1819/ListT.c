

#include "ListT.h"
#include <stdio.h>
#include <stdlib.h> 
#include <Windows.h>
#include<conio.h>

typedef struct listImplT {
	ListElem_Train *elements;
	unsigned int size;
	unsigned int capacity;
} ListImplT;

/*
Cria uma nova instância da List.
Recebe:
initialCapacity - capacidade inicial (se aplicável)
Retorno:
referência da instância ou;
NULL no caso de inexistência de memória.
*/
PtListT listCreateT(unsigned int capacity) {
	PtListT newList = (PtListT)malloc(sizeof(ListImplT));
	if (newList == NULL) { return NULL; }

	newList->elements = (ListElem_Train*)calloc(capacity, sizeof(ListElem_Train));
	if (newList->elements == NULL) {
		free(newList);
		return NULL;
	}

	newList->size = 0;
	newList->capacity = capacity;

	return newList;
}

/*
Destroi uma instância, libertando a memória associada.
Argumentos:
ptList - endereço da referência da instância;
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listDestroyT(PtListT *ptList) {
	PtListT curList = (*ptList);

	if (curList == NULL) return LIST_NULL;

	free(curList->elements);
	free(curList);

	(*ptList) = NULL;

	return LIST_OK;
}

/*
Adiciona um elemento numa dada instância.
Argumentos:
list - referência da instância;
rank - o rank/índice para a operação  (0 >= r <= size);
elem - elemento a emlistar;
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_FULL caso a lista esteja cheia, ou;
LIST_NO_MEMORY caso nao haja memória para guardar o elemento, ou;
LIST_INVALID_RANK caso o rank seja inválido para a operação, ou;
LIST_OK em caso de sucesso;
*/
int listAddT(PtListT list, int rank, ListElem_Train elem) {
	if (list == NULL) { return LIST_NULL; }
	if (list->size == list->capacity) { return LIST_FULL; }
	if (rank < 0 || rank > list->size) { return LIST_INVALID_RANK; }


	/* inserir em rank, deslocando antes os elementos seguintes
	para haver espaco para o novo elemento */
	for (int i = list->size - 1; i >= rank; i--) {
		list->elements[i + 1] = list->elements[i];
	}

	list->elements[rank] = elem;
	list->size++;

	return LIST_OK;
}

/*
Remove um elemento de uma dada instância.
Argumentos:
list - referência da instância;
rank - o rank/índice para a operação  (0 >= r <= size - 1);
ptElem - elemento removido (retorno por referência);
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inválido para a operação, ou;
LIST_OK em caso de sucesso;
*/
int listRemoveT(PtListT list, int rank, ListElem_Train *ptRemovedElem) {
	if (list == NULL) { return LIST_NULL; }
	if (list->size == 0) { return LIST_EMPTY; };
	if (rank < 0 || rank > list->size - 1) { return LIST_INVALID_RANK; }

	(*ptRemovedElem) = list->elements[rank];

	/* deslocar todos os elementos seguintes uma posicao atras*/
	for (int i = rank; i < list->size - 1; i++) {
		list->elements[i] = list->elements[i + 1];
	}

	list->size--;

	return LIST_OK;
}

/*
Obtem o elemento no rank de uma dada instância.
Argumentos:
list - referência da instância;
rank - o rank/índice para a operação  (0 >= r <= size - 1);
ptElem - elemento no rank (retorno por referência);
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inválido para a operação, ou;
LIST_OK em caso de sucesso;
*/
int listGetT(PtListT list, int rank, ListElem_Train *ptElem) {
	if (list == NULL) { return LIST_NULL; }
	if (list->size == 0) { return LIST_EMPTY; }
	if (rank < 0 || rank > list->size - 1) { return LIST_INVALID_RANK; }

	(*ptElem) = list->elements[rank];

	return LIST_OK;
}

/*
Substitui o elemento no rank de uma dada instância, retornando o
elemento substituido.
Argumentos:
list - referência da instância;
rank - o rank/índice para a operação  (0 >= r <= size - 1);
elem - elemento a inserir no rank;
ptOldElem - elemento anterior no rank (retorno por referência);
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inválido para a operação, ou;
LIST_OK em caso de sucesso;
*/
int listSetT(PtListT list, int rank, ListElem_Train newElem, ListElem_Train *ptOldElem) {
	if (list == NULL) { return LIST_NULL; }
	if (list->size == 0) { return LIST_EMPTY; }
	if (rank < 0 || rank > list->size - 1) { return LIST_INVALID_RANK; }

	(*ptOldElem) = list->elements[rank];

	list->elements[rank] = newElem;

	return LIST_OK;
}

/*
Quantos elementos estão armazenados numa instância.
Argumentos:
list - referência da instância;
ptSize - número de elementos (retorno por referência);
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listSizeT(PtListT list, int *ptSize) {
	if (list == NULL) { return LIST_NULL; }

	(*ptSize) = list->size;
	return LIST_OK;
}

/*
Verifica se a instância está vazia (não contém elementos)
Argumentos:
list - referência da instância;
Retorno:
1 caso esteja vazia ou a referência seja NULL, ou;
0 caso não esteja vazia;
*/
int listIsEmptyT(PtListT list) {
	if (list == NULL) return 1;

	return (list->size == 0) ? 1 : 0;
}

/*
Limpa uma instância (remove todos os elementos)
Argumentos:
list - referência da instância;
Retorno:
LIST_NULL se a referência recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listClearT(PtListT list) {
	if (list == NULL) return LIST_NULL;

	list->size = 0;

	return LIST_OK;
}

/*
Mostra informação sobre uma instância
Argumentos:
list - referência da instância;
*/
void listPrintT(PtListT list) {
	if (list == NULL) {
		printf("LIST NULL \n");
	}
	else if (listIsEmpty(list)) {
		printf("LIST EMPTY \n");
	}
	else {
		//mostra ranks e elementos
		printf("LIST elements: \n");
		for (int i = 0; i < list->size; i++) {
			//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | 3);
			printf("\nAt rank %d: ", i);
			//listElemPrint(list->elements[i]);
			listElemPrint_Train(list->elements[i]);
		}
		printf("-------------- \n");
	}
}