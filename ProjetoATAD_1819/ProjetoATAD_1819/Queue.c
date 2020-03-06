#include "Queue.h" /* já inclui também queueElem.h */
#include <stdio.h>
#include <stdlib.h>

/* Definicao da representacao de dados em memória: */
typedef struct queueImpl {
	QueueElem *elements;
	unsigned int capacity;
	unsigned int size;
} QueueImpl;


/*
Cria uma nova instância da Queue.
Recebe:
initialCapacity - capacidade inicial (se aplicável)
Retorno:
referência da instância ou;
NULL no caso de inexistência de memória.
*/
PtQueue queueCreate(unsigned int initialCapacity) {
	PtQueue newQueue = (PtQueue)malloc(sizeof(QueueImpl));
	if (newQueue == NULL)
	{
		return NULL;
	}

	newQueue->elements = (QueueElem*)calloc(initialCapacity,
		sizeof(QueueElem));
	if (newQueue->elements == NULL)
	{
		free(newQueue);
		return NULL;
	}

	newQueue->capacity = initialCapacity;
	newQueue->size = 0;

	return newQueue;
}

/*
Destroi uma instância, libertando a memória associada.
Argumentos:
ptQueue - endereço da referência da instância;
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_OK em caso de sucesso;
*/
int queueDestroy(PtQueue *ptQueue) {
	PtQueue tempQueue = *ptQueue;
	if (tempQueue == NULL) {
		return QUEUE_NULL;
	}

	free(tempQueue->elements);
	free(tempQueue);
	*ptQueue = NULL;

	return QUEUE_OK;
}


/*
Insere um elemento numa dada instância.
Argumentos:
queue - referência da instância;
elem - elemento a inserir;
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_FULL caso a fila esteja cheia, ou;
QUEUE_NO_MEMORY caso nao haja memória para guardar o elemento, ou;
QUEUE_OK em caso de sucesso;
*/
int queueEnqueue(PtQueue queue, QueueElem elem) {
	if (queue == NULL) {
		return QUEUE_NULL;
	}

	if (queue->size == queue->capacity) {
		//a taxa de crescimento é criterio do programador
		//neste caso dobra a capacidade, poderia ser apenas
		//espaço para mais um elemento
		QueueElem *elements = (QueueElem*)realloc(queue->elements,
			queue->capacity * 2 * sizeof(QueueElem));
		if (elements == NULL) {
			//atenção: bloco anterior é mantido pelo realloc
			return QUEUE_NO_MEMORY;
		}
		queue->elements = elements;
		queue->capacity *= 2;
	}

	queue->elements[queue->size++] = elem;
	return QUEUE_OK;
}

/*
Remove um elemento numa dada instância.
Argumentos:
queue - referência da instância;
ptElem - elemento removido (retorno por referência);
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_EMPTY caso a fila esteja vazia, ou;
QUEUE_OK em caso de sucesso;
*/
int queueDequeue(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {
		return QUEUE_NULL;
	}

	if (queueIsEmpty(queue)) {
		return QUEUE_EMPTY;
	}

	*ptElem = queue->elements[0];

	//para queue->size = 0, queue->size - 1 resultara em underflow do tipo uint
	//para nunca acontecera, pq essa situacao caira no if anterior
	for (unsigned int i = 0; i < queue->size - 1; i++) {
		queue->elements[i] = queue->elements[i + 1];
	}

	queue->size--;
	return QUEUE_OK;
}

/*
Espreita o elemento do início numa dada instância.
Argumentos:
queue - referência da instância;
ptElem - elemento no início (retorno por referência);
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_EMPTY caso a fila esteja vazia, ou;
QUEUE_OK em caso de sucesso;
*/
int queuePeek(PtQueue queue, QueueElem *ptElem) {
	if (queue == NULL) {
		return QUEUE_NULL;
	}

	if (queueIsEmpty(queue)) {
		return QUEUE_EMPTY;
	}

	*ptElem = queue->elements[0];
	return QUEUE_OK;
}

/*
Quantos elementos estão armazenados numa instância.
Argumentos:
queue - referência da instância;
ptSize - número de elementos (retorno por referência);
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_OK em caso de sucesso;
*/
int queueSize(PtQueue queue, int *ptSize) {
	if (queue == NULL) return QUEUE_NULL;
	*ptSize = queue->size;
	return QUEUE_OK;
}

/*
Verifica se a instância está vazia (não contém elementos)
Argumentos:
queue - referência da instância;
Retorno:
1 caso esteja vazia ou a referência seja NULL, ou;
0 caso não esteja vazia;
*/
int queueIsEmpty(PtQueue queue) {
	if (queue == NULL) return 1;
	return (queue->size > 0) ? 0 : 1;
}

/*
Limpa uma instância (remove todos os elementos)
Argumentos:
queue - referência da instância;
Retorno:
QUEUE_NULL se a referência recebida for NULL, ou;
QUEUE_OK em caso de sucesso;
*/
int queueClear(PtQueue queue) {
	if (queue == NULL) return QUEUE_NULL;
	queue->size = 0;
	return QUEUE_OK;
}

/*
Mostra informação sobre uma instância
Argumentos:
queue - referência da instância;
*/
void queuePrint(PtQueue queue) {
	if (queue == NULL) {
		printf("(Queue NULL) \n");
	}
	else if (queue->size == 0) {
		printf("(Queue Empty) \n");
	}
	else {
		//imprimir do inicio para o fim da fila:
		printf("Queue contents (begin to end): \n");
		for (unsigned int i = 0; i < queue->size; i++) {
			queueElemPrint(queue->elements[i]);
		}
		printf("------------------------------ \n");
	}
}

