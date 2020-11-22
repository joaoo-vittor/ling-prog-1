/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


3.37 Qual é a velocidade do seu computador? Como
você pode determinar a velocidade com que seu compu-
tador realmente opera? Escreva um programa com um
loop while que conte de 1 até 300.000.000 em inter-
valos de 1. Toda vez que o contador atingir um múltiplo
de 100.000.000, mostre esse número na tela. Use seu
relógio para marcar o tempo gasto entre cada repetição
do loop por 100 milhões de vezes.

Meu notebook travou.

*/

#include <stdio.h>

int main() {
  int counter = 0;

  while (counter <= 300000000) {
    if (counter % 100000000) {
      printf("%d", counter);
    }
    counter += 1;
  }

  return 0;
}
