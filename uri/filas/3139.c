#include <stdio.h>
#include <math.h>

#define tam 30


int fila[tam] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; 
int cabeca = 0;
int fim = 29;


int andaFila(int * media) {
  int i;
  int aux;

  fila[0] = 0;

  for (i = 1; i < 30; i++) {
    aux = fila[i];
    fila[i-1] = aux;
  }

  fila[fim] = (*media);

}

int fazerMedia() {
  int i;
  int media = 0;

  for (i = 0; i < 30; i++) {
    media += fila[i];
  }

  media = media/30;
  media = ceil(media);

  return media;
}


int main(){
  int n, m;
  int i, cont = 0;
  int soma = 0;
  int media;
  int aux = 0;
  int casoBase = 0;


  scanf("%d %d", &n, &m);

  for (i = 0; i < 30; i++) {
    scanf("%d", &fila[i]);
  }

  casoBase = n;

  while (1) {
    media = fazerMedia();
    andaFila(&media);
    
    if (casoBase > m) {
      printf("%d\n", cont);
      break;
    }
    
    casoBase += fila[cabeca];
    
    cont++;
    cabeca++;
    
    if (cabeca > 29) {
      cabeca = 0;
    }
  }

  return 0;
}