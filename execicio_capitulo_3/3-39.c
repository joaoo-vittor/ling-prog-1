/*

3.39 Contando 7s. Escreva um programa que leia um intei-
ro e determine e imprima quantos dígitos no inteiro são
algarismos 7.

Não compreendi essa questão.

*/

#include <stdio.h>

int main() {
  int number, seven;

  printf("Enter a number: ");
  scanf("%d", &number);

  seven = number / 7;

  printf("Digit amount of 7 is %d", seven);

  return 0;
}
