#ifndef _OBJECTS_H
#define _OBJECTS_H

//# include "includes.h"
# include "vectors.h"
# include "raytrace.h"

/*
** Object
*/
typedef struct	s_obj3d
{
	void		*data;
	t_bool		(*intersect)(t_ray *, void *);
}				t_obj3d;

/*
** Math SPHERE primitive definition
*/
typedef struct	s_shpere
{
	t_vec3d		pos;
	float		radius;
	int			material;
}				t_sphere;

/* Sphere intersection */
t_bool intersect_sphere(t_ray *r, t_sphere *s);

#endif
