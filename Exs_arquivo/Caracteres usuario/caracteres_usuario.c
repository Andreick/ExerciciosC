/* Escreva um programa que:
(a) Crie/abra um arquivo texto de nome “arq.txt”
(b) Permita que o usuario grave diversos caracteres nesse arquivo, ate
que o usuario entre com o caractere ‘0’
(c) Feche o arquivo
Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela
todos os caracteres armazenados. */

#include <stdio.h>

int main() {
	FILE *arquivo;
	char c;

	arquivo = fopen("arq.txt", "w");

	printf("Digite um caractere: ");
	c = getchar();
	while (c != '0') {

		if (c != '\n') {
			//scanf("%*[^\n]"); getchar();
			while(getchar() != '\n');
		}

		fputc(c, arquivo);

		printf("Digite um caractere: ");
		c = getchar();
	}

	fclose(arquivo);

	arquivo = fopen("arquivos//arq.txt", "r");

	printf("\n");

	c = fgetc(arquivo);
	while (c != EOF) {

		printf("%c", c);

		c = fgetc(arquivo);
	}

	printf("\n");

	fclose(arquivo);

	return 0;
}
