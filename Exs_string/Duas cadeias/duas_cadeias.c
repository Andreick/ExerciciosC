/*Leia duas cadeias de caracteres A e B. Determine quantas vezes a
cadeia A ocorre na cadeia B.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 100

void getLine(char *str) {
	fgets(str, STRSIZE, stdin);

	int last = strlen(str) - 1;

	if (str[last] == '\n')
		str[last] = '\0';
}

int main() {
	char linhaA[STRSIZE], linhaB[STRSIZE];
	int linhaBTam, ultimoIndiceLA;
	int i, j;
	int qnt = 0;

	printf("Digite uma string: ");
	getLine(linhaA);

	printf("Digite outra string: ");
	getLine(linhaB);

	linhaBTam = strlen(linhaB);
	ultimoIndiceLA = strlen(linhaA) - 1;

	for (i = 0; i < linhaBTam; i++) {

		for (j = 0; j <= ultimoIndiceLA; j++) {

			if (linhaB[i + j] == linhaA[j]) {

				if (j == ultimoIndiceLA) {
					i += ultimoIndiceLA;
					qnt++;
				}
			}
			else {
				break;
			}
		}
	}

	printf("%d\n", qnt);
	
	system("pause");
	return 0;
}
