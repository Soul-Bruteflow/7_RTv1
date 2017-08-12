#include "objects.h"
#include "rtv1.h"

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

void	set_sphere(t_obj3d *obj, t_vec3d new_position, float new_radius, Uint16 new_material)
{
	set_object_position(obj, new_position);
	set_object_material(obj, new_material);
	set_sphere_radius(obj, new_radius);
}

//void	set_sphere_color(t_sphere *sphere, t_vec3d new_position)
//{
//	sphere->pos.x = new_position.x;
//	sphere->pos.y = new_position.y;
//	sphere->pos.z = new_position.z;
//}