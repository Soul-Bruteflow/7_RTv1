#include "rtv1.h"
#include "objects.h"

t_scene *new_scene(Uint8 obj_number)
{
	t_scene *scene;

	scene = malloc(sizeof(*(scene)));
	if (scene == NULL)
		rtv_error(malloc_error);
	scene->obj = malloc(obj_number * sizeof(scene->obj));
	if (scene->obj == NULL)
		rtv_error(malloc_error);
	scene->ray = malloc(sizeof(*(scene->ray)));
	if (scene->obj == NULL)
		rtv_error(malloc_error);
	return (scene);
}

void create_sceen_one(t_scene *scene)
{
	scene->obj[0] = new_object(sphere);
//	scene->obj[0].intersect = intersect_sphere;
//	/* Position the sphere */
//	scene->obj[0].data
////	s.pos.y = 20;
////	s.pos.z = 20;

	t_vec3d sphere_position;

	sphere_position.x = 200;
	sphere_position.y = 400;
	sphere_position.z = 0;
	/* Sphere radius */
	set_sphere_radius(scene->obj[0]->sphere, 50);
	set_sphere_position(scene->obj[0]->sphere, sphere_position);
}

t_scene *create_sceen(int sceen_number)
{
	t_scene *scene;

	if (sceen_number == 1)
	{
		scene = new_scene(1);
		create_sceen_one(scene);
	}
	scene->ray->dir.x = 0;
	scene->ray->dir.y = 0;
	scene->ray->dir.z = 1;

	/* Start position of the ray, z coordinate */
	scene->ray->start.z = 0;
	return (scene);
}

t_obj3d *new_object(t_obj_type object_type)
{
	t_obj3d *new_obj;

	new_obj = malloc(sizeof(*(new_obj)));
	if (new_obj == NULL)
		rtv_error(malloc_error);
	if (object_type == sphere)
		new_obj->sphere = new_sphere();
	return (new_obj);
}