#include "rtv.h"
#include <math.h>

/*
** Compares the two values for equality, allowing the given amount of absolute error.
*/
t_bool equal_abs(float a, float b, float epsilon)
{
	return (fabs(a-b) < epsilon);
}