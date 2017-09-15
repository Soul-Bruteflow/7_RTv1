#include <math.h>
#include "vectors.h"

t_vec3d	ft_vec3d_unit(t_vec3d v)
{
	t_vec3d	unit_vector;

	unit_vector = vec3d_scale((1 / ft_vec3d_len(v)), &v);
	return (unit_vector);
}