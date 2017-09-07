#include "rtv_includes.h"
//
///*
//** Determines how many there is intersection between ray and sphere
//** negative - 0, 0 - exactly one, 1 - exactly two.
//*/
//float	sphere_discriminant(t_ray *r, t_sphere *s, float *b)
//{
//	t_vec3d	dist;
//	float	a;
//	float	c;
//	float	discr;
//
//	a = vec3d_dot(&r->dir, &r->dir);
//	dist = vec3d_sub(&r->start, &s->pos);
//	*b = 2 * vec3d_dot(&r->dir, &dist);
//	c = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
//	discr = *b * *b - 4 * a * c;
//	return (discr);
//}
//
///*
//** t represents the distance between the start of the ray and
//** the point on the sphere where it intersects
//*/
//
//t_bool intersect_sphere(t_ray *r, t_sphere *s)
//{
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
//}
//
////t_bool	intersect_sphere(t_ray *r, t_sphere *s, float *t)
////{
//////	t_vec3d dist;
//////	float a;
//////	float b;
//////	float c;
//////	float discr;
//////
//////	a = vec3d_dot(&r->dir, &r->dir);
//////	dist = vec3d_sub(&r->start, &s->pos);
//////	b = 2 * vec3d_dot(&r->dir, &dist);
//////	c = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
//////	discr = b * b - 4 * a * c;
//////	if (discr < 0)
//////		return false;
//////	else
//////		return true;
////
////
////	float	b;
////	float	discr;
////	float	sqrtdiscr;
////	float	t0;
////	float	t1;
////
////	discr = sphere_discriminant(r, s, &b);
////	if(discr < 0)
////		return (false);
////	else
////	{
////		sqrtdiscr = sqrtf(discr);
////		t0 = (-b + sqrtdiscr)/(2);
////		t1 = (-b - sqrtdiscr)/(2);
////		if(t0 > t1)
////			t0 = t1;
////		if((t0 > 0.001f) && (t0 < *t))
////		{
////			*t = t0;
////			return (true);
////		}
////		else
////			return (false);
////	}
////}

/* Check if the ray and sphere intersect */
t_bool intersectRaySphere(t_ray *r, t_obj3d *object, float *t)
{

	t_sphere *s;
	t_obj3d *o;
	t_bool retval;

	o = object;
	s = object->type;

	/* A = d.d, the vector dot product of the direction */
	float A = vec3d_dot(&r->dir, &r->dir);

	/* We need a vector representing the distance between the start of
	 * the ray and the position of the circle.
	 * This is the term (p0 - c)
	 */
	t_vec3d dist = vec3d_sub(&r->start, &o->pos);

	/* 2d.(p0 - c) */
	float B = 2 * vec3d_dot(&r->dir, &dist);

	/* (p0 - c).(p0 - c) - r^2 */
	float C = vec3d_dot(&dist, &dist) - (s->radius * s->radius);

	/* Solving the discriminant */
	float discr = B * B - 4 * A * C;

	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 * t represents the distance between the start of the ray and
	 * the point on the sphere where it intersects.
	 */
	if(discr < 0)
		retval = false;
	else{
		float sqrtdiscr = sqrtf(discr);
		float t0 = (-B + sqrtdiscr)/(2);
		float t1 = (-B - sqrtdiscr)/(2);

		/* We want the closest one */
		if(t0 > t1)
			t0 = t1;

		/* Verify t1 larger than 0 and less than the original t */
		if((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			retval = true;
		}else
			retval = false;
	}

	return retval;
}