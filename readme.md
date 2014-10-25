Summary
-------

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






