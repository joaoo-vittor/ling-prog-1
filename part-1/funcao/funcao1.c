#include <stdio.h>

// Prototipacao

int soma(int num1, int num2);
float divide(float num1, float num2);

int main() {
  float div;

  printf("%d\n", soma(5, 8));

  div = divide(5.8, 2);
  if (!div) {
    printf("Não pode dividir por ZERO!\n");
  } else {
    printf("%.2f\n", div);
  }

  return 0;
}

int soma(int num1, int num2) {
  int result = num1 + num2;

  return result;
}

float divide(float num1, float num2) {
  float result;
  if (!num2) {
    return 0;
  }
  result = num1 / num2;
  return result;
}

