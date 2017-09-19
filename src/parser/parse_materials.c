#include "rtv.h"
#include "rtv_defines.h"

static t_bool	mats_line_one(t_rtv *r)
{
	if (ft_strcmp(r->pars->line, "materials:") == 0)
	{
		free(r->pars->line);
		return (true);
	}
	return (false);
}

static t_bool	parse_mats_color(t_rtv *r)
{
	int i;

	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		i = -1;
		while (i++ < r->scene->materials_n)
		{
			if (ft_strcmp(r->pars->line, "color:") == 0)
			{
				free(r->pars->line);
				if (!(parse_color(r, &r->scene->materials[i]->diffuse, C_MIN, C_MAX)))
					return (false);
				r->pars->n = get_next_line(r->pars->fd, &r->pars->line);
			}
		}
		return (true);
	}
	return (false);
}

static t_bool	parse_mats_reflection(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->materials_n)
	{
		if (ft_strcmp(r->pars->line, "reflection:") == 0)
		{
			free(r->pars->line);
			if (!(parse_float_number(r, &r->scene->materials[i]->reflection, R_MIN, R_MAX)))
				return (false);
			r->pars->n = get_next_line(r->pars->fd, &r->pars->line);
		}
	}
	return (true);
}

static t_bool	parse_mats_data(t_rtv *r)
{
	if (!(parse_mats_color(r)))
		return (false);
	if (!(parse_mats_reflection(r)))
		return (false);
	return (true);
}

t_bool parse_materials(t_rtv *r)
{
	if (!(mats_line_one(r)))
		return (false);
	if (!(parse_mats_data(r)))
		return (false);
	return (true);
}