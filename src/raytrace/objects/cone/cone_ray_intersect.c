#include "rtv_includes.h"

/*
** Solving the discriminant
*/
static float	calculate_discriminant(t_ray *r, t_obj3d *o, float *b, float *a)
{
	t_cone *s;
	s = o->type;
	float c;

	float dv = vec3d_dot(&r->dir, &s->axis);
	t_vec3d co = vec3d_sub(&r->start, &s->tip);
	float cov = vec3d_dot(&co, &s->axis);
	float dco = vec3d_dot(&r->dir, &co);
	float cos = powf(cosf(s->angle), 2);
	float codot = vec3d_dot(&co, &co);

	*a = powf(dv, 2) - cos;
	*b = 2.0f * (dv * cov - dco * cos);
	 c = powf(cov, 2) - codot * cos;

	return (powf(*b, 2) - (4 * *a * c));

//	float	c;
//
//	t_cylinder *cy;
//
//	struct s_cylinder cr;
//
//	cy = o->type;
//	*a = powf(r->dir.x, 2) + powf(r->dir.z, 2);
//	*b = (2 * (r->dir.x * (r->start.x - o->pos.x))) +
//		 (2 * (r->dir.z * (r->start.z - o->pos.z)));
//	c = powf(r->start.x - o->pos.x, 2) +
//		powf(r->start.z - o->pos.z, 2) -
//		cy->radius * cy->radius;
//	return (*b * *b - 4 * *a * c);
}


/*
** Check if the ray and sphere intersect
*/
t_bool intersect_cone_ray(t_ray *r, t_obj3d *object, float *t)
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
		if((t0 > 0.f) && (t0 < *t))
		{
			*t = t0;
			return (true);
		}
		else
			return (false);
	}
}