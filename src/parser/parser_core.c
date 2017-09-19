#include "rtv.h"
#include "rtv_defines.h"

t_bool	new_lights(t_rtv *r)
{
	int i;

	i = 0;
	while (i < r->scene->lights_n)
	{
		r->scene->lights[i] = new_light();
		i++;
	}
//	r->scene->lights[0] = new_light();
//	r->scene->lights[1] = new_light();
//	r->scene->lights[2] = new_light();
	return (true);
}

t_bool	create_scene_real(t_rtv* r)
{
	new_scene(r, r->scene->lights_n, r->scene->materials_n, r->scene->objects_n);
	if (!(new_lights(r)))
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

//	printf("0 pos.x %f, ", r->scene->lights[0]->pos.x);
//	printf("0 pos.y %f, ", r->scene->lights[0]->pos.y);
//	printf("0 pos.z %f\n", r->scene->lights[0]->pos.z);

	printf("r %f, ", r->scene->lights[0]->color.red);
	printf("g %f, ", r->scene->lights[0]->color.green);
	printf("b %f, ", r->scene->lights[0]->color.blue);
	printf("a %f\n", r->scene->lights[0]->color.alpha);

//	printf("1 pos.x %f, ", r->scene->lights[1]->pos.x);
//	printf("1 pos.y %f, ", r->scene->lights[1]->pos.y);
//	printf("1 pos.z %f\n", r->scene->lights[1]->pos.z);

	printf("r %f, ", r->scene->lights[1]->color.red);
	printf("g %f, ", r->scene->lights[1]->color.green);
	printf("b %f, ", r->scene->lights[1]->color.blue);
	printf("a %f\n", r->scene->lights[1]->color.alpha);

//	printf("2 pos.x %f, ", r->scene->lights[2]->pos.x);
//	printf("2 pos.y %f, ", r->scene->lights[2]->pos.y);
//	printf("2 pos.z %f\n", r->scene->lights[2]->pos.z);

	printf("r %f, ", r->scene->lights[2]->color.red);
	printf("g %f, ", r->scene->lights[2]->color.green);
	printf("b %f, ", r->scene->lights[2]->color.blue);
	printf("a %f\n", r->scene->lights[2]->color.alpha);


	gnl_error(r, r->pars->n);
	close_file(r);
}
