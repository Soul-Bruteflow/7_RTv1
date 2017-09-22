#include "rtv.h"

t_bool	parser_core(t_rtv *r)
{
	open_file(r);
	if (!(check_line(r, "scene:")))
		return (false);
	if (!(parse_scene(r)))
		return (false);
	create_scene(r);
	if (!(check_line(r, "camera:")))
		return (false);
	if (!(parse_camera(r)))
		return (false);
	if (!(check_line(r, "lights:")))
		return (false);
	if (!(parse_lights(r)))
		return (false);
	if (!(check_line(r, "materials:")))
		return (false);
	if (!(parse_materials(r)))
		return (false);
	if (!(check_line(r, "objects:")))
		return (false);
	if (!(parse_objects(r)))
		rtv_error(parse_error);
	gnl_error(r, r->pars->n);
	close_file(r);

	t_cylinder 	*cy;

	cy = r->scene->objects[3]->type;
	cy->a.x = 200;
	cy->a.y = 200;
	cy->a.z = 200;

	cy->b.x = 600;
	cy->b.y = 600;
	cy->b.z = 600;

	return (true);
}
