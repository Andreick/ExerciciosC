#include <stdio.h>
#include <stdlib.h>

int main() {
  short int contador;
  long long int num, fatorial;
  
  printf("Digite um numero inteiro: ");
  scanf("%lld", &num);
  
  fatorial = num;
  
  for (contador = num - 1; contador > 1; contador--) {
    fatorial *= contador;
  }
  
  printf("\nFatorial de %lld: %lld\n", num, fatorial);
  
  system("pause");
  return 0;
}
