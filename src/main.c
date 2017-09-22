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

#include "rtv.h"

int		main(int ac, char **av)
{
	t_rtv	*rtv;

	if (ac == 2)
	{
		rtv = rtv_init(av);
		if (!(parser_core(rtv)))
			rtv_error(parse_error);
		init_camera(rtv);
		create_window(rtv, 800, 600, "RTv1, 800x600\0");
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
		rtv_loop(rtv);
	}
	else
		rtv_error(usage_error);
}

