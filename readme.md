Summary
-------
This file contains a brief description of the main function provided by the 
library. More details about these function scan be found here 
http://cristid9.github.io/libMatrix/files.html.

This is is a minimalist matrix library which provides support for
basic mathematical operations like:
  * addition of 2 matrices
  * multiplication with a scalar
  * multiplication of 2 matrices
  * computing the trace
  * computing the transpose
  * computin the determinant
  * computing the minorants of a matrix 
  * computing the inverse
  * raising a matrix to a given power

It also provides some uility function that will make your life easier in 
with the data structures of the library:
  * creating a matrix
  * destroying a matrix
  * printing a matrix(to the stdout)
  * reading a matrix(from the stdin)
  * copying a matrix
  * comparing matrices
  
Building the library
--------------------

To build the library you need to run the following commands:

```
sudo make
sudo make install
```

Creating a matrix
-----------------

In order to create a matrix you need to include the `matrix.h` header file:
```
#include <matrix.h>
```

After you have done this you need to declare a pointer to a `Matrix` and 
assign to it the value returned by `create_matrix`. The function `create_matrix`
takes 2 arguments: the number of rows and the number of columns. This is how
you create a 2 by 2 matrix.
```
#include <matrix.h>

int main()
{
    Matrix *foo = create_matrix(2, 2);    
    destroy_matrix(foo);
    return 0;
}
```
The call to `destroy_matrix` is used to release the memory allocated for `foo`.

Compiling a source file
-----------------------

To compile a source file that uses the matrix library you need to dynamically
link the library. This is how you will compile the file from the previous 
section:
```
gcc -Wall main.c -lMatrix -lm
```
Please remember to add `-lm` after `-lMatrix`.

Accessing properietes of a matrix
----------------------------------
A matrix has some proprietes that you should care about:
  * its elements
  * trace
  * inverse
  * determinant

This is how you will access these proprites:
```
matrix->value[line][column];
matrix->trace;
matrix->determinant;
matrix->inverse->value[lineOfInverse][columnOfInverse];

```

Muliplication of a matrix with a scalar
---------------------------------------
 In order to multiply a matrix with a scalar you will need to use the 
`multiply_matrix_with_scalar` function. This function takes 2 arguments:
the matrix and the scalar to multiply that matrix with. The only issue of this
function is that it modifies the value of the original matrix. 

This is how you will do this:
```
#include <matrix.h>

int main()
{
    Matrix *foo = create_matrix(2, 2);
    multiply_matrix_with_scalar(foo, 2);
    print_matrix(foo);
    destroy_matrix(foo);

    return 0;
}
```
Computing the minorant of a matrix
----------------------------------
You will use `get_minor` to do this job, which takes 3 arguments: the matrix, 
the line and the column that will be eliminated for the minorant. It returns
a pointer to a `Matrix` which is the minorant. After you hae finished with
the minorant and you do not need it anymore you need to destroy it.

```
#include <matrix.h>

int main()
{
    // let foo be a 3 by 3 not null matrix
    Matrix *minorantOfFoo = get_minor(foo, 1, 1);
    // do something with minorantOfFoo
    destroy_matrix(minorantOfFoo);
    
}

```
Computing the transpose of a matrix
-----------------------------------
The function that does this is called `get_transpose` and it takes 2 arguments
the matrix, and a pointer to a matrix where the transpose will be initialized.
This function returns an error status.

```
#include <matrix.h>

int main()
{
    // let foo be a 3 by 3 matrix
    Matrix *transpose;
    get_transpose(foo, &transpose);
    // do something with the transpose
    destroy_matrix(transpose);
}
```
Computing the inverse of a matrix
--------------------------------
The function that does this is called `compute_inverse` and will just set the 
`inverse` member of the matrix you want to compute the inverse of.

This is how you will compute the inverse of a matrix called foo:
```
#include <matrix.h>

int main()
{
    // let foo be a 3 by 3 matrix
    compute_inverse(foo);
    destroy_matrix(foo);
}
```

You do not have to care about releasing the memory allocated to foo. 
`destroy_matrix` will do this for you.

Computing the determinant of a matrix
-------------------------------------
This operation is very simillar with the previous one. The function that does
this is called `get_determinant` and takes only one argument, the matrix
you want to compute the determinant of and it just sets the `determinant`
member of that matrix.

This is how you will compute the determinant of a matrix:

```
#include <matrix.h>

int main()
{
    // let foo be a 3 by 3 matrix
    get_determinant(foo);
    // do something with the determinant of foo
    destroy_matrix(foo);    
}
```

Multiplying 2 matrices
----------------------
In order to multiply 2 matrices you need to have a third variable where the
result will be stored. 

This is how you multiply 2 matrices `a` and `b`.
```
#include <matrix.h>

int main()
{
    // let a and b be 3 by 3 matrices
    Matrix *c; // the result
    // the result will be stored in c
    multiply_matrices(a, b, &c); 
    // destroy a and b
    destroy_matrix(c);

}
```

Adding 2 matrices
-----------------
This is very simillar with the process of multiplying 2 matrices.

```
int main()
{
    // let a and b be 3 by 3 matrices
    Matrix *c; // the result
    // the result will be stored in c
    add_matrices(a, b, &c); 
    // destroy a and b
    destroy_matrix(c);

}
```

Copying a matrix
----------------
Say you want to copy the value of a matrix `foo` to a matrix `bar`.
This is how you do it:

```
#include <matrix.h>

int main()
{
    // let foo be a 3 by 3 not empty matrix and bar newly created matrix.
    copy_matrix(foo, bar);
    // release the memory
}

```
Raising a matrix to a power
---------------------------
This is done with the function `matrix_pow`, which takes as arguments the 
matrix and the power to raise that matrix to. The function will return a 
pointer to the result.

```
#include <matrix.h>

int main()
{
    // let foo be a matrix
    Matrix *fooRaisedTo3 = matrix_pow(foo, 3);
    // do something with it
    destroy_matrix(fooRaisedTo3);
}

```

Comparing 2 matrices
--------------------
In order to comper 2 matrices you will use the function `compare_matrices`
which returns `true` if the matrices have the same elemnts and `false` 
otherwise. Boolean types are not suported in c89, we encourage you to use the
c99 standard.

```
#include <matrix.h>

int main()
{
    // let foo and bar be 2 equal matrices
    if(compare_matrices(foo, bar)) {
        // they are equal
    }
    else {
        // they are not equal
    }
    
}
```
