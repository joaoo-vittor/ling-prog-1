#include <stdio.h>

/*

[linha|coluna]

[0,0][0,1][0,2][0,3][0,4]
[1,0][1,1][1,2][1,3][1,4]
[2,0][2,1][2,2][2,3][2,4]
[3,0][3,1][3,2][3,3][3,4]
[4,0][4,1][4,2][4,3][4,4]

*/


int main() {
  char nome[3][50];
  int i;

  for (i = 0; i < 3; i++) {
    printf("Qual e seu nome: ");
    scanf("%s", nome[i]);
  }

  for (i = 0; i < 3; i++) {
    printf("Olá, %s\n", nome[i]);
  }

  return 0;
}
