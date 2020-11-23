#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dadoNo {
  int codigo;
  int tempo;
  char nome[20];
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
void inserir(Fila * fila, DadoNo dado);
void exiberFila(Fila * fila);
void ordena(Fila * fila, int tipo);
int vazia(Fila * fila);
void limpabuffer();


int main() {

  Fila * fila = criaFila();

  DadoNo dado;

  for (int i = 0; i < 4; i++) {
    printf("nome: ");
    fgets(dado.nome, 20, stdin);
    printf("Codigo prioridade: ");
    scanf("%d", &dado.codigo);
    dado.tempo = 0;
    inserir(fila, dado);
    limpabuffer();
  }
  
  exiberFila(fila);

  ordena(fila, 1);

  exiberFila(fila);

  return 0;
}


void limpabuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {};
}

int vazia(Fila * fila) {
  return (fila->tamFila == 0);
}


Fila * criaFila() {
  Fila * fila = (Fila*) malloc(sizeof(Fila));

  fila->tamFila = 0;
  fila->cabeca = NULL;

  return fila;
}


void inserir(Fila * fila, DadoNo dado) {
  No * no = (No*) malloc(sizeof(No));

  no->dado = dado;
  no->prox = fila->cabeca;
  fila->cabeca = no;
  fila->tamFila++;
}


void exiberFila(Fila * fila) {
  if (vazia(fila)) {
    printf("Lista vazia\n");
    return;
  }

  No * apontador = fila->cabeca;

  while (apontador != NULL) {
    printf(" N: %s C: %2d ", strtok(apontador->dado.nome, "\n"), apontador->dado.codigo);
    apontador = apontador->prox;
  }

  printf("\n");
}


void ordena(Fila * fila, int tipo) {
  
  if (vazia(fila)) {
    printf(" Fila vazia\n");
    return;
  }

  No * i;
  No * j;

  for (i = fila->cabeca; i->prox != NULL; i = i->prox) {
    No * maior = i;
    for (j = i->prox; j != NULL; j = j->prox) {
      if (tipo == 1) {
        if (j->dado.codigo >= maior->dado.codigo) {
          maior = j;
        }
      } else {
        if (j->dado.codigo >= maior->dado.codigo) {
          maior = j;
        }
      }
    }
    int auxCodigo = i->dado.codigo;
    int auxTempo = i->dado.tempo;
    char auxNomeA[20];
    char auxNomeB[20];
    stpcpy(auxNomeA, i->dado.nome);
    stpcpy(auxNomeB, maior->dado.nome);

    i->dado.codigo = maior->dado.codigo;
    i->dado.tempo = maior->dado.tempo;
    stpcpy(i->dado.nome, auxNomeB);

    maior->dado.codigo = auxCodigo;
    maior->dado.tempo = auxTempo;
    stpcpy(maior->dado.nome, auxNomeA);
  }
}

