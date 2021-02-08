#include <stdio.h>
#include <stdlib.h>

enum {Segunda = 4, Terca, Quarta};
enum {QUINTA, SEXTA, SABADO};

int main() {
	printf("%d %d %d\n", Segunda, Terca, Quarta);
	printf("%d %d %d\n", QUINTA, SEXTA, SABADO);

	system("pause");
	return 0;
}
