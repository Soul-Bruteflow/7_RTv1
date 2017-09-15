#include "rtv_includes.h"

/*
** Solving the discriminant
*/

static float	calculate_discriminant(t_ray *r, t_obj3d *object, float *b)
{
	float a;
	float c;
	t_vec3d dist;
	t_sphere *s;

	s = object->type;
	a = vec3d_dot(&r->dir, &r->dir);
	dist = vec3d_sub(&r->start, &object->pos);
	*b = 2 * vec3d_dot(&r->dir, &dist);
	c = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
	return (*b * *b - 4 * a * c);
}


/*
** Check if the ray and sphere intersect
*/
t_bool intersect_sphere_ray(t_ray *r, t_obj3d *object, float *t)
{
	float b;
	float discr;
	float sqrtdiscr;
	float t0;
	float t1;

	b = 0;
	discr = calculate_discriminant (r, object, &b);
	if(discr < 0)
		return (false);
	else
	{
		sqrtdiscr = sqrtf(discr);
		t0 = (-b + sqrtdiscr)/(2);
		t1 = (-b - sqrtdiscr)/(2);
		if(t0 > t1)
			t0 = t1;
		if((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}