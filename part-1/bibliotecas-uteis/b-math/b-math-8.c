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

// ceil(); // arredonda para cima um numero
// floor(); // arredonda para baixo um numero

int main() {
  double num1 = 4.73423;
  double num2 = 9.72351;

  printf("O valor %lf arredondado para cima é %lf\n", num1, ceil(num1));
  printf("O valor %lf arredondado para baixo é %lf\n", num2, floor(num2));

  return 0;
}
