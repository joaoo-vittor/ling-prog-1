#include <stdio.h>
#include <stdlib.h>


struct st_arvore {
  int dado;
  struct st_arvore * direita;
  struct st_arvore * esquerda;
};


typedef struct st_arvore arvore;


arvore * criaArvore() {
  return NULL;
}


int arvoreVazia(arvore * dado) {
  return dado == NULL;
}


void mostraArvore(arvore * dado) {
  // printf("<");
  if (!arvoreVazia(dado)) {
    printf("  %d  ", dado->dado);
    mostraArvore(dado->esquerda);
    mostraArvore(dado->direita);
  }
  // printf(">");
}


void insere(arvore ** dado, int valor) {
  if (*dado == NULL) {
    *dado = (arvore*)malloc(sizeof(arvore));
    (*dado)->esquerda = NULL;
    (*dado)->direita  = NULL;
    (*dado)->dado = valor;
  } else {
    if (valor < (*dado)->dado) {
      insere(&(*dado)->esquerda, valor);
    } else {
      insere(&(*dado)->direita, valor);
    }
  }
}


int busca(arvore * dado, int valor) {
  if (arvoreVazia(dado)) {
    return 0;
  }

  if (dado->dado == valor) {
    return valor;
  }

  if (valor < dado->dado) {
    return busca(dado->esquerda, valor);
  } else {
    return busca(dado->direita, valor);
  }
}

int main() {

  arvore * dado = criaArvore();

  insere(&dado, 12);
  insere(&dado, 15);
  insere(&dado, 10);
  insere(&dado, 13);

  mostraArvore(dado);

  if (arvoreVazia(dado)) {
    printf("\n\nArvore esta vazia\n");
  }

  if (busca(dado, 15)) {
    printf("\nO elemento 15 esta na arvore\n");
  } else {
    printf("\nO elemento 15 nao esta na arvore\n");
  }

  return 0;
}
