#include <stdio.h>

// Constantes
#ifndef PI // verifica se a constante já foi criada;
  #define PI 3.14567
#endif

// ifndef -> Diretiva de Compilação



int main() {
  int valor = 5;
  valor = 365;

  printf("O valor e %d\n", valor);

  printf("PI vale %f\n", PI);


  return 0;
}
