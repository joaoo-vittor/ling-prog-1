#include <stdio.h>
#include <time.h>

// Funcoes de data e hora

// clock(); // retorna o numero de pulsos de clock decorridos desde que o programa foi lancado.
// time(); // retorna o tempo atual do calendario
// localtime(); // converte o valor tima para uma hora local

int main() {
  
  time_t segundos;
  struct tm * dataHoraAtual;

  time(&segundos);

  dataHoraAtual = localtime(&segundos);

  // printf("%s\n", asctime(info));

  printf(" %d:%d:%d \n", dataHoraAtual->tm_hour, dataHoraAtual->tm_min, dataHoraAtual->tm_sec);
  printf(" %d/%d/%d \n", dataHoraAtual->tm_mday, dataHoraAtual->tm_mon+1, dataHoraAtual->tm_year+1900);

  return 0;
}

