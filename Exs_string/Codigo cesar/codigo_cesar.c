/*Implemente um programa que faca uso desse Codigo de Cesar (3 posicoes),
entre com uma string e retorne a string codificada*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 70

void getLine(char *str) {
	fgets(str, STRSIZE, stdin);

	int last = strlen(str) - 1;

	if (str[last] == '\n')
		str[last] = '\0';
}

int main() {
	char linha[STRSIZE];
	int linhaTam;
	int pos;
	int i;

	printf("Digite uma string: ");
	getLine(linha);

	printf("Digite uma posicao: ");
	scanf("%d", &pos);

	linhaTam = strlen(linha);

	for (i = 0; i < linhaTam; i++) {

		if (linha[i] >= 97 && linha[i] <= 122)
			linha[i] -= 32;

		if (linha[i] >= 65 && linha[i] <= 90) {
			linha[i] += pos;

			if (linha[i] > 90)
				linha[i] -= 26;
		}

		printf("%c", linha[i]);
	}

	printf("\n");
	
	system("pause");
	return 0;
}
