#include "rtv.h"
#include "rtv_defines.h"

static t_bool	parse_mats_color(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->mats_n - 1)
	{
		if (check_line(r, "color:"))
		{
			if (!(parse_color(r,
				&r->scene->materials[i]->diffuse, C_MIN, C_MAX)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->mats_n)
		return (false);
	return (true);
}

static t_bool	parse_mats_reflection(t_rtv *r)
{
	int i;

	i = -1;
	while (i++ < r->scene->mats_n - 1)
	{
		if (check_line(r, "reflection:"))
		{
			if (!(parse_float_number(r,
				&r->scene->materials[i]->reflection, R_MIN, R_MAX)))
				return (false);
		}
		else
			return (false);
	}
	if (i != r->scene->mats_n)
		return (false);
	return (true);
}

t_bool parse_materials(t_rtv *r)
{
	if (!(parse_mats_color(r)))
		return (false);
	if (!(parse_mats_reflection(r)))
		return (false);
	return (true);
}