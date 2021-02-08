/*Considerando a estrutura:

struct Ponto{ int x; int y; };

para representar um ponto em uma grade 2D, implemente uma funcao que
indique se um ponto p esta localizado dentro ou fora de um retangulo. O
retangulo e definido por seus vertices inferior esquerdo v1 e superior
direito v2. A funcao deve retornar 1 caso o ponto esteja localizado
dentro do retangulo e 0 caso contrario. Essa funcao deve obedecer ao
prototipo:

int dentroRet (struct Ponto* v1, struct Ponto* v2, struct Ponto* p);*/

#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} bool;

typedef struct {
	int x, y;
} ponto;

typedef struct {
	ponto v1, v2;
} retangulo;

bool dentroRet (ponto* v1, ponto* v2, ponto* p) {

	if (p->x >= v1->x && p->x <= v2->x && p->y >= v1->y && p->y <= v2->y) {
		return true;
	}
	return false;
}

int main() {
	retangulo ret;
	ponto p;

	ret.v1.x = 0;
	ret.v1.y = 0;
	ret.v2.x = 5;
	ret.v2.y = 5;

	p.x = 3;
	p.y = 2;

	if (dentroRet(&ret.v1, &ret.v2, &p)) {
		printf("Verdadeiro\n");
	}
	else {
		printf("Falso\n");
	}

	system("pause");
	return 0;
}
