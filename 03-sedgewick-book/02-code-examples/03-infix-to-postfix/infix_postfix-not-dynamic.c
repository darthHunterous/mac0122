#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"
#include "STACK.h"

int main(int argc, char *argv[]) {

	char a[100]; 
	int i, N;

	scanf ("%s", a);

	N = strlen(a);
	STACKinit(N);

	for (i = 0; i < N; i++) {
		if (a[i] == ')')
			printf("%c ", STACKpop());
		if ((a[i] == '+') || (a[i] == '*'))
			STACKpush(a[i]);
		if ((a[i] >= '0') && (a[i] <= '9'))
			printf("%c ", a[i]);
	}

	printf("\n");
	return 0;
}