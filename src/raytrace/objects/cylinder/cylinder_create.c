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

void	set_cylinder(t_obj3d *obj, t_vec3d new_position, float new_radius, Uint16 new_material)
{
	set_object_position(obj, new_position);
	set_object_material(obj, new_material);
	set_cylinder_radius(obj, new_radius);
}