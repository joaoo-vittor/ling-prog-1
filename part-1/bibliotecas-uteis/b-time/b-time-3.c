#include <stdio.h>
#include <time.h>

// Funcoes de data e hora

// clock(); // retorna o numero de pulsos de clock decorridos desde que o programa foi lancado.
// time(); // retorna o tempo atual do calendario
// localtime(); // converte o valor tima para uma hora local

int main() {
  time_t tempoBruto;
  struct tm *info;

  time(&tempoBruto);

  info = localtime(&tempoBruto);

  printf("Data e Hora local %s\n", asctime(info));

  return 0;
}

