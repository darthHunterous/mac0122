#include <stdio.h>
#include "Point.h"

/* funcao que recebe dois pontos de coordendas cartesianas inteiras no R2 e devolve sua soma */
point soma (point a, point b) {
	point c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	
	return c;
}

/* funcao que recebe um ponto (com valores inteiros) e imprime suas coordenadas cartesianas em R2 */
void imprime (point a) {
	printf ("\n(%d,%d)", a.x, a.y);
}

/* funcao que recebe dois pontos de coordenadas cartesianas inteiras em R2 e calcula o quadrado da distancia entre eles */
int quadrado_distancia (point a, point b) {
	return ((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

/* funcao que retorna um numero inteiro de 0 a 3 */
int passo_aleatorio () {
	return (rand () % 4);
}

/* funcao que, baseada em um numero aleatorio gerado, define um passo aleatorio de coordenadas inteiras
   em uma das direcoes: norte, sul, leste, oeste, retornando o ponto resultante apos o passo */
point passo (point a) {

	int rand_num = passo_aleatorio();
	point b;

	if (rand_num == 0) b.x = 1, b.y = 0;
	if (rand_num == 1) b.x = -1, b.y = 0;
	if (rand_num == 2) b.x = 0, b.y = 1;
	if (rand_num == 3) b.x = 0, b.y = -1;
	
	return soma (a, b);
}




	

