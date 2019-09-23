#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

static Item *s;
static int N;

void STACKinit(int maxN) {
	s = malloc(maxN*sizeof(Item));
	N = 0;
}

int STACKempty() {
	return N == 0;
} /* retorna 1 se N == 0 e zero se o contrario */

void STACKpush(Item item) {
	s[N++] = item;
}

Item STACKpop() {
 return s[--N];
}