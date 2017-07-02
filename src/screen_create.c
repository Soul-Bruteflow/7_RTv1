#include "rtv1.h"

void	create_buffer(Uint8 **draw_buffer, Uint16 width, Uint16 height, t_rtv *rtv)
{
	if (*draw_buffer == NULL)
	{
		*draw_buffer = (Uint8*)malloc(sizeof(Uint8) * width * height * 4);
		if (*draw_buffer == NULL)
			rtv_error(malloc_error, rtv->utl->errors);
	}
}

void	screen_size(t_rtv *rtv, Uint16 width, Uint16 height)
{
	rtv->win->width = width;
	rtv->win->height = height;
	create_buffer(&rtv->win->draw_buf, width, height, rtv);
}

void	screen_create(t_rtv *rtv, Uint16 wdth, Uint16 hght, const char *title)
{
	screen_size(rtv, wdth, hght);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		rtv_error(sdl_init_error, rtv->utl->errors);
	rtv->sdl->window = SDL_CreateWindow(title,
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			rtv->win->width, rtv->win->height, SDL_WINDOW_OPENGL);
	if (rtv->sdl->window == NULL)
		rtv_error(sdl_window_error, rtv->utl->errors);
	rtv->sdl->renderer = SDL_CreateRenderer(rtv->sdl->window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (rtv->sdl->renderer == NULL)
		rtv_error(sdl_renderer_error, rtv->utl->errors);
	rtv->win->screen = SDL_CreateTexture(rtv->sdl->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
			rtv->win->width, rtv->win->height);
}