#include "rtv.h"

/*
** Find closest intersection
*/
t_bool	object_intersect(t_obj3d **objects, t_ray *r, int *cur_obj, t_vec3d *new_start)
{
	float	t;
	int		i;
	t_vec3d	scaled;

	t = 2000;
	i = -1;
	while(i++ < 3)
	{
		if (objects[i]->intersect(r, objects[i], &t))
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
*/
t_bool normal_of_intersect(t_vec3d *normal, t_vec3d *new_start, t_obj3d **objects, int cur_obj)
{
	float temp;
	*normal = vec3d_sub(new_start, &objects[cur_obj]->pos);
	temp = vec3d_dot(normal, normal);
	if(temp == 0)
		return (false);
	temp = 1.0f / sqrtf(temp);
	*normal = vec3d_scale(temp, normal);
	return (true);
}