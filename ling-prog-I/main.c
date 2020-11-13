#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h> // Linux ou Mac
// #include <windows.h>


// Structs

typedef struct {
  int codigo;
  char nome[30];
  float preco;
  int estoque;
} Produto;


typedef struct {
  Produto produto;
  int quantidade;
} Carrinho;


// Prototipação

void infoProdutoCarrinho(Produto produto);
void infoProduto(int flag);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNocarrinho(int codigo);
void fecharPedido();
void limpabuffer();
int buscaEmArquivo(int codigo);
int tamanhoArquivo(char nome[]);
int pegaUltimoID(char nome[]);
int * verificaID(int codigo);
void inicializaArquivo();
int reduzEstoque(int codigo);
int * pegaEstoque();
void limpa(char nome[]);
int * excluirProduto(int codigo);
int atualizaId(int * ids, int tamArq);
void excluir();
void atualizar();
int atualizaEstoque(int codigo, int novaQtd);


// Variaveis globais

static int contadorProduto = 0;
static int contadorCarrinho = 0;
static int indexProduto = 0;
static Carrinho carrinho[50];
static Produto produtos[50];


int main() {
  setlocale(LC_ALL, "Portuguese");

  inicializaArquivo();

  menu();

  return 0;
}


void infoProdutoCarrinho(Produto produto) {
  printf(" Código: %d \n Nome: %s \n Preço: %.2f \n Estoque: %d \n", produto.codigo, strtok(produto.nome, "\n"), produto.preco, produto.estoque);
}


void infoProduto(int flag) {
  
  FILE * idProduto;
  FILE * nomeProduto;
  FILE * precoProduto;
  FILE * estoque;
  
  int i;
  int auxId;
  char auxNome[30];
  float auxPreco;
  int tamArqId;
  int estoq;

  idProduto = fopen("idProduto.txt", "r");
  nomeProduto = fopen("nomeProduto.txt", "r");
  precoProduto = fopen("precoProduto.txt", "r");
  estoque = fopen("estoque.txt", "r");

  tamArqId = tamanhoArquivo("idProduto.txt");

  if (idProduto && nomeProduto && precoProduto) {
    for (i = 0; i < tamArqId; i++) {
      fscanf(idProduto, "%d", &auxId);
      fgets(auxNome, 30, nomeProduto);
      fscanf(precoProduto, "%f", &auxPreco);
      fscanf(estoque, "%d", &estoq);

      if (estoq != 0 && flag == 0) {
        printf(" Código: %d \n Nome: %s \n Preço: %.2f \n Estoque: %d \n ", auxId, strtok(auxNome, "\n"), auxPreco, estoq);
        printf("--------------------- \n");
      } 

      if (flag == 1) {
        printf(" Código: %d \n Nome: %s \n Preço: %.2f \n Estoque: %d \n ", auxId, strtok(auxNome, "\n"), auxPreco, estoq);
        printf("--------------------- \n");
      }

      sleep(1);
    }
    printf(" ");
  }

  fclose(idProduto);
  fclose(nomeProduto);
  fclose(precoProduto);
  fclose(estoque);
}


void menu() {
  int opcao;

  contadorProduto = pegaUltimoID("idProduto.txt");

  printf(" ================================\n");
  printf(" ========= Bem-vindo(a) =========\n");
  printf(" =========    mercado   =========\n");
  printf(" ================================\n");

  printf(" Selecione uma opção abaixo: \n");
  printf(" 1 - Cadastra produto\n");
  printf(" 2 - Listar produtos\n");
  printf(" 3 - Comprar produto\n");
  printf(" 4 - Vizualizar carrinho\n");
  printf(" 5 - Fechar Pedido\n");
  printf(" 6 - Excluir Produto\n");
  printf(" 7 - Atualizar Produto\n");
  printf(" 8 - Sair\n ");

  scanf("%d", &opcao);
  getchar();

  switch (opcao) {
    case 1:
      cadastrarProduto();
      break;
    case 2:
      listarProdutos();
      break;
    case 3:
      comprarProduto();
      break;
    case 4:
      visualizarCarrinho();
      break;
    case 5:
      fecharPedido();
      break;
    case 6:
      excluir();
      break;
    case 7:
      atualizar();
      break;  
    case 8:
      printf("\tVolte sempre!!!\n");
      sleep(2);
      // Sleep(2); // Utilize esta função caso esteja no windows;
      exit(0);
    default:
      printf(" Opção invalida.\n");
      limpabuffer();
      sleep(2);
      // Sleep(2); // Utilize esta função caso esteja no windows;
      menu();
      break;
  }

}


void excluir() {
  int codigo;

  printf(" Excluir Produto\n");
  printf(" =================\n");
  infoProduto(0);

  printf("Informe o id do produto: \n ");
  scanf("%d", &codigo);

  excluirProduto(codigo);

  menu();
}

void atualizar() {
  int codigo;
  int novaQtd;

  printf(" Atualizar Produto\n");
  printf(" =================\n");
  infoProduto(1);

  printf("Informe o id do produto: \n ");
  scanf("%d", &codigo);

  printf(" Informe a nova quantidade: \n ");
  scanf("%d", &novaQtd);

  atualizaEstoque(codigo, novaQtd);

  menu();
}


void cadastrarProduto() {
  
  FILE * idProduto;
  FILE * nomeProduto;
  FILE * precoProduto;
  FILE * estoque;

  
  int i;
  char nome[30];
  float preco;
  int ultimoID = 0;
  int aux;
  int estoq;

  printf(" Cadastra Produto\n");
  printf(" =================\n");

  printf(" Informe o nome do produto: \n ");
  fgets(nome, 30, stdin);

  printf(" Informe o preço do produto: \n ");
  scanf("%f", &preco);

  printf(" Informe a quantidade em estoque do produto %s: \n ", strtok(nome, "\n"));
  scanf("%d", &estoq);

  printf(" O produto %s foi cadastrado com sucesso.\n", strtok(nome, "\n"));

  aux = tamanhoArquivo("idProduto.txt");

  if (aux > 0) {
    ultimoID = pegaUltimoID("idProduto.txt");
  }

  idProduto = fopen("idProduto.txt", "a");
  nomeProduto = fopen("nomeProduto.txt", "a");
  precoProduto = fopen("precoProduto.txt", "a");
  estoque = fopen("estoque.txt", "a");


  if (idProduto && nomeProduto && precoProduto) {
    fprintf(idProduto, "%d\n", ultimoID + 1);
    fprintf(nomeProduto, "%s\n", nome);
    fprintf(precoProduto, "%.2f\n", preco);
    fprintf(estoque, "%d\n", estoq);
  } else {
    printf(" Não foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(idProduto);
  fclose(nomeProduto);
  fclose(precoProduto);
  fclose(estoque);

  contadorProduto++;

  limpabuffer();
  sleep(2);
  menu();
}


void listarProdutos() {
  int i;
  int temProduto;

  temProduto = tamanhoArquivo("idProduto.txt");
  
  if (temProduto > 0) {
    printf(" Listagem de produtos: \n");
    printf(" ---------------------\n");
    infoProduto(0);
    sleep(2);
    menu();
  } else {
    printf(" Não temos produtos cadastrados.\n");
    sleep(2);
    menu();
  }
}


void comprarProduto() {
  int i, codigo, temMercado = 0;
  int * itemCarrinho;
  Produto prod;
  int * verificaId;
  int temProdArq;

  temProdArq = tamanhoArquivo("idProduto.txt");
  
  if (contadorProduto > 0 && temProdArq > 0) {
    printf(" Informe o código do produto que deseja adicionar no carrinho: \n");

    printf(" ========= Produtos Disponíveis =========\n");
    infoProduto(0);
    sleep(1);
    
    scanf("%d", &codigo);
    getchar();

    verificaId = verificaID(codigo);

    if (verificaId == 0) {
      printf(" O produto não existe.\n");
      menu();
    }

    for (i = 0; i < contadorProduto; i++) {
      if (verificaId[0] == 1) {
        
        temMercado = 1;
        
        if (contadorCarrinho > 0) {
          itemCarrinho = temNocarrinho(codigo);

          if (itemCarrinho[0] == 1) {
            carrinho[itemCarrinho[1]].produto.estoque -= 1;
            carrinho[itemCarrinho[1]].quantidade++;
            reduzEstoque(codigo);
            printf(" Aumentei a quantidade em 1 unidade do produto %s, já existente no carrinho.\n", 
            strtok(carrinho[itemCarrinho[1]].produto.nome, "\n"));
            itemCarrinho[0] = 0;
            itemCarrinho[1] = 0;
            sleep(2);
            // Sleep(2); // Utilize esta função caso esteja no windows;
            menu();
          } else {
            buscaEmArquivo(codigo);
            reduzEstoque(codigo);
            prod = pegarProdutoPorCodigo(codigo);
            carrinho[contadorCarrinho].produto = prod;
            carrinho[contadorCarrinho].quantidade = 1;
            carrinho[contadorCarrinho].produto.estoque -= 1;
            contadorCarrinho++;
            printf(" O produto %s, foi adicionado ao carrinho.\n", strtok(prod.nome, "\n"));
            sleep(2);
            // Sleep(2); // Utilize esta função caso esteja no windows;
            menu();
          }
        } else {
          buscaEmArquivo(codigo);
          reduzEstoque(codigo);
          prod = pegarProdutoPorCodigo(codigo);
          carrinho[contadorCarrinho].produto = prod;
          carrinho[contadorCarrinho].quantidade = 1;
          carrinho[contadorCarrinho].produto.estoque -= 1;
          contadorCarrinho++;
          printf(" O produto %s, foi adicionado ao carrinho.\n", strtok(prod.nome, "\n"));
          sleep(2);
          // Sleep(2); // Utilize esta função caso esteja no windows;
          menu();
        }
      } 
    }

    verificaId[0] = 0;
    verificaId[1] = 0;

    if (temMercado < 1) {
      printf(" Não foi encontrado o produto com código %d\n", codigo);
      sleep(2);
      // Sleep(2); // Utilize esta função caso esteja no windows;
      menu();
    }

  } else {
    printf(" Ainda não temos produtos disponiveis.\n");
    sleep(2);
    // Sleep(2); // Utilize esta função caso esteja no windows;
    menu();
  }
}


void visualizarCarrinho() {
  int i;

  if (contadorCarrinho > 0) {
    printf(" Produtos no carrinho: \n");
    printf(" ---------------------\n");
    for (i = 0; i < contadorCarrinho; i++) {
      infoProdutoCarrinho(carrinho[i].produto);
      printf(" Quantidade: %d\n", carrinho[i].quantidade);
      printf(" ---------------------\n");
      sleep(1);
      // Sleep(1); // Utilize esta função caso esteja no windows;
    }
    sleep(2);
    menu();
  } else {
    printf(" Não temos produtos no carrinho.\n");
    sleep(2);
    menu();
  }
}


Produto pegarProdutoPorCodigo(int codigo) {
  Produto prod;
  int i;

  for (i = 0; i < contadorProduto; i++) {
    if (produtos[i].codigo == codigo) {
      prod = produtos[i];
    }
  }

  return prod;
}


int * temNocarrinho(int codigo) {
  int static item[] = {0, 0};
  int i;

  for (i = 0; i < contadorCarrinho; i++) {
    if (carrinho[i].produto.codigo == codigo) {
      item[0] = 1; // Tem o produto no carrinho
      item[1] = i; // indice do produto
    }
  }

  return item;
}


void fecharPedido() {
  int i, quantidade;
  Produto prod;

  if (contadorCarrinho > 0) {
    float valorTotal = 0.0;
    printf(" Produtos do carrinho: \n");
    printf(" ---------------------\n");
    for (i = 0; i < contadorCarrinho; i++) {
      prod = carrinho[i].produto;
      quantidade = carrinho[i].quantidade;
      valorTotal += prod.preco * quantidade;
      infoProdutoCarrinho(prod);
      printf(" Quantidade: %d\n", quantidade);
      printf(" ---------------------\n");
      sleep(1);
      // Sleep(1); // Utilize esta função caso esteja no windows;
    }
    printf(" Sua fatura é R$ %.2f\n", valorTotal);

    // Limpar carrinho;
    contadorCarrinho = 0;
    printf(" Obrigado pela preferência.\n");
    sleep(5);
    menu();

  } else {
    printf(" Você não tem nenhum produto no carrinho ainda.\n");
    sleep(3);
    // Sleep(3); // Utilize esta função caso esteja no windows;
    menu();
  }
}


void limpabuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}


int buscaEmArquivo(int codigo) {
  
  FILE * idProduto;
  FILE * nomeProduto;
  FILE * precoProduto;
  FILE * estoque;
  
  int i;
  int tamArqId, tamArqNome, tamArqPreco, tamArqEstoque;
  int codigoDaBase;
  int estoqueBase;
  float precoDaBase;
  char nomeDaBase[30];
  int posicaoDeslocamento;


  idProduto = fopen("idProduto.txt", "r");
  nomeProduto = fopen("nomeProduto.txt", "r");
  precoProduto = fopen("precoProduto.txt", "r");
  estoque = fopen("estoque.txt", "r");


  if (idProduto && nomeProduto && precoProduto && estoque) {
  
    tamArqId = tamanhoArquivo("idProduto.txt");
    tamArqNome = tamanhoArquivo("nomeProduto.txt");
    tamArqPreco = tamanhoArquivo("precoProduto.txt");
    tamArqEstoque = tamanhoArquivo("estoque.txt");

    
    if (tamArqId == tamArqNome && tamArqNome == tamArqPreco && tamArqEstoque == tamArqPreco) {
      for (i = 0; i < tamArqId; i++) {
        fscanf(idProduto, "%d", &codigoDaBase);
        
        if (codigo == codigoDaBase) {
          posicaoDeslocamento = i;
        }
      }

      for (i = 0; i <= posicaoDeslocamento; i++) {
        if (i == posicaoDeslocamento) {
          fgets(produtos[indexProduto].nome, 30, nomeProduto);
          fscanf(precoProduto, "%f", &produtos[indexProduto].preco);
          fscanf(estoque, "%d", &produtos[indexProduto].estoque);
          produtos[indexProduto].codigo = codigo;
          break;
        }
        fgets(nomeDaBase, 30, nomeProduto);
        fscanf(precoProduto, "%f", &precoDaBase);
        fscanf(estoque, "%d", &estoqueBase);
      }

    }

  } else {
    printf(" Não foi possivel encontrar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(idProduto);
  fclose(nomeProduto);
  fclose(precoProduto);
}


int reduzEstoque(int codigo) {
  FILE * estoque;

  int * posicaoProd;
  int auxEstoque;
  int * arrayEstoque;
  int tamEstoque;
  int i;

  arrayEstoque = pegaEstoque();
  
  posicaoProd = verificaID(codigo);
  estoque = fopen("estoque.txt", "a");
  tamEstoque = tamanhoArquivo("estoque.txt");

  if (estoque) {
    limpa("estoque.txt");
    for (i = 0; i < tamEstoque; i++) {
      if (posicaoProd[1] == i) {
        fprintf(estoque, "%d\n", arrayEstoque[posicaoProd[1]]-1);
      }
      if (posicaoProd[1] != i) {
        fprintf(estoque, "%d\n", arrayEstoque[i]);
      }
    }
  }

  fclose(estoque);
}

void limpa(char nome[]) {
  FILE * estoque;
  estoque = fopen(nome, "w");
  fclose(estoque);
}


int * pegaEstoque() {
  FILE * estoque;

  int estoq;
  int static arrayEstoque[50] = {};
  int tamEstoque;
  int i;

  estoque = fopen("estoque.txt", "r");
  tamEstoque = tamanhoArquivo("estoque.txt");

  if (estoque) {
    for (i = 0; i < tamEstoque; i++) {
      fscanf(estoque, "%d", &arrayEstoque[i]);
    }
  } else {
    printf(" Arquivo não encontradp\n");
  }

  fclose(estoque);

  return arrayEstoque;
}


int tamanhoArquivo(char nome[]) {
  FILE * arquivo;
  int tamanho = 0;
  char c;

  arquivo = fopen(nome, "r");

  if (arquivo) {
    while ((c = getc(arquivo)) != EOF) {
      if (c == '\n') {
        tamanho++;
      }
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }

  fclose(arquivo);

  return tamanho;
}


int pegaUltimoID(char nome[]) {
  FILE * arquivo;
  int ultimoId;
  int tamDeslocamento;
  int i;
  int lixo;

  tamDeslocamento = tamanhoArquivo(nome);

  arquivo = fopen(nome, "r");

  if (arquivo) {
    for (i = 0; i < tamDeslocamento; i++) {
      if (i == tamDeslocamento-1) {
        fscanf(arquivo, "%d", &ultimoId);
        break;
      }
      fscanf(arquivo, "%d", &lixo);
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }

  fclose(arquivo);

  return ultimoId;
}


int * verificaID (int codigo) {
  FILE * idProduto;
  int tamArqId;
  int static retorno[] = {0, 0};
  int i;
  int idBase;

  idProduto = fopen("idProduto.txt", "r");
  tamArqId = tamanhoArquivo("idProduto.txt");

  if (codigo == 0) {
    return 0;
  }
  
  for (i = 0; i < tamArqId; i++) {
    fscanf(idProduto, "%d", &idBase);
    
    if (codigo == idBase) {
      retorno[0] = 1;
      retorno[1] = i;
    }
  }

  return retorno;
}


int * excluirProduto(int codigo) {
  FILE * auxEstoque;
  FILE * estoque;

  int static arrayEstoque[50] = {};
  int i, j;
  int auxEs;
  int tamArqEs;
  int * posicaoEx;
  
  estoque = fopen("estoque.txt", "r");
  posicaoEx = verificaID(codigo);
  tamArqEs = tamanhoArquivo("estoque.txt");

  if (estoque) {
    for (i = 0; i < tamArqEs; i++) {
      fscanf(estoque, "%d", &auxEs);
      if (posicaoEx[1] == i) {
        arrayEstoque[i] = 0;
      } else {
        arrayEstoque[i] = auxEs;
      }
    }
    fclose(estoque);
  } else {
    printf("Arquivo não encontrado!\n");
  }

  limpa("estoque.txt");

  auxEstoque = fopen("estoque.txt", "w");

  if (auxEstoque) {
    for (j = 0; j < tamArqEs; j++) {
      fprintf(auxEstoque, "%d\n", arrayEstoque[j]);
    }
  } else {
    printf("Arquivo não encontrado!\n");
  }

  fclose(auxEstoque);

  return arrayEstoque;
}


int atualizaEstoque(int codigo, int novaQtd) {
  FILE * estoque;
  FILE * auxEstoque;

  int static arrayEstoque[50] = {};
  int auxEst;
  int * posicaoEx;
  int tamArqEs; 
  int i, j;


  estoque = fopen("estoque.txt", "r");

  posicaoEx = verificaID(codigo);
  tamArqEs = tamanhoArquivo("estoque.txt");

  if (estoque) {
    for (i = 0; i < tamArqEs; i++) {
      fscanf(estoque, "%d", &auxEst);
      if (posicaoEx[1] == i) {
        arrayEstoque[i] = novaQtd;
      } else {
        arrayEstoque[i] = auxEst;
      }
    }
    fclose(estoque);
  } else {
    printf("Arquivo não encontrado!\n");
  }

  limpa("estoque.txt");

  auxEstoque = fopen("estoque.txt", "w");

  if (auxEstoque) {
    for (j = 0; j < tamArqEs; j++) {
      fprintf(auxEstoque, "%d\n", arrayEstoque[j]);
    }
    fclose(auxEstoque);
  } else {
    printf("Arquivo não encontrado!\n");
  }

}


void inicializaArquivo() {
  FILE * idProduto;
  FILE * nomeProduto;
  FILE * precoProduto;
  FILE * estoque;

  estoque = fopen("estoque.txt", "a");
  idProduto = fopen("idProduto.txt", "a");
  nomeProduto = fopen("nomeProduto.txt", "a");
  precoProduto = fopen("precoProduto.txt", "a");

  fclose(estoque);
  fclose(idProduto);
  fclose(nomeProduto);
  fclose(precoProduto);
}

