/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


3.36 Imprimindo o equivalente decimal de um núme-
ro binário. Leia um inteiro contendo apenas 0s e 1s
(ou seja, um inteiro ‘binário’) e imprima seu equivalen-
te decimal. [Dica: use os operadores de módulo e divisão
para apanhar os dígitos do número ‘binário’ um de cada
vez, da direita para a esquerda. Assim como no sistema
numérico decimal, em que o dígito mais à direita tem
um valor posicional de 1, e o próximo dígito à esquerda
tem um valor posicional de 10, depois de 100, depois de
1.000, e assim por diante, no sistema binário, o dígito
mais à direita tem um valor posicional de 1, o próximo
dígito à esquerda tem um valor posicional de 2, depois de
4, depois de 8 e assim por diante. Assim, o número 234
pode ser interpretado como 4 * 1 + 3 * 10 + 2 * 100.
O equivalente decimal do binário 1101 é 1 * 1 + 0 * 2
+ 1 * 4 + 1 * 8 ou 1 + 0 + 4 + 8 ou 13.]

*/

#include <stdio.h>

int main() {
  int binary, equivalent;
  int unity = 0, decimal = 0, hundred = 0, thousand = 0;

  printf("Enter a number for verified if it is a binary:");
  scanf("%d", &binary);

  unity = binary % 10;
  decimal = (binary % 100) / 10;
  hundred = (binary / 1000) % 10 ;
  thousand = binary / 1000;

  equivalent = (unity * 1) + (decimal * 2) + (hundred * 4) + (thousand * 8);

  printf("%d is the decimal equivalent of the %d", equivalent, binary);

  return 0;
}





