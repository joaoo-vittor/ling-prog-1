/*

3.18 Calculadora de limite de crédito. Desenvolva um
programa em C que determine se um cliente de uma
loja de departamentos excedeu seu limite de crédito. Os
seguintes fatos estão disponíveis para cada cliente:

a) Número de conta.
b) Saldo no início do mês.
c) Total de todos os encargos desse cliente nesse mês.
d) Total de todos os créditos aplicados à conta desse
cliente nesse mês.
e) Limite de crédito autorizado.

O programa deverá ler cada um desses fatos, calcular o
novo saldo (= saldo inicial + encargos - créditos)
e determinar se o novo saldo é superior ao limite de
crédito do cliente. Para os clientes cujo limite de crédi-
to foi ultrapassado, o programa deverá exibir o número
de conta do cliente, o limite de crédito, o novo saldo e
a mensagem ‘Limite de crédito ultrapassado’. Veja um
exemplo do diálogo de entrada/saída:

*/

#include <stdio.h>

int main() {
  float opening_balance, full_charge, credit_limit;
  float new_balance, full_credit;
  int account;

  printf("Enter the account number (-1 to sign out): ");
  scanf("%d", &account);

  if (account == -1) {
    return 0;
  }

  printf("Enter the current balenca: ");
  scanf("%f", &opening_balance);

  printf("Enter the total charges: ");
  scanf("%f", &full_charge);

  printf("Enter the total credits: ");
  scanf("%f", &full_credit);

  printf("Enter the credit limit: ");
  scanf("%f", &credit_limit);

  while(account != -1) {
    float final_balance = 0;
    new_balance = opening_balance + full_charge - full_credit;
    final_balance = full_credit + opening_balance;

    if (new_balance > credit_limit) {
      printf("Account: %d\n", account);
      printf("Credit limit: %.2f\n", full_credit);
      printf("Balance: %.2f\n", final_balance);
      printf("credit limit exceeded.\n");
    }

    printf("Enter the account number (-1 to sign out): ");
    scanf("%d", &account);

    if (account == -1) {
      break;
    }

    printf("Enter the current balenca: ");
    scanf("%f", &opening_balance);

    printf("Enter the total charges: ");
    scanf("%f", &full_charge);

    printf("Enter the total credits: ");
    scanf("%f", &full_credit);

    printf("Enter the credit limit: ");
    scanf("%f", &credit_limit);

  }
  
  return 0;
}

