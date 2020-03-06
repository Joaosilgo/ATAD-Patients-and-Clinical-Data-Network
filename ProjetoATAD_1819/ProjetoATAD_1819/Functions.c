#include "Functions.h"

#include "Map.h"
#include "AvgDistrict.h"
#include <Windows.h>






int getAge(int d1, int m1, int y1, int d2, int m2, int y2)
{
	if (d2 > d1)
	{
		m1 = m1 - 1;
		d1 = d1 + 30;
	}
	if (m2 > m1)
	{
		y1 = y1 - 1;
		m1 = m1 + 12;
	}
	if (y2 > y1)
	{
		exit(0);
	}
	int d3 = d1 - d2;
	int m3 = m1 - m2;
	int y3 = y1 - y2;
	return  y3;


}

int compareDates(Date d1, Date d2) {
	if (d1.year < d2.year) {
		return 1;
	}

	if (d1.year == d2.year && d1.month < d2.month) {
		return 1;
	}

	if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) {
		return 1;
	}

	return 0;
}


void bubbleSortDate(PtList list) {
	int size;
	listSize(list, &size);

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);

			if (compareDates(elem1.birthdate, elem2.birthdate) == 0) {
				listSet(list, j, elem2, &aux);
				listSet(list, j + 1, elem1, &aux);
			}
		}
	}
}

void sortByDate(PtList originalList) {
	int inicialCapacity;
	listSize(originalList, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem elem;
		listGet(originalList, i, &elem);
		listAdd(newList, i, elem);
	}
	bubbleSortDate(newList);
	listPrint(newList);
}








int compareHospital(char hospital1[], char hospital2[])
{
	if (strcmp(hospital1, hospital2) > 0)
	{
		return 1;
	}
	if (strcmp(hospital1, hospital2) < 0)
	{
		return -1;
	}
	if (strcmp(hospital1, hospital2) == 0)
	{
		return 0;
	}
}

void bubbleSortHospital(PtList list)
{
	int size;
	listSize(list, &size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);
			if (strcmp(elem1.hospital, elem2.hospital) > 0) {//poderiamos usar aqui o int compareHospital() que irá fazer a mesma coisa

				listSet(list, j, elem2, &aux);
				listSet(list, j + 1, elem1, &aux);
			}
			if (strcmp(elem1.hospital, elem2.hospital) == 0)//desempate se o hospital for igual
			{
				if (compareDates(elem1.birthdate, elem2.birthdate) == 0) { // compara-se as datas
					listSet(list, j, elem2, &aux);
					listSet(list, j + 1, elem1, &aux);
				}
			}
		}
	}
}




void sortByHospital(PtList originalList)
{
	int inicialCapacity;
	listSize(originalList, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);//nunca usar a lista original

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem elem;
		listGet(originalList, i, &elem);
		listAdd(newList, i, elem);
	}
	bubbleSortHospital(newList);
	listPrint(newList);
}












int compareDistrict(char district1[], char district2[])
{
	if (strcmp(district1, district2) > 0)
	{
		return 1;
	}
	if (strcmp(district1, district2) < 0)
	{
		return -1;
	}
	if (strcmp(district1, district2) == 0)
	{
		return 0;
	}
}


void bubbleSortDistrict(PtList list)
{
	int size;
	listSize(list, &size);
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			ListElem elem1;
			ListElem elem2;
			ListElem aux;
			listGet(list, j, &elem1);
			listGet(list, j + 1, &elem2);
			if (strcmp(elem1.district, elem2.district) > 0) {//poderiamos usar aqui o int compareDistrict() que irá fazer a mesma coisa

				listSet(list, j, elem2, &aux);
				listSet(list, j + 1, elem1, &aux);
			}
			if (strcmp(elem1.district, elem2.district) == 0)//desempate se o district for igual
			{
				if (strcmp(elem1.hospital, elem2.hospital) > 0) {//poderiamos usar aqui o int compareHospital() que irá fazer a mesma coisa

					listSet(list, j, elem2, &aux);
					listSet(list, j + 1, elem1, &aux);
				}
			}
		}
	}
}











void sortByDistrict(PtList originalList)
{
	int inicialCapacity;
	listSize(originalList, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);//nunca usar a lista original

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem elem;
		listGet(originalList, i, &elem);
		listAdd(newList, i, elem);
	}
	bubbleSortDistrict(newList);
	listPrint(newList);
}





PtList copyList(PtList list)
{
	int inicialCapacity;
	listSize(list, &inicialCapacity);

	PtList newList = listCreate(inicialCapacity);
	int posicao = 0;

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem oldElem;
		ListElem elem;
		listGet(list, i, &elem);

		if (elem.clinicalData.clinicalDataCount > 0) {
			listAdd(newList, posicao, elem);
			listSet(newList, posicao, elem, &oldElem);
			posicao++;

		}
	}
	//listPrint(newList);
	return newList;

}

PtMap sumVals(PtList list, PtMap map)
{
	int capacity;
	listSize(list, &capacity);
	//PtMap map = mapCreate(1000);

	for (int i = 0; i < capacity; i++)
	{
		ListElem patient;
		listGet(list, i, &patient);
		int count = 0;
		District d = createDistrict(patient.district);
		if (mapContains(map, d))
		{
			AvgDistrict PtAvgDistrict;

			mapGet(map, d, &PtAvgDistrict);
			PtAvgDistrict.avgAgeDistrict += patient.clinicalData.age;
			PtAvgDistrict.avgBMIDistrict += patient.clinicalData.bmi;
			PtAvgDistrict.avgGlucoseDistrict += patient.clinicalData.glucose;
			PtAvgDistrict.avgInsulinDistrict += patient.clinicalData.insulin;
			PtAvgDistrict.avgMcp1District += patient.clinicalData.mcp1;
			PtAvgDistrict.count = (PtAvgDistrict.count + 1);

			mapPut(map, d, PtAvgDistrict);
		}
		else
		{
			//count = count + 1;
			AvgDistrict  avg = createAvgDistrict(1, patient.clinicalData.age, patient.clinicalData.bmi, patient.clinicalData.glucose, patient.clinicalData.insulin, patient.clinicalData.mcp1);
			avg.count++;
			mapPut(map, d, avg);
		}

	}
	return map;

}


PtMap avgVals(PtMap map)
{
	int size;
	mapSize(map, &size);

	MapKey *codes = mapKeys(map);
	if (codes != NULL) {

		for (int i = 0; i < size; i++) {

			AvgDistrict PtAvgDistrict;
			mapGet(map, codes[i], &PtAvgDistrict);
			PtAvgDistrict.avgAgeDistrict = PtAvgDistrict.avgAgeDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgBMIDistrict = PtAvgDistrict.avgBMIDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgGlucoseDistrict = PtAvgDistrict.avgGlucoseDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgInsulinDistrict = PtAvgDistrict.avgInsulinDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgMcp1District = PtAvgDistrict.avgMcp1District / PtAvgDistrict.count;

			mapPut(map, codes[i], PtAvgDistrict);
		}
		//printf("------------------- \n");
	}
	return map;
}



//AVG

PtList averageClinicalData(PtList patients, PtMap map)
{
	PtList newList = copyList(patients);
	PtMap maps = sumVals(newList, map);
	avgVals(map);
	mapBubbleSortDistrict(map);
	mapPrint(map);
	return  newList;
}




















void menuNorm()
{
	system("@cls||clear");
	
	printf("\n\n                                        NORM \n");
	printf("\n\n\n                                        Normalização dos dados significa ajustar os valores \n");
	printf("                                        em diferentes escalas para uma escala geralmente comum  \n");
	printf("\n                                        Neste caso as estatísticas dos pacientes estão normalizadas no \n");
	printf("                                        normalizadas intervalo[-k, k]. sendo K o Valor Escolhido \n");
	printf("\n                                        0 para sair \n");
	system("color 8F");

}


int normalizeK()
{

	int command;
	int quit = 0;
	while (!quit) {
		menuNorm();

		printf("\n\n\n                                        Por favor Digite o K  \n");
		printf("                                        ->");
		scanf_s("%d", &command);
		if (command == 0) {
			quit = 1; /* vai provocar a saída do interpretador */
			printf("                                        Goodbye\n");
		}
		else
		{
			printf("is integer %d \n", command);
			return command;
		}

	}
}




PtList normalizeStatistics(PtList list, int k) {
	if (list == NULL) return NULL;
	ListElem patient;
	listGet(list, 0, &patient);
	//minimo
	float minAge = patient.clinicalData.age;
	float minBmi = patient.clinicalData.bmi;
	float minGlucose = patient.clinicalData.glucose;
	float minInsulin = patient.clinicalData.insulin;
	float minMcp1 = patient.clinicalData.mcp1;
	//maximo
	float maxAge = 0.0;
	float maxBmi = 0.0;
	float maxGlucose = 0.0;
	float maxInsulin = 0.0;
	float maxMcp1 = 0.0;
	int size;
	listSize(list, &size);
	//determinar valores maximos e minimos 
	for (int i = 0; i < size; i++)
	{
		ListElem p;
		listGet(list, i, &p);

		if (p.clinicalData.clinicalDataCount != 0)
		{
			//min
			if (p.clinicalData.age < minAge) {
				minAge = p.clinicalData.age;
			}
			if (p.clinicalData.bmi < minBmi) {
				minBmi = p.clinicalData.bmi;
			}
			if (p.clinicalData.glucose < minGlucose) {
				minGlucose = p.clinicalData.glucose;
			}
			if (p.clinicalData.insulin < minInsulin) {
				minInsulin = p.clinicalData.insulin;
			}
			if (p.clinicalData.mcp1 < minMcp1) {
				minMcp1 = p.clinicalData.mcp1;
			}
			//max
			if (p.clinicalData.age > maxAge) {
				maxAge = p.clinicalData.age;
			}
			if (p.clinicalData.bmi > maxBmi) {
				maxBmi = p.clinicalData.bmi;
			}
			if (p.clinicalData.glucose > maxGlucose) {
				maxGlucose = p.clinicalData.glucose;
			}
			if (p.clinicalData.insulin > maxInsulin) {
				maxInsulin = p.clinicalData.insulin;
			}
			if (p.clinicalData.mcp1 > maxMcp1) {
				maxMcp1 = p.clinicalData.mcp1;
			}

		}
	}
	PtList normList = listCreate(size);
	int posicao = 0;
	//adicionar - calcular as normas
	for (int a = 0; a < size; a++)
	{
		ListElem newPatient;
		listGet(list, a, &newPatient);

		if (newPatient.clinicalData.clinicalDataCount != 0) {
			float cima = newPatient.clinicalData.age - minAge;
			float baixo = maxAge - minAge;
			newPatient.clinicalData.age = (cima / baixo)*(2 * k) - k;
			//bmi
			cima = newPatient.clinicalData.bmi - minBmi;
			baixo = maxBmi - minBmi;
			newPatient.clinicalData.bmi = (cima / baixo)*(2 * k) - k;
			//glucose
			cima = newPatient.clinicalData.glucose - minGlucose;
			baixo = maxGlucose - minGlucose;
			newPatient.clinicalData.glucose = (cima / baixo)*(2 * k) - k;
			//insulin
			cima = newPatient.clinicalData.insulin - minInsulin;
			baixo = maxInsulin - minInsulin;
			newPatient.clinicalData.insulin = (cima / baixo)*(2 * k) - k;
			//mcp1
			cima = newPatient.clinicalData.mcp1 - minMcp1;
			baixo = maxMcp1 - minMcp1;
			newPatient.clinicalData.mcp1 = (cima / baixo)*(2 * k) - k;

			listAdd(normList, posicao, newPatient);
			posicao++;
		}
	}
	return normList;
}















void Queue(PtList list, PtQueue queue)
{


	//tamanho da lista para 
	int size;
	listSize(list, &size);
	//printf("%d \n", size);
	float avgAge = 0.0;
	float avgBmi = 0.0;
	float avgGlucose = 0.0;
	float avgInsulin = 0.0;
	float avgMcp1 = 0.0;

	for (int i = 0; i < size; i++)
	{
		ListElem patient;
		listGet(list, i, &patient);

		avgAge = avgAge + patient.clinicalData.age;
		avgBmi = avgBmi + patient.clinicalData.bmi;
		avgGlucose = avgGlucose + patient.clinicalData.glucose;
		avgInsulin = avgInsulin + patient.clinicalData.insulin;
		avgMcp1 = avgMcp1 + patient.clinicalData.mcp1;
	}
	//piece = (float)((b - a) / d);

	avgAge = (float)(avgAge / (float)size);
	avgBmi = (float)(avgBmi / (float)size);
	avgGlucose = (float)(avgGlucose / (float)size);
	avgInsulin = (float)(avgInsulin / (float)size);
	avgMcp1 = (float)(avgMcp1 / (float)size);


	for (int i = 0; i < size; i++)
	{
		ListElem p;
		listGet(list, i, &p);
		if (p.clinicalData.age < avgAge || (p.clinicalData.age > avgAge  && p.clinicalData.bmi < avgBmi && p.clinicalData.glucose < avgGlucose && p.clinicalData.insulin < avgInsulin && p.clinicalData.mcp1 < avgMcp1))

			queueEnqueue(queue, p);
	}


}




void commandQueue(PtQueue queue)
{
	int command;
	int quit = 0;


	while (!quit)
	{


		QueueElem elem;
		system("@cls||clear");
		int code = queueDequeue(queue, &elem);
		if (code == 3)
		{
			printf("                QUEUE IS EMPTY \n\n\n");
			quit = 1;
		}
		queueElemPrint(elem);

		printf("                1-Next\n");
		printf("                0-Sair\n");

		printf("                Option> ");

		scanf_s("%d", &command);

		if (command == 0)
		{
			system("@cls||clear");
			quit = 1;
		}
	}





}










PtListT normalizePatientTrain(PtListT list)
{
	int k = 5;
	if (list == NULL) return NULL;
	ListElem_Train patient;
	listGetT(list, 0, &patient);
	//minimo
	float minAge = patient.clinicalData_Train.age;
	float minBmi = patient.clinicalData_Train.bmi;
	float minGlucose = patient.clinicalData_Train.glucose;
	float minInsulin = patient.clinicalData_Train.insulin;
	float minMcp1 = patient.clinicalData_Train.mcp1;
	float minc1 = patient.clinicalData_Train.c1;
	float minc2 = patient.clinicalData_Train.c2;
	float minc3 = patient.clinicalData_Train.c3;
	float minc4 = patient.clinicalData_Train.c4;
	//maximo
	float maxAge = 0.0;
	float maxBmi = 0.0;
	float maxGlucose = 0.0;
	float maxInsulin = 0.0;
	float maxMcp1 = 0.0;
	float maxc1 = 0.0;
	float maxc2 = 0.0;
	float maxc3 = 0.0;
	float maxc4 = 0.0;

	int size;
	listSizeT(list, &size);
	//determinar valores maximos e minimos 
	for (int i = 0; i < size; i++)
	{
		ListElem_Train p;
		listGetT(list, i, &p);

		if (p.clinicalData_Train.clinicalDataCount != 0)
		{
			//min
			if (p.clinicalData_Train.age < minAge) {
				minAge = p.clinicalData_Train.age;
			}
			if (p.clinicalData_Train.bmi < minBmi) {
				minBmi = p.clinicalData_Train.bmi;
			}
			if (p.clinicalData_Train.glucose < minGlucose) {
				minGlucose = p.clinicalData_Train.glucose;
			}
			if (p.clinicalData_Train.insulin < minInsulin) {
				minInsulin = p.clinicalData_Train.insulin;
			}
			if (p.clinicalData_Train.mcp1 < minMcp1) {
				minMcp1 = p.clinicalData_Train.mcp1;
			}
			/*if (p.clinicalData_Train.c1 < minc1) {
				minc1 = p.clinicalData_Train.c1;
			}
			if (p.clinicalData_Train.c2 < minc2) {
				minc2 = p.clinicalData_Train.c2;
			}
			if (p.clinicalData_Train.c3 < minc3) {
				minc3 = p.clinicalData_Train.c3;
			}
			if (p.clinicalData_Train.c4 < minc4) {
				minc4 = p.clinicalData_Train.c4;
			}*/

			//max
			if (p.clinicalData_Train.age > maxAge) {
				maxAge = p.clinicalData_Train.age;
			}
			if (p.clinicalData_Train.bmi > maxBmi) {
				maxBmi = p.clinicalData_Train.bmi;
			}
			if (p.clinicalData_Train.glucose > maxGlucose) {
				maxGlucose = p.clinicalData_Train.glucose;
			}
			if (p.clinicalData_Train.insulin > maxInsulin) {
				maxInsulin = p.clinicalData_Train.insulin;
			}
			if (p.clinicalData_Train.mcp1 > maxMcp1) {
				maxMcp1 = p.clinicalData_Train.mcp1;
			}
			/*	if (p.clinicalData_Train.c1 > maxc1) {
					maxc1 = p.clinicalData_Train.c1;
				}
				if (p.clinicalData_Train.c2 > maxc2) {
					maxc2 = p.clinicalData_Train.c2;
				}
				if (p.clinicalData_Train.c3 > maxc3) {
					maxc3 = p.clinicalData_Train.c3;
				}
				if (p.clinicalData_Train.c4 > maxc4) {
					maxc4 = p.clinicalData_Train.c4;
				}*/

		}
	}
	PtListT normList = listCreateT(size);
	int posicao = 0;
	//adicionar - calcular as normas
	for (int a = 0; a < size; a++)
	{
		ListElem_Train newPatient;
		listGetT(list, a, &newPatient);

		if (newPatient.clinicalData_Train.clinicalDataCount != 0) {
			float cima = newPatient.clinicalData_Train.age - minAge;
			float baixo = maxAge - minAge;
			newPatient.clinicalData_Train.age = (cima / baixo)*(2 * k) - k;
			//BMI
			cima = newPatient.clinicalData_Train.bmi - minBmi;
			baixo = maxBmi - minBmi;
			newPatient.clinicalData_Train.bmi = (cima / baixo)*(2 * k) - k;
			//GLUCOSE
			cima = newPatient.clinicalData_Train.glucose - minGlucose;
			baixo = maxGlucose - minGlucose;
			newPatient.clinicalData_Train.glucose = (cima / baixo)*(2 * k) - k;
			//INSULIN
			cima = newPatient.clinicalData_Train.insulin - minInsulin;
			baixo = maxInsulin - minInsulin;
			newPatient.clinicalData_Train.insulin = (cima / baixo)*(2 * k) - k;
			//MCP1
			cima = newPatient.clinicalData_Train.mcp1 - minMcp1;
			baixo = maxMcp1 - minMcp1;
			newPatient.clinicalData_Train.mcp1 = (cima / baixo)*(2 * k) - k;

			//Não é neçessario mexer nestes valores
		/*	cima = newPatient.clinicalData_Train.c1 - minc1;
			baixo = maxc1 - minc1;
			newPatient.clinicalData_Train.c1 = (cima / baixo)*(2 * k) - k;

			cima = newPatient.clinicalData_Train.c2 - minc2;
			baixo = maxc2 - minc2;
			newPatient.clinicalData_Train.c2 = (cima / baixo)*(2 * k) - k;

			cima = newPatient.clinicalData_Train.c3 - minc3;
			baixo = maxc3 - minc3;
			newPatient.clinicalData_Train.c3 = (cima / baixo)*(2 * k) - k;

			cima = newPatient.clinicalData_Train.c4 - minc4;
			baixo = maxc4 - minc4;
			newPatient.clinicalData_Train.c4 = (cima / baixo)*(2 * k) - k;
*/
			listAddT(normList, posicao, newPatient);
			posicao++;
		}
	}
	return normList;

}





PtListT copyListT(PtListT list)
{
	int inicialCapacity;
	listSizeT(list, &inicialCapacity);

	PtListT newList = listCreateT(inicialCapacity);
	int posicao = 0;

	for (int i = 0; i < inicialCapacity; i++) {
		ListElem_Train oldElem;
		ListElem_Train elem;
		listGetT(list, i, &elem);

		if (elem.clinicalData_Train.clinicalDataCount > 0) {
			listAddT(newList, posicao, elem);
			listSetT(newList, posicao, elem, &oldElem);
			posicao++;

		}
	}
	//listPrint(newList);
	return newList;

}






PtListT averageClinicalDataT(PtListT listT, PtMap map)
{
	PtListT newList = copyListT(listT);
	PtMap maps = sumValsT(newList, map);
	avgValsT(map);
	mapBubbleSortDistrict(map);
	mapPrint(map);
	return  newList;
}


PtMap sumValsT(PtListT newList, PtMap map)
{
	int capacity;
	listSizeT(newList, &capacity);
	//PtMap map = mapCreate(1000);

	for (int i = 0; i < capacity; i++)
	{
		ListElem_Train patient;
		listGetT(newList, i, &patient);
		int count = 0;
		District d = createDistrict(patient.district);
		if (mapContains(map, d))
		{
			AvgDistrict PtAvgDistrict;

			mapGet(map, d, &PtAvgDistrict);
			PtAvgDistrict.avgAgeDistrict += patient.clinicalData_Train.age;
			PtAvgDistrict.avgBMIDistrict += patient.clinicalData_Train.bmi;
			PtAvgDistrict.avgGlucoseDistrict += patient.clinicalData_Train.glucose;
			PtAvgDistrict.avgInsulinDistrict += patient.clinicalData_Train.insulin;
			PtAvgDistrict.avgMcp1District += patient.clinicalData_Train.mcp1;
			PtAvgDistrict.count = (PtAvgDistrict.count + 1);

			mapPut(map, d, PtAvgDistrict);
		}
		else
		{
			//count = count + 1;
			AvgDistrict  avg = createAvgDistrict(1, patient.clinicalData_Train.age, patient.clinicalData_Train.bmi, patient.clinicalData_Train.glucose, patient.clinicalData_Train.insulin, patient.clinicalData_Train.mcp1);
			avg.count++;
			mapPut(map, d, avg);
		}

	}
	return map;

}

PtMap avgValsT(PtMap map)
{
	int size;
	mapSize(map, &size);

	MapKey *codes = mapKeys(map);
	if (codes != NULL) {

		for (int i = 0; i < size; i++) {

			AvgDistrict PtAvgDistrict;
			mapGet(map, codes[i], &PtAvgDistrict);
			PtAvgDistrict.avgAgeDistrict = PtAvgDistrict.avgAgeDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgBMIDistrict = PtAvgDistrict.avgBMIDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgGlucoseDistrict = PtAvgDistrict.avgGlucoseDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgInsulinDistrict = PtAvgDistrict.avgInsulinDistrict / PtAvgDistrict.count;
			PtAvgDistrict.avgMcp1District = PtAvgDistrict.avgMcp1District / PtAvgDistrict.count;

			mapPut(map, codes[i], PtAvgDistrict);
		}

	}
	return map;
}



















