#include "rtv.h"

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

t_bool	parse_camera(t_rtv *r)
{
	if (!(cam_line_one(r)))
		return (false);
	if (!(parse_vecor(r, &r->scene->cam.o)))
		return (false);
	if (!(cam_line_two(r)))
		return (false);
	if (!(parse_vecor(r, &r->scene->cam.d)))
		return (false);

	printf("x %f, ", r->scene->cam.d.x);
	printf("y %f, ", r->scene->cam.d.y);
	printf("z %f\n", r->scene->cam.d.z);

	return (true);
}

void	parser_read_one(t_rtv *r)
{
	open_file(r);
	if (!(parse_scene(r)))
		rtv_error(parse_error);
	if (!(parse_camera(r)))
		rtv_error(parse_error);
	gnl_error(r, r->pars->n);
	close_file(r);
}
