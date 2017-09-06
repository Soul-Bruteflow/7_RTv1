#include "rtv.h"

t_plane *new_plane()
{
	t_plane *plane;

	plane = malloc(sizeof(*(plane)));
	if (plane == NULL)
		rtv_error(malloc_error);
	return (plane);
}

void	set_plane_distance(t_obj3d *obj, float new_distance)
{
	t_plane *tmp_plane;

	tmp_plane = obj->type;
	tmp_plane->distance = new_distance;
}

void	set_plane_normal(t_obj3d *obj, t_vec3d new_normal)
{
	t_plane *tmp_plane;

	tmp_plane = obj->type;
	tmp_plane->normal.x = new_normal.x;
	tmp_plane->normal.y = new_normal.y;
	tmp_plane->normal.z = new_normal.z;
}

void	set_plane(t_obj3d *obj, t_vec3d new_norm, float new_dist, Uint16 new_mat)
{
	set_plane_distance(obj, new_dist);
	set_plane_normal(obj, new_norm);
	set_object_material(obj, new_mat);
}