#include <stdio.h>


int main() {
  char opcao;
  int i;


  printf("Informe uma opcao: \n");
  printf("a -  Saldo da conta. \n");
  printf("b - Extrato da canta. \n");
  printf("c - Limite da conta. \n");
  scanf("%c", &opcao);


  if (opcao == 'a') {
    printf("Seu Saldo é....\n");
  } else if (opcao == 'b') {
    printf("Seu Extrato é....\n");
  } else if (opcao == 'c') {
    printf("Seu Limite é....\n");
  } else {
    printf("Opcao invalida!\n");
  }


  for (i = 97; i <= 122; i++) {
    printf("%c\n", i);
  }


  return 0;
}

