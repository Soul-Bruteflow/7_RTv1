#include "rtv_includes.h"

t_bool intersect_sphere(t_ray *r, t_sphere *s)
{
	t_vec3d dist;
	float a;
	float b;
	float c;
	float discr;

	a = vec3d_dot(&r->dir, &r->dir);
	dist = vec3d_sub(&r->start, &s->pos);
	b = 2 * vec3d_dot(&r->dir, &dist);
	c = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
	discr = b * b - 4 * a * c;
	if (discr < 0)
		return false;
	else
		return true;
}