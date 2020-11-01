#include <stdio.h>

int main() {

  FILE *arq;

                              //  w -> forma de abertura;
  arq = fopen("nomeArquivo.txt", "w");

  fclose(arq);

  return 0;
}