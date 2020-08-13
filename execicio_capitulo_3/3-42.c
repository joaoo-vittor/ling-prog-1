/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

3.42 Diâmetro, circunferência e área de um círcu-
lo. Escreva um programa que leia o raio de um círculo
(como um valor float ) e calcule e imprima o diâmetro,
a circunferência e a área. Use o valor 3.14159 para p.

*/

#include <stdio.h>

int main() {
  float radius, area, diameter, circumference;
  float pi = 3.14159;

  printf("Enter the radius of the circle: ");
  scanf("%f", &radius);

  area = pi * (radius * radius);
  circumference = 2 * pi * radius;
  diameter = 2 * radius;

  printf("The area of the circle is %.2f\n", area);
  printf("The circumference of the circle is %.2f\n", circumference);
  printf("The diameter is %.2f", diameter);

  return 0;
}

