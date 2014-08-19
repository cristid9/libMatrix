#ifndef MATRICI_H
#define MATRICI_H

#include <stdbool.h>

struct Matrix {
	int lines;
	int columns;

	double determinant;
	double trace;
			
	double **value;
	struct Matrix *inverse;
};

struct Matrix *create_matrix(int rows, int columns);
void read_matrix(struct Matrix *a);
int print_matrix(struct Matrix *a);
struct Matrix *get_minor(struct Matrix *a, int line, int column);
void multiply_matrix_with_scalar(struct Matrix *a, double scalar); 
int get_transpose(struct Matrix *a, struct Matrix **transpose);
void destroy_matrix(struct Matrix *a); 
int compute_inverse(struct Matrix *a);
double get_determinant(struct Matrix *a);
int multiply_matrices(struct Matrix *a, struct Matrix *b, 
					  struct Matrix **result);

bool isEqual(double a, double b);
/**
 * @brief Use this function to add 2 matrices. Note that the result will
 *        be stored in a third matrix.
 *
 * @param a An instance of struct Matrix.
 * @param b An instance of struct Matrix.
 * @param c An instance of struct Matrix.
 *
 * @return int Returns and error status.
 *
 */
int add_matrices(struct Matrix *a, struct Matrix *b, struct Matrix **result);
void copy_matrix(struct Matrix *a, struct Matrix **destination); 
struct Matrix *matrix_pow(struct Matrix *a, int power); 

/**
 * @brief Use this function to compare to matrices. The criteria
 *        used to compare the matrices are the dimensions and the
 *        actual values of the 2 matrices.
 *
 * @param a An instance of struct matrix.
 * @param b An instance of sruct martix.
 *
 * @return bool 1 if the matrices are equal and 0 otherwise.
 *
 */
bool compare_matrices(struct Matrix *a, struct Matrix *b);

#endif 
