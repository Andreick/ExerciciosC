#include <stdio.h>
#include <stdlib.h> // Necessario para a funcao atoi()

int main() {
  char snum[] = "50";
  int inum;

  inum = atoi(snum);

  printf("inum = %d\n", inum);
  
  return 0;
}
