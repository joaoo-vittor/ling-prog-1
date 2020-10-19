#include <stdio.h>
#include <stdlib.h>

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

  ponteiro = (int*)malloc(quantidade * sizeof(int)); // quantidade X 4 == 4.quantidade bytes

  // verificar se a memoria foi alocada;
  if (ponteiro) {
    for (int i = 0; i < quantidade; i++) {
      printf("Informe o valor para a posição %d do vetor: ", i);
      scanf("%d", &ponteiro[i]);
    }

    for (int i = 0; i < quantidade; i++) {
      printf("A variavel 'ponteiro[%d]' vale %d e ocupa %ld bytes de memoria.\n", i, ponteiro[i], sizeof(ponteiro[i]));
    }
    
    printf("A variavel 'ponteiro' ocupa %ld bytes de memoria.\n", quantidade * sizeof(int));
  } else {
    printf("Memoria indisponivel no momento");
  }


  // liberar a memoria (desalocar)

  free(ponteiro);
  ponteiro = NULL; // Medida de Segurança 

  return 0;
}
