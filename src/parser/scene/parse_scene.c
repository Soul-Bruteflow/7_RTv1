#include "rtv.h"
#include "rtv_defines.h"

t_bool	parse_scene(t_rtv *r)
{
	float n;

	if (!(check_line(r, "lights:")))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
			return (false);
	r->scene->lits_n = (Uint8)n;
	if (!(check_line(r, "materials:")))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->mats_n = (Uint8)n;
	if (!(check_line(r, "objects:")))
		return (false);
	if (!(parse_number(r, &n, S_MIN, S_MAX)))
		return (false);
	r->scene->objs_n = (Uint8)n;
	return (true);
}