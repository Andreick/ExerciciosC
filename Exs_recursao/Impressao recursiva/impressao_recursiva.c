/*Faca uma funcao recursiva que receba um numero inteiro positivo N e
imprima todos os numeros naturais de 0 ate N em ordem crescente.*/

#include <stdio.h>
#include <stdlib.h>

void imprimeNums(int n) {
	if (n > 0) {
		imprimeNums(n - 1);
	}
	printf("%d\n", n);
}

int main() {
	imprimeNums(5);

	system("pause");
	return 0;
}
