#include <stdio.h>
#include <string.h>

// Operação em string

// strcpy(); // copia de string
// strcat(); // concatena string

int main() {
  
  char str1[20], str2[20];

  strcpy(str1, "Quinta-");
  strcpy(str2, "Feira");

  strcat(str1, str2);

  printf("%s\n", str1);

  return 0;
}

