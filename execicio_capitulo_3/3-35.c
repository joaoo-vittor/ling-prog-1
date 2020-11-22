/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

3.35 Testador de palíndromo. Um palíndromo é um nú-
mero, ou uma frase textual, que pode ser lido da mes-
ma forma da esquerda para a direita e vice-versa. Por
exemplo, cada um dos seguintes inteiros de cinco dígitos
é um palíndromo: 12321, 55555, 45554 e 11611. Escre-
va um programa que leia um inteiro de cinco dígitos e
determine se ele é ou não um palíndromo. [Dica: use os
operadores de divisão e módulo para separar o número
em seus dígitos individuais.]

*/

#include <stdio.h>

int main() {
  int palindrome;
  int unity = 0, decimal = 0, hundred = 0, thousand = 0;


  printf("Enter a number for verified if it is a palindrome:");
  scanf("%d", &palindrome);

  unity = palindrome % 10;
  decimal = (palindrome % 100) / 10;
  hundred = (palindrome / 1000) % 10 ;
  thousand = palindrome / 10000;

  int poli_bool = ((unity + decimal) == (hundred + thousand)) ? 1 : 0;

  if (poli_bool) {
    printf("The number %d is palindrome", palindrome);
  } else {
    printf("The number %d not palindrome", palindrome);
  }

  return 0;
}
