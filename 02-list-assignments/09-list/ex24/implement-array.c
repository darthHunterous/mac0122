#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N;
static int finalN;

/* STACKinit deve receber o valor total de elementos de ambas
as listas */
void STACKinit(int maxN) {
	s = malloc(maxN*sizeof(Item));
	N = 0;
    finalN = maxN - 1;
}

/* verifica se a primeira  lista esta vazia */
int STACKempty1() {
	return N == 0;
} 

/* verifica se a segunda lista esta vazia */
int STACKempty2() {
	return finalN == 0;
}

/* insere o elemento item no topo da primeira lista */
void STACKpush1(Item item) {
	s[N] = item;
	N++;
}

/* insere o elemento item no topo da segunda lista */
void STACKpush2(Item item){
	s[finalN] = item;
	finalN--;
}

/* remove o elemento no topo da primeira lista, retornando-o
na funcao */
Item STACKpop1() {
	Item aux = s[N];
	s[N] = 0;
	N--;

	return aux;
}

/* remove o elemento no topo da segunda lista, retornando-o */
Item STACKpop2() {
	Item aux = s[finalN];
	s[finalN] = 0;
	finalN++;

	return aux;
}