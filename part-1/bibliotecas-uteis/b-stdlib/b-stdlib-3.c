#include <stdio.h>
#include <string.h>

#include <stdlib.h>
// Converção de string

// atof(); // converte string para double
// atoi(); // converte string para inteiro
// atol(); // converte string para long float


int main() {
  char valor_s[500];
  double valor_li;

  strcpy(valor_s, "456216511816181");

  valor_li = atol(valor_s);

  printf("O valor é %lf\n", valor_li);

  return 0;
}

