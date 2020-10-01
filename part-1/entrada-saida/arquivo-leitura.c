#include <stdio.h>

int main() {
  FILE *arq;
  char nome[10], *result;

  arq = fopen("arquivo.txt", "r"); // r -> leitura de arquivo

  if (arq) {
    while(!feof(arq)) {
      result = fgets(nome, 10, arq);
      if (result) {
        printf("nome %s\n", nome);
      }
    }
  } else {
    printf("Arquivo nao encontrado\n");
  }

  fclose(arq);

  return 0;
}
