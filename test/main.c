#include <stdio.h>
#include <stdlib.h>

typedef struct dadoNo {
  int codigo;
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
void removeNo(Fila * fila);
int vazia(Fila * fila);
No * posicaoNo(Fila * fila, int indice);
int indiceNo(Fila * fila, No * no);
void removePorIndice(Fila * fila, int indice);
void inserirPorIndice(Fila * fila, DadoNo dado, int indice);
void tracaDoisNos(Fila * fila, No * primeiroNo, No * segundoNo);
No * min(Fila * fila, int indice);
No * max(Fila * fila, int indice);
void ordenaCres(Fila * fila);
void ordenaDecr(Fila * fila);


int main() {

  Fila * fila = criaFila();
  DadoNo dado;

  dado.codigo = 4;
  inserir(fila, dado);

  dado.codigo = 1;
  inserir(fila, dado);

  dado.codigo = 3;
  inserir(fila, dado);

  dado.codigo = 11;

  inserir(fila, dado);

  dado.codigo = 17;

  inserir(fila, dado);
  
  exiberFila(fila);

  printf("  min : %d\n", min(fila, 0)->dado.codigo);
  printf("  max : %d\n", max(fila, 0)->dado.codigo);

  ordenaCres(fila);

  exiberFila(fila);

  ordenaDecr(fila);

  exiberFila(fila);

  return 0;
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
    printf(" %2d ", apontador->dado.codigo);
    apontador = apontador->prox;
  }

  printf("\n");
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


void tracaDoisNos(Fila * fila, No * primeiroNo, No * segundoNo) {

  
  if (primeiroNo == segundoNo) {
    return;
  }

  int indicePrimeiroNo = indiceNo(fila, primeiroNo);
  int indiceSegundoNo = indiceNo(fila, segundoNo);

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


No * min(Fila * fila, int indice) {
  No * auxPonteiro = posicaoNo(fila, indice);

  if (auxPonteiro != NULL) {
    No * minCodigo = auxPonteiro;
    while (auxPonteiro != NULL) {
      if (auxPonteiro->dado.codigo < minCodigo->dado.codigo) {
        minCodigo = auxPonteiro;
      }
      auxPonteiro = auxPonteiro->prox;
    }
    return minCodigo;
  }

  return NULL;
}

No * max(Fila * fila, int indice) {
  No * auxPonteiro = posicaoNo(fila, indice);

  if (auxPonteiro != NULL) {
    No * maxCodigo = auxPonteiro;
    while (auxPonteiro != NULL) {
      if (auxPonteiro->dado.codigo > maxCodigo->dado.codigo) {
        maxCodigo = auxPonteiro;
      }
      auxPonteiro = auxPonteiro->prox;
    }
    return maxCodigo;
  }

  return NULL;
}

void ordenaCres(Fila * fila) {
  int i;
  for (i = 0; i < fila->tamFila - 1; i++) {
    tracaDoisNos(fila, posicaoNo(fila, i), min(fila, i));
  }
}

void ordenaDecr(Fila * fila) {
  int i;
  for (i = 0; i < fila->tamFila - 1; i++) {
    tracaDoisNos(fila, posicaoNo(fila, i), max(fila, i));
  }
}


int vazia(Fila * fila) {
  return (fila->tamFila == 0);
}
