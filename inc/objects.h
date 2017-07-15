#ifndef _OBJECTS_H
#define _OBJECTS_H

//# include "includes.h"
# include "vectors.h"
# include "raytrace.h"
# include "bool.h"

typedef enum	e_obj_type
{
	sphere,
	plane,
	cylinder,
	cone
}				t_obj_type;

/*
** Math SPHERE primitive definition
*/
typedef struct	s_shpere
{
	t_vec3d		pos;
	float		radius;
	int			material;
}				t_sphere;

/*
** Object
*/
typedef struct	s_obj3d
{
	t_sphere   	*sphere;
	t_bool		hit;
	t_bool		(*intersect)(t_ray *, void *);
}				t_obj3d;

/* Sphere intersection */
t_bool			intersect_sphere(t_ray *r, t_sphere *s);
t_sphere		*new_sphere();
void			set_sphere_radius(t_sphere *sphere, float new_radius);
void			set_sphere_position(t_sphere *sphere, t_vec3d new_position);

#endif
