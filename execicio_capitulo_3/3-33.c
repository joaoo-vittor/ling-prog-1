/*

3.33 Quadrado de asteriscos. Escreva um programa que
leia o lado de um quadrado e depois exiba esse quadra-
do a partir de asteriscos. Seu programa deverá funcionar
para quadrados de todos os tamanhos de lado entre 1 e
20. Por exemplo, se o programa ler um tamanho 4, ele
deverá exibir.

*/

#include <stdio.h>

int main() {
  int side = 0, total_asterisk = 0;

  printf("Inform the side of the square: ");
  scanf("%d", &side);

  if (side > 1 && side < 20) {
    total_asterisk = side * side;

    for (int i = 1; i <= side; i++) {
      for (int i = 1; i <= side; i++) {
        printf("*");
      }
      printf("\n");
    }
  }

  return 0;
}
