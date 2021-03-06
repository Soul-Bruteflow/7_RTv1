/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 11:39:16 by mvlad             #+#    #+#             */
/*   Updated: 2017/10/09 15:16:49 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv.h"
#include "rtv_defines.h"

void	alloc_new_sphere(t_rtv *r, int i)
{
	r->scene->objects[i] = new_object(sphere);
	r->scene->objects[i]->type = new_sphere();
	r->scene->objects[i]->intersect = intersect_sphere_ray;
}

t_bool	parse_sphere(t_rtv *r, int i)
{
	t_vec3d		position;
	float		radius;
	Uint16		material;

	free(r->pars->line);
	alloc_new_sphere(r, i);
	if (!(check_line(r, "position:")))
		return (false);
	if (!(parse_vector(r, &position, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "radius:")))
		return (false);
	if (!(parse_number(r, &radius, V_MIN, V_MAX)))
		return (false);
	if (!(check_line(r, "material:")))
		return (false);
	if (!(valid_material(r, &material, M_MIN, M_MAX)))
		return (false);
	set_sphere(r->scene->objects[i], position, radius, material);
	return (true);
}
