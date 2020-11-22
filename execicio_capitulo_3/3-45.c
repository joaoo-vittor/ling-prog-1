/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

3.45 Lados de um triângulo retângulo. Escreva um pro-
grama que leia três inteiros diferentes de zero e deter-
mine e imprima se eles poderiam ser os lados de um
triângulo retângulo.

*/

#include <stdio.h>

int main() {
  int side_a, side_b, side_c;
  int hypotenuse, opposite_side;


  printf("Enter the hypotenuse: ");
  scanf("%d", &side_a);

  printf("Enter the opposite side b: ");
  scanf("%d", &side_b);

  printf("Enter the opposite side c: ");
  scanf("%d", &side_c);

  hypotenuse = side_a * side_a;
  opposite_side = (side_b * side_b) + (side_c * side_c);

  if (hypotenuse == opposite_side) {
    printf("The sides represent a triangle rectangle.");
  } else {
    printf("The sides don't represent a triangle rectangle.");
  }

  return 0;
}


