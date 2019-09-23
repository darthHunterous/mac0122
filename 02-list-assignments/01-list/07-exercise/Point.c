#include <math.h>
#include "Point.h" /* inclusao das bibliotecas utilizadas, bem como o header que define o tipo de dados e operacoes */

/* execucao da funcao de calculo de distancia*/
float distance (point a, point b) {
	
	float dx = a.x - b.x, dy = a.y - b.y;
	
	return sqrt(dx*dx + dy*dy);
}

