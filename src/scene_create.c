#include "rtv1.h"
#include "objects.h"

t_scene *new_scene(Uint8 number_of_objects, Uint8 number_of_lights)
{
	t_scene *scene;

	scene = malloc(sizeof(*(scene)));
	if (scene == NULL)
		rtv_error(malloc_error);
	scene->obj = malloc(number_of_objects * sizeof(scene->obj));
	if (scene->obj == NULL)
		rtv_error(malloc_error);
	scene->material = malloc(number_of_objects * sizeof(scene->material));
	if (scene->material == NULL)
		rtv_error(malloc_error);
	scene->light = malloc(number_of_lights * sizeof(scene->light));
	if (scene->light == NULL)
		rtv_error(malloc_error);
	scene->ray = malloc(sizeof(*(scene->ray)));
	if (scene->obj == NULL)
		rtv_error(malloc_error);
	return (scene);
}

void create_sceen_one(t_scene *scene)
{
	scene->obj[0] = new_object(sphere);
//	scene->obj[1] = new_object(plane);
//	scene->obj[0].intersect = intersect_sphere;
//	/* Position the sphere */
//	scene->obj[0].data
////	s.pos.y = 20;
////	s.pos.z = 20;

	t_vec3d sphere_position;

	sphere_position.x = 200;
	sphere_position.y = 300;
	sphere_position.z = 0;
	/* Sphere radius */
	set_sphere_radius(scene->obj[0]->sphere, 100);
	set_sphere_position(scene->obj[0]->sphere, sphere_position);

//	scene->obj[1]->plane->d = 6;
//	scene->obj[1]->plane->n.x = 0;
//	scene->obj[1]->plane->n.y = 0;
//	scene->obj[1]->plane->n.z = 1;

//	scene->obj[1]->plane->pos.x = 0;
//	scene->obj[1]->plane->pos.y = 0;
//	scene->obj[1]->plane->pos.z = 20;
//
//	scene->obj[1]->plane->rot.x = 0;
//	scene->obj[1]->plane->rot.y = 0;
//	scene->obj[1]->plane->rot.z = -1;
}

t_scene *create_sceen(int sceen_number)
{
	t_scene *scene;

	if (sceen_number == 1)
	{
		scene = new_scene(1, 1);
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
	else if (object_type == plane)
		new_obj->plane = new_plane();
	return (new_obj);
}