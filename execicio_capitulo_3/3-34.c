/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

3.34 Quadrado de asteriscos vazio. Modifique o progra-
ma que você escreveu no Exercício 3.33 para que ele
exiba um quadrado vazio. Por exemplo, se seu progra-
ma ler um tamanho 5, ele deverá exibir

*/

#include <stdio.h>

int main() {
  int side = 0, aux = 0;

  printf("Inform the side of the square: ");
  scanf("%d", &side);

  if (side > 1 && side <= 20) {
    for (int i = 1; i <= side; i++) {
      aux += side;
      for (int j = 1; j <= side; j++) {
        if (i == 1 || i == side) {
          printf("*");
        } else if (j == 1 || j == side) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
  }

  return 0;
}
