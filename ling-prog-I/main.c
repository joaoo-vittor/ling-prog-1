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
} Produto;

typedef struct {
  Produto produto;
  int quantidade;
} Carrinho;


// Prototipação

void infoProduto(Produto produto);
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNocarrinho(int codigo);
void fecharPedido();
void limpabuffer();
Produto guardaEmArquivo();
Produto buscaEmArquivo();
int tamanhoArquivo(char nome[]);


// Variaveis globais

static int contadorProduto = 0;
static int contadorCarrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main() {
  setlocale(LC_ALL, "Portuguese");

  menu();

  return 0;
}


void infoProduto(Produto produto) {
  printf(" Código: %d \n Nome: %s \n Preço: %.2f\n", produto.codigo, strtok(produto.nome, "\n"), produto.preco);
}


void menu() {
  int opcao;

  printf(" ================================\n");
  printf(" ========= Bem-vindo(a) =========\n");
  printf(" =========    mercado   =========\n");
  printf(" ================================\n");

  printf(" Selecione uma opção abaixo: \n");
  printf(" 1 - Cadastra produto\n");
  printf(" 2 - Listar produtos\n");
  printf(" 3 - Comprar produto\n");
  printf(" 4 - Vizualizar carrinho\n");
  printf(" 5 - Finalizar compra\n");
  printf(" 6 - Sair\n ");

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


void cadastrarProduto() {
  printf(" Cadastra Produto\n");
  printf(" =================\n");

  printf(" Informe o nome do produto: \n ");
  fgets(produtos[contadorProduto].nome, 30, stdin);

  printf(" Informe o preço do produto: \n ");
  scanf("%f", &produtos[contadorProduto].preco);

  printf(" O produto %s foi cadastrado com sucesso.\n", strtok(produtos[contadorProduto].nome, "\n"));

  produtos[contadorProduto].codigo = (contadorProduto + 1);
  contadorProduto++;
  guardaEmArquivo();

  limpabuffer();
  sleep(2);
  menu();
}


void listarProdutos() {
  int i;

  buscaEmArquivo();
  
  if (contadorProduto > 0) {
    printf(" Listagem de produtos: \n");
    printf(" ---------------------\n");
    for (i = 0; i < contadorProduto; i++) {
      infoProduto(produtos[i]);
      printf(" ---------------------\n");
      sleep(1);
      // Sleep(1); // Utilize esta função caso esteja no windows;
    }
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
  
  if (contadorProduto > 0) {
    printf(" Informe o código do produto que deseja adicionar no carrinho: \n");

    printf(" ========= Produtos Disponíveis =========\n");
    for (i = 0; i < contadorProduto; i++) {
      infoProduto(produtos[i]);
      printf(" ---------------------\n ");
      sleep(1);
      // Sleep(2); // Utilize esta função caso esteja no windows;
    }
    
    scanf("%d", &codigo);
    getchar();

    for (i = 0; i < contadorProduto; i++) {
      if (produtos[i].codigo == codigo) {
        temMercado = 1;
        if (contadorCarrinho > 0) {
          itemCarrinho = temNocarrinho(codigo);

          if (itemCarrinho[0] == 1) {
            carrinho[itemCarrinho[1]].quantidade++;
            printf(" Aumentei a quantidade em 1 unidade do produto %s, já existente no carrinho.\n", 
            strtok(carrinho[itemCarrinho[1]].produto.nome, "\n"));
            sleep(2);
            // Sleep(2); // Utilize esta função caso esteja no windows;
            menu();
          } else {
            prod = pegarProdutoPorCodigo(codigo);
            carrinho[contadorCarrinho].produto = prod;
            carrinho[contadorCarrinho].quantidade = 1;
            contadorCarrinho++;
            printf(" O produto %s, foi adicionado ao carrinho.\n", strtok(prod.nome, "\n"));
            sleep(2);
            // Sleep(2); // Utilize esta função caso esteja no windows;
            menu();
          }
        } else {
          prod = pegarProdutoPorCodigo(codigo);
          carrinho[contadorCarrinho].produto = prod;
          carrinho[contadorCarrinho].quantidade = 1;
          contadorCarrinho++;
          printf(" O produto %s, foi adicionado ao carrinho.\n", strtok(prod.nome, "\n"));
          sleep(2);
          // Sleep(2); // Utilize esta função caso esteja no windows;
          menu();
        }
      } 
    }

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
      infoProduto(carrinho[i].produto);
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
      infoProduto(prod);
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


Produto guardaEmArquivo() {
  int i;
  FILE * idProduto;
  FILE * nomeProduto;
  FILE * precoProduto;

  idProduto = fopen("idProduto.dat", "ab");
  nomeProduto = fopen("nomeProduto.dat", "ab");
  precoProduto = fopen("precoProduto.dat", "ab");

  if (idProduto && nomeProduto && precoProduto) {
    for (i = contadorProduto - 1; i < contadorProduto; i++) {
      fprintf(idProduto, "%d\n", produtos[i].codigo);
      fprintf(nomeProduto, "%s\n", produtos[i].nome);
      fprintf(precoProduto, "%.2f\n", produtos[i].preco);
    }
  } else {
    printf(" Não foi possivel criar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(idProduto);
  fclose(nomeProduto);
  fclose(precoProduto);

}


Produto buscaEmArquivo() {
  int i;
  FILE * idProduto;
  FILE * nomeProduto;
  FILE * precoProduto;
  int tamArqId, tamArqNome, tamArqPreco;
  int aux;
  char auxnome[30];

  idProduto = fopen("idProduto.dat", "rb");
  nomeProduto = fopen("nomeProduto.dat", "rb");
  precoProduto = fopen("precoProduto.dat", "rb");

  if (idProduto && nomeProduto && precoProduto) {
  
    tamArqId = tamanhoArquivo("idProduto.dat");
    tamArqNome = tamanhoArquivo("nomeProduto.dat");
    tamArqPreco = tamanhoArquivo("precoProduto.dat");
    
    printf(" %d\n", tamArqId);
    printf(" %d\n", tamArqNome);
    printf(" %d\n", tamArqPreco);

    if (tamArqId == tamArqNome && tamArqNome == tamArqPreco) {
      printf(" Entrei\n");
      for (i = 0; i < tamArqId; i++) {
        // fread(aux, sizeof(int), tamArqId, idProduto);
        // printf("%d", aux);
        fgets(auxnome, 30, nomeProduto);
        printf(" %s", auxnome);
        // fscanf(idProduto, "%d", produtos[i].codigo);
        // fscanf(precoProduto, "%f", produtos[i].preco);
      }
    }


  } else {
    printf(" Não foi possivel encontrar o arquivo,\n entre em contato com o desenvolvedor.\n ");
  }

  fclose(idProduto);
  fclose(nomeProduto);
  fclose(precoProduto);

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

  return tamanho;
}

