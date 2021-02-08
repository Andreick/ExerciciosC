#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	/*Invertendo uma string
	sem usar outra string*/
	char str[] = "Linguagem C";
	char c;
	int i, tam = strlen(str);

	printf("str = %s\n", str);

	for (i = 0; i < tam / 2; i++) {
		c = str[i];
		str[i] = str[tam - 1 - i];
		str[tam - 1 - i] = c;
	}

	printf("str = %s\n", str);

	system("pause");
	return 0;
}
