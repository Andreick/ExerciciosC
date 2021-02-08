/*Leia uma cadeia de caracteres e converta todos os caracteres para
maiuscula. Dica: subtraia 32 dos caracteres cujo codigo ASCII esta
entre 97 e 122*/

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

		if (linha[i] >= 97 && linha[i] <= 122)
			linha[i] -= 32;
	}

	printf("%s\n", linha);
	
	system("pause");
	return 0;
}
