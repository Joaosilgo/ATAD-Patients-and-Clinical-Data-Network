/* PROJETO  ATAD 2018-19
* Identificacao dos Alunos:
*
*      Numero: 150221001 | Nome: João da Silva Gomes
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "Uteis.h"
#include "Date.h"
#include "Commands.h"
#include "Map.h"



#include<stdio.h> 

#include<dos.h> 




typedef char String[255];

/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char str2[]);
void printCommandsMenu();

//...

/*
* Descrição do Programa
*/
int main(int argc, char** argv) {





	system("color 8F");

	/* declaracao de variaveis */
	PtList list = listCreate(2000);
	/*PtMap map = mapCreate(1000);*/
	PtListT listT = listCreateT(1000);
	/* interpretador de comandos */
	String command;
	int quit = 0;
	int load = 0;
	while (!quit) {
		printf("\n\n\n\                                        Go to main Menu  ");
		system("pause > nul");
		system("@cls||clear");
		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */
			dataDumpingLoader();
			listDestroy(&list);
			listDestroyT(&listT);
		}
		else if (equalsStringIgnoreCase(command, "LOAD")) {
			listClear(list);
			loader();
			system("cls");
			LOAD(list);
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			system("cls");
			CLEAR(list);
		}
		else if (equalsStringIgnoreCase(command, "SHOW")) {
			system("cls");
			SHOW(list);
		}
		else if (equalsStringIgnoreCase(command, "SORT")) {
			system("cls");
			SORT(list);
		}
		else if (equalsStringIgnoreCase(command, "AVG")) {
			system("cls");
			AVG(list);
		}
		else if (equalsStringIgnoreCase(command, "NORM")) {
			NORM(list);
		}
		else if (equalsStringIgnoreCase(command, "QUEUE")) {
			//printf("Comando QUEUE nao implementado.\n");
			QUEUE(list);
		}
		else if (equalsStringIgnoreCase(command, "CHECKDISTRICT")) {
			system("cls");
			CHECKDISTRICT(list);
		}
		else if (equalsStringIgnoreCase(command, "LOADT")) {
			//printf("Comando MFOULG nao implementado.\n");
			system("cls");
			listClearT(listT);
			LOADT(listT);
		}
		else if (equalsStringIgnoreCase(command, "SHOWT")) {
			//printf("Comando MFOULG nao implementado.\n");
			system("cls");
			SHOWT(listT);
		}
		else if (equalsStringIgnoreCase(command, "AVGT")) {
			//printf("Comando MFOULG nao implementado.\n");
			system("cls");
			AVGT(listT);
		}
		else if (equalsStringIgnoreCase(command, "NORMT")) {
			//printf("Comando NORMT nao implementado.\n");
			system("cls");
			NORMT(listT);

		}
		else if (equalsStringIgnoreCase(command, "NEURALNET")) {
			//printf("Comando NEURALNET nao implementado.\n");


		}

		else {
			printf("Comando não encontrado.\n");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char str2[]) {
	/* Apenas faz uma comparacao utilizando o strcmp.
	* Necessita de modificacao para obter uma comparacao
	* 'case insensitive' */
	//	return (strcmp(str1, str2) == 0);
	//'case sensitive'
	return (_stricmp(str1, str2) == 0);
}

void printCommandsMenu() {

	printf("\n                ===================================================================================");
	//settextstyle(2, 0, 1);
	printf("\n                                          PROJECT: Patients and Clinical Data                      ");

	printf("\n                ===================================================================================");
	printf("\n                A. Info about players (LOAD, SHOW, CLEAR).");
	printf("\n                B. Aggregated info about patients and clinical data (SORT, AVG, NORM, QUEUE, CHECKDISTRICT).");
	printf("\n                C. Advanced indicator (LOADT, SHOWT, AVGT, NORMT, NEURALNET)");
	printf("\n                D. Exit (QUIT)\n\n");
	printf("                  COMMAND> ");

}

