#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
<<<<<<< HEAD
#include <ctype.h>


typedef struct dadoNo {
  int codigo;
  int codigoDePrioridade;
  char nome[20];
  int tamArq;
  int tempoFila;
=======

typedef struct dadoNo {
  int codigo;
  char nome[20];
  int tamArq;
  // int tempoFila;
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
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
<<<<<<< HEAD
void opcao(int opcao, Fila * filaAux, Fila * origFila);
void cadastraCliente(Fila * fila);
void atenderCliente(Fila * fila);
void inserir(Fila * fila, DadoNo dado);
void exiberFila(Fila * fila, int tipoVizualizacao);
void removeNo(Fila * fila);
int vazia(Fila * fila);
void inserirClienteEmFila(Fila * origFila, Fila * auxFila);
void alterarCodigo(Fila * origFila, Fila * auxFila, int tipoCodigo);
int * verificaCodigo(Fila * fila, int codigo);
=======
void opcao(int opcao, Fila * fila);
void cadastraCliente(Fila * fila);
void atenderCliente(Fila * fila);
void inserir(Fila * fila, DadoNo dado);
void exiberFila(Fila * fila);
void removeNo(Fila * fila);
int vazia(Fila * fila);
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
void limpabuffer();


int main() {

<<<<<<< HEAD
  Fila * origFila = criaFila();
  Fila * auxFila = criaFila();
=======
  Fila * fila = criaFila();
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e

  int op;

  do {
    op = menu();
<<<<<<< HEAD
    opcao(op, auxFila, origFila);
=======
    opcao(op, fila);
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
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
<<<<<<< HEAD
    fila->tamFila++;
  }
}


int * verificaCodigo(Fila * fila, int codigo) {
  int static retorno[] = {0, 0, 0};

  if (vazia(fila)) {
    return retorno;
  }
  
  No * auxPont = fila->cabeca;

  while (auxPont->prox != NULL && auxPont->dado.codigo != codigo) {
    auxPont = auxPont->prox;
  }
  
  if (auxPont->dado.codigo == codigo) {
    retorno[0] = 1; // codigo existe
    retorno[1] = codigo; // codigo
    retorno[2] = auxPont->dado.codigoDePrioridade; // codigo de prioridade
    return retorno;
  }
  return retorno;
}


void exiberFila(Fila * fila, int tipoVizualizacao) {
  if (vazia(fila)) {
    if (tipoVizualizacao == 1) {
      printf("\n Lista vazia\n");
    } else {
      printf("\n Base de Dados Vazia\n");
    }
=======
  }
}


void exiberFila(Fila * fila) {
  if (vazia(fila)) {
    printf("\n Lista vazia\n");
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
    sleep(3);
    system("clear");
    return;
  }

  No * apontador = fila->cabeca;

  system("clear");

<<<<<<< HEAD
  if (tipoVizualizacao == 1) {
    printf(" Fila de atendimento: \n\n");
  } else {
    printf(" Base de Dados: \n\n");
  }

  while (apontador != NULL) {
    if (tipoVizualizacao == 1) {
      printf(" | Nome: %s, Codigo: %d, Codigo de prioridade: %d, Tamanho do arquivo: %d, Tempo em fila: %d | <- ",
      strtok(apontador->dado.nome, "\n"), apontador->dado.codigo, apontador->dado.codigoDePrioridade
      , apontador->dado.tamArq, apontador->dado.tempoFila);
    } else {
      printf(" Nome: %s\n Codigo: %d\n Codigo de prioridade: %d\n Tamanho do arquivo: %d\n",
      strtok(apontador->dado.nome, "\n"), apontador->dado.codigo, apontador->dado.codigoDePrioridade
      , apontador->dado.tamArq);
      printf("\n");
    }
=======
  printf(" Fila de atendimento: \n\n");

  while (apontador != NULL) {
    printf(" | Codigo: %d, Nome: %s, Tamanho do arquivo: %d | <- ", apontador->dado.codigo, strtok(apontador->dado.nome, "\n"), apontador->dado.tamArq);
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
    apontador = apontador->prox;
  }

  printf("\n\n");
}


void removeNo(Fila * fila) {
  if (!vazia(fila)) {
    No * auxPonteiro = fila->cabeca;
<<<<<<< HEAD
    printf("\n O cliente %s foi atendido!\n\n", strtok(auxPonteiro->dado.nome, "\n"));
    fila->cabeca = auxPonteiro->prox;
    free(auxPonteiro);
    fila->tamFila--;
  } else {
    printf(" Não tem clientes na fila de atendimento\n");
    return;
  }

  No * apotadorAux = fila->cabeca;

  while (apotadorAux != NULL) {
    apotadorAux->dado.tempoFila++;
    apotadorAux = apotadorAux->prox;
  }
}


void inserirClienteEmFila(Fila * origFila, Fila * auxFila) {
  
  if (vazia(auxFila)) {
    printf(" Base de dados esta vazia\n");
    return;
  }

  int * estaEmFila;

  exiberFila(auxFila, 2);

  int codigo;
  printf(" insira o codigo do cliente: ");
  scanf("%d", &codigo);

  estaEmFila = verificaCodigo(origFila, codigo);

  if (estaEmFila[0]) {
    printf("\n O cliente com o codigo %d já esta na fila\n\n", codigo);
    return;
  }

  No * auxPonteiroAuxFila = auxFila->cabeca;


  while (auxPonteiroAuxFila->dado.codigo != codigo && auxPonteiroAuxFila->prox != NULL) {
    auxPonteiroAuxFila = auxPonteiroAuxFila->prox;
  }

  if (auxPonteiroAuxFila->dado.codigo != codigo) {
    printf("\n Codigo não encontrado\n");
    return;
  }

  No * auxPonteiroOrigFila = (No*) malloc(sizeof(No));

  if (vazia(origFila)) {
    auxPonteiroOrigFila->dado = auxPonteiroAuxFila->dado;
    auxPonteiroOrigFila->prox = NULL;
    origFila->cabeca = auxPonteiroOrigFila;
    origFila->tamFila++;
  } else {
    No * auxPont = origFila->cabeca;
    while (auxPont->prox != NULL) {
      auxPont = auxPont->prox;
    }
    auxPonteiroOrigFila->prox = NULL;
    auxPonteiroOrigFila->dado = auxPonteiroAuxFila->dado;
    auxPont->prox = auxPonteiroOrigFila;
    origFila->tamFila++;
  }
  printf("\n O cliente %s foi inserido na fila\n\n", strtok(auxPonteiroOrigFila->dado.nome, "\n"));
}


void alterarCodigo(Fila * origFila, Fila * auxFila, int tipoCodigo) {
  int codigoNovo, codigoCliente;
  
  if (vazia(auxFila)) {
    printf("\n Base de Dados Vazia\n");
    return;
  }

  exiberFila(auxFila, 2);

  int * verifCodigo;

  limpabuffer();
  
  if (tipoCodigo == 1) {
    printf(" ===== Alterar Codigo do Cliente ====\n");
    do {
      printf(" Codigo Antigo: ");
      scanf("%d", &codigoCliente);
      verifCodigo = verificaCodigo(auxFila, codigoCliente);
      if (verifCodigo[1] == 0) {
        printf("\n Codigo não encontrado\n");
      }
    } while (verifCodigo[0] != 1);

    char auxOpc;
    int aux = 1;

    do {
      printf(" Codigo Novo: ");
      scanf("%d", &codigoNovo);
      if (codigoNovo == verifCodigo[1]) {
        printf(" Deseja inserir o mesmo codigo [S]im ou [N]ão : ");
        limpabuffer();
        scanf("%c", &auxOpc);
      } else {
        aux = 0;
      }
      if (auxOpc == 'S' || auxOpc == 's') {
        verifCodigo[0] = 0;
        verifCodigo[1] = 0;
        return;
      }
      getchar();
    } while (aux);

  } else {
    printf(" ==== Alterar Codigo de Prioridade do Cliente ====\n");
    do {
      printf(" Codigo do cliente: ");
      scanf("%d", &codigoCliente);
      verifCodigo = verificaCodigo(auxFila, codigoCliente);
      if (verifCodigo[1] == 0) {
        printf("\n Codigo não encontrado\n");
      }
    } while (verifCodigo[0] != 1);

    char auxOpc;
    int aux = 1;

    do {

      printf(" Novo Codigo de prioridade: ");
      scanf("%d", &codigoNovo);

      if (codigoNovo < 0 || codigoNovo > 4) {
        printf(" Codigo de prioridade invalido, os codigos devem estar entra 1 e 4\n");
      } else {

        if (codigoNovo == verifCodigo[2]) {
        printf(" Deseja inserir o mesmo codigo [S]im ou [N]ão : ");
        limpabuffer();
        scanf("%c", &auxOpc);
        } else {
          aux = 0;
        }

        if (auxOpc == 'S' || auxOpc == 's') {
          verifCodigo[0] = 0;
          verifCodigo[1] = 0;
          verifCodigo[2] = 0;
          return;
        }
      }  

      getchar();
    } while (aux);
  }
  
  verifCodigo[0] = 0;
  verifCodigo[1] = 0;
  verifCodigo[2] = 0;

  No * auxPontAuxFila = auxFila->cabeca;
  No * auxPontOrigFila = origFila->cabeca;

  while (auxPontAuxFila->dado.codigo != codigoCliente && auxPontAuxFila->prox != NULL) {
    auxPontAuxFila = auxPontAuxFila->prox;
  }

  if (tipoCodigo == 1) {
    
    if (auxPontAuxFila->dado.codigo == codigoCliente) {
      auxPontAuxFila->dado.codigo = codigoNovo;
    } else {
      printf(" Codigo invalido\n");
      return;
    }

    if (!vazia(origFila) && verificaCodigo(origFila, codigoCliente)[0]) {
      while (auxPontOrigFila->dado.codigo != codigoCliente && auxPontOrigFila->prox != NULL) {
        auxPontOrigFila = auxPontOrigFila->prox;
      }
      if (auxPontOrigFila->dado.codigo == codigoCliente) {
        auxPontOrigFila->dado.codigo = codigoNovo;
      } 
    }

    
  } else {

    if (auxPontAuxFila->dado.codigo == codigoCliente) {
      auxPontAuxFila->dado.codigoDePrioridade = codigoNovo;
    } else {
      printf("\n Codigo invalido\n");
      return;
    }

    if (!vazia(origFila)) {
      while (auxPontOrigFila->dado.codigo != codigoCliente && auxPontOrigFila->prox != NULL) {
        auxPontOrigFila = auxPontOrigFila->prox;
      } 
      if (auxPontOrigFila->dado.codigo == codigoCliente) {
        auxPontOrigFila->dado.codigoDePrioridade = codigoNovo;
      }
    }

=======
    fila->cabeca = auxPonteiro->prox;
    free(auxPonteiro);
    fila->tamFila--;
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
  }
}


int vazia(Fila * fila) {
  if (fila->cabeca == NULL) {
    return 1;
  }
  return 0;
}


int menu() {
  int opcao = 0;

<<<<<<< HEAD
  printf(" ========= Menu Principal =========\n");
  printf(" 1 - Cadastra Cliente\n");
  printf(" 2 - Listar Cliente Em Atendimento\n");
  printf(" 3 - Atender Cliente\n");
  printf(" 4 - Inserir Cliente em Fila de Atendimento\n");
  printf(" 5 - Listar Clientes da Base de Dados\n");
  printf(" 6 - Alterar Codigo do Cliente\n");
  printf(" 7 - Alterar Codigo de Prioridade do Cliente\n");
  printf(" 8 - sair\n");
  printf(" opção: ");
  scanf("%d", &opcao);

  if (isdigit(opcao)) {
    return opcao;
  } else {
    printf(" Valor inserido é invalido!\n");
    system("clear");
    menu();
  }

}


void opcao(int opcao, Fila * filaAux, Fila * origFila) {
  switch (opcao) {
    case 1:
      cadastraCliente(filaAux);
      break;
    case 2:
      exiberFila(origFila, 1);
      break;
    case 3:
      removeNo(origFila);
      break;
    case 4:
      inserirClienteEmFila(origFila, filaAux);
      break;
    case 5:
      exiberFila(filaAux, 2);
      break;
    case 6:
      // alterar codigo cliente
      alterarCodigo(origFila, filaAux, 1);
      break;
    case 7:
      // alterar codigo de prioridade do cliente
      alterarCodigo(origFila, filaAux, 2);
      break;
    case 8:
=======
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
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
      exit(1);
    default:
      printf(" Opção invalida!\n");
      break;
  }
}

<<<<<<< HEAD

void cadastraCliente(Fila * fila) {
  DadoNo dado;
  int codigoPrio, codigoCli;
  int * auxVerif;
=======
void cadastraCliente(Fila * fila) {
  DadoNo dado;
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e

  system("clear");
  limpabuffer();

  printf(" insira o nome do cliente: ");
  fgets(dado.nome, 20, stdin);

<<<<<<< HEAD
  if (vazia(fila)) {
    printf(" insira o codigo do cliente: ");
    scanf("%d", &dado.codigo);
  } else {
    do {
      auxVerif[0] = 0;
      auxVerif[1] = 0;
      auxVerif[2] = 0;
      printf(" insira o codigo do cliente: ");
      scanf("%d", &codigoCli);
      auxVerif = verificaCodigo(fila, codigoCli);
      if (auxVerif[0]) {
        printf(" Codigo já existe, tente outro!\n");
      }
    } while (auxVerif[0]);
    dado.codigo = codigoCli;
  }

  do {
    printf(" insira o codigo de prioridade do cliente: ");
    scanf("%d", &codigoPrio);
    if (codigoPrio < 0 || codigoPrio > 4) {
      printf(" Codigo de prioridade invalido, os codigos devem estar entra 1 e 4\n");
    }
  } while (codigoPrio < 0 || codigoPrio > 4);
  dado.codigoDePrioridade = codigoPrio;
=======
  printf(" insira o codigo do cliente: ");
  scanf("%d", &dado.codigo);
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e

  printf(" insira o tamanho do arquivo: ");
  scanf("%d", &dado.tamArq);

<<<<<<< HEAD
  dado.tempoFila = 0;
=======
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
  inserir(fila, dado);
  limpabuffer();
  system("clear");
}

<<<<<<< HEAD
=======

// void atenderCliente();
>>>>>>> ebdff3bb3cf51d8b9b594e0d6d30f1fe8271530e
