#include <stdio.h>



void main () {

	int linha, coluna;
	int aux, i, j;
	int pivo, auxQtdZero = 0, qtdZero = 0;
	int escada;


	scanf("%d %d", &linha, &coluna);
	int matriz[linha][coluna];

	for (i = 0; i < linha; i++) {
		
		for (j = 0; j < coluna; j++) {
			scanf("%d", &matriz[i][j]);
		}

	}

/*

1 1 1 1
0 0 1 1
0 0 0 0

*/
	for (i = 0; i < linha; i++) {
		for (j = 0; j < coluna; j++) {
			if (matriz[i][j] == 0 && qtdZero > auxQtdZero) {
				qtdZero++;
			}
		}
		auxQtdZero = qtdZero;
	}

	if (escada == 1) {
		printf("S\n");
	} else {
		printf("N\n");
	}

}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct brinquedo {

	unsigned short tempo;
	unsigned short qtsPontos;
	double razaoPontoTempo;

} brinquedo;

int compara(brinquedo *a, brinquedo *b);

void main () { 
	unsigned short i;
	unsigned short instancia;
	unsigned short qtsAtracoes;
	unsigned short limiteTempo, aux;
	unsigned short pontoTotal, tempoTotal;

	instancia = 0;
	while (true) {

		scanf("%hu %hu", &qtsAtracoes, &limiteTempo);

		if (qtsAtracoes == 0)
			break;

		brinquedo brinquedos[qtsAtracoes];

		for (i = 0; i < qtsAtracoes; ++i) {

			scanf("%hu %hu", &brinquedos[i].tempo, &brinquedos[i].qtsPontos);
			brinquedos[i].razaoPontoTempo = (brinquedos[i].qtsPontos / (double)brinquedos[i].tempo);

		}

		qsort(brinquedos, qtsAtracoes, sizeof(brinquedo), compara);

		i = 0;
		pontoTotal = tempoTotal = 0;

		while (i < qtsAtracoes){

			aux = tempoTotal + brinquedos[i].tempo;
			if (aux <= limiteTempo)
			{

				pontoTotal += brinquedos[i].qtsPontos;
				tempoTotal = aux;

			}
			else
				i++;
		}

		printf("Instancia %hu\n%hu\n\n", ++instancia, pontoTotal);

	}

}

int compara(brinquedo *a, brinquedo *b) {

	if (a->razaoPontoTempo == b->razaoPontoTempo)
		return 0;
	else if (a->razaoPontoTempo > b->razaoPontoTempo)
		return -1;
	else
		return 1;

}