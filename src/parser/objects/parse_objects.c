#include "rtv.h"

t_bool	choose(t_rtv *r, int i)
{
	if ((ft_strcmp(r->pars->line, "plane:") == 0))
	{
		if (!(parse_plane(r, i)))
			return (false);
	}
	else if ((ft_strcmp(r->pars->line, "sphere:") == 0))
	{
		if (!(parse_sphere(r, i)))
			return (false);
	}
	else if ((ft_strcmp(r->pars->line, "cylinder:") == 0))
	{
		if (!(parse_cylinder(r, i)))
			return (false);
	}
	else if ((ft_strcmp(r->pars->line, "cone:") == 0))
	{
		if (!(parse_cone(r, i)))
			return (false);
	}
	else
		return (false);
	return (true);
}

t_bool	parse_objects(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->objs_n - 1)
	{
		if (!(get_str(r)))
			return (false);
		if (!(choose(r, i)))
			return (false);
	}
	if (i != r->scene->objs_n || (check_line(r, "end") == false))
		return (false);
	return (true);
}