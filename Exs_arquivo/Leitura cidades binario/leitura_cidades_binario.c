#include <stdio.h>
#include <stdlib.h>

#define ENTRADA "cidades_binario.txt"

typedef struct {
	int len;
	char *str;
} String;

typedef struct {
	String nome;
	int populacao;
} Cidade;

int main() {
	FILE *entrada;
	Cidade cidade;

	entrada = fopen("arquivos\\"ENTRADA, "rb");
	if (entrada == NULL) {
		printf("Erro na abertura do arquivo"ENTRADA"!\n");
		exit(1);
	}

	//cidade.nome.str = malloc(1);

	do {
		fread(&cidade.nome.len, sizeof(int), 1, entrada);
		printf("%d\n", cidade.nome.len);

		cidade.nome.str = realloc(cidade.nome.str, cidade.nome.len * sizeof(char));

		fread(cidade.nome.str, sizeof(char), cidade.nome.len, entrada);
		printf("%s\n", cidade.nome.str);

		fread(&cidade.populacao, sizeof(int), 1, entrada);
		printf("%d\n\n", cidade.populacao);

	} while (!feof(entrada));

	fclose(entrada);
	
	return 0;
}
