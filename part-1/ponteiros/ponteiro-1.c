#include <stdio.h>

void incrementa(int* num);

int main() {
  int contador = 10;

  printf("Antes %d\n", contador);

  incrementa(&contador);

  printf("Depois %d\n", contador);

  return 0;
}


void incrementa(int* num) {
  printf("Dentro %d\n", ++(*num));
}

