#include <stdio.h>
#include <stdlib.h>

/*
malloc -> quanto é alocada a memoria pode haver lixo de memoria e não remove o lixo.
calloc -> quando é alocada a memoria é limpado o lixo de memoria e atribuido zeros.
realloc -> realocação de memoria
*/

int main() {
  
  int quantidade, *ponteiro;

  printf("Informe a quantidade de elementos para o vetor: ");
  scanf("%d", &quantidade);

  ponteiro = (int*)malloc(quantidade * sizeof(int)); // quantidade X 4 == 4.quantidade bytes

  // verificar se a memoria foi alocada;
  if (ponteiro) {

    printf("A variavel 'ponteiro' ocupa %ld bytes de memoria.\n", quantidade * sizeof(int));

    printf("Informe a quantidade de elementos para realocação do vetor: ");
    scanf("%d", &quantidade);

    ponteiro = (int*)realloc(ponteiro, quantidade * sizeof(int));

    if (ponteiro) {
      printf("A variavel 'ponteiro' ocupa %ld bytes de memoria.\n", quantidade * sizeof(int));
    } else {
      printf("Memoria indisponivel no momento\n");
    }

  } else {
    printf("Memoria indisponivel no momento\n");
  }

  // liberar a memoria (desalocar)
  free(ponteiro);
  ponteiro = NULL; // Medida de Segurança 

  return 0;
}

