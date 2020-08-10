/*

3.20 Calculadora de juros. Os juros simples sobre um
empréstimo são calculados a partir da fórmula
juros = principal * taxa * dias / 365;
Essa fórmula considera que taxa seja a taxa de juros
anual e, portanto, inclui a divisão por 365 (dias). Desen-
volva um programa que aceite principal , taxa e dias
para vários empréstimos, calcule e apresente os juros sim-
ples para cada empréstimo, usando a fórmula apresenta-
da. Veja um exemplo do diálogo de entrada/saída:

*/

#include <stdio.h>

int main() {
  float principal_loan_amount, interest_rate, days, interest_rate_amount;

  printf("Enter the main loan value (-1 to sign out): ");
  scanf("%f", &principal_loan_amount);

  if (principal_loan_amount == -1) {
    return 0;
  }

  printf("Enter the interst rate: ");
  scanf("%f", &interest_rate);

  printf("Enter the loan term in days: ");
  scanf("%f", &days);

  // juros = principal * taxa * dias / 365;
  while (principal_loan_amount != -1) {
    interest_rate_amount = principal_loan_amount * interest_rate * days / 365;

    printf("Value the interest is of the R$%.2f\n", interest_rate_amount);


    printf("Enter the main loan value (-1 to sign out): ");
    scanf("%f", &principal_loan_amount);

    if (principal_loan_amount == -1) {
      break;
    }

    printf("Enter the interst rate: ");
    scanf("%f", &interest_rate);

    printf("Enter the loan term in days: ");
    scanf("%f", &days);

  }
  
  return 0;
}



