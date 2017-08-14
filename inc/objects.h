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
	float		radius;
}				t_sphere;

/*
** Plane primitive definition
*/
typedef struct	s_plane
{
//	t_vec3d		n;
//	float		d;
	t_vec3d		rot;
}				t_plane;

/*
** Object
*/
typedef struct	s_obj3d
{
	void		*type;
	t_obj_type	obj_type;
	t_bool		hit;
	t_vec3d		pos;
	Uint16		material;
	t_bool		(*intersect)(t_ray *, struct s_obj3d *, float *);
}				t_obj3d;

/*
** General
*/
void	set_object_position(t_obj3d *obj, t_vec3d new_position);
void	set_object_material(t_obj3d *obj, Uint16 new_material);

/*
** Sphere intersection
*/
t_bool intersectRaySphere(t_ray *r, t_obj3d *object, float *t);

//t_bool			intersect_sphere(t_ray *r, t_sphere *s, float *t);

t_bool intersect_sphere(t_ray *r, t_sphere *s);

t_bool intersect_plane_line(t_ray *r, t_plane *p, float *t);
t_bool intersect_plane_ray(t_ray *r, t_plane *p);

t_sphere		*new_sphere();
void			set_sphere(t_obj3d *obj, t_vec3d new_position, float new_radius, Uint16 new_material);
void			set_sphere_radius(t_obj3d *obj, float new_radius);


t_plane *new_plane();
t_bool intersect_plane(t_ray *r, t_plane *p);

#endif
