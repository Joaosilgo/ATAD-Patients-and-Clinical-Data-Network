#include "Commands.h"
#include "Patient.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Map.h"
#include <Windows.h>
#include "Queue.h"
#include "Patient_Train.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "MapElem.h"

#include "AvgDistrict.h"




char** split(char *str, int nFields, const char *delim) {

	char **tokens = malloc(sizeof(char*) * nFields);

	int index = 0;
	char *next_token = NULL; //para controlo interno da funcao strtok_s

	char *token = strtok_s(str, delim, &next_token);
	while (token)
	{
		//puts(token);
		tokens[index++] = token;
		token = strtok_s(NULL, delim, &next_token);
	}

	return tokens;
}


void LOAD(PtList list)
{
	FILE *fd;
	int err = fopen_s(&fd, "patients.csv", "r");
	if (err != 0) {
		printf("\n                Nao foi possivel abrir o ficheiro %s ... \n", "patients.csv");
	}
	char nextLinee[1024];
	//contagem de Patients lidos
	int countPatients = 0;
	while (fgets(nextLinee, sizeof(nextLinee), fd))
	{

		if (strlen(nextLinee) < 1) {
			continue;
		}
		char **tokens = split(nextLinee, 5, ";");

		//o array neste momento contém as seguintes "strings":


		//tokens[0] - id
		//tokens[1] - birth_date
		//tokens[2] - gender
		//tokens[3] - hospital
		//tokens[4] - district

		int patientID = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		char patientGender = tokens[2][0]; //primeiro carater de tokens[2]
		Date date = createDate(day, month, year);
		size_t length = strlen(tokens[4]);
		
		//Problemas no paraiso
		for (int i = 0; i < length; i++)
		{
			if (tokens[4][i] == '\n')
			{
				tokens[4][i] = '\0';
			}
		}

		Patient patient = createPatient(patientID, date, patientGender, tokens[3], tokens[4]);
		listAdd(list, countPatients, patient);
		free(tokens);
		countPatients++;
	}
	FILE *clinic;
	int file = fopen_s(&clinic, "clinicalData.csv", "r");
	if (file != 0) {
		printf("\n                Nao foi possivel abrir o ficheiro %s ... \n", "clinicalData.csv");
	}
	char nextLine[1024];
	//contagem de Patient lidos
	int countClinicalData = 0;
	while (fgets(nextLine, sizeof(nextLine), clinic))
	{
		if (strlen(nextLine) < 1) {
			continue;
		}

		char **tokens = split(nextLine, 6, ";");

		int patientIDs = atoi(tokens[0]);

		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		Date date = createDate(day, month, year);

		//tokens[0] - id
		//tokens[1] - date
		//tokens[2] - bmi
		//tokens[3] - glucose
		//tokens[4] - insulin
		//tokens[5] - mcp1

		float bmi = atof(tokens[2]);
		float glucose = atof(tokens[3]);
		float insulin = atof(tokens[4]);
		float mcp1 = atof(tokens[5]);

		int size;
		listSize(list, &size);
		for (int i = 0; i < size; i++)
		{
			ListElem patient, aux;
			listGet(list, i, &patient);
			if (patient.id == patientIDs)
			{
				int age = 0;
				age = calculateAge(patient.birthdate, date);

				patient.clinicalData.clinicalDataCount++;
				patient.clinicalData.age += age;
				patient.clinicalData.bmi = (float)patient.clinicalData.bmi + bmi;
				patient.clinicalData.glucose = (float)patient.clinicalData.glucose + glucose;
				patient.clinicalData.insulin += (float)insulin;
				patient.clinicalData.mcp1 += (float)mcp1;


				listSet(list, i, patient, &patient);


			}
		}
		free(tokens);
		countClinicalData++;
	}

	avg(list);
	printf("\n                Foram lidos %d Patients e informacao sobre %d ClinicalData\n", countPatients, countClinicalData);
}

void avg(PtList list)
{
	int sizes;
	listSize(list, &sizes);
	for (int i = 0; i < sizes; i++)
	{
		ListElem patient, aux;
		listGet(list, i, &patient);

		patient.clinicalData.age = patient.clinicalData.age / patient.clinicalData.clinicalDataCount;
		patient.clinicalData.bmi = patient.clinicalData.bmi / patient.clinicalData.clinicalDataCount;
		patient.clinicalData.glucose = patient.clinicalData.glucose / patient.clinicalData.clinicalDataCount;
		patient.clinicalData.insulin = patient.clinicalData.insulin / patient.clinicalData.clinicalDataCount;
		patient.clinicalData.mcp1 = patient.clinicalData.mcp1 / patient.clinicalData.clinicalDataCount;
		listSet(list, i, patient, &aux);

	}
}



//COMMAND CLEAR
void CLEAR(PtList list) {
	int size;
	listSize(list, &size);
	listClear(list);
	printf("                Foram apagados %d registos", size);
}




//COMMAND SHOW
void SHOW(PtList list) {
	listPrint(list);
}

//COMMAND SORT
void SORT(PtList list) {
	int option;
	printf("                Sort by:\n");
	printf("                \t1-Data de nascimento\n                \t2-Hospital\n                \t3-Distrito\n");
	printf("                Option> ");
	scanf_s("%d", &option);

	if (option == 1)
	{
		sortByDate(list);
	}
	else if (option == 2)
	{
		sortByHospital(list);
	}
	else if (option == 3)
	{
		sortByDistrict(list);
	}
	else {
		printf("Insira uma opcao valida!");
	}
}




//COMMAND AVG
void AVG(PtList list)
{

	PtMap map = mapCreate(1000);
	PtList average = averageClinicalData(list, map);
	mapDestroy(&map);
}





void CHECKDISTRICT(PtList list)
{

	PtMap map = mapCreate(1000);
	sumVals(list, map);
	avgVals(map);


	typedef char String[255];

	String command;
	int quit = 0;
	while (!quit) {

		
		printf("\n\n\n                                        Introduza o Distrito para a consulta  \n");
		printf("                                        0 para sair \n");		
		printf("                                        ->");
		fgets(command, sizeof(command), stdin);
		
		command[strlen(command) - 1] = '\0';

		if (strcmp(command, "0") == 0) {
			quit = 1; /* vai provocar a saída do interpretador */
			printf("Goodbye\n");

		}
		else
		{
			
			District d = createDistrict(command);
			int size;
			mapSize(map, &size);

			MapKey *codes = mapKeys(map);
			if (codes != NULL) {

				for (int i = 0; i < size; i++) {


					//O PROBLEMA ERA O  DO \N (ATENÇÃO EXISTE O PROBLEMA NOS FICHEIROS NO FIAL DO TOKEN EXISTE  \N)
				
					if (_stricmp(codes[i].district, d.district) == 0)
					{
						AvgDistrict PtAvgDistrict;
						mapGet(map, codes[i], &PtAvgDistrict);
						mapKeyPrint(d);
						mapValuePrint(PtAvgDistrict);
					}
				}
			}
			
		}


	}	


}







void NORM(PtList list)
{
	
	PtList newList = copyList(list);
	int x = normalizeK();
	PtList normalizeList = normalizeStatistics(newList, x);
	listPrint(normalizeList);
	listClear(newList);
	listClear(normalizeList);
	listDestroy(&newList);
	listDestroy(&normalizeList);
	
}

















void QUEUE(PtList list)
{
	PtList newList = copyList(list);
	int size;
	listSize(list, &size);
	PtQueue queue = queueCreate(size);
	Queue(list, queue);
	commandQueue(queue);
	listClear(newList);
	listDestroy(&newList);
	queueClear(queue);
	queueDestroy(&queue);
}


























void LOADT(PtListT listT)
{


	FILE *fdt;
	int err = fopen_s(&fdt, "patients_train.csv", "r");
	if (err != 0) {
		printf("\nNao foi possivel abrir o ficheiro %s ... \n", "patients_train.csv");
	}
	char nextLinee[1024];
	//contagem de Patients lidos
	int countPatients = 0;
	while (fgets(nextLinee, sizeof(nextLinee), fdt))
	{
		if (strlen(nextLinee) < 1) {
			continue;
		}
		char **tokens = split(nextLinee, 5, ";");
		//o array neste momento contém as seguintes "strings":
		//tokens[0] - id
		//tokens[1] - birth_date
		//tokens[2] - gender
		//tokens[3] - hospital
		//tokens[4] - district

		int patientID = atoi(tokens[0]);
		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		char patientGender = tokens[2][0]; //primeiro carater de tokens[2]
		Date date = createDate(day, month, year);

		size_t length = strlen(tokens[4]);

		//Problemas no paraiso
		for (int i = 0; i < length; i++)
		{
			if (tokens[4][i] == '\n')
			{
				tokens[4][i] = '\0';
			}
		}


		Patient_Train patient = createPatient_Train(patientID, date, patientGender, tokens[3], tokens[4]);
		listAddT(listT, countPatients, patient);
		free(tokens);
		countPatients++;
	}
	FILE *clinic_Train;
	int file = fopen_s(&clinic_Train, "clinicalData_train.csv", "r");
	if (file != 0) {
		printf("\nNao foi possivel abrir o ficheiro %s ... \n", "clinicalData_train.csv");
	}
	char nextLine[1024];
	//contagem de Patient lidos
	int countClinicalData = 0;
	while (fgets(nextLine, sizeof(nextLine), clinic_Train))
	{
		if (strlen(nextLine) < 1) {
			continue;
		}
		char **tokens = split(nextLine, 11, ";");
		int patientID = atoi(tokens[0]);

		int day, month, year;
		sscanf_s(tokens[1], "%d/%d/%d", &day, &month, &year);
		Date date = createDate(day, month, year);




		float bmi = atof(tokens[2]);
		float glucose = atof(tokens[3]);
		float insulin = atof(tokens[4]);
		float mcp1 = atof(tokens[5]);
		int disease_type = atoi(tokens[6]);
		float c1 = atof(tokens[7]);
		float c2 = atof(tokens[8]);
		float c3 = atof(tokens[9]);
		//float c4 = atof(tokens[10]);
		size_t length = strlen(tokens[10]);

		//		Problemas no paraiso
		for (int i = 0; i < length; i++)
		{
			if (tokens[10][i] == '\n')
			{
				tokens[10][i] = '\0';
			}
		}
		float c4 = atof(tokens[10]);




		int size;
		listSizeT(listT, &size);
		for (int i = 0; i < size; i++)
		{
			ListElem_Train patient, aux;
			listGetT(listT, i, &patient);
			if (patient.id == patientID) {
				//patient.clinicalData_Train.clinicalDataCount++;

				int age = 0;
				age = calculateAge(patient.birthdate, date) + 1900;

				patient.clinicalData_Train.clinicalDataCount++;
				patient.clinicalData_Train.age += age;
				patient.clinicalData_Train.bmi = (float)patient.clinicalData_Train.bmi + bmi;
				patient.clinicalData_Train.glucose = (float)patient.clinicalData_Train.glucose + glucose;
				patient.clinicalData_Train.insulin += (float)insulin;
				patient.clinicalData_Train.mcp1 += (float)mcp1;
				patient.clinicalData_Train.c1 += (float)c1;
				patient.clinicalData_Train.c2 += (float)c2;
				patient.clinicalData_Train.c3 += c3;
				patient.clinicalData_Train.c4 += c4;

				listSetT(listT, i, patient, &aux);
			}
		}
		free(tokens);
		countClinicalData++;
	}

	//avgT(listT);

	//Foram lidos <N> pacientes e informação sobre <M> dados clinicos
	printf("\nForam lidos %d Patients e informacao sobre %d ClinicalData\n", countPatients, countClinicalData);


}


void avgT(PtListT listT)
{
	int sizes;
	listSizeT(listT, &sizes);
	for (int i = 0; i < sizes; i++)
	{
		ListElem_Train patient, aux;
		listGetT(listT, i, &patient);
		//if (patient.id == patientID) {
		patient.clinicalData_Train.age = patient.clinicalData_Train.age / patient.clinicalData_Train.clinicalDataCount;

		patient.clinicalData_Train.bmi = patient.clinicalData_Train.bmi / patient.clinicalData_Train.clinicalDataCount;
		patient.clinicalData_Train.glucose = patient.clinicalData_Train.glucose / patient.clinicalData_Train.clinicalDataCount;
		patient.clinicalData_Train.insulin = patient.clinicalData_Train.insulin / patient.clinicalData_Train.clinicalDataCount;
		patient.clinicalData_Train.mcp1 = patient.clinicalData_Train.mcp1 / patient.clinicalData_Train.clinicalDataCount;
		listSetT(listT, i, patient, &aux);
		//}
	}
}


void SHOWT(PtListT listT)
{
	listPrintT(listT);
}




void NORMT(PtListT listT)
{
	PtListT newList = copyListT(listT);


	PtListT normalizeList = normalizePatientTrain(newList);


	listPrintT(normalizeList);
	listClearT(newList);
	listClearT(normalizeList);
	listDestroyT(&newList);
	listDestroyT(&normalizeList);
}



void AVGT(PtListT listT)
{
	PtMap map = mapCreate(1000);
	PtListT average = averageClinicalDataT(listT, map);
	mapDestroy(&map);
}



void NEURALNET()
{

}