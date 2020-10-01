#include <stdio.h>

int main() {
  /*
    0   1    2    3    4
  +---+----+----+----+----+
  | 9 | 10 | 45 | 18 | 22 |
  +---+----+----+----+----+
  */
  
  int valores[5];
  int i;


  for (i = 0; i < 5; i++) {
    printf("Informe um numero: ");
    scanf("%d", &valores[i]);
  }

  printf("Os valores informados foram: \n");
  for (i = 0; i < 5; i++) {
    printf("Endereco de memoria %d\n", &valores[i]);
  }

  return 0;
}
