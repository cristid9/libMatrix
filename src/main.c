#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "error.h"

int main () {
	struct Matrix *a = create_matrix(3, 3);
	struct Matrix *b;
	
	read_matrix(a);
	b = matrix_pow(a, 2);

	print_matrix(b);

	return 0;
}
