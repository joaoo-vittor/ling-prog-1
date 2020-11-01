#include <stdio.h>
#include <string.h>

int main() {
  
  char s[] = "NONPNOPNP.........NONPNOPNP";
  int n = strlen(s);
  int m;

  while (1) {
    scanf("%d", &m);

    if (!m) {
      return 0;
    }

    int i = 0;

    while (m--) {
      printf("%d", s[i]);
      i = (i + 1) % n;
    }
  printf("\n");
  }
  
  return 0;
}