#include "rtv_includes.h"

/*
** Determines how many there is intersection between ray and sphere
** negative - 0, 0 - exactly one, 1 - exactly two.
*/
float	sphere_discriminant(t_ray *r, t_sphere *s, float *b)
{
	t_vec3d	dist;
	float	a;
	float	c;
	float	discr;

	a = vec3d_dot(&r->dir, &r->dir);
	dist = vec3d_sub(&r->start, &s->pos);
	*b = 2 * vec3d_dot(&r->dir, &dist);
	c = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
	discr = *b * *b - 4 * a * c;
	return (discr);
}

/*
** t represents the distance between the start of the ray and
** the point on the sphere where it intersects
*/
t_bool	intersect_sphere(t_ray *r, t_sphere *s, float *t)
{
//	t_vec3d dist;
//	float a;
//	float b;
//	float c;
//	float discr;
//
//	a = vec3d_dot(&r->dir, &r->dir);
//	dist = vec3d_sub(&r->start, &s->pos);
//	b = 2 * vec3d_dot(&r->dir, &dist);
//	c = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
//	discr = b * b - 4 * a * c;
//	if (discr < 0)
//		return false;
//	else
//		return true;


	float	b;
	float	discr;
	float	sqrtdiscr;
	float	t0;
	float	t1;

	discr = sphere_discriminant(r, s, &b);
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