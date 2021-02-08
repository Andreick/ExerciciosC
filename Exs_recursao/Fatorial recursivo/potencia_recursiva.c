/*Crie uma funcao recursiva que receba dois inteiros positivos k e n e
calcule k^n*/

#include <stdio.h>
#include <stdlib.h>

/*
Expressao generalizada 	K^N = K * K^(N-1)
Caso base 				K^0 = 1
*/

int potencia(int k, int n) {
	if (n == 0) {
		return 1;
	}
	else {
		return k * potencia(k, n - 1);
	}
}

int main() {
	printf("%d\n", potencia(2, 10));

	system("pause");
	return 0;
}
