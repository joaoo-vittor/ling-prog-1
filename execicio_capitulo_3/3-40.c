/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

Padrão de asteriscos em xadrez. Escreva um pro-
grama que apresente o seguinte padrão de tabuleiro de
xadrez:

  * * * * * * * *
    * * * * * * * *
  * * * * * * * *
    * * * * * * * *
  * * * * * * * *
    * * * * * * * *
  * * * * * * * *
    * * * * * * * *

Seu programa deverá usar apenas três instruções de saí-
da, uma de cada das seguintes formas:
    printf( “* “ );
    printf( “ “ );
    printf( “\n” );

*/

#include <stdio.h>

int main() {
  int side = 8;

  for (int i = 1; i <= side; i++) {
    if (i % 2 == 0) {
    printf(" ");
    }
    for (int j = 1; j <= side; j++) {
      printf("* ");
    }
    printf("\n");
  }


  return 0;
}
