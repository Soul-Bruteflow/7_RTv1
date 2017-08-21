#include "rtv.h"

t_material	*new_material()
{
	t_material *new_material;

	new_material = malloc(sizeof(*(new_material)));
	if (new_material == NULL)
		rtv_error(malloc_error);
	return (new_material);
}

void		set_material(t_material *material, t_rgbap diffuse, float reflect)
{
	material->diffuse.red = diffuse.red;
	material->diffuse.green = diffuse.green;
	material->diffuse.blue = diffuse.blue;
	material->diffuse.alpha = diffuse.alpha;
	material->reflection = reflect;
}