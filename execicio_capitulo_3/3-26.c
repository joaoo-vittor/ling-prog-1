/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


Saída tabular. Escreva um programa que use o loo-
ping para produzir a seguinte tabela de valores:

  A   A+2   A+4   A+6
  3   5     7     9
  6   8     10    12
  9   11    13    15
  12  14    16    18
  15  17    19    21



*/

#include <stdio.h>

int main() {

  printf("A       A+2     A+4     A+6\n");
  for (int i = 3; i < 16; i++) {
    if (i % 3 == 0) {
      printf("%d\t%d\t%d\t%d\n", i, i+2, i+4, i+6);
    }
  }

  return 0;
}
