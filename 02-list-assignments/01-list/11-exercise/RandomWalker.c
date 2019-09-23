#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Point.h"
/* a biblioteca time.h foi utilizada para a inicializacao do seed do gerador de numeros aleatorios */

/* o programa recebe uma quantidade de passos aleatorios inseridos pelo usuario e os executa,
   imprimindo cada coordenada e, ao final, a distancia ate a origem ao quadrado */
int main () {
	int N, i;
	point caminhante_pos, origem;
	caminhante_pos.x = 0, caminhante_pos.y = 0;
	origem.x = 0, origem.y = 0;

	printf ("Insira a quantidade de passos para o caminhante aleatorio: ");
	scanf ("%d", &N);
	
	srand (time(NULL));

	for (i = 0; i < N; i++) {
		caminhante_pos = passo (caminhante_pos);
		imprime (caminhante_pos);
	}
	
	printf ("\ndistancia ao quadrado = %d", quadrado_distancia (origem, caminhante_pos));

	return 0;
}

	