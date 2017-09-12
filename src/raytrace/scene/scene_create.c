#include "rtv.h"
#include "objects.h"

/*
** Allocates memory for new scene. And all objects,
** lights and materials defined bu arguments.
*/
t_scene *new_scene(Uint8 nbr_of_objs, Uint8 nbr_of_mats, Uint8 nbr_of_lights)
{
	t_scene *scene;

	scene = malloc(sizeof(*(scene)));
	if (scene == NULL)
		rtv_error(malloc_error);
	scene->objects = malloc(nbr_of_objs * sizeof(scene->objects));
	if (scene->objects == NULL)
		rtv_error(malloc_error);
	scene->materials = malloc(nbr_of_mats * sizeof(scene->materials));
	if (scene->materials == NULL)
		rtv_error(malloc_error);
	scene->lights = malloc(nbr_of_lights * sizeof(scene->lights));
	if (scene->lights == NULL)
		rtv_error(malloc_error);
	scene->objects_n = nbr_of_objs;
	scene->materials_n = nbr_of_mats;
	scene->lights_n = nbr_of_lights;
	return (scene);
}

void create_sceen_one(t_scene *scene)
{
	scene->objects[0] = new_object(plane);
	scene->objects[1] = new_object(sphere);
	scene->objects[2] = new_object(cylinder);

	scene->objects[0]->type = new_plane();
	scene->objects[1]->type = new_sphere();
	scene->objects[2]->type = new_cylinder();

	scene->objects[0]->intersect = intersect_plane_ray;
	scene->objects[1]->intersect = intersect_sphere_ray;
	scene->objects[2]->intersect = intersect_cylinder_ray;

	scene->materials[0] = new_material();
	scene->materials[1] = new_material();
	scene->materials[2] = new_material();
	scene->lights[0] = new_light();
	scene->lights[1] = new_light();
	scene->lights[2] = new_light();

	set_plane(scene->objects[0], ft_set_vector(2, 90, 200), ft_set_vector(500, 500, 200), 0);
	set_sphere(scene->objects[1], ft_set_vector(400, 400, 0), 100, 1);
	set_cylinder(scene->objects[2], ft_set_vector(2, 90, 200), 80, 2);

	set_material(scene->materials[0], ft_set_color(0, 1, 1, 1), 0.01);
	set_material(scene->materials[1], ft_set_color(0, 1, 0, 1), 0.01);
	set_material(scene->materials[2], ft_set_color(0, 0, 1, 1), 0.01);

	set_light(scene->lights[0], ft_set_vector(0, 1240, -100), ft_set_color(1, 1, 1, 1));
	set_light(scene->lights[1], ft_set_vector(400, 300, -1000), ft_set_color(0.6, 0.7, 1, 1));
	set_light(scene->lights[2], ft_set_vector(1600, 0, -100), ft_set_color(0.3, 0.5, 1, 1));

}

t_scene *create_scene(int sceen_number)
{
	t_scene *scene;

	if (sceen_number == 1)
	{
		scene = new_scene(3, 3, 3);
		create_sceen_one(scene);
	}
	return (scene);
}

t_obj3d *new_object(t_obj_type object_type)
{
	t_obj3d *new_obj;

	new_obj = malloc(sizeof(*(new_obj)));
	if (new_obj == NULL)
		rtv_error(malloc_error);
	new_obj->obj_type = object_type;
	return (new_obj);
}