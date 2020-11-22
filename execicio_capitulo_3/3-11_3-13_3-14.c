/*

Disciplina : 2020.1 LABORATÓRIO DE PROGRAMAÇÃO I
Aluno: João Vitor Barbosa da Silva


3.11 Identifique e corrija os erros dos seguintes trechos e có-
digos: [Nota: pode haver mais de um erro em cada um.]


a)

  if ( idade >= 65 );
    printf( “Idade é maior ou igual a
    65\n” );
  else
    printf( “Idade é menor que 65\n” );


b)
  int x = 1, total;

  while ( x <= 10 )
    total += x;
    ++x;
  }


c)
  while ( x <= 100 )
    total += x;
    ++x;


d)



===> RESPOSTA:

a)

#include <stdio.h>

int main() {
  int idade = 0;

  printf("Qual sua idade: ");
  scanf("%d", idade);

  if( idade >= 65 ) {
    printf("Idade é maior ou igual a 65\n");
  } else {
    printf("Idade é menor que 65\n");
  }

  return 0;
}

b)

#include <stdio.h>

int main() {
  int x = 1, total;

  while( x <= 10 ) {
    total += x;
    ++x;
  }

  return 0;
}

c)

#include <stdio.h>

int main() {
  int x = 1, total;

  while( x <= 100 ) {
    total += x;
    ++x;
  }

  return 0;
}

d)

#include <stdio.h>

int main() {

  while( y > 0 ) {
    printf("%d\n", y);
    ++y;
  }

  return 0;
}


*/

/*

3.13 O que o programa a seguir imprime?

#include <stdio.h>
int main( void )
{
int x = 1, total = 0, y;

while ( x <= 10 ) {
  y = x * x;
  printf( “%d\n”, y );
  total += y;
  ++x;

} // fim do while

  printf(“Total is %d\n”, total);
  return 0;

} // fim do main

===> RESPOSTA:
  O programa acima imprime a acumulação da multiplação de x * x


*/

/*
3.14 Escreva uma única instrução em pseudocódigo que indi-
que cada um dos seguintes comandos:

a) Apresente a mensagem ' Digite dois números '.
  escreva(' Digite dois números ')

b) Atribua a soma das variáveis x , y e z à variável p .
  p = x + y + z

c) A seguinte condição deve ser testada em uma estru-
tura de seleção if...else : o valor atual da variável
m é maior que o dobro do valor atual da variável v .
  if m > (v*2)

d) Obtenha valores para as variáveis s , r e t pelo te-
clado.
  leia(s)
  leia(r)
  leia(t)


*/
