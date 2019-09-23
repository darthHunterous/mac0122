#include <stdio.h>
#include <string.h>
#include "Item.h"
#include "STACK.h"

int main(int argc, char *argv[]) {

	char *a = argv[1]; 
	int i, N = strlen(a);
	STACKinit(N);

	for (i = 0; i < N; i++) {
		if (a[i] == ')')
		/* por algum motivo bizarro o argv buga com
		os parenteses, todavia, a substituicao por 
		outro caractere resolve o problema*/
			printf("%c ", STACKpop());
		if ((a[i] == '+') || (a[i] == '*'))
			STACKpush(a[i]);
		if ((a[i] >= '0') && (a[i] <= '9'))
			printf("%c ", a[i]);
	}

	printf("\n");
	return 0;
}
