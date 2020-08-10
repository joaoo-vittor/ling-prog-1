/*

3.22 Pré-incrementando versus pós-incrementando.
Escreva um programa que demonstre a diferença entre
pré-decrementar e pós-decrementar usando o operador
de decremento --.

*/

#include <stdio.h>

int main() {
  int j = 10, p = 0;

  for (int i = 1; i <= 10; i++) {
    p = j - i;

    printf("%d   %d \n", i, p);
  }
  
  return 0;
}
