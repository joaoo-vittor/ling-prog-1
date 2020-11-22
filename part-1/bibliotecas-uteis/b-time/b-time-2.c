#include <stdio.h>
#include <time.h>

// Funcoes de data e hora

// clock(); // retorna o numero de pulsos de clock decorridos desde que o programa foi lancado.
// time(); // retorna o tempo atual do calendario

int main() {
  time_t segundos;

  segundos = time(NULL);
  printf("Horas desde 1 de janeiro de 1970 = %ld\n", segundos/3600);

  return 0;
}

