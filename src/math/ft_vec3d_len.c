#include <math.h>
#include "vectors.h"

float	ft_vec3d_len(t_vec3d v)
{
	float len;

	len = sqrtf(vec3d_dot(&v, &v));
	return (len);
}