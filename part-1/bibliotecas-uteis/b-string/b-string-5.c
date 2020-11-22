#include <stdio.h>
#include <string.h>

// Operação em string

// strcpy(); // copia de string
// strcat(); // concatena string
// strcmp(); // compara duas strings

// Busca

// strchr(); // localiza a primeira ocorrencia de caractere em uma string
// strtok(); // dividir uma string em uma sub-string com base em um caractere
// strlen(); // retorna o tamanho da string

int main() {
  
  char str1[] = "joaoo.vittor007@gmail.com";

  printf("O tamanho da string %s e %ld\n", str1, strlen(str1));

  return 0;
}

