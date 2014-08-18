#include <stdio.h>
#include "error.h"

void printErrorMesage(int error) 
{
	switch(error) {
		case NOT_SQUARE_MATRIX:
			printf("the matrix is not suqare\n");
			break;
		case NO_INVERSE:
			printf("matrcicea asta nu are inversa\n");  
			break;
		case NO_ERROR:
			printf(" ");
			break;
		case MATRIX_NOT_EXISTS:
			printf("matrcicea nu exista \n");
			break;
		case NOT_SAME_SIZE:
			printf("matricile nu au aceleasi marimi\n");
			break;
		case SIZE_NOT_MATCH:
			printf("marimile matricilor nu se potrivesc \n" );
			break;
		case CANT_CREATE_MATRIX:
			printf("matriccea nu poate fi creata \n");
			break;
	}

}

