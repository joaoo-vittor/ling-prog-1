#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//  gcc b-math-1.c -o b-math-1 -lm
// prototipação
void menu();

void menuInt();
void tipoTriango();
void senCosTg();

void menuString();


void meuArray();
void menorPosicao();
void invertePosicao();

void menuMatriz();



int main() {
  menu();
  return 0;
}

// menu principal

void menu() {
  char opcao;
  do {
    printf("\t\t\tMENU  PRINCIPAL\n");
    printf("\t\t============================\n");
    printf("\t\ta - Manipulando Inteiro.\n");
    printf("\t\tb - Manipulando String.\n");
    printf("\t\tc - Manipulando Vetor.\n");
    printf("\t\td - Manipulando Matriz.\n");
    printf("\t\ts - Para Sair.\n");
    printf("\t\tOpção: ");
    
    scanf("%c", &opcao);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': menuInt(); break;
      case 'b':
      case 'B': puts("Listar de Alunos."); break;
      case 'c':
      case 'C': puts("Cadastra Curso."); break;
      case 'd':
      case 'D': puts("Listar Cursos."); break;
      case 's':
      case 'S': exit(0);
      default:
        puts("Opção INVALIDA!!!");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}


// menu Inteiro 

void menuInt() {
  char opcao;
  do {
    printf("\t\t\tMENU  PRINCIPAL\n");
    printf("\t\t============================\n");
    printf("\t\ta - Tipo de triangulo.\n");
    printf("\t\tb - Seno Cosseno Tangente e Quadrante.\n");
    printf("\t\ts - Voltar para menu anterior.\n");
    printf("\t\tOpção: ");
    fflush(stdin);
    scanf("%c", &opcao);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': tipoTriango(); break;
      case 'b':
      case 'B': senCosTg(); break;
      case 's':
      case 'S': menu();
      default:
        puts("Opção INVALIDA!!!");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}

// Inteiro

void tipoTriango() {
  int lado_a, lado_b, lado_c;

  printf("\t\tDigite os 3 lados (a, b, c) do triangulo: ");
  scanf("%d%d%d", &lado_a, &lado_b, &lado_c);


  // printf("a %d, b %d, c %d \n", lado_a, lado_b, lado_c);
  if (lado_a != lado_b && lado_b != lado_c && lado_c != lado_a) {
    printf("\t\tÉ um triângulo é escaleno\n");
  } else if (lado_a == lado_b && lado_a != lado_c && lado_b != lado_c) {
    printf("\t\tÉ um triângulo é isósceles\n");
  } else if (lado_a == lado_b && lado_b == lado_c && lado_a == lado_c) {
    printf("\t\tÉ um triângulo é equilátero\n");
  }

}


void senCosTg() {
  int angulo;

  printf("\t\tDigite um angulo: ");
  scanf("%d", &angulo);

  if (angulo >= 0) {
    printf("\t\tSeno de %d é %lf\n", angulo, sin(angulo));
    printf("\t\tCosseno de %d é %lf\n", angulo, cos(angulo));
    printf("\t\tTangente de %d é %lf\n", angulo, tan(angulo));
  }
  
  if (angulo > 0 && angulo < 90) {
    printf("\t\tO angulo de %d está no 1° quadrante.\n", angulo);
  } else if (angulo > 90 && angulo < 180) {
    printf("\t\tO angulo de %d está no 3° quadrante.\n", angulo);
  } else if (angulo > 180 && angulo < 270) {
    printf("\t\tO angulo de %d está no 1° quadrante.\n", angulo);
  } else if (angulo > 270 && angulo < 360) {
    printf("\t\tO angulo de %d está no 4° quadrante.\n", angulo);
  }

}

// Array

void menorPosicao() {
  int a, num, posicao, menor;

  scanf("%d", &num);

  int arr[num];
  for(a = 0; a < num; a++) {
    scanf("%d", &arr[a]);
  }

  menor = arr[0];

  for(a = 1; a < num; a++) {
    if(menor> arr[a]) {
      menor = arr[a];
      posicao = a;
    }
  }
  printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
  
  menu();
}


// void listarAluno();
