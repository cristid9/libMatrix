#include "matrix.h"
#include "error.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

Matrix *get_minor(Matrix *a, int line, int columns)
{
    Matrix *minor = create_matrix(a->lines - 1, a->columns - 1);
    if (minor == NULL)
    {
        return NULL;
    }

    int x = 0, y = 0;
    for (int i = 0; i < a->lines; i++)
    {
        if (i == line)
            x--;
        for (int j = 0; j < a->columns; j++)
        {
            if (i != line && j != columns)
            {
                minor->value[x][y] = a->value[i][j];
                y++;
            }
        }
        x++;
        y = 0;
    }

    return minor;
}

double get_determinant(Matrix *a)
{
    double det;
    Matrix *m;

    if (a->lines == 1 && a->columns == 1)
    {
        return a->value[0][0];
    }
    else
    {
        det = 0;
        for (int i = 0; i < a->columns; i++)
        {
            m = get_minor(a, 0, i);
            det += (a->value[0][i]) * (pow(-1, 2 + i)) * (get_determinant(m));
            destroy_matrix(m);
        }
        return det;
    }
}

int get_transpose(Matrix *a, Matrix **transpose)
{
    *transpose = create_matrix(a->columns, a->lines);
    if (*transpose == NULL)
    {
        return CANT_CREATE_MATRIX;
    }

    for (int i = 0; i < a->lines; i++)
    {
        for (int j = 0; j < a->columns; j++)
        {
            (*transpose)->value[j][i] = a->value[i][j];
        }
    }

    return NO_ERROR;
}

void multiply_matrix_with_scalar(Matrix *a, double scalar)
{
    for (int i = 0; i < a->lines; i++)
    {
        for (int j = 0; j < a->columns; j++)
        {
            a->value[i][j] *= scalar;
        }
    }
}

int compute_inverse(Matrix *a)
{
    if (a->determinant == 0.0)
    {
        return NO_INVERSE;
    }

    Matrix *transpose = create_matrix(a->lines, a->columns);
    Matrix *adjugate = create_matrix(a->lines, a->columns);
    Matrix *current_minor;

    get_transpose(a, &transpose);
    for (int i = 0; i < transpose->lines; i++)
    {
        for (int j = 0; j < transpose->columns; j++)
        {
            current_minor = get_minor(transpose, i, j);
            adjugate->value[i][j] = pow(-1.0, (double)i + (double)j) *
                                    get_determinant(current_minor);

            destroy_matrix(current_minor);
        }
    }
    destroy_matrix(transpose);

    a->inverse = adjugate;
    multiply_matrix_with_scalar(a->inverse, 1 / a->determinant);

    return NO_ERROR;
}

int multiply_matrices(Matrix *a, Matrix *b, Matrix **result)
{
    if (a->columns != b->lines)
    {
        return SIZE_NOT_MATCH;
    }

    *result = create_matrix(a->lines, b->columns);
    if (*result == NULL)
    {
        return CANT_CREATE_MATRIX;
    }

    int x = 0, y = 0;
    for (int i = 0; i < a->lines; i++)
    {
        y = 0;
        for (int k = 0, columns = b->columns; columns > 0; columns--)
        {
            for (int j = 0; j < a->columns; j++)
            {
                (*result)->value[x][y] += a->value[i][j] * b->value[j][k];
            }
            k++;
            y++;
        }
        x++;
    }

    return NO_ERROR;
}

Matrix *matrix_pow(Matrix *a, int power)
{
    Matrix *result = create_matrix(a->lines, a->columns);
    copy_matrix(a, &result);

    for (int i = 0; i < power - 1; i++)
    {
        multiply_matrices(result, a, &result);
    }

    return result;
}

int add_matrices(Matrix *a, Matrix *b, Matrix **result)
{
    if (a->lines != b->lines && a->columns != b->columns)
    {
        return NOT_SAME_SIZE;
    }

    *result = create_matrix(a->lines, a->columns);

    for (int i = 0; i < a->lines; i++)
    {
        for (int j = 0; j < a->columns; j++)
        {
            (*result)->value[i][j] = a->value[i][j] + b->value[i][j];
        }
    }

    return NO_ERROR;
}

int compute_trace(Matrix *a)
{
    if (a->columns != a->lines)
    {
        return NOT_SQUARE_MATRIX; // error
    }

    for (int i = 0; i < a->columns; i++)
    {
        a->trace += a->value[i][i];
    }

    return NO_ERROR;
}
