#include <stdio.h>
#include "minunit.h"
#include "../src/matrix.h"

int tests_run = 0;

static char *test_add_matrices()
{
	// We should create 2 empty matrices. If we add them we should get
	// an empty matrix.
	struct Matrix *a = create_matrix(2, 2);
	struct Matrix *b = create_matrix(2, 2);
	// We will store the result of the adition in a third matrix c.
	struct Matrix *c = create_matrix(2, 2);

	add_matrices(a, b, &c);

	// Since a and b are empty their result will an empty matrix too
	// so it makes sense to compare c against b or a.
	mu_assert("c != a or b", compare_matrices(a, c));


	destroy_matrix(a);
	destroy_matrix(b);
	destroy_matrix(c);
	
	return 0;
}

static char *test_compare_matrices() 
{

	// By default newly create marices have all elements
	// equal to 0. So a and b should be equal.
	struct Matrix *a = create_matrix(2, 2);
	struct Matrix *b = create_matrix(2, 2);

	mu_assert("a != b", compare_matrices(a, b) == 1);

	// Let's modify their values a bit.
	a->value[1][1] = 2;
	b->value[0][0] = 1;

	// They should be not equal now
	mu_assert("a == b, should be different", compare_matrices(a, b) == 0);

	destroy_matrix(a);
	destroy_matrix(b);
	
	return 0;
}

static char *all_tests() {
	mu_run_test(test_compare_matrices); 
	mu_run_test(test_add_matrices);
	return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
     }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
