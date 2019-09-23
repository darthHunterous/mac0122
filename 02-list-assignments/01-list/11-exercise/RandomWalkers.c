#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Point.h"
/* a biblioteca time.h e' utilizada para inicializar o seed da funcao aleatoria com base no horario do sistema operacional */

/* o programa recebe atraves do usuario uma quantidade de passos aleatorios N a serem executados e uma quantidade de vezes T que tal experimento 
   de movimentacao aleatoria sera executado, calculando a posicao final do caminhante em cada experimento e depois de todos executados, imprimindo
   a distancia ao quadrado media */

int main () {
	int N, T, i, j, soma_disquadrado = 0;
	point caminhante_pos, origem;
	origem.x = 0, origem.y = 0;

	printf ("Insira a quantidade de passos para o caminhante aleatorio: ");
	scanf ("%d", &N);
	
	printf ("\nInsira a quantidade de experimentos: ");
	scanf ("%d", &T);
	
	srand (time(NULL));
	
	for (i = 0; i < T; i++) {
		caminhante_pos.x = 0, caminhante_pos.y = 0;
		for (j = 0; j < N; j++) caminhante_pos = passo (caminhante_pos);
		soma_disquadrado += quadrado_distancia (origem, caminhante_pos);			
	}
	
	printf ("\ndistancia ao quadrado media = %f", ((double) soma_disquadrado/T));

	return 0;
}

	