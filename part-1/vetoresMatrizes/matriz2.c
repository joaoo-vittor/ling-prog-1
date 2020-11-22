#include <stdio.h>

int main() {
  int numeros[2][2];
  int i, j;

  numeros[0][0] = 1;
  numeros[0][1] = 2;
  numeros[1][0] = 3;
  numeros[1][1] = 4;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      printf("%d ", numeros[i][j]);
    }
    printf("\n");
  }


  float valores[2][2];
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      valores[i][j] = (float)numeros[i][j] / (float)2;
    }
  }

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      printf("%.1f ", valores[i][j]);
    }
    printf("\n");
  }

  return 0;
}
