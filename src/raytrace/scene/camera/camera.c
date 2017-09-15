//#include "rtv.h"
//
//t_cam *create_perspective_cam(t_vec3d origin, t_vec3d target, t_vec3d upguide, float fov_asp[])
//{
//	t_cam *new_cam;
//	t_vec3d tmp1;
//	t_vec3d tmp2;
//
////	new_cam = malloc(sizeof(*(new_cam)));
////	if (new_cam == NULL)
////		rtv_error(malloc_error);
//
//	new_cam->origin = origin;
//	tmp1 = vec3d_sub(&target, &origin);
//	tmp2 = vec3d_cross(&new_cam->forward, &upguide);
//	new_cam->forward = ft_vec3d_norm(tmp1);
//	new_cam->right = ft_vec3d_norm(tmp2);
//	new_cam->up = vec3d_cross(&new_cam->right, &new_cam->forward);
//	new_cam->h = tanf(fov_asp[0]);
//	new_cam->w = new_cam->h * fov_asp[1];
//	return (new_cam);
//}
//
//void make_ray(t_cam *cam, t_vec2d point, t_ray *r)
//{
//	t_vec3d tmp1 = vec3d_scale((point.u * cam->w), &cam->right);
//	t_vec3d tmp2 = vec3d_scale((point.v * cam->h), &cam->up);
//	t_vec3d tmp3 = vec3d_add(&cam->forward, &tmp1);
//	t_vec3d dir = vec3d_add(&tmp3, &tmp2);
//	r->start = cam->origin;
//	r->dir = ft_vec3d_norm(dir);
//}