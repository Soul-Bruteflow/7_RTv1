#include <math.h>
#include "vectors.h"

float	ft_vec3d_magnitude(t_vec3d v)
{
	return (sqrtf((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}