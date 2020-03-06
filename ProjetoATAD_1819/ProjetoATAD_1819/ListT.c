

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
Cria uma nova inst�ncia da List.
Recebe:
initialCapacity - capacidade inicial (se aplic�vel)
Retorno:
refer�ncia da inst�ncia ou;
NULL no caso de inexist�ncia de mem�ria.
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
Destroi uma inst�ncia, libertando a mem�ria associada.
Argumentos:
ptList - endere�o da refer�ncia da inst�ncia;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
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
Adiciona um elemento numa dada inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size);
elem - elemento a emlistar;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_FULL caso a lista esteja cheia, ou;
LIST_NO_MEMORY caso nao haja mem�ria para guardar o elemento, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
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
Remove um elemento de uma dada inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size - 1);
ptElem - elemento removido (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
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
Obtem o elemento no rank de uma dada inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size - 1);
ptElem - elemento no rank (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
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
Substitui o elemento no rank de uma dada inst�ncia, retornando o
elemento substituido.
Argumentos:
list - refer�ncia da inst�ncia;
rank - o rank/�ndice para a opera��o  (0 >= r <= size - 1);
elem - elemento a inserir no rank;
ptOldElem - elemento anterior no rank (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_EMPTY caso a lista esteja vazia, ou;
LIST_INVALID_RANK caso o rank seja inv�lido para a opera��o, ou;
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
Quantos elementos est�o armazenados numa inst�ncia.
Argumentos:
list - refer�ncia da inst�ncia;
ptSize - n�mero de elementos (retorno por refer�ncia);
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listSizeT(PtListT list, int *ptSize) {
	if (list == NULL) { return LIST_NULL; }

	(*ptSize) = list->size;
	return LIST_OK;
}

/*
Verifica se a inst�ncia est� vazia (n�o cont�m elementos)
Argumentos:
list - refer�ncia da inst�ncia;
Retorno:
1 caso esteja vazia ou a refer�ncia seja NULL, ou;
0 caso n�o esteja vazia;
*/
int listIsEmptyT(PtListT list) {
	if (list == NULL) return 1;

	return (list->size == 0) ? 1 : 0;
}

/*
Limpa uma inst�ncia (remove todos os elementos)
Argumentos:
list - refer�ncia da inst�ncia;
Retorno:
LIST_NULL se a refer�ncia recebida for NULL, ou;
LIST_OK em caso de sucesso;
*/
int listClearT(PtListT list) {
	if (list == NULL) return LIST_NULL;

	list->size = 0;

	return LIST_OK;
}

/*
Mostra informa��o sobre uma inst�ncia
Argumentos:
list - refer�ncia da inst�ncia;
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