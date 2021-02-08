/*Faca uma funcao recursiva que calcule e retorne o fatorial de um
numero inteiro N.*/

#include <stdio.h>
#include <stdlib.h>

/*
Expressao generalizada 	N! = N * (N - 1)!
Caso base 				0! = 1
*/

int fatorial(int n) {
	if (n == 0) { //criterio de parada
		return 1;
	}
	else { //parametro da chamada recursiva
		return n * fatorial(n - 1);
	}
}

int main() {
	printf("%d\n", fatorial(-1));

	system("pause");
	return 0;
}
