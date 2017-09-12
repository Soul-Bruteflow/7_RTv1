#include "objects.h"
#include "rtv.h"

t_bool intersect_plane_ray(t_ray *r, t_obj3d *obj, float *t)
{
	t_plane		*p;
	float		denom;
	float		t0;
	t_vec3d		tmp;

	p = obj->type;
	denom = vec3d_dot(&r->dir, &p->normal);
	if (fabs(denom) >= 1e-1f)
	{
		tmp = vec3d_sub(&p->point, &r->start);
		t0 = vec3d_dot(&tmp, &p->normal) / denom;
		if (t0 >= 1e-1f)
		{
			*t = t0;
			return (true);
		}
	}
	return (false);
}