/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

3.41 Múltiplos de 2 com um loop infinito. Escreva um pro-
grama que continue imprimindo os múltiplos do inteiro 2,
a saber 2, 4, 8, 16, 32, 64 e assim por diante. Seu loop não
deverá terminar (ou seja, você deverá criar um loop infini-
to). O que acontece quando você executa esse programa?

Ele vai criar um loop infinito e travar meu pc.

*/

#include <stdio.h>

int main() {
  int counter;

  while (counter < 100) {
    if (counter % 2 == 0) {
      printf("%d\n", counter);
    }
    counter += 1;
  }

  return 0;
}


