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

//void	set_cone_radius(t_obj3d *obj, float new_radius)
//{
//	t_cone *tmp_cone;
//
//	tmp_cone = obj->type;
//	tmp_cone->params[0] = new_radius;
//}

//void	set_cone_height(t_obj3d *obj, float new_height)
//{
//	t_cone *tmp_cone;
//
//	tmp_cone = obj->type;
//	tmp_cone->params[1] = new_height;
//}

void	set_cone(t_obj3d *obj, t_vec3d new_position, float params[], Uint16 new_material)
{
	set_object_position(obj, new_position);
	set_object_material(obj, new_material);
//	set_cone_radius(obj, params[0]);
//	set_cone_height(obj, params[1]);
}