#include <stdio.h>

// Enum -> Enumeração

enum dias_da_semana {
  segunda,
  terca,
  quarta,
  quinta,
  sexta,
  sabado,
  domingo
};

int main() {

  enum dias_da_semana d1, d2;

  d1 = quinta;
  d2 = 4;

  if (d1 == d2) {
    printf("Os dias sao iguais...\n");
  } else {
    printf("Os dias nao sao iguais...\n");
  }

  return 0;
}
