#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrix.h"
#include "error.h"
#include "helpers.h"

Matrix *create_matrix(int lines, int columns) 
{
	Matrix *a = malloc(sizeof(struct Matrix));
	if(a == NULL) {
		return NULL;
	}

	// set matrix atributes
	a->lines       = lines;
	a->columns     = columns;
	a->determinant = 0.0;
	a->trace       = 0.0;
	a->inverse     = NULL;

	// set matrix's value
	a->value = malloc(lines * sizeof(double));
	if(a->value == NULL) {
		return NULL;
	} 

	for(int i = 0; i < lines; i++) {
		a->value[i] = calloc(columns, sizeof(double));
		if(a->value == NULL) {
			return NULL;
		}
	}

	return a;
}

void destroy_matrix(Matrix *a) 
{
	int lines = a->lines;

	// free the value of matrix
	for(int i = 0; i < lines; i++) {
		free(a->value[i]);
	}
	free(a->value);

	if(a->inverse != NULL) {
		destroy_matrix(a->inverse);
	}
}

void copy_matrix(Matrix *a, Matrix **destination) 
{
	for(int i = 0; i < a->lines; i++) {
		for(int j = 0; j < a->columns; j++) {
			(*destination)->value[i][j] = a->value[i][j];
		}
	}
}

void read_matrix(Matrix *a) 
{
	int lines    = a->lines;
	int columns = a->columns;

	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < columns; j++) {
			printf("introduceti elementul a[%d][%d]: ", i, j);
			scanf("%lf", &a->value[i][j]);
		}
	}
}

int print_matrix(Matrix *a)
{
	if(a == NULL) {
		return MATRIX_NOT_EXISTS;
	}

	int lines    = a->lines;
	int columns = a->columns;
	
	for(int i = 0; i < lines; i++) {
		for(int j = 0; j < columns; j++) {
			printf("%lf ", a->value[i][j]);
		}
		printf("\n");
	}

	return NO_ERROR;
}

bool compare_matrices(Matrix *a, Matrix *b)
{
	// To be equal 2 matrices shouls have the same dimensions
	if(a->lines != b->lines)
		return 0;
	if(a->columns != b->columns)
		return 0;

	// They have the same dimensions, now we should check to see if 
	// they have the same values
	for(int i = 0; i < a->lines; i++) {
		for(int j = 0; j < a->columns; j++) {
			if(!isEqual(a->value[i][j], b->value[i][j]))
				return false;
		}
	}
	return true;
}

