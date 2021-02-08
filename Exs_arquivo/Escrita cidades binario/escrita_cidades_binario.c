#include <stdio.h>
#include <stdlib.h>

#define ENTRADA "cidades_populosas.txt"
#define SAIDA "cidades_binario.txt"

typedef struct {
	int len;
	char *str;
} String;

typedef struct {
	String nome;
	int populacao;
} Cidade;

enum {MAX_NOME = 15, MAX_CIDADES = 20};

int main() {
	Cidade *cidades;
	FILE *entrada;
	FILE *saida;
	char c;
	int i, j, m;
	int max_cidades, max_nome;

	entrada = fopen("arquivos\\"ENTRADA, "r");
	if (entrada == NULL) {
		printf("Erro na abertura do arquivo "ENTRADA"!\n");
		exit(1);
	}

	fgetc(entrada);
	if (feof(entrada)) {
		printf("Arquivo "ENTRADA" vazio!\n");
		fclose(entrada);
		exit(1);
	}
	rewind(entrada);

	saida = fopen("arquivos\\"SAIDA, "wb");
	if (saida == NULL) {
		printf("Erro na abertura do arquivo "SAIDA"!\n");
		exit(1);
	}

	cidades = malloc(MAX_CIDADES * sizeof(Cidade));
	max_cidades = MAX_CIDADES;


	c = fgetc(entrada);
	for (i = 0; !feof(entrada); i++) {

		// ~ aumenta a memoria alocada quando necessario ~

		if (i == max_cidades) {
			max_cidades *= 1.5;
			cidades = realloc(cidades, max_cidades * sizeof(Cidade));
		}


		// ~ guardando o nome da Cidade ~

		cidades[i].nome.str = malloc(MAX_NOME * sizeof(char));
		max_nome = MAX_NOME;

		j = 0;
		do {
			cidades[i].nome.str[j] = c;

			if (++j == max_nome) {
				max_nome *= 1.5;
				cidades[i].nome.str = realloc(cidades[i].nome.str, max_nome * sizeof(char));
			}

			c = fgetc(entrada);

		} while (c != '\t');
		cidades[i].nome.str[j] = '\0';

		cidades[i].nome.len = ++j;
		fwrite(&cidades[i].nome.len, sizeof(int), 1, saida);

		cidades[i].nome.str = realloc(cidades[i].nome.str, j * sizeof(char));
		fwrite(cidades[i].nome.str, sizeof(char), j, saida);


		// ~ guardando a populacao ~

		fscanf(entrada, "%d", &cidades[i].populacao);
		fgetc(entrada); // Descarta o '\n'

		fwrite(&cidades[i].populacao, sizeof(int), 1, saida);


		// ~ avancando para a proxima Cidade ~

		c = fgetc(entrada);
	}

	cidades = realloc(cidades, i * sizeof(Cidade));

	fclose(entrada);
	fclose(saida);

	m = i; // Guarda a quantidade total de cidades

	for (i = 0; i < m; i++) {

		printf("Cidade: %s\nPopulacao: %d\n\n", cidades[i].nome.str, cidades[i].populacao);
		free(cidades[i].nome.str);
	}

	free(cidades);

	return 0;
}
