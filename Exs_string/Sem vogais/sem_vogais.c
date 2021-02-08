/*Faca um programa que receba do usuario uma string. O programa imprime
a string sem suas vogais*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 47

void getLine(char *str) {
	fgets(str, STRSIZE, stdin);

	int last = strlen(str) - 1;

	if (str[last] == '\n')
		str[last] = '\0';
}

int main() {
	char linha[STRSIZE];
	char vogais[11] = "aeiouAEIOU";
	int linhaTam, vogaisTam;
	int i, j, k;

	printf("Digite uma string: ");
	getLine(linha);

	linhaTam = strlen(linha);
	vogaisTam = strlen(vogais);

	for (i = 0, j = 0; i < linhaTam; i++, j++) {

		linha[j] = linha[i];

		for (k = 0; k < vogaisTam; k++) {

			if (linha[j] == vogais[k]) {
				j--;
				break;
			}
		}
	}

	linha[j] = '\0';

	printf("%s\n", linha);
	
	system("pause");
	return 0;
}