#include <stdio.h>
#include <string.h>

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

int main() {
  int i;
  time_t t;

  // inicializar o gerador 
  srand((unsigned) time(&t));


  // Gerar 6 numero entre 0 e 60
  for (i = 0; i < 6; i++) {
    printf("%d\n", rand() % 61);
  }

  return 0;
}

