#include "vectors.h"

t_vec3d	ft_vec3d_scale(t_vec3d v, float s)
{
	v.x *= s;
	v.y *= s;
	v.z *= s;
	return (v);
}