#include "rtv.h"
#include "rtv_defines.h"

static t_bool	lights_line_one(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, "lights:") == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}


static t_bool	parse_lights_position(t_rtv *r)
{
	int i;

	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		i = -1;
		while (i++ < r->scene->lights_n)
		{
			if (ft_strcmp(r->pars->line, "position:") == 0)
			{
				free(r->pars->line);
				if (!(parse_vector(r, &r->scene->lights[i]->pos, V_MIN, V_MAX)))
					return (false);
				r->pars->n = get_next_line(r->pars->fd, &r->pars->line);
			}
		}
		return (true);
	}
	return (false);
}

static t_bool	parse_lights_color(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->lights_n)
	{
		if (ft_strcmp(r->pars->line, "color:") == 0)
		{
			free(r->pars->line);
			if (!(parse_color(r, &r->scene->lights[i]->color, C_MIN, C_MAX)))
				return (false);
			r->pars->n = get_next_line(r->pars->fd, &r->pars->line);
		}
	}
	return (true);
}

static t_bool	parse_lights_data(t_rtv *r)
{
	if (!(parse_lights_position(r)))
		return (false);
	if (!(parse_lights_color(r)))
		return (false);
	return (true);
}

t_bool parse_lights(t_rtv *r)
{
	if (!(lights_line_one(r)))
		return (false);
	if (!(parse_lights_data(r)))
		return (false);
	return (true);
}