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

// Aritmetica de inteiros

// abs(); // valor absoluto
// div(); // divisao inteira


int main() {
  int valor_a, valor_b;

  valor_a = abs(5);
  printf("O valor absoluto de 5 é %d\n", valor_a);

  valor_b = abs(-15);
  printf("O valor absoluto de -15 é %d\n", valor_b);

  return 0;
}

