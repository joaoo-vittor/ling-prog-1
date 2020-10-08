#include <stdio.h>
#include <time.h>

// Funcoes de data e hora

// clock(); // retorna o numero de pulsos de clock decorridos desde que o programa foi lancado.

int main() {
  long int inicio_t, fim_t, total_t;

  inicio_t = clock();

  printf("Realizar um loop grande, inicio_t = %ld\n", inicio_t);
  for (int i = 0; i <= 100000000; i++) {} 

  fim_t = clock();
  printf("Realizar um loop grande, fim_t = %ld\n", fim_t);

  total_t = (double)((double)fim_t - (double)inicio_t) / (double)CLOCKS_PER_SEC;

  printf("Clocks por segundo: %ld\n", CLOCKS_PER_SEC);
  printf("Tempo total usado pela CPU: %lf\n", (double)total_t);
  printf("Finalizando o programa!\n");

  return 0;
}

