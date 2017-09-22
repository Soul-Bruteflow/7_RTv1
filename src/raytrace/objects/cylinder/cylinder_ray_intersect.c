#include "rtv_includes.h"

/*
** Solving the discriminant
*/
static float	calculate_discriminant(t_ray *r, t_obj3d *o, float *b, float *a)
{
	float		c;
	t_cylinder 	*cy;

	cy = o->type;

	t_vec3d AB = vec3d_sub(&cy->b, &cy->a);
	t_vec3d AO = vec3d_sub(&r->start, &cy->a);
	t_vec3d AOxAB = vec3d_cross(&AO, &AB); // cross product
	t_vec3d VxAB  = vec3d_cross(&r->dir, &AB); // cross product
	float  ab2   = vec3d_dot(&AB, &AB); // dot product
	*a      = vec3d_dot(&VxAB, &VxAB); // dot product
	*b      = 2 * vec3d_dot(&VxAB, &AOxAB); // dot product
	c      = vec3d_dot(&AOxAB, &AOxAB) - (cy->radius * cy->radius * ab2);

//	*a = powf(r->dir.x, 2) + powf(r->dir.z, 2);
//	*b = (2 * (r->dir.x * (r->start.x - o->pos.x))) +
//		(2 * (r->dir.z * (r->start.z - o->pos.z)));
//	c = powf(r->start.x - o->pos.x, 2) +
//		powf(r->start.z - o->pos.z, 2) -
//		cy->radius * cy->radius;
	return (*b * *b - 4 * *a * c);
}


/*
** Check if the ray and sphere intersect
*/
t_bool intersect_cylinder_ray(t_ray *r, t_obj3d *object, float *t)
{

	float	b;
	float 	a;
	float	discr;
	float	t0;
	float	t1;

	discr = calculate_discriminant(r, object, &b, &a);
	if (discr < 0)
		return (false);
	else
	{
		t0 = (-b + sqrtf(discr)) / (2 * a);
		t1 = (-b - sqrtf(discr)) / (2 * a);
		if(t0 > t1)
			t0 = t1;
		if((t0 > 1e-1f) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}