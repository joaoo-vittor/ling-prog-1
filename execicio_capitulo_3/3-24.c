/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


3.24 Ache o número maior. O processo de achar o número
maior (ou seja, o máximo de um grupo de números)
é usado com frequência nas aplicações de computador.
Por exemplo, um programa que determina o vencedor
de uma disputa de vendas lerá o número de unidades
vendidas por vendedor. O vendedor que tiver vendido
mais unidades vence a disputa. Escreva um programa
em pseudocódigo e depois um programa que leia uma
série de 10 números, determine e imprima o maior dos
números. [Dica: seu programa deverá usar três variá­veis
da seguinte forma]:

  contador : Um contador para contar até 10 (ou seja,
             registrar quantos números foram informa-
             dos e determinar quando os 10 números
             foram processados)

  número :	 O número da entrada atual no programa

  maior :	   O maior número achado até o momento

*/

#include <stdio.h>

int main() {
  int counter = 0, bigger = 0;
  int number;

  while (counter < 10) {

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number > bigger) {
      bigger = number;
    }

    counter += 1;
  }

  printf("The bigger number is %d", bigger);

  return 0;
}
