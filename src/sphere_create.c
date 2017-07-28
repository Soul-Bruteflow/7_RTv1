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

void	set_sphere_position(t_sphere *sphere, t_vec3d new_position)
{
	sphere->pos.x = new_position.x;
	sphere->pos.y = new_position.y;
	sphere->pos.z = new_position.z;
}

void	set_sphere(t_sphere *sphere, t_vec3d new_position, float new_radius, int material)
{
	set_sphere_radius(sphere, new_radius);
	set_sphere_position(sphere, new_position);
	sphere->material = material;
}

//void	set_sphere_color(t_sphere *sphere, t_vec3d new_position)
//{
//	sphere->pos.x = new_position.x;
//	sphere->pos.y = new_position.y;
//	sphere->pos.z = new_position.z;
//}