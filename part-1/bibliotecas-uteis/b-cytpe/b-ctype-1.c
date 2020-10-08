#include <stdio.h>
#include <ctype.h>

// Teste de tipos de caracteres

// isalnum(); // verifica se o caractere é aflanumerico (abc123)
// isalpha(); // verifica se o caracrete é alfabetico (abcde...)
// isdigit(); // verifica se o caractere é um digito decimal (0123...)
// ispunct(); // verifica se o carectere é um pontuacao (?!.)
// isspace(); // se é um espaço ( )
// isupper(); // se é maiuscula (ABCD)
// islower(); // se e minusculo (abcd)
// tolower(); // Converte para minuscula
// toupper(); // converte para maiuscula

int main() {
  char teste1 = '4';
  char teste2 = 'c';
  char teste3 = '4';
  char teste4 = '?'; 
  char teste5 = ' ';
  char teste6 = 'A';
  char teste7 = 'b';


  if (isalnum(teste1)) {
    printf("E alfanumerico\n");
  } else {
    printf("Não e alfanumerico\n");
  }

  if (isalpha(teste2)) {
    printf("E alfabetico\n");
  } else {
    printf("Não e alfabetico\n");
  }

  if (isdigit(teste3)) {
    printf("E digito decimal\n");
  } else {
    printf("Não e digito decimal\n");
  }

  if (ispunct(teste4)) {
    printf("E pontuacao\n");
  } else {
    printf("Não e pontuacao\n");
  }

  if (isspace(teste5)) {
    printf("E espaco\n");
  } else {
    printf("Não e espaco\n");
  }

  if (isupper(teste6)) {
    printf("E espaco\n");
  } else {
    printf("Não e espaco\n");
  }

  printf("Antes: %c, Depois: %c\n", teste6, tolower(teste6));
  printf("Antes: %c, Depois: %c\n", teste7, toupper(teste7));

  return 0; 
}
