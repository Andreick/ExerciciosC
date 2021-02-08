/*Escreva um programa para converter uma cadeia de caracteres de letras
maiusculas em letras minusculas. Dica: some 32 dos caracteres cujo
codigo ASCII esta entre 65 e 90*/

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
	int i;

	printf("Digite uma string: ");
	getLine(linha);

	linhaTam = strlen(linha);

	for (i = 0; i < linhaTam; i++) {

		if (linha[i] >= 65 && linha[i] <= 90)
			linha[i] += 32;
	}

	printf("%s\n", linha);
	
	system("pause");
	return 0;
}
