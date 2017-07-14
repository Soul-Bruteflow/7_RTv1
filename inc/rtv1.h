#ifndef _RTV1_H
#define _RTV1_H

# include <SDL2/SDL.h>
# include "rtv1_error.h"

/*
** RGBA
*/
typedef struct		s_rgba
{
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8			a;
}					t_rgba;

/*
** Basic SDL2 variables
** key_state - current key code
*/
typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	const Uint8		*key_state;
}					t_sdl;

/*
** Window draw
** screen - texture on which drawing is happening
** draw_buf - content of draw buffer is updated on to the texture
** each redraw call.
** pitch - the length of a row of pixels in bytes
** offset - draw location in draw buffer
*/
typedef struct		s_win
{
	SDL_Texture		*screen;
	Uint8			*draw_buf;
	int 			pitch;
	size_t			offset;
	Uint16			width;
	Uint16			height;
	char 			*title;
}					t_win;

/*
** Scene
*/
typedef struct		s_scene
{
	t_obj3d			*obj;
	t_sphere   		*spheres;
	t_ray			*ray;
}					t_scene;

/*
** Main struct.
** av - ./RTv1 arguments
*/
typedef struct		s_rtv
{
	char 			**av;
	t_sdl			*sdl;
	t_win			*win;
	t_utl			*utl;
	t_scene			*scene;
}					t_rtv;

/*
** Errors
*/
void				rtv_error(t_error error_code);
void				print_error_and_exit(const char *error_text, Uint8 sdl);

/*
** RTv1
*/
void	ft_noise(t_rtv *rtv);

t_rtv				*rtv_init(char **av);
void				screen_create(t_rtv *rtv, Uint16 wdth, Uint16 hght, const char *title);
void				rtv_loop(t_rtv *rtv);

/*
** Keyboard
*/
void				keyboard_core(t_rtv *rtv);

/*
** Screen
*/
void	rtv_quit(t_rtv *rtv);
void	screen_clear(t_rtv *rtv);
void	screen_update(t_rtv *rtv);

#endif
