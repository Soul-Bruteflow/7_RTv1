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
** SPHERE primitive definition
*/
typedef struct	s_shpere
{
	t_vec3d		pos;
	float		radius;
	int			material;
}				t_sphere;

/*
** Plane primitive definition
*/
typedef struct	s_plane
{
//	t_vec3d		n;
//	float		d;
	t_vec3d		rot;
	t_vec3d		pos;
	int			material;
}				t_plane;

/*
** Object
*/
typedef struct	s_obj3d
{
	t_sphere   	*sphere;
	t_plane		*plane;
	t_bool		hit;
	t_bool		(*intersect)(t_ray *, void *);
}				t_obj3d;

/*
** Sphere intersection
*/
t_bool			intersect_sphere(t_ray *r, t_sphere *s, float *t);

t_bool intersect_plane_line(t_ray *r, t_plane *p, float *t);
t_bool intersect_plane_ray(t_ray *r, t_plane *p);

t_sphere		*new_sphere();
void			set_sphere_radius(t_sphere *sphere, float new_radius);
void			set_sphere_position(t_sphere *sphere, t_vec3d new_position);
void			set_sphere(t_sphere *sphere, t_vec3d new_position, float new_radius, int material);


t_plane *new_plane();
t_bool intersect_plane(t_ray *r, t_plane *p);

#endif
