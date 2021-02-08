/*Leia um vetor contendo letras de uma frase inclusive os espacos em
branco. Retirar os espacos em branco do vetor e depois escrever o vetor
resultante.*/

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
	int linhaTam;
	int i, j;

	printf("Digite uma string: ");
	getLine(linha);

	linhaTam = strlen(linha);

	for (i = 0, j = 0; i < linhaTam; i++) {
		if (linha[i] != 32) {
			linha[j] = linha[i];
			j++;
		}
	}

	linha[j] = '\0';

	printf("%s\n", linha);
	
	system("pause");
	return 0;
}
