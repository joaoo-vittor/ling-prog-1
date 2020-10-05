#include <stdio.h>


#include <stdlib.h>
// Converção de string

// atof(); // converte string para double
// atoi(); // converte string para inteiro
// atol(); // converte string para long float

// Geração de sequencia  pseudo-aleatoria

// rand(); // gera numero aleatorio
// srand(); // inicializa o gerador de numero aleatorio

// Gerenciamento de memoria dinamica

// malloc(); // manten o lixo de memoria
// calloc(); // retira o lixo da memoria
// free(); // libera a memoria 
// realloc(); // modifica o tamanho da memoria alocada

// Pesquisa e ordenação

// qsort(); // ordena os elementos de um array

int compara(int *x, int *y) {
  if (*x > *y) {
    return 1;
  } else if (*x == *y) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  int array[] = {3, 9, 1, 54, 5, 6, 42, 7, 61};
  int i;

  qsort(array, 9, sizeof(int), (void *)compara);

  for (i = 0; i < 9; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}

