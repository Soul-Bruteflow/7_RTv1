#include "rtv.h"
#include "string.h"
#include "rtv_defines.h"

t_bool parse_float_number(t_rtv *r, float *n, float min, float max)
{
	float tmp;
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		tmp = ft_atof(r->pars->line);
		if (tmp >= min && tmp <= max)
		{
			*n = tmp;
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

/*
** Parses line by line vector values.
*/
t_bool parse_color(t_rtv *r, t_rgbap *c, float min, float max)
{
	if (!(parse_float_number(r, &c->red, min, max)))
		return (false);
	if (!(parse_float_number(r, &c->green, min, max)))
		return (false);
	if (!(parse_float_number(r, &c->blue, min, max)))
		return (false);
	if (!(parse_float_number(r, &c->alpha, min, max)))
		return (false);
	return (true);
}