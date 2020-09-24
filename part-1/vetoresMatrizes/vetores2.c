#include <stdio.h>

int main() {
  // vetor de inteiros
  int numeros[5];
  int i, j, k;

  // atribuicao manual
  numeros[0] = 1;
  numeros[1] = 5;
  numeros[2] = 7;
  numeros[3] = 98;
  numeros[4] = 23;

  // for (i = 0; i < 5; i++) {
  //   printf("%d ", numeros[i]);
  // }
  // printf("\n");

  // vetor de reais
  float valores[5];
  for (j = 0; j < 5; j++) {
    valores[j] = (float)numeros[j] / (float)2;
  }

  for (k = 4; k >= 0; k--) {
    printf("%.2f\n", valores[k]);
  }

  return 0;
}
