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
** ADD two vectors and return the resulting vector
*/
t_vec3d vec3d_add(t_vec3d *v1, t_vec3d *v2);
/*
** SUBTRACT two vectors and return the resulting vector
*/
t_vec3d vec3d_sub(t_vec3d *v1, t_vec3d *v2);
/*
** MULTIPLY two vectors and return the resulting scalar (DOT PRODUCT)
*/
float vec3d_dot(t_vec3d *v1, t_vec3d *v2);
/*
** Calculate Vector x Scalar
*/
t_vec3d vec3d_scale(float c, t_vec3d *v);
/*
** Calculate Vector CROSS PRODUCT
*/
t_vec3d vec3d_cross(t_vec3d *v1, t_vec3d *v2);

#endif
