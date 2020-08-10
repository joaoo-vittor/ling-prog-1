/*

3.19 Calculadora de comissão de vendas. Uma grande
companhia química paga seus vendedores por comissão.
Os vendedores recebem R$ 200,00 por semana, mais 9
por cento de suas vendas brutas nessa semana. Por exem-
plo, um vendedor que comercialize R$ 5.000,00 em pro-
dutos químicos em uma semana receberá R$ 200,00 e
mais 9 por cento de R$ 5.000,00, ou seja, receberá um
total de R$ 650,00. Desenvolva um programa que peça os
valores brutos de cada vendedor na semana que passou,
calcule e apresente o valor que esse vendedor deverá rece-
ber. Processe os valores referentes a um vendedor por vez.
Veja um exemplo do diálogo de entrada/saída:

*/

#include <stdio.h>

int main() {
  float value_sold, payment;

  printf("Inform the sale in R$ (-1 to sign out): ");
  scanf("%f", &value_sold);

  if (value_sold == -1) {
    return 0;
  }

  while(value_sold != -1) {
    payment = (value_sold * 0.09) + 200;

    printf("The payment is %.2f\n", payment);

    printf("Inform the sale in R$ (-1 to sign out): ");
    scanf("%f", &value_sold);

    if (value_sold == -1) {
      break;
    }

  }
  
  return 0;
}
