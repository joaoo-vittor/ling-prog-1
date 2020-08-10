/*

3.21 Calculadora de salário. Desenvolva um programa
que determine o salário semanal bruto de vários fun-
cionários. A empresa paga ‘uma hora normal’ para cada
funcionário pelas primeiras 40 horas trabalhadas, ‘uma
hora normal e meia’ por hora trabalhada a partir de 40
horas. Você recebe uma lista de funcionários da empre-
sa, o número de horas que cada funcionário trabalhou
na semana anterior e o valor ganho por hora de cada
funcionário. Seu programa deverá ler essas informações
para cada funcionário e determinar e exibir o salário que
cada um deverá receber. Aqui está um exemplo do diálo-
go de entrada/saída:

*/

#include <stdio.h>

int main() {
  int work_hours;
  float hourly_payment, salary;

  printf("Enter the work hours (-1 to sign out): ");
  scanf("%d", &work_hours);

  if (work_hours == -1) {
    return 0;
  }

  printf("Enter the hourly wage of the worker (R$00.00): ");
  scanf("%f", &hourly_payment);

  while (work_hours != -1) {
    
    if (work_hours <= 40) {
      salary = work_hours * hourly_payment;
      printf("Salary is R$%.2f\n", salary);
    } else if (work_hours > 40) {
      salary = (work_hours * hourly_payment) + (hourly_payment / 2);
      printf("Salary is R$%.2f\n", salary);
    } else {
      printf("Invalid salary entered.\n");
    }

    printf("Enter the work hours (-1 to sign out): ");
    scanf("%d", &work_hours);

    if (work_hours == -1) {
      break;
    }

    printf("Enter the hourly wage of the worker (R$00.00): ");
    scanf("%f", &hourly_payment);

  }

  return 0;
}

