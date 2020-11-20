#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct dadoNo {
  int codigo;
  char nome[20];
  int tamArq;
  // int tempoFila;
} DadoNo;


typedef struct no {
  DadoNo dado;
  struct no * prox;
} No;


typedef struct fila {
  int tamFila;
  No * cabeca;
} Fila;


Fila * criaFila();
int menu();
void opcao(int opcao, Fila * fila);
void cadastraCliente(Fila * fila);
void atenderCliente(Fila * fila);
void inserir(Fila * fila, DadoNo dado);
void exiberFila(Fila * fila);
void removeNo(Fila * fila);
int vazia(Fila * fila);
No * posicaoNo(Fila * fila, int indice);
int indiceNo(Fila * fila, No * no);
void removePorIndice(Fila * fila, int indice);
void inserirPorIndice(Fila * fila, DadoNo dado, int indice);
void tracaDoisNos(Fila * fila, int indicePrimeiroNo, int indiceSegundoNo);
void limpabuffer();


int main() {

  Fila * fila = criaFila();

  int op;

  do {
    op = menu();
    opcao(op, fila);
    op = 0;
  } while (opcao);

  return 0;
}


void limpabuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {};
}


Fila * criaFila() {
  Fila * fila = (Fila*) malloc(sizeof(Fila));

  fila->tamFila = 0;
  fila->cabeca = NULL;

  return fila;
}


void inserir(Fila * fila, DadoNo dado) {
  No * no = (No*) malloc(sizeof(No));

  if (fila->tamFila == 0) {
    no->dado = dado;
    no->prox = NULL;
    fila->cabeca = no;
    fila->tamFila++;
  } else {
    No * temp = fila->cabeca;
    while (temp->prox != NULL) {
      temp = temp->prox;
    }
    no->prox = NULL;
    no->dado = dado;
    temp->prox = no;
  }
}


void exiberFila(Fila * fila) {
  if (vazia(fila)) {
    printf("\n Lista vazia\n");
    sleep(3);
    system("clear");
    return;
  }

  No * apontador = fila->cabeca;

  system("clear");

  printf(" Fila de atendimento: \n\n");

  while (apontador != NULL) {
    printf(" | Codigo: %d, Nome: %s, Tamanho do arquivo: %d | <- ", apontador->dado.codigo, strtok(apontador->dado.nome, "\n"), apontador->dado.tamArq);
    apontador = apontador->prox;
  }

  printf("\n\n");
}


void removeNo(Fila * fila) {
  if (!vazia(fila)) {
    No * auxPonteiro = fila->cabeca;
    fila->cabeca = auxPonteiro->prox;
    free(auxPonteiro);
    fila->tamFila--;
  }
}


No * posicaoNo(Fila * fila, int indice) {
  if (indice >= 0 && indice <= fila->tamFila-1) {
    No * auxNo = fila->cabeca;
    int i;

    for (i = 0; i < indice; i++) {
      auxNo = auxNo->prox;
    }

    return auxNo;
  }

  printf("Indice invalidado!\n");
  return NULL;
}


void removePorIndice(Fila * fila, int indice) {
  if (indice == 0) {
    removeNo(fila);
  } else {
    No * atual = posicaoNo(fila, indice);

    if (atual != NULL) {
      No * anterior = posicaoNo(fila, indice-1);
      anterior->prox = atual->prox;

      free(atual);
      fila->tamFila--;
    }
  }
}


int indiceNo(Fila * fila, No * no) {
  if (no != NULL) {
    No * auxPonteiro = fila->cabeca;

    int indice = 0;
    while (auxPonteiro != no & auxPonteiro != NULL) {
      auxPonteiro = auxPonteiro->prox;
      indice++;
    }

    if (auxPonteiro != NULL) {
      return indice;
    }
  }
  printf("no não pertence a fila\n");
  return -1;
}


void inserirPorIndice(Fila * fila, DadoNo dado, int indice) {
  if (indice == 0) {
    inserir(fila, dado);
  } else {
    No * atual = posicaoNo(fila, indice);

    if (atual != NULL) {
      No * anterior = posicaoNo(fila, indice-1);

      No * novoNo = (No*) malloc(sizeof(No));

      novoNo->dado = dado;

      anterior->prox = novoNo;
      novoNo->prox = atual;
      fila->tamFila++;
    }
  }
}


void tracaDoisNos(Fila * fila, int indicePrimNo, int indiceSegNo) {

  No * primeiroNo = posicaoNo(fila, indicePrimNo);
  No * segundoNo = posicaoNo(fila, indiceSegNo);
  
  if (primeiroNo == NULL || segundoNo == NULL) {
    printf("indice invalido"); 
    return;
  }

  if (primeiroNo == segundoNo) {
    return;
  }

  int indicePrimeiroNo = indicePrimNo;
  int indiceSegundoNo = indiceSegNo;

  if (indicePrimeiroNo == -1 || indiceSegundoNo == -1) {
    return;
  }

  if (indicePrimeiroNo > indiceSegundoNo) {
    primeiroNo = segundoNo;
    segundoNo = posicaoNo(fila, indicePrimeiroNo);

    indicePrimeiroNo = indiceSegundoNo;
    indiceSegundoNo = indiceNo(fila, segundoNo);
  }

  No * anteriorSegundoNo = posicaoNo(fila, indiceSegundoNo-1);
  
  if (primeiroNo == fila->cabeca) {
    fila->cabeca = segundoNo;
  } else {
    No * anteriorPrimeiroNo = posicaoNo(fila, indicePrimeiroNo-1);
    anteriorPrimeiroNo->prox = segundoNo;
  }

  anteriorSegundoNo->prox = primeiroNo;

  No * auxPonteiro = primeiroNo->prox;

  primeiroNo->prox = segundoNo->prox;
  segundoNo->prox = auxPonteiro;

}


int vazia(Fila * fila) {
  if (fila->cabeca == NULL) {
    return 1;
  }
  return 0;
}


int menu() {
  int opcao = 0;

  printf(" ========= CriptEx =========\n");
  printf(" 1 - Cadastra Cliente\n");
  printf(" 2 - Listar Cliente\n");
  printf(" 3 - Atender Cliente\n");
  printf(" 4 - sair\n");
  printf(" opção: ");
  scanf("%d", &opcao);

  return opcao;
}


void opcao(int opcao, Fila * fila) {
  switch (opcao) {
    case 1:
      cadastraCliente(fila);
      break;
    case 2:
      exiberFila(fila);
      break;
    case 3:
      removeNo(fila);
      break;
    case 4:
      exit(1);
    default:
      printf(" Opção invalida!\n");
      break;
  }
}

void cadastraCliente(Fila * fila) {
  DadoNo dado;

  system("clear");
  limpabuffer();

  printf(" insira o nome do cliente: ");
  fgets(dado.nome, 20, stdin);

  printf(" insira o codigo do cliente: ");
  scanf("%d", &dado.codigo);

  printf(" insira o tamanho do arquivo: ");
  scanf("%d", &dado.tamArq);

  inserir(fila, dado);
  limpabuffer();
  system("clear");
}


// void atenderCliente();