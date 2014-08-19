#include <math.h>
#include <stdbool.h>

#define EPSILON 0.000001

bool isEqual(double a, double b)
{
	return fabs(a - b) < EPSILON;
}

