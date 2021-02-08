/* Faca um programa que leia 2 valores inteiros e chame uma funcao que
receba estas 2 variaveis e troque o seu conteudo, ou seja, esta funcao e
chamada passando duas variaveis A e B por exemplo e, apos a execucao da
funcao, A contera o valor de B e B tera o valor de A. */

#include <stdio.h>

void troca(int *numA, int *numB) {
	int numC;

	numC = *numA;
	*numA = *numB;
	*numB = numC;
}

int main() {
	int varA = 3;
	int varB = 5;

	troca(&varA, &varB);
	printf("varA = %d\n", varA);
	printf("varB = %d\n", varB);
		
	return 0;
}