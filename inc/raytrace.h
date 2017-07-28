#ifndef _RAYTRACE_H
#define _RAYTRACE_H

# include "vectors.h"
# include <SDL2/SDL.h>

/*
** RGBA color 0-255 definition
*/
typedef struct	s_rgba
{
	Uint8		red;
	Uint8		green;
	Uint8		blue;
	Uint8		alpha;
}				t_rgba;

/*
** RGBA color 0%-100%/0-1.0 definition
*/
typedef struct	s_rgbap
{
	float		red;
	float		green;
	float		blue;
	float		alpha;
}				t_rgbap;

/*
** Ray definition
*/
typedef struct	s_ray
{
	t_vec3d		start;
	t_vec3d		dir;
}				t_ray;

/*
** Material definition
*/
typedef struct	s_material
{
	t_rgbap		diffuse;
	float		reflection;
}				t_material;

/*
** Light source definition
*/
typedef struct	s_light
{
	t_vec3d		pos;
	t_rgbap		intensity;
}				t_light;

/*
** Common
*/
t_rgbap			ft_set_color(float r, float g, float b, float a);
t_vec3d			ft_set_vector(float x, float y, float z);

/*
** Material
*/
t_material 		*new_material();
void			set_material(t_material *material, t_rgbap diffuse, float r);
/*
** Light
*/
t_light 		*new_light();
void			set_light(t_light *light, t_vec3d pos, t_rgbap intensity);
#endif
