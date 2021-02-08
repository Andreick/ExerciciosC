/* Escreva um programa que aloque dinamicamente uma matriz (de inteiros)
de dimensoes definidas pelo usuario e a leia. Em seguida, implemente uma
funcao que receba um valor, retorne 1 caso o valor esteja na matriz ou
retorne 0 caso nao esteja na matriz. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int **body;
	int rows;
	int columns;
} int_matrix;

int_matrix criarMatriz() {
	int_matrix matrix;

	printf("Digite a quantidade de linhas da matriz: ");
	scanf("%d", &matrix.rows);

	matrix.body = malloc(matrix.rows * sizeof(int *));

	printf("Digite a quantidade de colunas da matriz: ");
	scanf("%d", &matrix.columns);

	for (int i = 0; i < matrix.rows; i++) {
		matrix.body[i] = malloc(matrix.columns * sizeof(int));
	}

	return matrix;
}

void preencherMatriz(int_matrix *matrix) {
	for (int i = 0; i < matrix -> rows; i++) {
		for (int j = 0; j < matrix -> columns; j++) {
			printf("Digite os valores da matriz: ");
			scanf("%d", &matrix -> body[i][j]);
		}
	}
}

bool estaNaMatriz(int_matrix matrix, int valor) {
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			if (matrix.body[i][j] == valor) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int_matrix matriz;
	int valor;

	matriz = criarMatriz();

	preencherMatriz(&matriz);

	printf("Digite um valor: ");
	scanf("%d", &valor);

	if (estaNaMatriz(matriz, valor)) {
		printf("Esta na matriz\n");
	}
	else {
		printf("Nao esta na matriz\n");
	}

	while (matriz.rows) {
		free(matriz.body[--matriz.rows]);
	}
	free(matriz.body);
	
	return 0;
}
