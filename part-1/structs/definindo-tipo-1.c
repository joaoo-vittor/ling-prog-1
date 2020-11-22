#include <stdio.h>
#include <string.h>

struct st_aluno {
  char matricula[10];
  char nome[100];
  char curso[50];
  int ano_nascimento;
};
// }aluno1;

int main() {
  struct st_aluno aluno1;
  
  fflush(stdin);
  printf("Informe a matricula do aluno: ");
  fgets(aluno1.matricula, 10, stdin);

  fflush(stdin);
  printf("Informe o nome do aluno: ");
  fgets(aluno1.nome, 10, stdin);

  fflush(stdin);
  printf("Informe o curso do aluno: ");
  fgets(aluno1.curso, 10, stdin);

  fflush(stdin);
  printf("Informe o ano de nascimento do aluno: ");
  scanf("%d", &aluno1.ano_nascimento);
  // getchar();

  printf("\n");
  printf("============ DADOS DO ALUNO =============\n");
  printf("Matricula: %s\n", aluno1.matricula);
  printf("Nome: %s\n", aluno1.nome);
  printf("Curso: %s\n", aluno1. curso);
  printf("Ano de nascimento: %d\n", aluno1.ano_nascimento);

  return 0;
}

