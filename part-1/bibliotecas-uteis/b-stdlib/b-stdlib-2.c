#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// atof(); // converte string para double
// atoi(); // converte string para inteiro

int main() {
  char valor_s[5];
  int valor_i;

  strcpy(valor_s, "45");

  valor_i = atoi(valor_s);

  printf("O valor é %d\n", valor_i);

  return 0;
}

