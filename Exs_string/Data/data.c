/*Leia uma cadeia de caracteres no formato DD/MM/AAAA e copie o dia,
mes e ano para 3 variaveis inteiras. Antes disso, verifique se as
barras estao no lugar certo, e se DD, MM e AAAA sao numericos*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 12

void getLine(char *str) {
	fgets(str, STRSIZE, stdin);

	int last = strlen(str) - 1;

	if (str[last] == '\n')
		str[last] = '\0';
}

int main() {
	char data[STRSIZE];
	int dia, mes, ano;
	int dataTam;
	int i, j;

	printf("Digite uma data (DD/MM/AAAA): ");
	getLine(data);

	dataTam = strlen(data);

	if (dataTam == 10) {
		
		if (data[2] == '/' && data[5] == '/') {
			
			for (i = 0; i < dataTam; i++) {
				
				if (data[i] >= 47 && data[i] <= 57) {
					
					if (i == 1) {
						dia = (data[0] - 48) * 10;
						dia += data[1] - 48;
						
						if (dia > 31) {
							printf("\nEsta data nao existe\n");
							break;
						}
					}

					if (i == 4) {
						mes = (data[3] - 48) * 10;
						mes += data[4] - 48;
						
						if (mes > 12) {
							printf("\nEsta data nao existe\n");
							break;
						}
					}

					if (i == 9) {
						ano = (data[6] - 48) * 1000;
						ano += (data[7] - 48) * 100;
						ano += (data[8] - 48) * 10;
						ano += data[9] - 48;
						printf("\nDia %d do %d de %d\n", dia, mes, ano);
					}
				}
				else {
					printf("\nDigite valores numericos\n");
					break;
				}
			}
		}
		else {
			printf("\nFormato invalido\n");
		}
	}
	else {
		printf("\nFormato invalido\n");
	}
	
	system("pause");
	return 0;
}
