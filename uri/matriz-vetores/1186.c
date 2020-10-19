#include <stdio.h>

/*

[linha|coluna]

 i j  i j  i j  i j  i j
[0,0][0,1][0,2][0,3][0,4]
 i j  i j  i j  i j  i j
[1,0][1,1][1,2][1,3][1,4]
 i j  i j  i j  i j  i j
[2,0][2,1][2,2][2,3][2,4]
 i j  i j  i j  i j  i j
[3,0][3,1][3,2][3,3][3,4]
 i j  i j  i j  i j  i j
[4,0][4,1][4,2][4,3][4,4]

*/

int main() {
  float matriz[12][12];
  int i, j, cont = 0, aux = 0;
  char opcao;
  float soma = 0, media = 0, elemento;

  scanf("%c", &opcao);

  for (i = 0; i < 12; i++) {
    for (j = 0; j < 12; j++) {
      scanf("%f", &elemento);
      matriz[i][j] = elemento;
    }
  }


  for (i = 1; i < 12; i++) {
    j = 11;
    while (i != 12 - j - 1) {
      soma += matriz[i][j];
      cont++;
      j--;
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
