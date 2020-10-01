#include <stdio.h>

int main() {
  FILE *arq;
  char fruta[10];

  arq = fopen("frutas.txt", "w "); // w -> leitura de arquivo 
                                   // a -> append

  if (arq) {
    printf("Informe uma fruta, ou 0 para sair: \n");
    fgets(fruta, 10, stdin);
    while(fruta[0] != '0') {
      fputs(fruta, arq);
      printf("Informe uma fruta, ou 0 para sair: \n");
      fgets(fruta, 10, stdin);
    }
  } else {
    printf("Arquivo nao encontrado\n");
  }

  fclose(arq);

  return 0;
}
