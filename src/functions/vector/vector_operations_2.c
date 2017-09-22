#include "vectors.h"
#include <math.h>

t_vec3d	vec3_norm(t_vec3d v)
{
	t_vec3d	unit_vector;

	unit_vector = vec3_scale((1 / vec3_len(v)), &v);
	return (unit_vector);
}

float	vec3_len(t_vec3d v)
{
	float len;

	len = sqrtf(vec3_dot(&v, &v));
	return (len);
}

t_vec3d vec3_add3(t_vec3d a, t_vec3d b, t_vec3d c)
{
	t_vec3d tmp;

	tmp.x = a.x + b.x + c.x;
	tmp.y = a.y + b.y + c.y;
	tmp.z = a.z + b.z + c.z;
	return (tmp);
}