#include <stdio.h>

int main() {
  // vetores e string
  // char nome[50];
  // printf("Qual é seu nome: ");
  // scanf("%s",nome);

  // printf("%s\n", nome);

  // ###########################
  char letras[26];
  int i, j, index = 0;

  for (i = 97; i <= 122; i++) {
    letras[index] = i;
    index++;
  }

  for (j = 0; j < 26; j++) {
    printf("%c ", letras[j]);
  }
  printf("\n");


  return 0;
}
