#include "objects.h"
#include "rtv.h"

t_plane *new_plane()
{
	t_plane *plane;

	plane = malloc(sizeof(*(plane)));
	if (plane == NULL)
		rtv_error(malloc_error);
	return (plane);
}

//t_bool intersect_plane_line(t_ray *r, t_plane *p, float *t)
//{
//	float denom = vec3d_dot(&p->n, &r->dir);
//	if (fabs(denom) > 1e-4f)
//	{
//		// Compute the distance from the line starting point to the point of intersection.
//		*t = (p->d - vec3d_dot(&p->n, &r->start)) / denom;
//		return true;
//	}
//
//	if (denom != 0.f)
//	{
//		*t = (p->d - vec3d_dot(&p->n, &r->start)) / denom;
//		if (fabs(*t) < 1e4f)
//			return true;
//	}
//	*t = 0.f;
//	return equal_abs(vec3d_dot(&p->n, &r->start), p->d, 1e-3f);
//}

//t_bool intersect_plane_ray(t_ray *r, t_plane *p)
//{
////	float t;
////	t_bool success = intersect_plane_line(r, p, &t);
//////	if (dist)
//////		*dist = t;
////	return (success && t >= 0.f);
//
//		float t0 = ((vec3d_dot(&p->rot, &p->pos) -
//				vec3d_dot(&p->rot, &r->start)) / vec3d_dot(&p->rot, &r->dir));
//		if (t0 < 0.0001)
//			return (false);
//		return (true);
//
//}