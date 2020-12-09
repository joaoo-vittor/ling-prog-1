#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>


typedef struct dadoNo {
  int codigo;
  int codigoDePrioridade;
  char nome[20];
  int tamArq;
  int tempoFila;
  char dataEnt[10];
  char horaEnt[10];
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
void menuCadastro(Fila * filaAux, Fila * origFila);
void auxMenu(Fila * filaAux, Fila * origFila);
void menuAtendimento(Fila * filaAux, Fila * origFila);
void opcao(char opcao, Fila * filaAux, Fila * origFila);
void opcaoAtendimento(Fila * filaAux, Fila * origFila);
void cadastraCliente();
void atenderCliente(Fila * fila);
void inserir(Fila * fila, DadoNo dado);
void exiberFila(Fila * fila, int tipoExibicao);
void removeNo(Fila * fila);
No * naPosicao(Fila * fila, int indice);
int indiceDoNo(Fila * fila, No * no);
void trocarNo(Fila * fila, No * primeiroNo, No * segundoNo);
No * minimo(Fila * fila, int indice, int tipo);
No * maximo(Fila * fila, int indice, int tipo);
int vazia(Fila * fila);
void inserirClienteEmFila(Fila * origFila, Fila * auxFila);
void alterarCodigoClienteArq();
void alterarCodigoClientePrioridadeArq();
void limpaArquivo(char nome[]);
int * verifCodigos(int * array, int codigo, int tam);
int * verificaCodigo(Fila * fila, int codigo);
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

  char op;

  do {
    op = menu();
    opcao(op, auxFila, origFila);
    limpabuffer();
  } while (1);

  free(origFila);
  free(auxFila);
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
    no->dado.tempoFila = 0;
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
    no->dado.tempoFila = 0;
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
    printf("\n\t\tFila vazia\n");
    sleep(3);
    system("clear");
    return;
  }

  No * apontador = fila->cabeca;

  system("clear");

  if (tipoExibicao == 1) {
    printf("\t\tFila de atendimento: \n\n");
  } else {
    printf("\t\tBase de Dados:\n\n");
  }

  while (apontador != NULL) {
    if (tipoExibicao == 1) {
      printf("\t\t| Nome: %s, Codigo: %d, Codigo de prioridade: %d, Tamanho do arquivo: %d, Tempo em fila: %d | \n",
      strtok(apontador->dado.nome, "\n"), apontador->dado.codigo, apontador->dado.codigoDePrioridade
      , apontador->dado.tamArq, apontador->dado.tempoFila);
      printf("\t\t\t\t\t\t\t\t^\n");
      printf("\t\t\t\t\t\t\t\t|\n");
    } else {
      printf("\t\tNome: %s\n\t\tCodigo: %d\n\t\tCodigo de prioridade: %d\n",
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

    guardarLog(auxPonteiro, 1);

    printf("\n\t\tO cliente %s foi atendido!\n\n", strtok(auxPonteiro->dado.nome, "\n"));
    fila->cabeca = auxPonteiro->prox;
    free(auxPonteiro);
    fila->tamFila--;
  } else {
    printf("\n\t\tNão tem clientes na fila de atendimento\n");
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

  time_t segundos;
  struct tm * dataHora;

  time(&segundos);

  dataHora = localtime(&segundos);
  
  if (vazia(auxFila)) {
    printf("\t\tBase de dados esta vazia\n");
    return;
  }

  int * estaEmFila;
  int * emFila;

  exiberFila(auxFila, 2);

  int codigo, aux = 1;

  do {
    printf("\t\tinsira o codigo do cliente: ");
    scanf("%d", &codigo);

    
    estaEmFila = verificaCodigo(origFila, codigo);


    if (estaEmFila[0]) {
      printf("\n\t\tO cliente com o codigo %d já esta na fila\n\n", codigo);
      estaEmFila[0] = 0;
      estaEmFila[1] = 0;
      estaEmFila[2] = 0;
      aux = 1;
    } else {

      emFila = verificaCodigo(auxFila, codigo);
      
      if (emFila[0] != 1) {
        printf("\t\tCodigo não encontrado\n");
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

  printf("\t\tinsira tamanho do arquivo: ");
  scanf("%d", &auxPonteiroAuxFila->dado.tamArq);

  No * auxPonteiroOrigFila = (No*) malloc(sizeof(No));

  char data[10];

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

  strftime(data, 10, "%d/%m/%y", dataHora);
  strcpy(auxPonteiroOrigFila->dado.dataEnt, data);
  strcpy(auxPonteiroOrigFila->dado.horaEnt, __TIME__);
  
  printf("\n\t\tO cliente %s foi inserido na fila\n\n", strtok(auxPonteiroOrigFila->dado.nome, "\n"));

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


No * noNaPosicao(Fila * fila, int indice) {
  
  if (indice >= 0 & indice < fila->tamFila) {
    No * auxPont = fila->cabeca;
    int i;

    for (i = 0; i < indice; i++) {
      auxPont = auxPont->prox;
    }

    return auxPont;
  }

  return NULL;
}


int indiceDoNo(Fila * fila, No * no) {

  if (!vazia(fila)) {
    No * auxNo = fila->cabeca;
    int indice = 0;
    while (auxNo != no && auxNo != NULL) {
      auxNo = auxNo->prox;
      indice++;
    }

    if (auxNo != NULL) {
      return indice;
    }
  }

  return -1;
}


void trocarNo(Fila * fila, No * primeiroNo, No * segundoNo) {
  
  if (primeiroNo == segundoNo) {
    return;
  }

  int indicePrimeiroNo = indiceDoNo(fila, primeiroNo);
  int indiceSegundoNo = indiceDoNo(fila, segundoNo);

  if (indicePrimeiroNo > indiceSegundoNo) {
    primeiroNo = segundoNo;
    segundoNo = noNaPosicao(fila, indicePrimeiroNo);

    indicePrimeiroNo = indiceSegundoNo;
    indiceSegundoNo = indiceDoNo(fila, segundoNo);
  }

  No * anteriorSegundoNo = noNaPosicao(fila, indiceSegundoNo - 1);

  if (primeiroNo == fila->cabeca) {
    fila->cabeca = segundoNo;
  } else {
    No * anteriorPrimeiroNo = noNaPosicao(fila, indicePrimeiroNo - 1);
    anteriorPrimeiroNo->prox = segundoNo;
  }

  anteriorSegundoNo->prox = primeiroNo;

  No * aux = primeiroNo->prox;
  primeiroNo->prox = segundoNo->prox;
  segundoNo->prox = aux;
}


No * maximo(Fila * fila, int indice, int tipo) {

  if (vazia(fila)) {
    return NULL;
  }

  No * auxPont = noNaPosicao(fila, indice);

  if (auxPont != NULL) {
    
    No * maxNo = auxPont;
    
    if (tipo == 1) {
      while (auxPont != NULL) {
        if (auxPont->dado.codigoDePrioridade > maxNo->dado.codigoDePrioridade) {
          maxNo = auxPont;
        }
        auxPont = auxPont->prox;
      }

      return maxNo;

    } else {
       while (auxPont != NULL) {
        if (auxPont->dado.tempoFila > maxNo->dado.tempoFila) {
          maxNo = auxPont;
        }
        auxPont = auxPont->prox;
      }

      return maxNo;

    }

  }

  return NULL;
}


void ordernar(Fila * fila, int tipo) {
  int i;

  for (i = 0; i < fila->tamFila; i++) {
    trocarNo(fila, noNaPosicao(fila, i), maximo(fila, i, tipo));
  }
}


int vazia(Fila * fila) {
  if (fila->cabeca == NULL) {
    return 1;
  }
  return 0;
}


int menu() {
  char opcao;

  printf("\t\t========= Menu Principal =========\n");
  printf("\t\t1 - Menu Cliente\n");
  printf("\t\t2 - Menu Atendimento\n");
  printf("\t\t3 - sair\n");
  printf("\t\topção: ");
  scanf("%c", &opcao);

  system("clear");

  return opcao;
}


void auxMenu(Fila * filaAux, Fila * origFila) {
  char op;
  limpabuffer();
  op = menu();
  opcao(op, filaAux, origFila);
}


void menuCadastro(Fila * filaAux, Fila * origFila) {
  char opcao;

  limpabuffer();

  printf("\t\t========= Menu Cliente =========\n");
  printf("\t\t1 - Cadastra Cliente\n");
  printf("\t\t2 - Listar Clientes da Base de Dados\n");
  printf("\t\t3 - Alterar Codigo do Cliente Em Arquivo\n");
  printf("\t\t4 - Alterar Codigo de Prioridade do Cliente Em Arquivo\n");
  printf("\t\t5 - Voltar ao Menu Anterior\n");
  printf("\t\t6 - Sair\n");
  printf("\t\topção: ");
  scanf("%c", &opcao);

  system("clear");

  switch (opcao) {
    case '1':
      cadastraCliente();
      menuCadastro(filaAux, origFila);
      break;
    case '2':
      exibirClienteDB();
      menuCadastro(filaAux, origFila);
      break;
    case '3':
      // Alterar Codigo do Cliente em arquivo
      alterarCodigoClienteArq();
      menuCadastro(filaAux, origFila);
      break;
    case '4':
      // Alterar Codigo de Prioridade do Cliente em arquivo
      alterarCodigoClientePrioridadeArq();
      menuCadastro(filaAux, origFila);
      break;
    case '5':
      auxMenu(filaAux, origFila);
      break;
    case '6': 
      exit(1);
    default:
      printf("\t\tOpção invalida!\n");
      menuCadastro(filaAux, origFila);
      break;
  }
}


void menuAtendimento(Fila * filaAux, Fila * origFila) {
  char opcao;

  pegaDadosEmArquivo(filaAux);

  limpabuffer();

  printf("\t\t========= Menu Atendimento =========\n");
  printf("\t\t1 - Atender Cliente\n");
  printf("\t\t2 - Listar Fila de Atrendimento\n");
  printf("\t\t3 - Inserir Cliente em Fila de Atendimento\n");
  printf("\t\t4 - Voltar ao Menu Anterior\n");
  printf("\t\t5 - sair\n");
  printf("\t\topção: ");
  scanf("%s", &opcao);

  system("clear");

  switch (opcao) {
    case '1':
      removeNo(origFila);
      menuAtendimento(filaAux, origFila);
      break;
    case '2':
      exiberFila(origFila, 1);
      menuAtendimento(filaAux, origFila);
      break;
    case '3':
      inserirClienteEmFila(origFila, filaAux);
      menuAtendimento(filaAux, origFila);
      break;
    case '4':
      auxMenu(filaAux, origFila);
      break;
    case '5':
      exit(1);
    default:
      printf("\t\tOpção invalida!\n");
      menuAtendimento(filaAux, origFila);
      break;
  }
}


void opcao(char opcao, Fila * filaAux, Fila * origFila) {
  switch (opcao) {
    case '1':
      menuCadastro(filaAux, origFila);
      break;
    case '2':
      menuAtendimento(filaAux, origFila);
      break;
    case '3':
      exit(1);
    default:
      printf("\t\tOpção invalida!\n");
      break;
  }
}


void cadastraCliente() {
  DadoNo dado;
  int codigoPrio, codigoCli;
  int auxVerif;

  system("clear");
  limpabuffer();

  printf("\t\tinsira o nome do cliente: ");
  fgets(dado.nome, 20, stdin);


  do {
    printf("\t\tinsira o codigo do cliente: ");
    scanf("%d", &codigoCli);
    auxVerif = verificaCodigoEmArquivo(codigoCli);
    if (auxVerif) {
      printf("\t\tCodigo já existe, tente outro!\n");
    }
  } while (auxVerif);
  dado.codigo = codigoCli;

  do {
    printf("\t\tinsira o codigo de prioridade do cliente: ");
    scanf("%d", &codigoPrio);
    if (codigoPrio < 0 || codigoPrio > 4) {
      printf("\t\tCodigo de prioridade invalido, os codigos devem estar entra 1 e 4\n");
    }
  } while (codigoPrio < 0 || codigoPrio > 4);
  dado.codigoDePrioridade = codigoPrio;

  guardaEmArquivo(dado);
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
    printf("\t\tNão foi possivel criar o arquivo,\n\t\tentre em contato com o desenvolvedor.\n");
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
    printf("\t\tArquivo não encontrado!\n");
  }

  fclose(arquivo);

  return tamanho;
}


void guardarLog(No * noDado, int tipo) {
  FILE * log;
  time_t segundos;
  struct tm * dataHoraAtual;
  char data[10];

  time(&segundos);

  dataHoraAtual = localtime(&segundos);

  log = fopen("logCliente.txt", "a");

  if (log) {

    strftime(data, 10, "%d/%m/%y", dataHoraAtual);

    fprintf(log, "Entrada: Hora %s Data %s \n", noDado->dado.horaEnt, noDado->dado.dataEnt);   
    
    fprintf(log, "Nome: %s\nCodigo: %d\nCodigo Prioridade: %d\nTamanho Arquivo:%d\n", 
      noDado->dado.nome, noDado->dado.codigo, noDado->dado.codigoDePrioridade, noDado->dado.tamArq);

    fprintf(log, "Saida: Hora %s Data %s \n--------------------------------------\n", __TIME__, data); 

  } else {
    printf("\t\tNão foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
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
    printf("\t\tNão foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
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
    printf("\t\tArquivo não encontrado!\n");
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

    printf("\t\tBase de Dados:\n");
    
    for (i = 0; i < tamNomeArq; i++) {
      fscanf(codigo, "%d", &codigoArq);
      fscanf(codigoPrioridade, "%d", &codigoPrioArq);
      fscanf(nome, "%s", nomeArq);
      printf("\n");
      printf("\t\tNome: %s \n", strtok(nomeArq, "\n"));
      printf("\t\tCodigo: %d \n", codigoArq);
      printf("\t\tCodigo Prioridade: %d \n", codigoPrioArq);
      printf("\n");
    }
  } else {
    printf("\t\tArquivo não encontrado!\n");
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
    printf("\t\tBase de Dados vazia\n");
    return;
  }
  
  codigo = fopen("codigoCliente.txt", "r");

  if (codigo) {
    for (i = 0; i < tamArq; i++) {
      fscanf(codigo, "%d", &arrayCodigo[i]);
    }
  } else {
    printf("\t\tArquivo não encontrado!\n");
  }

  fclose(codigo);

  int codigoAntigo, codigoNovo;
  int * verifCodigo;

  do {
    printf("\t\tDigite o Codigo Antigo: ");
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
    printf("\t\tDigite o Novo Codigo: ");
    scanf("%d", &codigoNovo);
    verifCodigo = verifCodigos(arrayCodigo, codigoNovo, tamArq);
    if (verifCodigo[0] == 1) {
      printf("\t\tCodigo %d já exite, tente outro.\n", codigoNovo);
    }
  } while (verifCodigo[0]);

  verifCodigo = verifCodigos(arrayCodigo, codigoAntigo, tamArq);


  arrayCodigo[verifCodigo[1]] = codigoNovo;
  limpaArquivo("codigoCliente.txt");

  FILE * cod;

  cod = fopen("codigoCliente.txt", "a");
  for (i = 0; i < tamArq; i++) {
    fprintf(cod, "%d\n", arrayCodigo[i]);
  }

  fclose(cod);
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
    printf("\t\tBase de Dados vazia\n");
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
    printf("\t\tArquivo não encontrado!\n");
  }
  fclose(codigo);
  fclose(codigoPrioridade);

  int codigoCli, codigoNovo;
  int * verifCodigo;

  do {
    printf("\t\tDigite o Codigo Cliente: ");
    scanf("%d", &codigoCli);
    verifCodigo = verifCodigos(arrayCodigo, codigoCli, tamCodArq);
    if (verifCodigo[0] == 0) {
      printf(" Codigo %d não exite.\n", codigoCli);
      verifCodigo[0] = 0;
      verifCodigo[1] = 0;
    }
  } while (!verifCodigo[0]);


  do {
    printf("\t\tDigite o Novo Codigo de Prioridade: ");
    scanf("%d", &codigoNovo);
    if (codigoNovo < 0 || codigoNovo > 4) {
      printf("\t\tCodigo de prioridade invalido, os codigos devem estar entra 1 e 4\n");
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

