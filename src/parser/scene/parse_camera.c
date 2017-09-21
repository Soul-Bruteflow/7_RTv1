#include "rtv.h"
#include "rtv_defines.h"

t_bool	parse_camera(t_rtv *r)
{
	float n;

	if (!(check_line(r, "camera position:")))
		return (false);
	if (!(parse_vector(r, &r->scene->cam.o, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "camera direction:")))
		return (false);
	if (!(parse_vector(r, &r->scene->cam.d, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "fov:")))
		return (false);
	if (!(parse_number(r, &n, F_MIN, F_MAX)))
		return (false);
	r->scene->cam.fov = n;
	return (true);
}