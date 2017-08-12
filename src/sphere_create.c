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

void	set_sphere_radius(t_sphere *sphere, float new_radius)
{
	sphere->radius = new_radius;
}

void	set_object_position(t_obj3d *obj, t_vec3d new_position)
{
	obj->pos.x = new_position.x;
	obj->pos.y = new_position.y;
	obj->pos.z = new_position.z;
}

void	set_object_material(t_obj3d *obj, Uint16 new_material)
{
	obj->material = new_material;
}

void	set_sphere(t_obj3d *obj, t_vec3d new_position, float new_radius, Uint16 material)
{
	set_sphere_radius(sphere, new_radius);
	set_sphere_position(sphere, new_position);
	obj->material = material;
}

//void	set_sphere_color(t_sphere *sphere, t_vec3d new_position)
//{
//	sphere->pos.x = new_position.x;
//	sphere->pos.y = new_position.y;
//	sphere->pos.z = new_position.z;
//}