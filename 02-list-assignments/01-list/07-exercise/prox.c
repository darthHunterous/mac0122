#include <stdio.h>
#include "Point.h"

int main () {
	
	int num, i;
	float distancia, menor;
	point a, b, c;
	
	printf("Insira a quantidade de pontos a serem lidos:");
	scanf("%d", &num);
	
	printf("\nInsira as coordenadas reais x e y do ponto padrao: ");
	scanf("%f %f", &a.x, &a.y);
	
	printf("\nInsira as coordenadas reais x e y do novo ponto: ");
	scanf("%f %f", &b.x, &b.y);
	
	distancia = distance(a, b);
	menor = distancia;
	c.x = b.x;
	c.y = b.y;
	
	for (i = 0; i < num - 2; i++) {
		printf("\nInsira as coordenadas reais x e y do novo ponto: ");
		scanf("%f %f", &b.x, &b.y);
		
		distancia = distance(a, b);
		
		if (distancia < menor) {
			menor = distancia;
			c.x = b.x;
			c.y = b.y;
		}
	}
	
	printf ("\nO ponto mais proximo de (%f, %f) e' (%f, %f), a %f de distancia", a.x, a.y, c.x, c.y, menor);
	
	return 0;
}
