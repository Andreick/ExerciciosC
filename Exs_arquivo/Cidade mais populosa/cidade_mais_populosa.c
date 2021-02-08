/* 10. Faca um programa que receba o nome de um arquivo de entrada e
outro de saıda. O arquivo de entrada contem em cada linha o nome de uma
cidade (ocupando 40 caracteres) e o seu numero de habitantes. O programa
devera ler o arquivo de entrada e gerar um arquivo de saıda onde aparece
o nome da cidade mais populosa seguida pelo seu numero de habitantes. */

#include <stdio.h>
#include <stdlib.h>

/* O nome das cidades possuem tamanhos variados sendo necessaria a
alocacao dinamica. A populacao sera armazenada como string e como
inteiro */
typedef struct {
	char *nome;
	char *str_populacao;
	int int_populacao;
} cidade;

int main() {
	cidade *cidades = NULL; // Array de cidades
	FILE *arq;
	char c;
	int i, j, m; /* Usados para percorrer o indice de cidades como se
	fosse uma matriz, seguindo os nomes convencionais i, j
	m = max(i), n = max(j) */
	int maior_populacao = 0;

	arq = fopen("Arquivos\\cidades_populosas.txt", "r");
	if (arq == NULL) {
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}

	i = 0;
	c = fgetc(arq);
	while (c != EOF) {

		cidades = realloc(cidades, (i + 1) * sizeof(cidade));


		// ~ guardando o nome da cidade ~

		j = 0;

		cidades[i].nome = malloc(sizeof(char));
		
		do {
			cidades[i].nome[j++] = c; /* Atribui a letra c para o array nome
			na posicao j, incrementando j em seguida */
			cidades[i].nome = realloc(cidades[i].nome, (j + 1) * sizeof(char));
			c = fgetc(arq);

		} while (c != '\t'); /* Sabemos que o nome da cidade termina quando
		chegamos no caractere '\t' */

		cidades[i].nome[j] = '\0';


		// ~ ignorando as tabulacoes ~

		do {
			c = fgetc(arq);

		} while (c == '\t');

		
		// ~ guardando a populacao como string e inteiro ~

		/* O processo de guardar a populacao como string e semelhante
		ao feito para guardar o nome da cidade */

		j = 0;

		cidades[i].str_populacao = malloc(sizeof(char));
		cidades[i].str_populacao[j++] = c;

		// Subtrai '0' de c para obter o valor inteiro correspondente de c
		cidades[i].int_populacao = c - '0';

		c = fgetc(arq);

		/* Sabemos que o numero da populacao termina quando chegamos
		no caractere '\n' */
		while (c != '\n') {

			cidades[i].str_populacao = realloc(cidades[i].str_populacao, (j + 1) * sizeof(char));
			cidades[i].str_populacao[j++] = c;

			/* Multiplica por 10 para adicionar o proximo digito e obter
			o numero inteiro completo no final */
			cidades[i].int_populacao *= 10;
			cidades[i].int_populacao += c - '0';

			c = fgetc(arq);
		}

		cidades[i].str_populacao = realloc(cidades[i].str_populacao, (j + 1) * sizeof(char));
		cidades[i].str_populacao[j] = '\0';


		// ~ avancando para a proxima cidade ~

		i++;
		c = fgetc(arq);
	}

	m = i; // Guarda a quantidade total de cidades

	fclose(arq);

	//Exibe todas as cidades e respectivas populacoes
	for (int i = 0; i < m; i++) {
		
		printf("Cidade: %s\nPopulacao: %d\n\n", cidades[i].nome, cidades[i].int_populacao);
	}

	// Gera um arquivo de saida com a cidade mais populosa
	for (i = 0; i < m; i++) {

		if (cidades[i].int_populacao > maior_populacao) {

			arq = fopen("Arquivos\\cidade_mais_populosa.txt", "w");

			fputs(cidades[i].nome, arq);
			fputc('\t', arq);
			fputs(cidades[i].str_populacao, arq);

			fclose(arq);

			maior_populacao = cidades[i].int_populacao;
		}
		
		// Como nao serao mais usados, os espacos de memoria podem ser liberados
		free(cidades[i].nome);
		free(cidades[i].str_populacao);
	}

	free(cidades);

	return 0;
}
