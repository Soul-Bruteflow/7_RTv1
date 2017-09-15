#ifndef _VECTORS_H
#define _VECTORS_H

/*
** 3d Vector definition
*/
typedef struct	s_vec3d
{
	float		x;
	float		y;
	float		z;
}				t_vec3d;

/*
** 2d Vector definition
*/
typedef struct	s_vec2d
{
	float		u;
	float		v;
}				t_vec2d;

/*
** ADD two vectors and return the resulting vector
*/
t_vec3d	vec3d_add(t_vec3d *v1, t_vec3d *v2);
/*
** ADD three vectors and return the resulting vector
*/
t_vec3d ft_vec3d_add3(t_vec3d a, t_vec3d b, t_vec3d c);
/*
** SUBTRACT two vectors and return the resulting vector
*/
t_vec3d vec3d_sub(t_vec3d *v1, t_vec3d *v2);
/*
** MULTIPLY two vectors and return the resulting scalar (DOT PRODUCT)
*/
float	vec3d_dot(t_vec3d *v1, t_vec3d *v2);
/*
** Calculate Vector x Scalar
*/
t_vec3d vec3d_scale(float c, t_vec3d *v);
/*
** Calculate Vector CROSS PRODUCT
*/
t_vec3d vec3d_cross(t_vec3d *v1, t_vec3d *v2);
/*
** Calculate vector length(magnitude).
*/
float	ft_vec3d_magnitude(t_vec3d v);
/*
** Calculate vector normal.
*/
t_vec3d	ft_vec3d_norm(t_vec3d v);
/*
** Scale vector by a factor s
*/
t_vec3d	ft_vec3d_scale(t_vec3d v, float s);

t_vec3d	ft_vec3d_devide(t_vec3d v, float s);

// Length, or magnitude, measured by [Euclidean norm](https://en.wikipedia.org/wiki/Euclidean_vector#Length)
float	ft_vec3d_len(t_vec3d v);

// Turn any vector into a vector that has a magnitude of 1.
t_vec3d	ft_vec3d_unit(t_vec3d v);

#endif
