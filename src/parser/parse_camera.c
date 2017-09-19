#include "rtv.h"
#include "rtv_defines.h"

static t_bool	cam_line_one(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, "camera position:") == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

static t_bool	cam_line_two(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, "camera direction:") == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

static t_bool	cam_line_three(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, "fov:") == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

t_bool	parse_camera(t_rtv *r)
{
	float n;

	if (!(cam_line_one(r)))
		return (false);
	if (!(parse_vector(r, &r->scene->cam.o, V_MIN, V_MAX)))
		return (false);
	if (!(cam_line_two(r)))
		return (false);
	if (!(parse_vector(r, &r->scene->cam.d, V_MIN, V_MAX)))
		return (false);
	if (!(cam_line_three(r)))
		return (false);
	if (!(parse_number(r, &n, F_MIN, F_MAX)))
		return (false);
	r->scene->cam.fov = n;
	return (true);
}