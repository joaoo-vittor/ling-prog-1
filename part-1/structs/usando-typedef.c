#include <stdio.h>

int main() {
  typedef float nota;

  // Declatando variaveis
  nota prova1 = 7.5;
  nota prova2 = 6.8;


  nota media = (prova1 + prova2) / 2;

  printf("A media das notas é %.2f\n", media);

  return 0;
}
