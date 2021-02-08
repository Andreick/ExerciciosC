/* Faca um programa que receba do usuario um arquivo texto e mostre na
tela quantas vezes cada letra do alfabeto aparece dentro do arquivo. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int quantLetras[26] = {};
	FILE *arq;
	char caractere;

	arq = fopen("arquivos//contar_letras.txt", "r");
	if (arq == NULL) {
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}

	caractere = fgetc(arq);
	while (caractere != EOF) {

		if (isalpha(caractere)) {
			
			caractere = tolower(caractere);

			for (char letra = 'a'; letra <= 'z'; letra++) {

				if (caractere == letra) {
					quantLetras[letra - 'a']++;
					break;
				}
			}
		}

		caractere = fgetc(arq);
	}

	for (int i = 0; i < 26; i++) {
		printf("%c: %d\n", 'A' + i, quantLetras[i]);
	}
	
	fclose(arq);

	return 0;
}
