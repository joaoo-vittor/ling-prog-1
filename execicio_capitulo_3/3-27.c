/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


3.27 Ache os dois maiores números. Usando uma técnica
semelhante à do Exercício 3.24, ache os dois maiores
valores dos 10 números. [Nota: você poderá informar
cada número apenas uma vez.]


*/

#include <stdio.h>

int main() {
  int bigger_1 = 0, bigger_2 = 0;
  int number;

  for (int i = 1; i <= 5; i++) {

    printf("Enter a number: ");
    scanf("%d", &number);

    if(number > bigger_1){
      if(bigger_1 > bigger_2){
        bigger_2 = bigger_1;
      }

      bigger_1 = number;
    }

    if(bigger_1 >= bigger_2 && number != bigger_1){
      if(number > bigger_2){
        bigger_2 = number;
      }
    }

  }

  printf("The first bigger number is %d\n", bigger_1);
  printf("The second bigger number is %d", bigger_2);


  return 0;
}
