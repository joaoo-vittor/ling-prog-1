#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>


typedef struct dadoNo {
  int codigo;
  int codigoDePrioridade;
  char nome[20];
  int tamArq;
  int tempoFila;
  char dataEntrada[10];
  char horaEntrada[8];
  char dataSaida[10];
  char horaSaida[8];
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
void menuCadastro();
void menuAtendimento(Fila * filaAux, Fila * origFila);
void opcao(int opcao, Fila * filaAux, Fila * origFila);
void opcaoCadastro(int opcao);
void opcaoAtendimento(Fila * filaAux, Fila * origFila);
void cadastraCliente();
void atenderCliente(Fila * fila);
void inserir(Fila * fila, DadoNo dado);
void exiberFila(Fila * fila, int tipoExibicao);
void removeNo(Fila * fila);
int vazia(Fila * fila);
void inserirClienteEmFila(Fila * origFila, Fila * auxFila);
void alterarCodigoClienteArq();
void alterarCodigoClientePrioridadeArq();
void limpaArquivo(char nome[]);
int * verifCodigos(int * array, int codigo, int tam);
void alterarCodigo(Fila * origFila, Fila * auxFila, int tipoCodigo);
int * verificaCodigo(Fila * fila, int codigo);
// https://www.youtube.com/watch?v=Rl3500be6Ns
void ordernar(Fila * fila, int tipo);
int * verificaTempoEmFila(Fila * fila);
void guardaEmArquivo(DadoNo dado);
void guardarLog(No * noDado, int tipo);
void pegaDadosEmArquivo(Fila * fila);
void inicializaArquivo();
int verificaCodigoEmArquivo(int codigoVerif);
int tamanhoArquivo(char nome[], int tipoArq);
void exibirClienteDB();
void limpabuffer();


int main() {

  Fila * origFila = criaFila();
  Fila * auxFila = criaFila();
  
  inicializaArquivo();

  int op;
  

  do {
    op = menu();
    opcao(op, auxFila, origFila);
  } while (1);

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


void exiberFila(Fila * fila, int tipoExibicao) {
  if (vazia(fila)) {
    printf("\n Lista vazia\n");
    sleep(3);
    system("clear");
    return;
  }

  No * apontador = fila->cabeca;

  system("clear");

  if (tipoExibicao == 1) {
    printf(" Fila de atendimento: \n\n");
  } else {
    printf(" Base de Dados:\n\n");
  }

  while (apontador != NULL) {
    if (tipoExibicao == 1) {
      printf(" | Nome: %s, Codigo: %d, Codigo de prioridade: %d, Tamanho do arquivo: %d, Tempo em fila: %d | \n",
      strtok(apontador->dado.nome, "\n"), apontador->dado.codigo, apontador->dado.codigoDePrioridade
      , apontador->dado.tamArq, apontador->dado.tempoFila);
      printf("\t\t\t\t\t^\n");
      printf("\t\t\t\t\t|\n");
    } else {
      printf(" Nome: %s\n Codigo: %d\n Codigo de prioridade: %d\n",
      strtok(apontador->dado.nome, "\n"), apontador->dado.codigo, apontador->dado.codigoDePrioridade);
      printf("\n");
    }
    
    apontador = apontador->prox;
  }

  printf("\n");
}


void removeNo(Fila * fila) {
  if (!vazia(fila)) {
    No * auxPonteiro = fila->cabeca;

    guardarLog(auxPonteiro, 2);

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

  int * tempFila;

  tempFila = verificaTempoEmFila(fila);

  if (fila->tamFila > 1) {
    if (tempFila[1] == 1) {
      ordernar(fila, 2);
    } else {
      ordernar(fila, 1); // 1 por codigo de prioridade
    }
    tempFila[0] = 0;
    tempFila[1] = 0;
  }

}


void inserirClienteEmFila(Fila * origFila, Fila * auxFila) {
  
  if (vazia(auxFila)) {
    printf(" Base de dados esta vazia\n");
    return;
  }

  int * estaEmFila;
  int * emFila;

  exiberFila(auxFila, 2);

  int codigo, aux = 1;

  do {
    printf(" insira o codigo do cliente: ");
    scanf("%d", &codigo);

    
    estaEmFila = verificaCodigo(origFila, codigo);


    if (estaEmFila[0]) {
      printf("\n O cliente com o codigo %d já esta na fila\n\n", codigo);
      estaEmFila[0] = 0;
      estaEmFila[1] = 0;
      estaEmFila[2] = 0;
      aux = 1;
    } else {

      emFila = verificaCodigo(auxFila, codigo);
      
      if (emFila[0] != 1) {
        printf(" Codigo não encontrado\n");
        emFila[0] = 0;
        emFila[1] = 0;
        emFila[2] = 0;
        aux = 1;
      } else {
        aux = 0;
        emFila[0] = 0;
        emFila[1] = 0;
        emFila[2] = 0;
      }

      estaEmFila[0] = 0;
      estaEmFila[1] = 0;
      estaEmFila[2] = 0;

    }    

  } while (aux);
  
  No * auxPonteiroAuxFila = auxFila->cabeca;

  while (auxPonteiroAuxFila->dado.codigo != codigo) {
    auxPonteiroAuxFila = auxPonteiroAuxFila->prox;
  }

  printf(" insira tamanho do arquivo: ");
  scanf("%d", &auxPonteiroAuxFila->dado.tamArq);

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

  int * tempFila;

  tempFila = verificaTempoEmFila(origFila);

  if (origFila->tamFila > 1) {
    if (tempFila[1] == 1) {
      ordernar(origFila, 2);
    } else {
      ordernar(origFila, 1); // 1 por codigo de prioridade
    }
  }

  tempFila[0] = 0;
  tempFila[1] = 0;

  guardarLog(auxPonteiroOrigFila, 1);

}


int * verificaTempoEmFila(Fila * fila) {
  if (vazia(fila)) {
    return 0;
  }

  No * aux = fila->cabeca;
  int i;
  int qtd = 0;
  int static retorno[] = {0, 0};

  for (i = 0; i < fila->tamFila; i++) {
    if (aux->dado.tempoFila > 6) {
      qtd++;
    }
    aux = aux->prox;
  }

  if (qtd > 0) {
    retorno[0] = 1; // se tem pessoas com tempo maior que 6
    retorno[1] = qtd;
  }

  return retorno;
}


void ordernar(Fila * fila, int tipo) {
   if (vazia(fila)) {
    return;
  }

  No * i;
  No * j;

  for (i = fila->cabeca; i->prox != NULL; i = i->prox) {
    No * maior = i;
    for (j = i->prox; j != NULL; j = j->prox) {
      if (tipo == 1) {
        if (j->dado.codigoDePrioridade >= maior->dado.codigoDePrioridade) {
          maior = j;
        }
      } else {
        if (j->dado.tempoFila >= maior->dado.tempoFila) {
          maior = j;
        }
      }
    }

    int auxCodigo = i->dado.codigo;
    int auxTempo = i->dado.tempoFila;
    int auxCodigoPrioridade = i->dado.codigoDePrioridade;
    int auxTamArq = i->dado.tamArq;

    char auxNomeA[20];
    char auxNomeB[20];
    stpcpy(auxNomeA, i->dado.nome);
    stpcpy(auxNomeB, maior->dado.nome);

    i->dado.codigo = maior->dado.codigo;
    i->dado.tempoFila = maior->dado.tempoFila;
    i->dado.codigoDePrioridade = maior->dado.codigoDePrioridade;
    i->dado.tamArq = maior->dado.tamArq;
    stpcpy(i->dado.nome, auxNomeB);

    maior->dado.codigo = auxCodigo;
    maior->dado.tempoFila = auxTempo;
    maior->dado.codigoDePrioridade = auxCodigoPrioridade;
    maior->dado.tamArq = auxTamArq;
    stpcpy(maior->dado.nome, auxNomeA);
  }
}


void alterarCodigo(Fila * origFila, Fila * auxFila, int tipoCodigo) {
  int codigoNovo, codigoCliente;
  
  if (vazia(auxFila)) {
    printf("\n Base de Dados Vazia\n");
    return;
  }

  exiberFila(auxFila, 1);

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

  }
}


int vazia(Fila * fila) {
  if (fila->cabeca == NULL) {
    return 1;
  }
  return 0;
}


int menu() {
  int opcao;

  printf(" ========= Menu Principal =========\n");
  printf(" 1 - Menu Cliente\n");
  printf(" 2 - Menu Atendimento\n");
  printf(" 3 - sair\n");
  printf(" opção: ");
  scanf("%d", &opcao);

  

  system("clear");

  return opcao;
}


void menuCadastro() {
  int opcao;

  printf(" ========= Menu Cliente =========\n");
  printf(" 1 - Cadastra Cliente\n");
  printf(" 2 - Listar Clientes da Base de Dados\n");
  printf(" 3 - Alterar Codigo do Cliente Em Arquivo\n");
  printf(" 4 - Alterar Codigo de Prioridade do Cliente Em Arquivo\n");
  printf(" 5 - Voltar ao Menu Anterior\n");
  printf(" 6 - Sair\n");
  printf(" opção: ");
  scanf("%d", &opcao);

  system("clear");


  switch (opcao) {
    case 1:
      cadastraCliente();
      break;
    case 2:
      exibirClienteDB();
      break;
    case 3:
      // Alterar Codigo do Cliente em arquivo
      alterarCodigoClienteArq();
      break;
    case 4:
      // Alterar Codigo de Prioridade do Cliente em arquivo
      alterarCodigoClientePrioridadeArq();
      break;
    case 5:
      break;
    case 6: 
      exit(1);
    default:
      printf(" Opção invalida!\n");
      break;
  }

}

void menuAtendimento(Fila * filaAux, Fila * origFila) {
  int opcao;

  pegaDadosEmArquivo(filaAux);

  printf(" ========= Menu Atendimento =========\n");
  printf(" 1 - Atender Cliente\n");
  printf(" 2 - Listar Fila de Atrendimento\n");
  printf(" 3 - Inserir Cliente em Fila de Atendimento\n");
  printf(" 4 - Voltar ao Menu Anterior\n");
  printf(" 5 - sair\n");
  printf(" opção: ");
  scanf("%d", &opcao);

  system("clear");


  switch (opcao) {
    case 1:
      removeNo(origFila);
      break;
    case 2:
      exiberFila(origFila, 1);
      break;
    case 3:
      inserirClienteEmFila(origFila, filaAux);
      break;
    case 4:
      break;
    case 5:
      exit(1);
    default:
      printf(" Opção invalida!\n");
      break;
  }
}


void opcao(int opcao, Fila * filaAux, Fila * origFila) {
  switch (opcao) {
    case 1:
      menuCadastro();
      break;
    case 2:
      menuAtendimento(filaAux, origFila);
      break;
    case 3:
      exit(1);
    default:
      printf(" Opção invalida!\n");
      break;
  }
}


void cadastraCliente() {
  DadoNo dado;
  int codigoPrio, codigoCli;
  int auxVerif;

  system("clear");
  limpabuffer();

  printf(" insira o nome do cliente: ");
  fgets(dado.nome, 20, stdin);


  do {
    printf(" insira o codigo do cliente: ");
    scanf("%d", &codigoCli);
    auxVerif = verificaCodigoEmArquivo(codigoCli);
    if (auxVerif) {
      printf(" Codigo já existe, tente outro!\n");
    }
  } while (auxVerif);
  dado.codigo = codigoCli;

  do {
    printf(" insira o codigo de prioridade do cliente: ");
    scanf("%d", &codigoPrio);
    if (codigoPrio < 0 || codigoPrio > 4) {
      printf(" Codigo de prioridade invalido, os codigos devem estar entra 1 e 4\n");
    }
  } while (codigoPrio < 0 || codigoPrio > 4);
  dado.codigoDePrioridade = codigoPrio;

  guardaEmArquivo(dado);
  limpabuffer();
  system("clear");
}


void guardaEmArquivo(DadoNo dado) {
  FILE * codigo;
  FILE * codigoPrioridade;
  FILE * nome;

  codigo = fopen("codigoCliente.txt", "a");
  codigoPrioridade = fopen("codigoPrioridade.txt", "a");
  nome = fopen("nomeCliente.txt", "a");

  if (codigoPrioridade && codigo && nome) {
    fprintf(codigo, "%d\n", dado.codigo);
    fprintf(codigoPrioridade, "%d\n", dado.codigoDePrioridade);
    fprintf(nome, "%s", dado.nome);
  } else {
    printf(" Não foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(codigo);
  fclose(codigoPrioridade);
  fclose(nome);
}


int tamanhoArquivo(char nome[], int tipoArq) {
  FILE * arquivo;
  int tamanho = 0;
  char c[20];
  char * result;
  int * aux;
  int valor;

  arquivo = fopen(nome, "r");

  if (arquivo) {
    if (tipoArq == 1) {
      while (!feof(arquivo)) {
        result = fgets(c, 20, arquivo);
        if (result) {
          tamanho++;
        }
      }
    } else {
      while (!feof(arquivo)) {
        result = fgets(c, sizeof(int) * 20, arquivo);
        if (result) {
          tamanho++;
        }
      }
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }

  fclose(arquivo);

  return tamanho;
}


void guardarLog(No * noDado, int tipo) {
  FILE * log;
  time_t segundos;
  struct tm * dataHoraAtual;

  time(&segundos);

  dataHoraAtual = localtime(&segundos);

  log = fopen("logCliente.txt", "a");

  if (log) {
    if (tipo == 1) {
      fprintf(log, "Entrada:\nHora %d:%d:%d Data %d/%d/%d \n", 
      dataHoraAtual->tm_hour, dataHoraAtual->tm_min, dataHoraAtual->tm_sec, 
      dataHoraAtual->tm_mday, dataHoraAtual->tm_mon+1, dataHoraAtual->tm_year+1900);

      fprintf(log, "Nome: %s\nCodigo: %d\nCodigo Prioridade: %d\nTamanho Arquivo:%d\n", 
      noDado->dado.nome, noDado->dado.codigo, noDado->dado.codigoDePrioridade, noDado->dado.tamArq);
    } else {
      fprintf(log, "Saida: \nHora %d:%d:%d Data %d/%d/%d \n", 
      dataHoraAtual->tm_hour, dataHoraAtual->tm_min, dataHoraAtual->tm_sec, 
      dataHoraAtual->tm_mday, dataHoraAtual->tm_mon+1, dataHoraAtual->tm_year+1900);

      fprintf(log, "Nome: %s\nCodigo: %d\nCodigo Prioridade: %d\nTamanho Arquivo:%d\n", 
      noDado->dado.nome, noDado->dado.codigo, noDado->dado.codigoDePrioridade, noDado->dado.tamArq);
    }
  } else {
    printf(" Não foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(log);
}


void pegaDadosEmArquivo(Fila * fila) {
  FILE * codigo;
  FILE * codigoPrioridade;
  FILE * nome;
  DadoNo dado;

  codigo = fopen("codigoCliente.txt", "r");
  codigoPrioridade = fopen("codigoPrioridade.txt", "r");
  nome = fopen("nomeCliente.txt", "r");

  int codigoArq, codigoPrioArq;
  char nomeArq[20];

  int tamNomeArq, tamCodArq, tamCodPriArq;
  int i;

  int * verifCod;
  
  if (codigoPrioridade && codigo && nome) {
    tamNomeArq = tamanhoArquivo("nomeCliente.txt", 1);
    tamCodArq = tamanhoArquivo("codigoPrioridade.txt", 2);
    tamCodPriArq = tamanhoArquivo("nomeCliente.txt", 2);

    for (i = 0; i < tamNomeArq; i++) {
      fscanf(codigo, "%d", &codigoArq);

      verifCod = verificaCodigo(fila, codigoArq);

      if (verifCod[0] != 1) {
        fscanf(codigoPrioridade, "%d", &codigoPrioArq);
        fscanf(nome, "%s", nomeArq);
        
        dado.codigo = codigoArq;
        dado.codigoDePrioridade = codigoPrioArq;
        strcpy(dado.nome, nomeArq);
        
        inserir(fila, dado);
      }
      verifCod[0] = 0;
    }
    
  } else {
    printf(" Não foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(codigo);
  fclose(codigoPrioridade);
  fclose(nome);
}


int verificaCodigoEmArquivo(int codigoVerif) {
  FILE * codigo;
  int codigoArq;
  char c;

  codigo = fopen("codigoCliente.txt", "r");

  if (codigo) {
    while (fscanf(codigo, "%d", &codigoArq) != EOF) {
      if (codigoArq == codigoVerif) {
        fclose(codigo);
        return 1;
      }
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }

  fclose(codigo);
  return 0;
}


void exibirClienteDB() {
  FILE * codigo;
  FILE * codigoPrioridade;
  FILE * nome;

  int codigoArq, codigoPrioArq;
  char nomeArq[20];

  int tamCodArq, tamCodPriArq, tamNomeArq;
  int i;

  codigo = fopen("codigoCliente.txt", "r");
  codigoPrioridade = fopen("codigoPrioridade.txt", "r");
  nome = fopen("nomeCliente.txt", "r");
  

  if (codigo && codigoPrioridade && nome) {
    tamCodArq = tamanhoArquivo("codigoCliente.txt", 2);
    tamCodPriArq = tamanhoArquivo("codigoPrioridade.txt", 2);
    tamNomeArq = tamanhoArquivo("nomeCliente.txt", 1);
    
    // printf("%d %d %d \n", tamNomeArq, tamCodPriArq, tamCodArq);
    for (i = 0; i < tamNomeArq; i++) {
      fscanf(codigo, "%d", &codigoArq);
      fscanf(codigoPrioridade, "%d", &codigoPrioArq);
      fscanf(nome, "%s", nomeArq);
      printf("\n");
      printf(" Nome: %s \n", strtok(nomeArq, "\n"));
      printf(" Codigo: %d \n", codigoArq);
      printf(" Codigo Prioridade: %d \n", codigoPrioArq);
      printf("\n");
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }


  fclose(codigo);
  fclose(codigoPrioridade);
  fclose(nome);
}


void alterarCodigoClienteArq() {
  FILE * codigo;

  int * arrayCodigo = (int*) malloc(sizeof(int));

  int tamArq = tamanhoArquivo("codigoCliente.txt", 2);
  int i;

  if (tamArq > 0) {
    exibirClienteDB();
  } else {
    printf(" Base de Dados vazia\n");
    return;
  }
  
  codigo = fopen("codigoCliente.txt", "r");

  if (codigo) {
    for (i = 0; i < tamArq; i++) {
      fscanf(codigo, "%d", &arrayCodigo[i]);
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }
  fclose(codigo);

  int codigoAntigo, codigoNovo;
  int * verifCodigo;

  do {
    printf(" Digite o Codigo Antigo: ");
    scanf("%d", &codigoAntigo);
    verifCodigo = verifCodigos(arrayCodigo, codigoAntigo, tamArq);
    if (verifCodigo[0] == 0) {
      printf(" Codigo %d não exite.\n", codigoAntigo);
      verifCodigo[0] = 0;
      verifCodigo[1] = 0;
    }
  } while (!verifCodigo[0]);


  do {
    verifCodigo[0] = 0;
    verifCodigo[1] = 0;
    printf(" Digite o Novo Codigo: ");
    scanf("%d", &codigoNovo);
    verifCodigo = verifCodigos(arrayCodigo, codigoNovo, tamArq);
    if (verifCodigo[0] == 1) {
      printf(" Codigo %d já exite, tente outro.\n", codigoNovo);
    }
  } while (verifCodigo[0]);

  verifCodigo = verifCodigos(arrayCodigo, codigoAntigo, tamArq);

  arrayCodigo[verifCodigo[1]] = codigoNovo;
  limpaArquivo("codigoCliente.txt");


  codigo = fopen("codigoCliente.txt", "a");
  for (i = 0; i < tamArq; i++) {
    fprintf(codigo, "%d\n", arrayCodigo[i]);
  }

  fclose(codigo);
  free(arrayCodigo);
}


void alterarCodigoClientePrioridadeArq() {
  FILE * codigo;
  FILE * codigoPrioridade;

  int * arrayCodigo = (int*) malloc(sizeof(int));
  int * arrayCodigoPrio = (int*) malloc(sizeof(int));

  int tamCodArq = tamanhoArquivo("codigoCliente.txt", 2);
  int tamCodPriArq = tamanhoArquivo("codigoPrioridade.txt", 2);
  int i;


  if (tamCodArq > 0) {
    exibirClienteDB();
  } else {
    printf(" Base de Dados vazia\n");
    return;
  }
  
  codigo = fopen("codigoCliente.txt", "r");
  codigoPrioridade = fopen("codigoPrioridade.txt", "r");

  if (codigo && codigoPrioridade) {
    for (i = 0; i < tamCodArq; i++) {
      fscanf(codigo, "%d", &arrayCodigo[i]);
      fscanf(codigoPrioridade, "%d", &arrayCodigoPrio[i]);
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }
  fclose(codigo);
  fclose(codigoPrioridade);

  int codigoCli, codigoNovo;
  int * verifCodigo;

  do {
    printf(" Digite o Codigo Cliente: ");
    scanf("%d", &codigoCli);
    verifCodigo = verifCodigos(arrayCodigo, codigoCli, tamCodArq);
    if (verifCodigo[0] == 0) {
      printf(" Codigo %d não exite.\n", codigoCli);
      verifCodigo[0] = 0;
      verifCodigo[1] = 0;
    }
  } while (!verifCodigo[0]);


  do {
    printf(" Digite o Novo Codigo de Prioridade: ");
    scanf("%d", &codigoNovo);
    if (codigoNovo < 0 || codigoNovo > 4) {
      printf(" Codigo de prioridade invalido, os codigos devem estar entra 1 e 4\n");
    }
  } while (codigoNovo < 0 || codigoNovo > 4);

  arrayCodigoPrio[verifCodigo[1]] = codigoNovo;
  limpaArquivo("codigoPrioridade.txt");


  codigoPrioridade = fopen("codigoPrioridade.txt", "a");
  for (i = 0; i < tamCodArq; i++) {
    fprintf(codigoPrioridade, "%d\n", arrayCodigoPrio[i]);
  }

  fclose(codigoPrioridade);
  free(arrayCodigo);
  free(arrayCodigoPrio);
}


int * verifCodigos(int * array, int codigo, int tam) {
  int static retorno[] = {0, 0};
  int i;
  for (i = 0; i < tam; i++) {
    if (array[i] == codigo) {
      retorno[0] = 1;
      retorno[1] = i;
      return retorno;
    }
  }
  return retorno;
}


void inicializaArquivo() {
  FILE * codigo;
  FILE * codigoPrioridade;
  FILE * nome;
  FILE * log;

  codigo = fopen("codigoCliente.txt", "a");
  codigoPrioridade = fopen("codigoPrioridade.txt", "a");
  nome = fopen("nomeCliente.txt", "a");
  log = fopen("logCliente.txt", "a");

  fclose(log);
  fclose(codigo);
  fclose(codigoPrioridade);
  fclose(nome);
}


void limpaArquivo(char nome[]) {
  FILE * arquivo;

  arquivo = fopen(nome, "w");

  fclose(arquivo);
}

