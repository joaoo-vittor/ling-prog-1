#include <stdio.h>
#include <string.h>

// Operação em string

// strcpy(); // copia de string
// strcat(); // concatena string
// strcmp(); // compara duas strings

int main() {
  
  char str1[20], str2[20];

  strcpy(str1, "Joao vitor");
  strcpy(str2, "Joao vitor");

  if (strcmp(str1, str2)) {
    printf("Não são iguais.\n");
  } else {
    printf("São iguais.\n");
  }

  return 0;
}

