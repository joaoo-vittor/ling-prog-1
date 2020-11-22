#include <stdio.h>

int main() {

  int tamanho;
  int linha, coluna;
  int inicio = tamanho / 3;
  int fim = tamanho - inicio;

  while(scanf("%d", &tamanho) != EOF) {

    int matriz[tamanho][tamanho];

    for (linha = 0; linha < tamanho; linha++) {
      for (coluna = 0; coluna < tamanho; coluna++) {

        if (linha == coluna) {
          matriz[linha][coluna] = 2;
        } else if (linha == tamanho - coluna - 1) {
          matriz[linha][coluna] = 3;
        } else {
          matriz[linha][coluna] = 0;
        }

      }
    }

    for (linha = 0; linha < tamanho; linha++) {
      for (coluna = 0; coluna < tamanho; coluna++) {
        matriz[linha][coluna] = 1;
      }
    }

    matriz[tamanho/2][tamanho/2];

    for (linha = 0; linha < tamanho; linha++) {
      for (coluna = 0; coluna < tamanho; coluna++) {
        printf("%d", matriz[linha][coluna]);
      }
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}

