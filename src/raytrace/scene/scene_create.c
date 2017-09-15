#include "rtv.h"
#include "objects.h"
#include "rtv_defines.h"

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
	scene->objects[3] = new_object(cone);

	scene->objects[0]->type = new_plane();
	scene->objects[1]->type = new_sphere();
	scene->objects[2]->type = new_cylinder();
	scene->objects[3]->type = new_cone();

	scene->objects[0]->intersect = intersect_plane_ray;
	scene->objects[1]->intersect = intersect_sphere_ray;
	scene->objects[2]->intersect = intersect_cylinder_ray;
	scene->objects[3]->intersect = intersect_cone_ray;

	scene->materials[0] = new_material();
	scene->materials[1] = new_material();
	scene->materials[2] = new_material();
	scene->lights[0] = new_light();
	scene->lights[1] = new_light();
	scene->lights[2] = new_light();

//	float tmp[2] = {30, 60};

	t_cone *cone;
	cone = scene->objects[3]->type;
	cone->angle = 10;
	cone->tip.x = 400;
	cone->tip.y = 400;
	cone->tip.z = 150;

	cone->axis.x = 0;
	cone->axis.y = 1;
	cone->axis.z = 0;

	cone->axis = ft_vec3d_norm(cone->axis);
	scene->objects[3]->material = 1;
	scene->objects[3]->pos.x = 400;
	scene->objects[3]->pos.y = 400;
	scene->objects[3]->pos.z = 150;

	set_plane(scene->objects[0], ft_set_vector(2, 90, 200), ft_set_vector(500, 500, 300), 0);
	set_sphere(scene->objects[1], ft_set_vector(100, 100, 0), 60, 1);
	set_cylinder(scene->objects[2], ft_set_vector(2, 90, 200), 80, 2);
//	set_cone(scene->objects[3], ft_set_vector(400, 400, 0), tmp, 2);

	set_material(scene->materials[0], ft_set_color(0, 1, 1, 1), 0.01);
	set_material(scene->materials[1], ft_set_color(0, 1, 0, 1), 0.01);
	set_material(scene->materials[2], ft_set_color(0, 0, 1, 1), 0.01);

	set_light(scene->lights[0], ft_set_vector(0, 0, -2000), ft_set_color(1, 1, 1, 1));
	set_light(scene->lights[1], ft_set_vector(400, 300, -1000), ft_set_color(0.6, 0.7, 1, 1));
	set_light(scene->lights[2], ft_set_vector(1600, 0, -100), ft_set_color(0.3, 0.5, 1, 1));

}

t_scene *create_scene(int sceen_number)
{
	t_scene *scene;

	if (sceen_number == 1)
	{
		scene = new_scene(4, 3, 3);

		scene->cam.o.x = 0;
		scene->cam.o.y = 0;
		scene->cam.o.z = -1900;
		scene->cam.d.x = 0;
		scene->cam.d.y = 0;
		scene->cam.d.z = 1;
		scene->cam.up.x = 0;
		scene->cam.up.y = 1;
		scene->cam.up.z = 0;
		scene->cam.fov = 65;
		scene->cam.eye = ft_vec3d_unit(vec3d_sub(&scene->cam.d, &scene->cam.o));
		scene->cam.vpRight = ft_vec3d_unit(vec3d_cross(&scene->cam.eye, &scene->cam.up));
		scene->cam.vpUp = ft_vec3d_unit(vec3d_cross(&scene->cam.vpRight, &scene->cam.eye));

		float fovRadians = PI * (scene->cam.fov / 2) / 180;
		float heightWidthRatio = 600.0f / 800.0f;
		scene->cam.halfWidth = tanf(fovRadians);
		scene->cam.halfHeight = heightWidthRatio * scene->cam.halfWidth;
		float camerawidth = scene->cam.halfWidth * 2;
		float cameraheight = scene->cam.halfHeight * 2;
		scene->cam.pixelWidth = camerawidth / (800.0f - 1);
		scene->cam.pixelHeight = cameraheight / (600.0f - 1);

		scene->ray.start = scene->cam.o;

//		scene->cam = create_perspective_cam(ft_set_vector(0, 0, -200),
//				ft_set_vector(0, 0, 1), ft_set_vector(0, 1, 0), w_h);

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