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

/**
 * @brief Returns a pointer to a struct Matrix with `rows` rows and `columns`
 *        columns. Note that the new matrix is empty, but it's elemnts are, by
 *        default 0.
 *
 * @param rows The number of rows of the matrix.
 * @param columns The number of columns of the matrix.
 *
 * @return struct Matrix A pointer to an empty struct Matrix.
 */
struct Matrix *create_matrix(int rows, int columns);

/**
 * @brief Utility function used to read a matrix from the standard input.
 *
 * @param a The matrix in which the readed elements will be stored.
 *
 * @retrun void It doesn't return anything.
 */
void read_matrix(struct Matrix *a);

/**
 * @brief utility function used to print a matrix to the standar output.
 *
 * @param a The matrix that should be printed.
 *
 * @return int If the matrix doesn't exists it will return MATRIX_NOT_EXISTS
 *         and NO_ERROR if the matrix was successfully printed.
 */
int print_matrix(struct Matrix *a);

/**
 * @brief Returns the minorant of a matrix by a specific row and column.
 *
 * @param a The matrix that we want to compute the minorant of.
 * @param line The line That should be elimined when selecting the minorant.
 * @param colum The column that should be elimined when computing the minorant.
 *
 * @return struct Matrix * It returns NULL or a pointer o to a struct Matrix
 *         that represents the minorant of the matrix `a`. 
 */
struct Matrix *get_minor(struct Matrix *a, int line, int column);

/**
 * @brief Multiplies a matrix `a` with an scalar. Note that the new value of 
 *        the matrix will be the result of this operation.
 *
 * @param a The matrix that should be multiplied with an scalar.
 * @param scalar The scalar that should be multiplied withe the matrix `a`.
 *
 * @return void It doesn't return anything.
 */
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
