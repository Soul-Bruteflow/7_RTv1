#include <math.h>
#include "vectors.h"

t_vec3d ft_vec3d_add3(t_vec3d a, t_vec3d b, t_vec3d c)
{
	t_vec3d tmp;

	tmp.x = a.x + b.x + c.x;
	tmp.y = a.y + b.y + c.y;
	tmp.z = a.z + b.z + c.z;
	return (tmp);
}