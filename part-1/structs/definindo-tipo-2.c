#include <stdio.h>
#include <string.h>

struct st_contato {
  char nome[100];
  int ano_nascimento;
  char telefone[15];
  char email[100];
};

struct st_agenda {
  struct st_contato contatos[100];
}agenda;

int main() {
  int i, j;

  for (i = 0; i < 3; i++) {
    
    fflush(stdin);
    printf("Informe o nome: ");
    fgets(agenda.contatos[i].nome, 100, stdin);

    fflush(stdin);
    printf("Informe o ano de nascimento: ");
    scanf("%d", &agenda.contatos[i].ano_nascimento);
    getchar();

    fflush(stdin);
    printf("Informe o telefone: ");
    fgets(agenda.contatos[i].telefone, 15, stdin);

    fflush(stdin);
    printf("Informe o email: ");
    fgets(agenda.contatos[i].email, 100, stdin);
  }

  for (j = 0; j < 3; j++) {
    printf("============ AGENDA N°%d =============\n", (i+1));
    printf("\n");
    printf("Nome: %s\n", strtok(agenda.contatos[j].nome, "\n"));
    printf("Ano de nascimento: %d\n", agenda.contatos[j].ano_nascimento);
    printf("Telefone: %s\n", strtok(agenda.contatos[j].telefone, "\n"));
    printf("Email: %s\n", strtok(agenda.contatos[j].email, "\n"));
    printf("\n");
  }

  return 0;
}

