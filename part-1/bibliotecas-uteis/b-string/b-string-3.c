#include <stdio.h>
#include <string.h>

// Operação em string

// strcpy(); // copia de string
// strcat(); // concatena string
// strcmp(); // compara duas strings

// Busca

// strchr(); // localiza a primeira ocorrencia de caractere em uma string


int main() {
  
  char str1[] = "joaoo.vittor007@gmail.com";
  char arob = '@';

  char *ret = strchr(str1, arob);

  printf("A partir do %c está %s\n", arob, ret);

  return 0;
}

