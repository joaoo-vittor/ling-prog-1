#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//  gcc main1.c -o main -lm
// prototipação
void menu();

void menuInt();
void tipoTriango();
void senCosTg();


void menuString();
void palindromo();
void senhaValida();


void menuArray();
void menorPosicao();
void inverteArray();


void menuMatriz();
void somEleAbaiDiag();
void somEleDiag();



int main() {
  menu();
  return 0;
}

// menu principal

void menu() {
  char opcao;
  do {
    printf("\t\t\tMENU  PRINCIPAL\n");
    printf("\t\t====================================\n");
    printf("\t\ta - Manipulando Inteiro.\n");
    printf("\t\tb - Manipulando String.\n");
    printf("\t\tc - Manipulando Vetor.\n");
    printf("\t\td - Manipulando Matriz.\n");
    printf("\t\ts - Para Sair.\n");
    printf("\t\tOpção: ");
    fflush(stdin);
    scanf(" %c", &opcao);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': menuInt(); break;
      case 'b':
      case 'B': menuString(); break;
      case 'c':
      case 'C': menuArray(); break;
      case 'd':
      case 'D': menuMatriz(); break;
      case 's':
      case 'S': exit(0);
      default:
        puts("\n\t\tOpção INVALIDA!!!\n");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}


// menu Inteiro 

void menuInt() {
  char opcao;
  do {
    printf("\t\t\tMANIPULAÇÃO DE INTEIRO\n");
    printf("\t\t====================================\n");
    printf("\t\ta - Tipo de triangulo.\n");
    printf("\t\tb - Seno Cosseno Tangente e Quadrante.\n");
    printf("\t\ts - Voltar para menu anterior.\n");
    printf("\t\tOpção: ");
    fflush(stdin);
    scanf(" %c", &opcao);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': tipoTriango(); break;
      case 'b':
      case 'B': senCosTg(); break;
      case 's':
      case 'S': menu();
      default:
        puts("\n\t\tOpção INVALIDA!!!\n");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}

// Inicio inteiro 

void tipoTriango() {
  int lado_a, lado_b, lado_c;

  fflush(stdin);
  printf("\t\tDigite os 3 lados (a, b, c) do triangulo: ");
  scanf("%d%d%d", &lado_a, &lado_b, &lado_c);
  getchar();

  if (lado_a != lado_b && lado_b != lado_c && lado_c != lado_a) {
    printf("\t\tÉ um triângulo é escaleno\n");
  } else if (lado_a == lado_b && lado_a != lado_c && lado_b != lado_c) {
    printf("\t\tÉ um triângulo é isósceles\n");
  } else if (lado_a == lado_b && lado_b == lado_c && lado_a == lado_c) {
    printf("\t\tÉ um triângulo é equilátero\n");
  }

  fflush(stdin);
  
  menuInt();
}


void senCosTg() {
  int angulo;

  fflush(stdin);
  printf("\t\tDigite um angulo: ");
  scanf("%d", &angulo);
  getchar();

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

  fflush(stdin);

  menuInt();
}

// Fim inteiro

// Menu String

void menuString() {
  char opcao;
  do {
    printf("\t\t\tMANIPULAÇÃO DE STRING\n");
    printf("\t\t====================================\n");
    printf("\t\ta - E palindromo.\n");
    printf("\t\tb - Validar senha.\n");
    printf("\t\ts - Voltar para menu anterior.\n");
    printf("\t\tOpção: ");
    fflush(stdin);
    scanf(" %c", &opcao);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': palindromo(); break;
      case 'b':
      case 'B': senhaValida(); break;
      case 's':
      case 'S': menu();
      default:
        puts("\n\t\tOpção INVALIDA!!!\n");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}

// Inicio String

void senhaValida() {
  int caracterEsp = 0, tam = 0, maiuscula = 0, minuscula = 0, tamanho;
  char senha[1000];
  int i;

  fflush(stdin);
  printf("\t\tATENÇÃO\n");
  printf("\t\tA senha deve conter, no mínimo, uma letra maiúscula, uma letra minúscula e um número\n");
  printf("\t\tA mesma não pode ter nenhum caractere de pontuação, acentuação ou espaço;\n");
  printf("\t\tAlém disso, a senha pode ter de 6 a 32 caracteres.\n");
  printf("\t\tInsira uma senha: ");
  scanf("%s", senha);
  getchar();
  
  tam = strlen(senha);
  tamanho = 1;

  if (6 > tam || tam > 32) {
    tamanho = 0;
  }

  for (i = 0; i < tam; i++) {
    if (isupper(senha[i]) != 0) {
      maiuscula++;
    } else if (islower(senha[i]) != 0) {
      minuscula++;
    } else if ((senha[i] >= 32 && senha[i] <= '/') || senha[i] > 58 && senha[i] > 40) {
      caracterEsp++;
    }
  }

  if (tamanho == 1 && maiuscula != 0 && minuscula != 0 && caracterEsp == 0) {
    printf("\t\tSenha valida!\n");
  } else {
    printf("\t\tSenha invalida!\n");
  }

  fflush(stdin);

  menuString();
}

void palindromo() {
  char palavra[1000];
  int i, j;
  int tam;
  int pali = 0;

  fflush(stdin);
  printf("\t\tInsira uma palavra: ");
  scanf("%s", palavra);
  getchar();

  tam = strlen(palavra);

  j = tam - 1;
  for (i = 0; i < tam; i++) {
    if (palavra[i] == palavra[j]) {
      pali++;
    }
    j--;
  }

  if (tam == pali) {
    printf("\t\tA palavra é palindromo.\n");
  } else {
    printf("\t\tA palavra não é palindromo.\n");
  }
  
  fflush(stdin);
  
  menuString();
}

// Fim string


// Menu array 


void menuArray() {
  char opcao;

  do {
    printf("\t\t\tMANIPULAÇÃO DE ARRAY\n");
    printf("\t\t====================================\n");
    printf("\t\ta - Menor e Posição.\n");
    printf("\t\tb - Inverter array.\n");
    printf("\t\ts - Voltar para menu anterior.\n");
    printf("\t\tOpção: ");
    scanf(" %c", &opcao);
    fflush(stdin);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': menorPosicao(); break;
      case 'b':
      case 'B': inverteArray(); break;
      case 's':
      case 'S': menu();
      default:
        puts("\n\t\tOpção INVALIDA!!!\n");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}

// inicio array

void menorPosicao() {
  int a, num, posicao, menor, i;

  char opc;
  
  time_t t;

  // inicializar o gerador 
  srand((unsigned) time(&t));

  printf("\t\tInsira o tamanho do array: ");
  scanf("%d", &num);

  getchar();
  printf("\t\tVoce quer gerar o array automaticamente [s]sim e [n]não: ");
  scanf("%c", &opc);

  int matriz[num];

  if (opc == 's' || opc == 'S') {
    // Gerar 6 numero entre 0 e 60
    for (i = 0; i < num; i++) {
      matriz[i] = (rand() % 99); 
    }
  } else {
    for (i = 0; i < num; i++) {
      printf("\t\tInsira manualmente o numero na posição %d -> ", i + 1);
      scanf("%d", &matriz[i]); 
    }
  }

  printf("\t\t[ ");
  for (i = 0; i < num; i++) {
    printf("%d ", matriz[i]);
  }
  printf("]\n");

  menor = matriz[0];

  for(a = 1; a < num; a++) {
    if(menor> matriz[a]) {
      menor = matriz[a];
      posicao = a;
    }
  }
  printf("\t\tMenor valor: %d\n", menor);
  printf("\t\tPosicao: %d\n", posicao + 1);
  
  fflush(stdin);

  menuArray();
}

void inverteArray() {
  int i, j = 0, num, posicao, menor;
  int aux;

  fflush(stdin);

  // printf("\t\tInsira o tamanho do array: ");
  // scanf("%d", &num);
  // getchar();

  // int arr[num];
  // for(i = 0; i < num; i++) {
  //   printf("\t\tInsira o elemento n°%d ", i+1);
  //   scanf("%d", &arr[i]);
  //   fflush(stdin);
  // } 

  char opc;
  
  time_t t;

  // inicializar o gerador 
  srand((unsigned) time(&t));

  printf("\t\tInsira o tamanho do array: ");
  scanf("%d", &num);

  getchar();
  printf("\t\tVoce quer gerar o array automaticamente [s]sim e [n]não: ");
  scanf("%c", &opc);

  int arrInv[num];
  int matriz[num];

  if (opc == 's' || opc == 'S') {
    // Gerar 6 numero entre 0 e 60
    for (i = 0; i < num; i++) {
      matriz[i] = (rand() % 99); 
    }
  } else {
    for (i = 0; i < num; i++) {
      printf("\t\tInsira manualmente o numero na posição %d -> ", i + 1);
      scanf("%d", &matriz[i]); 
    }
  }

  printf("\t\tArray gerado    [ ");
  for (i = 0; i < num; i++) {
    printf("%d ", matriz[i]);
  }
  printf("]\n");


  j = num - 1;
  for (i = 0; i < num; i++) {
    arrInv[i] = matriz[j];
    j--;
  }

  printf("\t\tArray invertido [ ");
  for (i = 0; i < num; i++) { 
    printf("%d ", arrInv[i]);
  }
  printf("]");

  printf("\n");

  fflush(stdin);

  menuArray();
}

// Fim array

// Menu Matriz

void menuMatriz() {
  char opcao;
  do {
    printf("\t\t\tMANIPULAÇÃO DE MATRIZ\n");
    printf("\t\t====================================\n");
    printf("\t\tOBS: As matrizes são geradas automaticamentes e depois de\n");
    printf("\t\t\tselecionado a opção os calculos seram realizados.\n");
    printf("\t\ta - Soma dos Elementos abaixo diagonal.\n");
    printf("\t\tb - Soma dos Elementos da diagonal.\n");
    printf("\t\ts - Voltar para menu anterior.\n");
    printf("\t\tOpção: ");
    fflush(stdin);
    scanf(" %c", &opcao);
    getchar();

    switch (opcao) {
      case 'a':
      case 'A': somEleAbaiDiag(); break;
      case 'b':
      case 'B': somEleDiag(); break;
      case 's':
      case 'S': menu();
      default:
        puts("\n\t\tOpção INVALIDA!!!\n");
        break;
    }
    getchar();
  } while (opcao != 's' || opcao != 'S');
}

// Inicio Matriz

void somEleAbaiDiag() {
  int i, j;
  int soma = 0;
  int num;

  time_t t;

  // inicializar o gerador 
  srand((unsigned) time(&t));

  fflush(stdin);
  printf("\t\tInsira o tamanho da matriz quadrada NxN: ");
  scanf("%d", &num);
  getchar();


  int matriz[num][num];
  // Gerar 6 numero entre 0 e 99
  for (i = 0; i < num; i++) {
    for (j = 0; j < num; j++) {
      matriz[i][j] = (rand() % 99); 
    }
  }

  for (i = 0; i < num; i++) {
    printf("\t\t");
    for (j = 0; j < num; j++) {
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < num; i++) {
    for (j = 0; j < num; j++) {
      if (i > j) {
        soma += matriz[i][j];
      }
    }
  }

  printf("\t\tA soma abaixo da diagonal: %d\n", soma);
  
  fflush(stdin);

  menuMatriz();
}

void somEleDiag() {
  int i, j;
  int soma = 0;
  int num;
  
  time_t t;

  // inicializar o gerador 
  srand((unsigned) time(&t));

  fflush(stdin);
  printf("\t\tInsira o tamanho da matriz quadrada NxN: ");
  scanf("%d", &num);
  getchar();
  
  int matriz[num][num];
  // Gerar 6 numero entre 0 e 60
  for (i = 0; i < num; i++) {
    for (j = 0; j < num; j++) {
      matriz[i][j] = (rand() % 99); 
    }
  }

  for (i = 0; i < num; i++) {
    printf("\t\t");
    for (j = 0; j < num; j++) {
      printf("%d\t", matriz[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < num; i++) {
    for (j = 0; j < num; j++) {
      if (i == j) {
        soma += matriz[i][j];
      }
    }
  }

  printf("\t\tA soma dos elementos da diagonal: %d\n", soma);

  fflush(stdin);

  menuMatriz();
}
