/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

3.44 Lados de um triângulo. Escreva um programa que leia
três valores float diferentes de zero, determine e impri-
ma se eles poderiam representar os lados de um triângulo.

*/

#include <stdio.h>

int main() {
  float side_a, side_b, side_c;
  int side_a_bool, side_b_bool, side_c_bool;

  printf("Enter the side a: ");
  scanf("%f", &side_a);

  printf("Enter the side b: ");
  scanf("%f", &side_b);

  printf("Enter the side c: ");
  scanf("%f", &side_c);

  side_a_bool = ((side_b - side_c) < side_a && side_a < (side_b + side_c)) ? 1 : 0;
  side_a_bool = ((side_a - side_b) < side_c && side_b < (side_a + side_b)) ? 1 : 0;
  side_a_bool = ((side_a - side_c) < side_b && side_b < (side_a + side_c)) ? 1 : 0;

  if (side_a_bool && side_b_bool && side_c_bool) {
    printf("The sides represent a triangle.");
  } else {
    printf("The sides don't represent a triangle.");
  }

  return 0;
}


