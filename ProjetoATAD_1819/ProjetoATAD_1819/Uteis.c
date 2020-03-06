#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <consoleapi.h>

void dataDumpingLoader() {
	int i;
	char str[] = "                                      DATA DUMPING                                                  ";
	for (i = 0; i <= 100; i++) {
		printf(" \r         [%s]", str);
		str[i] = '/';
		Sleep(100);
	}
}





void Quit()
{
	
	printf("\n        ===================================================================================\n");
	
	printf("                                    PROJECT: Patients and Clinical Data                        ");

	printf("\n        ===================================================================================");
	printf("\n        * Autores: 150221001 - João da Silva Gomes");
	printf("\n        * Docente	Bruno Silva \n\n");
	

	dataDumpingLoader();


}



void loader() {
	int i;
	char str[] = "               LOADING                  ";
	for (i = 0; i <= 40; i++) {
		printf("                \r                [%s]", str);
		str[i] = '|';
		Sleep(100);
	}

	

}