#include "rtv.h"
#include "rtv_defines.h"

static t_bool	scene_line_one(t_rtv *r)
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

static t_bool	scene_line_two(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, "materials:") == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

static t_bool	scene_line_three(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, "objects:") == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

t_bool	parse_scene(t_rtv *r)
{
	float n;

	if (!(scene_line_one(r)))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
			return (false);
	r->scene->lights_n = (Uint8)n;
	if (!(scene_line_two(r)))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->materials_n = (Uint8)n;
	if (!(scene_line_three(r)))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->objects_n = (Uint8)n;
	return (true);
}