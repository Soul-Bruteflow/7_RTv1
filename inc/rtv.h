#ifndef _RTV1_H
#define _RTV1_H

# include <SDL2/SDL.h>
# include "rtv_error.h"
# include "objects.h"

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
	t_obj3d			**objects;
	t_material		**materials;
	t_light			**lights;
	t_ray			ray;
	Uint8 			objects_n;
	Uint8 			materials_n;
	Uint8 			lights_n;
}					t_scene;

/*
** Support struct for calculation
*/
typedef	struct 		s_calc
{
	t_rgbap			color;
	t_rgba			pixel_color;
	int				level;
	float			coef;
	int				cur_obj;
	t_vec3d			intersect_normal;
	t_vec3d			new_start;
	t_material		cur_mat;
	int				material_n;
	float			reflect;
	t_vec3d			tmp;
}					t_calc;

/*
** Main struct.
** av - ./RTv1 arguments
*/
typedef struct		s_rtv
{
	char 			**av;
	t_sdl			*sdl;
	t_win			*win;
	t_scene			*scene;
	t_calc			*calc;
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
void				rtv_loop(t_rtv *rtv);
void				rtv_quit(t_rtv *rtv);


/*
** Raycast
*/
void				raytrace(t_rtv *rtv);
t_bool				normal_of_intersect(t_vec3d *normal, t_vec3d *new_start, t_obj3d **objects, int cur_obj);
t_bool				object_intersect(t_obj3d **objects, t_ray *r, int *cur_obj, t_vec3d *new_start);
void				calculate_light(t_rtv *rtv);
void				calculate_reflection(t_rtv *rtv);

/*
** Scene
*/
t_scene *new_scene(Uint8 nbr_of_objs, Uint8 nbr_of_mats, Uint8 nbr_of_lights);
void create_sceen_one(t_scene *scene);
t_scene *create_scene(int sceen_number);
t_obj3d *new_object(t_obj_type object_type);

/*
** Keyboard
*/
void				keyboard_core(t_rtv *rtv);

/*
** Window
*/
void	create_window(t_rtv *rtv, Uint16 wdth, Uint16 hght, const char *title);
void	clear_window(t_rtv *rtv);
void	render_present(t_rtv *rtv);
void	ft_draw_pixel(Uint16 x, Uint16 y, t_rgba *color, Uint8 *draw_buffer);

/*
** Math
*/
t_bool	equal_abs(float a, float b, float epsilon);

#endif
