#include "rtv.h"
# include "get_next_line.h"

/*
** fdf_close_file
** Closes the file, and checks for the errors.
*/

void	close_file(t_rtv *r)
{
	if ((close(r->pars->fd)) < 0)
		rtv_error(file_close_error);
}

/*
** fdf_close_line
** Closes the file on the line error, and checks for the errors.
*/

void	close_line(t_rtv *r)
{
	if (w->tmp != w->map_x)
	{
		close_file(w);
		rtv_error(line_error);
	}
}

/*
** fdf_open_file
** Opens the file, and checks for the errors.
*/

void	open_file(t_rtv *r)
{
	w->fd = open(w->av[1], O_RDONLY);
	if (w->fd < 0)
		rtv_error(file_open_error);
}

/*
** fdf_gnl_error
** Checks for the GNL errors.
*/

void	gnl_error(t_rtv *r, int i)
{
	if (i < 0)
	{
		close_file(w);
		rtv_error(gnl_error_c);
	}
}