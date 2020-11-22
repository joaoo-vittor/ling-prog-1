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

// Funcao de potencia

// pow(); retorna a base elevada ao expoente
// sqrt(); retorna a raiz quadrada de um numero

int main() {
  int base = 2;
  int expo = 2;
  int num = 25;

  printf("O numero %d elevado a %d é %.2lf\n", base, expo, pow(base, expo));
  
  printf("A raiz quadrada de %d é %.2lf\n", num, sqrt(num));

  return 0;
}
