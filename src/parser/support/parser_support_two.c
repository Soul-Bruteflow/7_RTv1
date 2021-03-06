/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_support_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:21:11 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "libft.h"

/*
** Parses float values in to the float.
*/

t_bool	parse_float_number(t_rtv *r, float *n, float min, float max)
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
** Parses line by line color values.
*/

t_bool	parse_color(t_rtv *r, t_rgbap *c, float min, float max)
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

/*
** Gets new string provided by the get_next_line. And checks if read from the
** file is possible.
*/

t_bool	get_str(t_rtv *r)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
		return (true);
	return (false);
}

/*
** Reads the line and compares it to the provided *s. Frees the line afterwards.
*/

t_bool	check_line(t_rtv *r, const char *s)
{
	if ((r->pars->n = get_next_line(r->pars->fd, &r->pars->line)) == 1)
	{
		if (ft_strcmp(r->pars->line, s) == 0)
		{
			free(r->pars->line);
			return (true);
		}
	}
	return (false);
}

/*
** Parses and checks if the parsed material value is valid.
*/

t_bool	valid_material(t_rtv *r, Uint16 *material, int min, int max)
{
	float tmp;

	if (!(parse_number(r, &tmp, min, max)))
		return (false);
	*material = (Uint16)tmp;
	if (tmp > r->scene->mats_n - 1)
		return (false);
	return (true);
}
