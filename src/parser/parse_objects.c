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

t_bool	parse_objects(t_rtv *r)
{
	int i;

	if (!(objs_line_one(r)))
		return (false);
	if (!(get_str(r)))
		return (false);
	i = -1;

//	if (!(get_str(r)))
//		return (false);
	while (i++ < r->scene->objects_n)
	{
		if ((ft_strcmp(r->pars->line, "plane:") == 0))
		{
			if (!(parse_plane(r, i)))
				return (false);
			if (!(get_str(r)))
				return (false);
		}
		else if ((ft_strcmp(r->pars->line, "sphere:") == 0))
		{
			if (!(parse_sphere(r, i)))
				return (false);
			if (!(get_str(r)))
				return (false);
		}
		else if ((ft_strcmp(r->pars->line, "cylinder:") == 0))
		{
			if (!(parse_cylinder(r, i)))
				return (false);
			if (!(get_str(r)))
				return (false);
		}
		else if ((ft_strcmp(r->pars->line, "cone:") == 0))
		{
			if (!(parse_cone(r, i)))
				return (false);
//			if (!(get_str(r)))
//				return (false);
		}
		else if (i == r->scene->objects_n)
			return (true);
		else
			return (false);
	}

//	if (r->pars->line == "plane:")




//	while (i++ < r->scene->objects_n)
//	{
//		if (!(get_str(r)))
//			return (false);
//		if (r->pars->line == "plane:")
//			parse_plane(r, i);
//		else if (r->pars->line == "sphere:")
//			parse_sphere(r, i);
//		else if (r->pars->line == "cylinder:")
//			parse_cylinder(r, i);
//		else if (r->pars->line == "cone:")
//			parse_cone(r, i);
//	}
	return (true);
}