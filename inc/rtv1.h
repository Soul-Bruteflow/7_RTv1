#ifndef _RTV1_H
#define _RTV1_H

#include "rtv1_error.h"
#include "rtv1_support.h"
#include "rtv1_defines.h"
#include "rtv1_constants.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_mixer/SDL_mixer.h>

/*
** Boolean replacement
*/
typedef enum		e_bool
{
	false, true
}					t_bool;
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
** Utility.
** errors - error messages.
** av - ./RTv1 arguments
*/
typedef struct		s_utl
{
	char			**errors;
	char 			**av;
}					t_utl;

typedef struct		s_rtv
{
	struct s_sdl	*sdl;
	struct s_win	*win;
	struct s_utl	*utl;
}					t_rtv;

/*
** Errors
*/
void				rtv_init_errors(char **errors);
void				rtv_error(t_error error_code, char **errors);
void				print_error_and_exit(const char *error_text, Uint8 sdl);

/*
** RTv1
*/
void	ft_noise(t_rtv *rtv);

t_rtv				*rtv_init(char **errors, char **av);
void				screen_create(t_rtv *rtv, Uint16 wdth, Uint16 hght, const char *title);

#endif
