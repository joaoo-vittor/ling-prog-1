#include <stdio.h>

int main() {
  int num;

  printf("Informe um numero: ");

  scanf("%d", &num);

  printf("Numero informado %d\n", num);
  printf("Endereco de memoria %d\n", &num);

  return 0;
}
