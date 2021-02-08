/*Faca um programa que, dada uma string, diga se ela e um palındromo ou
nao. Lembrando que um palındromo e uma palavra que tenha a propriedade
de poder ser lida tanto da direita para a esquerda como da esquerda para
a direita*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 50

void getLine(char *str) {
	fgets(str, STRSIZE, stdin);

	int last = strlen(str) - 1;

	if (str[last] == '\n')
		str[last] = '\0';
}

int main() {
	char linha[STRSIZE];
	char caractere;
	int linhaTam, indiceMedio, ultimoIndice;
	int i, j;

	printf("Digite uma string: ");
	getLine(linha);

	linhaTam = strlen(linha);

	for (i = 0, j = 0; i < linhaTam; i++) {

		if (linha[i] >= 65 && linha[i] <= 122) {

			if (linha[i] <= 90)
				linha[i] += 32;

			linha[j] = linha[i];
			j++;
		}
	}

	linha[j] = '\0';

	//printf("%s\n", linha);

	indiceMedio = (strlen(linha) / 2) - 1;
	ultimoIndice = strlen(linha) - 1;

	for (i = 0; i <= indiceMedio; i++) {

		if (linha[i] == linha[ultimoIndice - i]) {

			if (i == indiceMedio){
				printf("E' palindromo.\n");
			}
		}
		else {
			printf("Nao e' palindromo.\n");
			break;
		}
	}
	
	system("pause");
	return 0;
}
