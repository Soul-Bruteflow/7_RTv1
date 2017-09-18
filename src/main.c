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

#include "rtv_includes.h"
//
int		main(int ac, char **av)
{
	t_rtv	*rtv;

	if (ac == 2)
	{
		rtv = rtv_init(av);

		parser_read_one(rtv);

		create_window(rtv, 800, 600, "RTv1, 800x600\0");
		rtv->scene = create_scene(1);

		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
		rtv_loop(rtv);

//error test
//		rtv_error(sdl_window_error, rtv->utl->errors);

//		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
//		wolf->av = av;
//		map_parser(wolf);
//		wolf->pitch = 800 *4;
//		wolf->offset = 0;
//		game_loop(wolf);
//		quit(wolf);
	}
	else
		rtv_error(usage_error);
}
//int main(int ac, char **av)
//{
//	t_rtv	*rtv;
//
//	rtv = rtv_init(av);
//	create_window(rtv, 800, 600, "RTv1, 800x600\0");
//
//	rtv->scene = create_scene(1);
//
//	clear_window(rtv);
//
//	raytrace(rtv);
//
//	render_present(rtv);
//	rtv_loop(rtv);
//	return (0);
//}

