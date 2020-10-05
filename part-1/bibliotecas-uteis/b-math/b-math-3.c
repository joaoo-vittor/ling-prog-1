#include <stdio.h>
#include <math.h>

// funcao trigonometricas
// tem que compilar na mao
//  gcc b-math-1.c -o b-math-1 -lm

// cos(); // calcula o cosseno de um angulo em radianos
// sin(); // calcula o seno de um angulo em radianos
// tan(); // calcula o tangente de um angulo em radianos


int main() {
  int angulo = 45;

  float resp = tan(angulo);

  printf("O tangente de %d é %f\n", angulo, resp);

  return 0;
}
