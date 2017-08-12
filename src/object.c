#include "rtv1.h"

void	set_object_position(t_obj3d *obj, t_vec3d new_position)
{
	obj->pos.x = new_position.x;
	obj->pos.y = new_position.y;
	obj->pos.z = new_position.z;
}

void	set_object_material(t_obj3d *obj, Uint16 new_material)
{
	obj->material = new_material;
}