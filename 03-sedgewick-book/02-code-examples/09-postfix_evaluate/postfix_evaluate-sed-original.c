#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

/* Esse programa abaixo, é, na verdade, uma bosta */
int main(int argc, char *argv[]) {
	
	char *a = argv[1];
	int i, N = strlen(a);
	STACKinit(N);

	for (i = 0; i < N; i++) {
		if (a[i] == '+')
			STACKpush(STACKpop()+STACKpop());
		if (a[i] == '*')
			STACKpush(STACKpop()*STACKpop());
		if ((a[i] >= '0') && (a[i] <= '9'))
			STACKpush(0);
		while ((a[i] >= '0') && (a[i] <= '9'))
			STACKpush(10*STACKpop() + (a[i] - '0'))
			i++;
	}

	printf("%d \n", STACKpop());

	printf("\n");
	return 0;
}
