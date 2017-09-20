#include "objects.h"
#include "rtv.h"

t_cone *new_cone()
{
	t_cone *cone;

	cone = malloc(sizeof(*(cone)));
	if (cone == NULL)
		rtv_error(malloc_error);
	return (cone);
}

void	set_cone_tip(t_obj3d *obj, t_vec3d new_tip)
{

}

void	set_cone_axis(t_obj3d *obj, t_vec3d new_axis)
{

}

void	set_cone_angle(t_obj3d *obj, float new_angle)
{

}

void	set_cone(t_obj3d *obj, t_vec3d *data, float angle, Uint16 new_material)
{
	set_object_position(obj, data[0]);
	set_object_material(obj, new_material);
	set_cone_angle(obj, angle);
	set_cone_tip(obj, data[1]);
	set_cone_axis(obj, data[2]);
}