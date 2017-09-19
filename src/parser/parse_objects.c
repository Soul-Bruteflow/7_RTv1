#include "rtv.h"
#include "rtv_defines.h"

static t_bool	objs_line_one(t_rtv *r)
{
	if (ft_strcmp(r->pars->line, "objects:") == 0)
	{
		free(r->pars->line);
		return (true);
	}
	return (false);
}


t_bool parse_objects(t_rtv *r)
{
	int i;

	if (!(objs_line_one(r)))
		return (false);
	if (!(get_str(r)))
		return (false);
	i = -1;
	while (i++ < r->scene->objects_n)
	{
		if (!(get_str(r)))
			return (false);
		if (r->pars->line == "plane:")
			parse_plane(r);
		else if (r->pars->line == "sphere:")
			parse_sphere(r);
		else if (r->pars->line == "cylinder:")
			parse_cylinder(r);
		else if (r->pars->line == "cone:")
			parse_cone(r);
		free(r->pars->line);
	}
	return (true);
}