#include "rtv.h"

t_bool	new_lights(t_rtv *r)
{
	int i;

	i = 0;
	while (i < r->scene->lights_n)
	{
		r->scene->lights[i] = new_light();
		i++;
	}
	return (true);
}

t_bool	new_materials(t_rtv *r)
{
	int i;

	i = 0;
	while (i < r->scene->materials_n)
	{
		r->scene->materials[i] = new_material();
		i++;
	}
	return (true);
}

t_bool	create_scene_real(t_rtv* r)
{
	new_scene(r, r->scene->lights_n, r->scene->materials_n, r->scene->objects_n);
	if (!(new_lights(r)))
		return (false);
	if (!(new_materials(r)))
		return (false);
	return (true);
}

void	parser_read_one(t_rtv *r)
{
	open_file(r);
	if (!(parse_scene(r)))
		rtv_error(parse_error);
	create_scene_real(r);
	if (!(parse_camera(r)))
		rtv_error(parse_error);
	if (!(parse_lights(r)))
		rtv_error(parse_error);
	if (!(parse_materials(r)))
		rtv_error(parse_error);
	if (!(parse_objects(r)))
		rtv_error(parse_error);

////	printf("0 pos.x %f, ", r->scene->lights[0]->pos.x);
////	printf("0 pos.y %f, ", r->scene->lights[0]->pos.y);
////	printf("0 pos.z %f\n", r->scene->lights[0]->pos.z);
//
//	printf("r %f, ", r->scene->materials[0]->diffuse.red);
//	printf("g %f, ", r->scene->materials[0]->diffuse.green);
//	printf("b %f, ", r->scene->materials[0]->diffuse.blue);
//	printf("a %f\n", r->scene->materials[0]->diffuse.alpha);
//
////	printf("1 pos.x %f, ", r->scene->lights[1]->pos.x);
////	printf("1 pos.y %f, ", r->scene->lights[1]->pos.y);
////	printf("1 pos.z %f\n", r->scene->lights[1]->pos.z);
//
//	printf("r %f, ", r->scene->materials[1]->diffuse.red);
//	printf("g %f, ", r->scene->materials[1]->diffuse.green);
//	printf("b %f, ", r->scene->materials[1]->diffuse.blue);
//	printf("a %f\n", r->scene->materials[1]->diffuse.alpha);
//
////	printf("2 pos.x %f, ", r->scene->lights[2]->pos.x);
////	printf("2 pos.y %f, ", r->scene->lights[2]->pos.y);
////	printf("2 pos.z %f\n", r->scene->lights[2]->pos.z);
//
//	printf("r %f, ", r->scene->materials[2]->diffuse.red);
//	printf("g %f, ", r->scene->materials[2]->diffuse.green);
//	printf("b %f, ", r->scene->materials[2]->diffuse.blue);
//	printf("a %f\n", r->scene->materials[2]->diffuse.alpha);

//	printf("r %f, ", r->scene->materials[0]->reflection);
//	printf("r %f, ", r->scene->materials[1]->reflection);
//	printf("r %f, ", r->scene->materials[2]->reflection);

	gnl_error(r, r->pars->n);
	close_file(r);
}
