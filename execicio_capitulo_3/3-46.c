/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva

.46 Fatorial. O fatorial de um inteiro não negativo n é es-
crito como n! (pronuncia-se ‘n fatorial’) e é definido da
seguinte forma:
n! = n · (n - 1) · (n - 2) · ... · 1 (para valores de n
maiores ou iguais a 1)
e
n! = 1 (para n = 0).

Por exemplo, 5! = 5 · 4 · 3 · 2 · 1, que é 120.
a) Escreva um programa que leia um inteiro não nega-
tivo e calcule e imprima seu fatorial.


b) Escreva um programa que calcule o valor da cons-
tante matemática e usando a fórmula:


c)
Escreva um programa que calcule o valor de e x
usando a fórmula


*/

#include <stdio.h>

int main() {
  int fact, aux;
  int accumulator = 0;

  printf("Enter a number: ");
  scanf("%d", &fact);

  aux = fact;

  for (int i = 1; i < fact; fact--) {
    if (aux == fact) {
      accumulator = fact * (fact - 1);
    } else {
      accumulator = accumulator * (fact - 1);
    }

    printf("%d\n", fact);
  }

  printf("accumulator  %d", accumulator);

  return 0;
}

