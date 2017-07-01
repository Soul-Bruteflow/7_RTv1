/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:13:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:14:44 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv_error.h>
#include "rtv1.h"

int		main(int ac, char **av)
{
	t_rtv	*rtv;
	char	*errors[number_of_errors];

	rtv_init_errors(errors);
	if (ac == 2)
	{
		rtv = rtv_init(errors, av);

		rtv->errors = errors;

		rtv_error(sdl_init_error, rtv->errors);

//		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
//		wolf->av = av;
//		map_parser(wolf);
//		wolf->pitch = 800 *4;
//		wolf->offset = 0;
//		game_loop(wolf);
//		quit(wolf);
	}
	else
		rtv_error(usage_error, errors);
}

