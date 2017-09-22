#include "rtv.h"
#include "rtv_defines.h"

void init_camera(t_rtv *r)
{
	float fovRadians;
	float heightWidthRatio;
	float camerawidth;
	float cameraheight;
	t_cam *tm_cam;

	tm_cam = &r->scene->cam;
	tm_cam->up.x = 0;
	tm_cam->up.y = 1;
	tm_cam->up.z = 0;
	tm_cam->eye = vec3_norm(vec3_sub(&tm_cam->d, &tm_cam->o));
	tm_cam->vpRight = vec3_norm(vec3_cross(&tm_cam->eye, &tm_cam->up));
	tm_cam->vpUp = vec3_norm(vec3_cross(&tm_cam->vpRight, &tm_cam->eye));
	fovRadians = PI * (tm_cam->fov / 2) / 180;
	heightWidthRatio = FHEIGHT / FWIDTH;
	tm_cam->halfWidth = tanf(fovRadians);
	tm_cam->halfHeight = heightWidthRatio * tm_cam->halfWidth;
	camerawidth = tm_cam->halfWidth * 2;
	cameraheight = tm_cam->halfHeight * 2;
	tm_cam->pixelWidth = camerawidth / (FWIDTH - 1);
	tm_cam->pixelHeight = cameraheight / (FHEIGHT - 1);
	r->scene->ray.start = tm_cam->o;
}