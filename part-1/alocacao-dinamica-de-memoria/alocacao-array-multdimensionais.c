#include <stdio.h>
#include <stdlib.h>

int main() {

  int *p, lin = 3, col = 3;

  p = (int*)malloc(lin * col * sizeof(int));

  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      p[i * col + j] = 3 * i + j;
    }
  }


  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d\n", p[i * col + j]);
    }
  }

  free(p);
  p = NULL;

  return 0;
}
