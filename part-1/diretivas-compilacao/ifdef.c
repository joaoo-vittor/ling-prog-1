#include <stdio.h>

// Constantes
// #ifndef PI // verifica se a constante já foi criada e cria a constante;
//   #define PI 3.14567
// #endif

// ifndef -> Diretiva de Compilação

int main() {
  int valor = 5;
  valor = 365;

  printf("O valor e %d\n", valor);

  // printf("PI vale %f\n", PI);

  #ifdef PI // execulta o codigo do bloco, caso a constante PI exista
    printf("O valor de PI é %f\n", PI);
  #endif

  return 0;
}

// gcc nomeDoArquivo.c -o nomeDoExecutavel
