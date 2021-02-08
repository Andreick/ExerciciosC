/*Faca uma funcao que receba duas strings e retorne a intercalacao letra
a letra da primeira com a segunda string. A string intercalada deve ser
retornada na primeira string*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intercala(char str1[], char str2[]) {
	int str1Tam, str2Tam, tamTot, tam;
	int i, j;

	str1Tam = strlen(str1);
	str2Tam = strlen(str2);

	if (str1Tam < str2Tam) {
		tamTot = insereEspaco(str1, str1Tam, str2Tam);
	}
	else if (str2Tam < str1Tam) {
		tamTot = insereEspaco(str2, str2Tam, str1Tam);
	}
	else {
		tamTot = str1Tam + str2Tam;
	}

	tam = tamTot / 2;

	for (i = tam - 1; i != 0; i--) {

		str1[i * 2] = str1[i];
	}

	for (i = 1, j = 0; j < tam; i += 2, j++) {

		str1[i] = str2[j];
	}

	str1[tamTot] = '\0';
}

int insereEspaco(char strMenor[], int tamMenor, int tamMaior) {
	int i;

	for (i = tamMenor; i < tamMaior; i++) {
		strMenor[i] = ' ';
	}

	strMenor[i] = '\0';
	return tamMaior * 2;
}

int main() {
	char strA[20] = "Ola ";
	char strB[20] = "mundo!";

	intercala(strA, strB);

	printf("Resultado: %s\n", strA);

	system("pause");
	return 0;
}
