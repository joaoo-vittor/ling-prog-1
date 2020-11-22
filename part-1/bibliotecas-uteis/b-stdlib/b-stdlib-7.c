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
  div_t saida;

  saida = div(27, 4);
  printf("O quociente de 27/4 é %d\n", saida.quot);
  printf("O resto de 27/4 é %d\n", saida.rem);  
  // quot -> quociente
  // rem -> resto

  saida = div(27, 3);
  printf("O quociente de 27/4 é %d\n", saida.quot);
  printf("O resto de 27/4 é %d\n", saida.rem);  
  
  return 0;
}

