#include "rtv.h"
#include "rtv_defines.h"

void	alloc_new_plane(t_rtv *r, int i)
{
	r->scene->objects[i] = new_object(plane);
	r->scene->objects[i]->type = new_plane();
	r->scene->objects[i]->intersect = intersect_plane_ray;
}

t_bool	parse_plane(t_rtv *r, int i)
{
	t_vec3d		normal;
	t_vec3d		point;
	Uint16		material;

	free(r->pars->line);
	alloc_new_plane(r, i);
	if (!(check_line(r, "normal:")))
		return (false);
	if (!(parse_vector(r, &normal, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "point:")))
		return (false);
	if (!(parse_vector(r, &point, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "material:")))
		return (false);
	if (!(valid_material(r, &material, M_MIN, M_MAX)))
		return (false);
	set_plane(r->scene->objects[i], normal, point, material);
	return (true);
}