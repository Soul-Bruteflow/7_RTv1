#include "rtv.h"

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

static t_bool get_scene_numbers(t_rtv *r, uint8_t *n)
{
	int tmp;

	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		tmp = ft_atoi(r->pars->line);
		if (tmp >= 1 && tmp <= 10)
		{
			*n = (uint8_t)tmp;
			return (true);
		}
	}
	return (false);
}

t_bool	parse_scene(t_rtv *r)
{
	uint8_t n;

	if (!(scene_line_one(r)))
		return (false);
	if (!(get_scene_numbers(r, &n)))
		return (false);
	r->scene->lights_n = n;
	if (!(scene_line_two(r)))
		return (false);
	if (!(get_scene_numbers(r, &n)))
		return (false);
	r->scene->lights_n = n;
	if (!(scene_line_three(r)))
		return (false);
	if (!(get_scene_numbers(r, &n)))
		return (false);
	r->scene->lights_n = n;
	return (true);
}