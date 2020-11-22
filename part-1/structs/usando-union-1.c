#include <stdio.h>
#include <string.h>

// A union, separa e utiliza apenas o espaço da maior variavel

union pessoa {
  char nome[100]; // char = 1 byte -> 1 * 100 = 100 bytes
  int idade; // 4 bytes -> total de 104 bytes
};


int main() {
  
  union pessoa pes;

  strcpy(pes.nome, "Joao Vitor Silva");
  printf("Dados de %s\n", pes.nome);

  pes.idade = 22;
  printf("Ela tem %d anos\n", pes.idade);
  printf("Ela tem %d anos\n", pes.idade);

  printf("Dados de %s\n", pes.nome);
  // o dado já foi sobrescrito por idade, por isso não é mostrado nada na variavel nome

  printf("A variavel 'pes' esta ocupando %ld bytes em memoria.\n", sizeof(pes));
  
  return 0;
}
