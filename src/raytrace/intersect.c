#include "rtv.h"

/*
** Find closest intersection
*/
t_bool	object_intersect(t_rtv *rtv, t_ray *r, int *cur_obj, t_vec3d *new_start)
{
	float	t;
	int		i;
	t_vec3d	scaled;

	t = 2000;
	i = -1;
	while(i++ < rtv->scene->objs_n - 1)
	{
		if (rtv->scene->objects[i]->intersect(r, rtv->scene->objects[i], &t))
			*cur_obj = i;
	}
	if(*cur_obj == -1)
		return (false);
	scaled = vec3d_scale(t, &r->dir);
	*new_start = vec3d_add(&r->start, &scaled);
	return (true);
}

/*
** Find the normal for this new vector at the point of intersection.
** n - normal; s - new_start;
*/
t_bool normal_of_intersect(t_vec3d *n, t_vec3d *s, t_obj3d **objs, int cur_obj)
{
	float temp;
	*n = vec3d_sub(s, &objs[cur_obj]->pos);
	temp = vec3d_dot(n, n);
	if(temp == 0)
		return (false);
	temp = 1.0f / sqrtf(temp);
	*n = vec3d_scale(temp, n);
	return (true);
}