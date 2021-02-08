/*Faca uma funcao chamada ‘simplifica’ que recebe como parametro o
numerador e o denominador de uma fracao. Esta funcao deve simplificar a
fracao recebida dividindo o numerador e o denominador pelo maior fator
possıvel. Por exemplo, a fracao 36/60 simplifica para 3/5 dividindo
o numerador e o denominador por 12. A funcao deve modificar as
variaveis passadas como parametro.*/

#include <stdio.h>
#include <stdlib.h>

void simplifica(int *n, int *d) {
	int fatorN, fatorD, fator;
	int menor;
	int i;
	
	if (*n > *d) {
		menor = *d;
	}
	else {
		menor = *n;
	}
	
	for (i = 1; i <= menor; i++) {
		
		fatorN = *n % i;
		fatorD = *d % i;
		
		if (fatorN == 0 && fatorD == 0) {
			fator = i;
		}
	}

	if (fator > 1) {
		*n /= fator;
		*d /= fator;
		printf("Fator: %d\n", fator);
	}
}

int main() {
	int num = 36, den = 60;
	
	simplifica(&num, &den);

	printf("Num: %d\n", num);
	printf("Den: %d\n", den);

	system("pause");
	return 0;
}
