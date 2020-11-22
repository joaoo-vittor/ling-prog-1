#include <stdio.h>
#include <stdlib.h>

/*
malloc -> quanto é alocada a memoria pode haver lixo de memoria e não remove o lixo.
calloc -> quando é alocada a memoria é limpado o lixo de memoria e atribuido zeros.
*/

int main() {

  // int numero = 9;

  // printf("A variavel 'numero' vale %d e ocupa %ld bytes de memoria.\n", numero, sizeof(numero));

  // int numeros[3];
  // numeros[0] = 1;
  // numeros[1] = 2;
  // numeros[2] = 3;
  
  int quantidade, *ponteiro;

  printf("Informe a quantidade de elementos para o vetor: ");
  scanf("%d", &quantidade);

  // ponteiro = (int*)malloc(quantidade * sizeof(int)); // quantidade X 4 == 4.quantidade bytes

  ponteiro = (int*)calloc(quantidade, sizeof(int)); // quantidade X 4 == 4.quantidade bytes


  // verificar se a memoria foi alocada;
  if (ponteiro) {
    printf("A variavel 'ponteiro' ocupa %ld bytes de memoria.\n", quantidade * sizeof(int));
    printf("Valor de 'p[0]' = %d\n", ponteiro[0]);
    printf("Valor de 'p[1]' = %d\n", ponteiro[1]);
    printf("Valor de 'p[2]' = %d\n", ponteiro[2]);
  } else {
    printf("Memoria indisponivel no momento\n");
  }


  // liberar a memoria (desalocar)

  free(ponteiro);
  ponteiro = NULL; // Medida de Segurança 

  return 0;
}

