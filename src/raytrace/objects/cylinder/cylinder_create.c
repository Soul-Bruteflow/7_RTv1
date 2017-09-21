#include "objects.h"
#include "rtv.h"

t_cylinder *new_cylinder()
{
	t_cylinder *cylinder;

	cylinder = malloc(sizeof(*(cylinder)));
	if (cylinder == NULL)
		rtv_error(malloc_error);
	return (cylinder);
}

void	set_cylinder_radius(t_obj3d *obj, float new_radius)
{
	t_cylinder *tmp_cylinder;

	tmp_cylinder = obj->type;
	tmp_cylinder->radius = new_radius;
}

void	set_cylinder(t_obj3d *o, t_vec3d new_pos, float new_rad, Uint16 new_mat)
{
	set_object_position(o, new_pos);
	set_object_material(o, new_mat);
	set_cylinder_radius(o, new_rad);
}