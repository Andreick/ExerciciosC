/* Escreva um programa que leia primeiro os 6 numeros gerados pela
loteria e depois os 6 numeros do seu bilhete. O programa entao compara
quantos numeros o jogador acertou. Em seguida, ele aloca espaco para um
vetor de tamanho igual a quantidade de numeros corretos e guarda os
numeros corretos nesse vetor. Finalmente, o programa exibe os numeros
sorteados e os seus numeros corretos. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *body;
	int size;
} int_array;

void compararNumeros(int *loteria, int *bilhete, int_array *corretos, int tamanho) {
	corretos->size = 0;

	corretos->body = malloc(tamanho * sizeof (int));

	for (int i = 0; i < tamanho; i++) {

		for (int j = 0; j < tamanho; j++) {

			if (loteria[i] == bilhete[j]) {

				corretos->body[corretos->size] = bilhete[j];
				corretos->size++;
				break;
			}
		}
	}

	corretos->body = realloc(corretos->body, corretos->size * sizeof (int));
}

int main() {
	int numLoteria[6] = {21, 92, 29, 24, 36, 33};
	int numBilhete[6] = {36, 34, 9, 54, 3, 29};
	int_array numCorretos;

	compararNumeros(numLoteria, numBilhete, &numCorretos, 6);

	printf("Numeros sorteados: -");
	for (int i = 0; i < 6; i++) {
		printf("%d-", numLoteria[i]);
	}

	printf("\nSeus numeros corretos: -");
	for (int i = 0; i < numCorretos.size; i++) {
		printf("%d-", numCorretos.body[i]);
	}

	printf("\n");

	free(numCorretos.body);
	
	return 0;
}
