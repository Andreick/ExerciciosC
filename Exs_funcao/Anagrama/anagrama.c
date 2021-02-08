/*Escreva uma funcao que compare e retorne verdadeiro, caso uma string
seja anagrama da outra, e falso, caso contrario*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void letras(char str[], int len) {
	int i, j;

	for (i = 0, j = 0; i < len; i++) {

		if (str[i] >= 65 && str[i] <= 122) {

			if (str[i] <= 90)
				str[i] += 32;

			str[j] = str[i];
			j++;
		}
	}

	str[j] = '\0';
}

int ehAnagrama(char strA[], char strB[]) {
	int len;
	int i, j;

	letras(strA, strlen(strA));
	letras(strB, strlen(strB));

	len = strlen(strA);

	if (len != strlen(strB)) {
		return 0;
	}

	for (i = 0; i < len; i++) {

		for (j = 0; j < len; j++) {

			if (strA[i] == strB[j]) {

				strB[j] = '\0';
				break;
			}
		}

		if (j == len) {
			return 0;
		}
	}

	return 1;
}

int main() {
	char anagrama1[] = "mora Roma";
	char anagrama2[] = "ramo amor";
	char anagrama1Cop[50];
	char anagrama2Cop[50];

	strcpy(anagrama1Cop, anagrama1);
	strcpy(anagrama2Cop, anagrama2);

	if (ehAnagrama(anagrama1Cop, anagrama2Cop)) {
		printf("E' anagrama\n");
	}
	else {
		printf("Nao e' anagrama\n");
	}

	system("pause");
	return 0;
}
