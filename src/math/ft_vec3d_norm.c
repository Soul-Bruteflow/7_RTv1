#include <math.h>
#include "vectors.h"

t_vec3d	ft_vec3d_norm(t_vec3d v)
{
	float	length;
	t_vec3d	norm_vector;

	length = ft_vec3d_magnitude(v);
	norm_vector.x = v.x / length;
	norm_vector.y = v.y / length;
	norm_vector.z = v.z / length;
	return (norm_vector);
}