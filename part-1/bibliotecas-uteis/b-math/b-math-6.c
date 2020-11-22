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
// log(); // logaritmo natural
// log10(); // logaritmo base 10


int main() {
  int num1 = 42;

  printf("O log de %d é %lf\n", num1, log(num1));
  printf("O log na base 10 de %d é %lf\n", num1, log10(num1));

  return 0;
}
