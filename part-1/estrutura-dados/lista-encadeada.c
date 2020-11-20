#include <stdio.h>
#include <stdlib.h>

/*

  no              no           no
+---+--+      +---+--+     +---+--+
| 1 |  | ->   | 4 |  | ->  | 7 |  | -> NULL
+---+--+      +---+--+     +---+--+
*/

struct st_no {
  int valor;
  struct st_no * prox;
};


typedef struct st_no no;


int vazia(no * list_enc) {
  if (list_enc->prox == NULL) {
    return 1;
  } 
  return 0;
}


void inicia(no * list_enc) {
  list_enc->prox = NULL;
}


void libera(no * list_enc) {
  if(!vazia(list_enc)) {
    no * proxNo, * atual;
    atual = list_enc->prox;
    while (atual != NULL) {
      proxNo = atual->prox;
      free(atual);
      atual = proxNo;
    }
  }
}


void exibe(no * list_enc) {
  if (vazia(list_enc)) {
    printf("Lista esta vazia!\n\n");
    return;
  }
  no * temp;
  temp = list_enc->prox;

  while(temp != NULL) {
    printf("%5d", temp->valor);
    temp = temp->prox;
  }
  printf("\n\n");
}


void insereInicio(no * list_enc) {
  no * novoNo = (no*) malloc(sizeof(no));

  if (!novoNo) {
    printf("Sem memoria disponivel!\n");
    exit(1);
  }

  printf("Informe um valor: ");
  scanf("%d", &novoNo->valor);

  no * noAnterior = list_enc->prox;
  list_enc->prox = novoNo;
  novoNo->prox = noAnterior;
}




void insereFinal(no * list_enc) {
  no * novoNo = (no*) malloc(sizeof(no));

  if (!novoNo) {
    printf("Sem memoria disponivel!\n");
    exit(1);
  }

  printf("Informe um valor: ");
  scanf("%d", &novoNo->valor);

  novoNo->prox = NULL;

  if (vazia(list_enc)) {
    list_enc->prox = novoNo;
  } else {
    no * temp = list_enc->prox;
    while(temp->prox != NULL) {
      temp = temp->prox;
    }
    temp->prox = novoNo;
  }
}


void opcao(no * list_enc, int op) {
  switch (op) {
    case 0:
      libera(list_enc);
      break;
    case 1:
      exibe(list_enc);
      break;
    case 2:
      insereInicio(list_enc);
      break;
    case 3:
      insereFinal(list_enc);
      break;
    case 4:
      inicia(list_enc);
      break;
    default:
      printf("Opção invalida!\n\n");
      break;
  }
}


int menu() {
  int opc;

  printf("Escolha a opcao: \n");
  printf("[0] - Sair: \n");
  printf("[1] - Exibir: \n");
  printf("[2] - Adicionar nó no inicio: \n");
  printf("[3] - Adicionar nó no fim: \n");
  printf("[4] - Zerar lista: \n");
  printf("Opção: ");
  scanf("%d", &opc);

  return opc;
}

int main() {

  no * list_enc = (no*) malloc(sizeof(no));

  if (!list_enc) {
    printf("Sem memoria disponivel! \n\n");
    exit(1);
  }

  inicia(list_enc);
  int opc;

  do {
    opc = menu();
    opcao(list_enc, opc);
  } while (opc != 0);

  free(list_enc);

  return 0;
}