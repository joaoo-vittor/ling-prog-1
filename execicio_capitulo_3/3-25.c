/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


para imprimir a tabela de valores a seguir. Use a sequência
de escape de tabulação, \t , na instrução printf para se-
parar as colunas com tabulações.

N    10*N      100*N     1000*N

*/

#include <stdio.h>

int main() {
  int n10, n100, n1000;

  for (int i = 1; i <= 10; i++) {
    n10 = i * 10;
    n100 = i * 100;
    n1000 = i * 1000;

    printf("%d\t%d\t%d\t%d\n", i, n10, n100, n1000);

  }

  return 0;
}
