#include <stdio.h>

int main() {
  // inteiros
  int nota1, nota2; // 5, 8, 9

  // reais
  float media; // 23.55, 48.484
  // double outraMedia; // capacidade em memoria o dobro de float

  printf("Insira a primeira nota: \n");
  scanf("%d", &nota1);

  printf("Insira a segunda nota: \n");
  scanf("%d", &nota2);

  media = (nota1 + nota2) / 2;

  printf("A media das notas é %.2f\n", media);

  return 0;
}
