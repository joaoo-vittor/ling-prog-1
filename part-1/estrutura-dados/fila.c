#include <stdio.h>

// Fila / Queue;

// O elemento que entra primeiro, sai primeiro;
// Sempre que um elemento é adicionado na fila, ele vai para i final dela;

// FIFO - First In | First Out;


#define TAMFILA 10


// fila
int fila[TAMFILA] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int head = 0;
int tail = 0;


void lista_elementos();
void adiciona_elemento();
void remove_elemento();
void limpa_fila();


int main() {

  char opcao;

  while (opcao != 's' || opcao != 'S') {
    printf("Selecione a opcao: \n\n");
    printf("[a] - Inserir elemento na fila.\n");
    printf("[b] - Remover elemento da fila.\n");
    printf("[c] - Limpar a fila.\n");
    printf("[d] - Listar\n");
    printf("[s] - Para sair.\n\n");
    
    scanf("%c", &opcao);
    // getchar();

    switch (opcao) {
      case 'a':
      case 'A':
        adiciona_elemento();
        break;
      case 'b':
      case 'B':
        remove_elemento();
        break;
      case 'c':
      case 'C':
        limpa_fila();
        break;
      case 'd':
      case 'D':
        lista_elementos();
        break;
      case 's':
      case 'S':
        break;
      default:
        printf("Opcao invalida!\n");
        break;
    }

    // limpar o buffer
    while ((opcao = getchar()) != '\n' && opcao != EOF) {}

  }

  return 0;
}


void lista_elementos() {
  int i;
  printf("\n====================FILA ATUAL====================\n");
  for (i = 0; i < TAMFILA; i ++) {
    printf("-");
    printf("|%d|", fila[i]);
    printf("-");
  }
  printf("\n\nHead: %d\n", head);
  printf("Tail: %d\n", tail);
  printf("\n\n");
}


void adiciona_elemento() {
  int valor;
  if (tail < TAMFILA) {
    printf("Informe o elemento para ser inserido na fila: ");
    scanf("%d", &valor);
    fila[tail] = valor;
    tail += 1;
    lista_elementos();
  } else {
    printf("A fila está cheia ...\n");
  }
}


void remove_elemento() {
  if (head < tail) {
    fila[head] = 0;
    head += 1;
    lista_elementos();
  } else {
    printf("A lista está vazia...");
  }
}


void limpa_fila() {
  int i;
  for (i = 0; i < TAMFILA; i++) {
    fila[i] = 0;
  }
  head = 0;
  tail = 0;
}

