#pragma once

#define DOENCA1 1
#define DOENCA2 2
#define DOENCA3 3
#define SEM_DOENCA 4

typedef struct clinicalData_Train {
	float age;			/* Média da idade em anos quando os dados foram obtidos */
	float bmi;			/* Valores médios do Imc- Indice Massa corporal médio (Kg/m2) */
	float glucose;		/* Valores médios da Glicose (mg/dl) */
	float insulin;		/* Valores médios da Insulina (μU/ml) */
	float mcp1;			/* Valores médios da Proteina MCP-1 (pg/ml)*/
	int disease_type;	/* Classificacao do Doente 1 – Doença1 2 – Doença2  3 – Doença3 4 – Sem Doença Usado apenas na opcao NEURALNET*/
	float c1;
	float c2;
	float c3;
	float c4;
	int clinicalDataCount;  /* Numero de vezes que os dados foram obtidos */ /* pode acrescentar algum atributo/campo se achar relevante */
}ClinicalData_Train;

typedef ClinicalData_Train* PtClinicalData_Train;

ClinicalData_Train createClinicalDataArg_Train(float age, float bmi, float glucose, float insulin, float mcp1, int disease_type, float c1,float c2,float c3,float c4, int clinicalDataCount);
void printClinicalData_Train(PtClinicalData_Train _this);
ClinicalData_Train createClinicalData_Train();