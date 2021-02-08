/* Faca um programa que leia do usuario o tamanho de um vetor a ser lido
e faca a alocacao dinamica de memoria. Em seguida, leia do usuario seus
valores e imprima o vetor lido. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *body;
	int lenght;
} int_array;

int_array criarVetor() {
	int_array array;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &array.lenght);

	array.body = malloc(array.lenght * sizeof (int));

	return array;
}

void preencherVetor(int_array *array) {
	for (int i = 0; i < array->lenght; i++) {
		printf("Digite os valores do vetor: ");
		scanf("%d", &array->body[i]);
	}
}

void imprimirVetor(int_array array) {
	for (int i = 0; i < array.lenght; i++) {
		printf("valor %d: %d\n", i, array.body[i]);
	}
}

int main() {
	int_array vetor;
	
	vetor = criarVetor();
	preencherVetor(&vetor);
	imprimirVetor(vetor);
	
	free(vetor.body);
	
	return 0;
}
