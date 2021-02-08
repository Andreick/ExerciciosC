/* Crie uma funcao que receba dois parametros: um array e um valor do
mesmo tipo do array. A funcao devera preencher os elementos de array com
esse valor. Nao utilize indices para percorrer o array, apenas
aritmetica de ponteiros. */

#include <stdio.h>

void preencher(int array[], int len, int value) {
	int *p;

	for (int i = 0; i < len; i++) {
		p = array + i;
		*p = value;
	}
}

int main() {
	int vetor[3];
	int valor = 6;

	int tam = sizeof vetor / sizeof *vetor;
	printf("tam = %d\n", tam);

	preencher(vetor, tam, valor);

	for (int i = 0; i < tam; i++) {
		printf("%d\n", *(vetor + i));
	}
		
	return 0;
}
