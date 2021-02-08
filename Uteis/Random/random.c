#include <stdio.h>
#include <stdlib.h> // necessario p/ as funcoes rand() e srand()
#include <time.h> //necessario p/ funcao time()

int main(void) {
  int i;
  
  printf("Gerando 10 valores aleatorios:\n\n");
  
  /*
  srand(time(NULL)) objetiva inicializar o gerador de numeros
  aleatorios com o valor da funcao time(NULL). Este por sua vez, e
  calculado como sendo o total de segundos passados desde 1 de
  janeiro de 1970 ate a data atual.
  Desta forma, a cada execucao o valor da "semente" sera diferente.
  */
  srand(time(NULL));
  
  for (i = 0; i < 10; i++) {
    // gerando valores aleatorios na faixa de 0 a 99
    printf("%d ", rand() % 100);
  }
  
  getchar();
  return 0;
}
