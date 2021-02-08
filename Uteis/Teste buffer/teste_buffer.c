#include <stdio.h>
#include <stdlib.h>

#define STRSIZE 4

void limparBuffer(void);
void skipTrash(void);

int main (){
	char str[STRSIZE];

	printf("Digite: ");
	fgets(str, STRSIZE, stdin);
	setbuf(stdin, NULL);
	//limparBuffer();
	//skipTrash();

	printf("Vc digitou: %s", str);

	printf("\nDigite: ");
	fgets(str, STRSIZE, stdin);
	setbuf(stdin, NULL);
	//limparBuffer();
	//skipTrash();

	printf("Vc digitou: %s\n", str);

	system("pause");
	return 0;
}

void limparBuffer() {
	char c;

	while ((c = getchar()) != EOF && c != '\n');
}

void skipTrash() {
	scanf("%*[^\n]"); getchar();
}
