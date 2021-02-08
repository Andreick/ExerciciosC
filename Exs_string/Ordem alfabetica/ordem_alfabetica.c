/*Escreva um programa que leia duas palavras e diga qual deles vem
primeiro na ordem alfabetica. Dica: ‘a’ e menor do que ‘b’.*/

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
	char linha1[STRSIZE], linha2[STRSIZE];
	char charL1, charL2;
	int i;

	printf("Digite uma string: ");
	getLine(linha1);

	printf("Digite outra string: ");
	getLine(linha2);

	for (i = 0; i < STRSIZE; i++) {

		charL1 = linha1[i];
		charL2 = linha2[i];
		
		if (charL1 == '\0' && charL2 == '\0') {
			printf("%s\n", linha1);
			printf("%s\n", linha2);
			break;
		}

		if (charL1 >= 65 && charL1 <= 90)
			charL1 += 32;
		if (charL2 >= 65 && charL1 <= 90)
			charL2 += 32;

		if (charL1 < charL2) {
			printf("%s\n", linha1);
			printf("%s\n", linha2);
			break;
			
		} else if (charL1 > charL2) {
			printf("%s\n", linha2);
			printf("%s\n", linha1);
			break;
		}
	}
	
	system("pause");
	return 0;
}
