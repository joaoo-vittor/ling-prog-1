#include <stdio.h>
#include "ajuda.h"


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
