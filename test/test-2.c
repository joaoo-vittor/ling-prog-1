#include <stdio.h>

int main() {

  FILE *arq;
  char nome;

  arq = fopen("nomeArquivo.txt", "r");

  if (arq) {
    while ((nome = getc(arq)) != EOF) {
      printf("%c", nome);
    }
  } else {
    printf("Não achei o arquivo\n");
  }
  
  fclose(arq);

  return 0;
}