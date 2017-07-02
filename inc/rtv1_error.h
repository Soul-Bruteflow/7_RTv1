#ifndef _RTV1_ERROR_H
#define _RTV1_ERROR_H

typedef enum		e_error
{
	usage_error,
	malloc_error,
	sdl_init_error,
	sdl_window_error,
	sdl_renderer_error,
	number_of_errors
}					t_error;

#endif
