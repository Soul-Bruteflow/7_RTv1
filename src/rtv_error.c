/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:24:32 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:24:54 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <SDL2/SDL.h>
#include "rtv_error.h"

void	print_error_and_exit(const char *error_text, Uint8 sdl)
{
	const char *buf;

	ft_putstr(error_text);
	if (sdl == 1)
	{
		buf = SDL_GetError();
		ft_putstr(buf);
	}
	write(1, "\n", 1);
	SDL_Quit();
	exit(1);
}

void	rtv_init_errors(char **errors)
{
	errors[0] = "Usage: ./RTv1 <scene>";
	errors[1] = "Malloc allocation error.";
	errors[2] = "SDL error: init. ";
	errors[3] = "SDL error: window. ";
	errors[4] = "SDL error: renderer. ";
}

void	rtv_error(t_error error_code, char **errors)
{
	print_error_and_exit(errors[error_code], 0);
}
