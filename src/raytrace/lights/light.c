#include "rtv.h"
#include "raytrace.h"

t_light	*new_light()
{
	t_light *new_light;

	new_light = malloc(sizeof(*(new_light)));
	if (new_light == NULL)
		rtv_error(malloc_error);
	return (new_light);
}

void	set_light(t_light *light, t_vec3d pos, t_rgbap intensity)
{
	light->pos.x = pos.x;
	light->pos.y = pos.y;
	light->pos.z = pos.z;
	light->intensity.red = intensity.red;
	light->intensity.green = intensity.green;
	light->intensity.blue = intensity.blue;
	light->intensity.alpha = intensity.alpha;
}