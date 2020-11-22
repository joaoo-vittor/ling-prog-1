#include <stdio.h>

int main() {

  FILE *arq;
  char nome[10]; 
  char *result;

  arq = fopen("nomeArquivo.txt", "r");

  if (arq) {
    while (!feof(arq)) {
      result = fgets(nome, 10, arq);
      printf("Valor da variavel 'result': %d\n", result);
      if (result) {
        printf("%s", nome);
      }
    }
  } else {
    printf("Não achei o arquivo\n");
  }

  fclose(arq);

  return 0;
}