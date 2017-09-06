#include "objects.h"
#include "rtv.h"

t_bool intersect_plane(t_ray *r, t_obj3d *object, float *t)
{
	t_plane *p = object->type;

////----------------------------------------
	float denom = vec3d_dot(&r->dir, &p->normal);
	if (fabs(denom) > 0.0001f) // your favorite epsilon
	{
		t_vec3d tmp = vec3d_sub(&p->point, &r->start);
		float t0 = vec3d_dot(&tmp, &p->normal) / denom;
		if (t0 >= 0)
		{
			*t = t0;
			return true;
		} // you might want to allow an epsilon here too
	}
	return false;
////----------------------------------------


//	result.Dist = t;
//	return result;

////	//-----------------------------
//	float t0 = 0;
//	float s;
//	float denom;
//
//	denom = vec3d_dot(&r->dir, &p->normal);
//	if (fabs(denom) > 1e-6f)
//	{
//		s = -(vec3d_dot(&r->start, &p->normal) + p->distance);
//		t0 = s / denom;
//		if (t0 >= 1e-6f)
////		if (denom != 0)
//		{
//			*t = t0;
////			if (fabs(*t) < 1e6f)
//				return (true);
//		}
//	}
////	*t = t0;
//	return (false);
//	//-------------------------

//	t_vec3d v0;
//
//	v0.x = 0;
//	v0.y = 0;
//	v0.z = 0;
//
//	float denom = vec3d_dot(&r->dir, &p->n);
//	float t1 = 0;
//	if (fabs(denom) > 1e-4f)
//	{
//		// Compute the distance from the line starting point to the point of intersection.
//		*t = (p->d - vec3d_dot(&p->n, &r->start)) / denom;
//		return true;
//	}
//	if (denom != 0.f)
//	{
//		*t = (p->d - vec3d_dot(&p->n, &r->start)) / denom;
//		if (fabs(*t) < 1e6f)
//			return true;
//	}
//	*t = 0.f;
//	return equal_abs(vec3d_dot(&p->n, &r->start), p->d, 1e-3f);

//	v0 = ft_vec3d_scale(r->dir, t1);
//		return add(out, origin, v0)
//	} else if (dot(normal, origin) + dist === 0) {
//		return copy(out, origin)
//	} else {
//		return null
//	}

//	t_vec3d norm_r_dir = ft_vec3d_norm(r->dir);
//	t_vec3d norm_r_start = ft_vec3d_norm(r->start);
//	t_vec3d norm_d = ft_vec3d_norm(p->d);
//
//	float denom = vec3d_dot(&p->n, &norm_r_dir);
//	if (denom > 1e-6)
//	{
//		t_vec3d p0l0 = vec3d_sub(&norm_d, &norm_r_start);
//		*t = vec3d_dot(&p0l0, &p->n) / denom;
//		return (t >= 0);
//	}
//	return false;
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