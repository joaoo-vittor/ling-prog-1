#include <stdio.h>

int main() {
  float matriz[12][12];
  int i, j, cont = 0;
  char opcao;
  float soma = 0, media = 0, elemento;

  scanf("%c", &opcao);

  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      scanf("%f", &elemento);
      matriz[i][j] = elemento;
    }
  }

  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      if (i < j) {
        soma += matriz[i][j];
        cont++;
      }
    }
  }

  if (opcao == 'S') {
    printf("%.1f\n", soma);
  } else {
    if (opcao == 'M') {
      printf("%.1f\n", soma / cont);
    }
  }

  return 0;
}
