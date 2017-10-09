/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:46:29 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "rtv_defines.h"

void	init_camera(t_rtv *r)
{
	float	fov_radians;
	float	height_width_ratio;
	float	camerawidth;
	float	cameraheight;
	t_cam	*tm_cam;

	tm_cam = &r->scene->cam;
	tm_cam->up.x = 0;
	tm_cam->up.y = 1;
	tm_cam->up.z = 0;
	tm_cam->eye = vec3_norm(vec3_sub(&tm_cam->d, &tm_cam->o));
	tm_cam->vp_right = vec3_norm(vec3_cross(&tm_cam->eye, &tm_cam->up));
	tm_cam->vp_up = vec3_norm(vec3_cross(&tm_cam->vp_right, &tm_cam->eye));
	fov_radians = PI * (tm_cam->fov / 2) / 180;
	height_width_ratio = FHEIGHT / FWIDTH;
	tm_cam->half_width = tanf(fov_radians);
	tm_cam->half_height = height_width_ratio * tm_cam->half_width;
	camerawidth = tm_cam->half_width * 2;
	cameraheight = tm_cam->half_height * 2;
	tm_cam->pixel_width = camerawidth / (FWIDTH - 1);
	tm_cam->pixel_height = cameraheight / (FHEIGHT - 1);
	r->scene->ray.start = tm_cam->o;
}
