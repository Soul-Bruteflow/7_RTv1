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
	scene->objects_n = number_of_objects;
	scene->lights_n = number_of_objects;
}

void create_sceen_one(t_scene *scene)
{
	scene->obj[0] = new_object(sphere);
	scene->material[0] = new_material();
	scene->light[0] = new_light();

	set_sphere(scene->obj[0]->sphere, ft_set_vector(200, 300, 0), 100, 0);
	set_material(scene->material[0], ft_set_color(1, 0, 0, SDL_ALPHA_OPAQUE), 0.2);
	set_light(scene->light[0], ft_set_vector(0, 240, -100), ft_set_color(1, 1, 1, SDL_ALPHA_OPAQUE));
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