#include <stdio.h>

int fibo(int num);

int main() {
  int tamanho, i;

  printf("Informe o tamanho da sequencia fibonacci: ");
  scanf("%d", &tamanho);

  for (i = 0; i < tamanho; i++) {
    printf("%d ", fibo(i + 1));
  }
  printf("\n");

  return 0;
}

int fibo(int num) {
  if (num == 0) {
    return 0;
  }

  if (num == 1) {
    return 1;
  }

  return fibo(num - 1) + fibo(num - 2);
}
