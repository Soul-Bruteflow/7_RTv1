#include "objects.h"
#include "rtv.h"

t_sphere *new_sphere()
{
	t_sphere *sphere;

	sphere = malloc(sizeof(*(sphere)));
	if (sphere == NULL)
		rtv_error(malloc_error);
	return (sphere);
}

void	set_sphere_radius(t_obj3d *obj, float new_radius)
{
	t_sphere *tmp_sphere;

	tmp_sphere = obj->type;
	tmp_sphere->radius = new_radius;
}

void	set_sphere(t_obj3d *obj, t_vec3d new_pos, float new_rad, Uint16 new_mat)
{
	set_object_position(obj, new_pos);
	set_object_material(obj, new_mat);
	set_sphere_radius(obj, new_rad);
}