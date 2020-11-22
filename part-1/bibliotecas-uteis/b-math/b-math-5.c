#include <stdio.h>
#include <math.h>

// funcao trigonometricas
// tem que compilar na mao
//  gcc b-math-1.c -o b-math-1 -lm

// cos(); // calcula o cosseno de um angulo em radianos
// sin(); // calcula o seno de um angulo em radianos
// tan(); // calcula o tangente de um angulo em radianos

// Funcoes hiberbolicas

// cosh(); // calcula o coseno hiperbolico de um angulo em radianos
// sinh(); // calcula o seno hiperbolico de um angulo em radianos
// tanh(); // calcula o tangente hiperbolico de um angulo em radianos

// Funcao exponenciacao e logaritmicas

// exp(); // calculo exponencial


int main() {
  double num1 = 4;
  double num2 = 2;

  printf("O exponencial de %lf é %lf\n", num1, exp(num1));
  printf("O exponencial de %lf é %lf\n", num2, exp(num2));

  return 0;
}
