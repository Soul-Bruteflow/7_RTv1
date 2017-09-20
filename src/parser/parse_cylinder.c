#include "rtv.h"
#include "rtv_defines.h"

void	alloc_new_cylinder(t_rtv *r, int i)
{
	r->scene->objects[i] = new_object(cylinder);
	r->scene->objects[i]->type = new_cylinder();
	r->scene->objects[i]->intersect = intersect_cylinder_ray;
}

t_bool	parse_cylinder(t_rtv *r, int i)
{
	t_vec3d		position;
	float		radius;
	Uint16		material;

	free(r->pars->line);
	alloc_new_cylinder(r, i);
	if (!(check_line(r, "position:")))
		return (false);
	if (!(parse_vector(r, &position, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "radius:")))
		return (false);
	if (!(parse_number(r, &radius, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "material:")))
		return (false);
	if (!(valid_material(r, &material, M_MIN, M_MAX)))
		return (false);
	set_cylinder(r->scene->objects[i], position, radius, material);
	return (true);
}