#include "rtv.h"
# include "get_next_line.h"

/*
** Closes the file, and checks for the errors.
*/

void	close_file(t_rtv *r)
{
	if ((close(r->pars->fd)) < 0)
		rtv_error(file_close_error);
}

/*
** Opens the file, and checks for the errors.
*/

void	open_file(t_rtv *r)
{
	r->pars->fd = open(r->pars->av[1], O_RDONLY);
	if (r->pars->fd < 0)
		rtv_error(file_open_error);
}

/*
** Checks for the GNL errors.
*/

void	gnl_error(t_rtv *r, int i)
{
	if (i < 0)
	{
		close_file(r);
		rtv_error(gnl_error_code);
	}
}

/*
** Converts current read string in to the float.
*/
t_bool parse_number(t_rtv *r, float *n)
{
	float tmp;

	tmp = ft_atoi(r->pars->line);
	if (tmp >= -10000 && tmp <= 10000)
	{
		*n = tmp;
		return (true);
	}
	return (false);
}

/*
** Parses line by line vector values.
*/
t_bool parse_vecor(t_rtv *r, t_vec3d *v)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (!(parse_number(r, &v->x)))
			return (false);
		free(r->pars->line);
	}
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (!(parse_number(r, &v->y)))
			return (false);
		free(r->pars->line);
	}
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (!(parse_number(r, &v->z)))
			return (false);
		free(r->pars->line);
		return (true);
	}
	return (false);
}