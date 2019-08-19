/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:01:21 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 15:16:14 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rot_x(t_window *mlx)
{
	int x;
	int y;
	int z;

	x = X0;
	y = Y0;
	z = Z0;
	Y0 = ((y * cos(ALPHA)) + (z * sin(ALPHA)));
	Z0 = (((-1 * (y * sin(ALPHA))) + (z * cos(ALPHA))));
	x = X1;
	y = Y1;
	z = Z1;
	Y1 = ((y * cos(ALPHA)) + (z * sin(ALPHA)));
	Z1 = (((-1 * (y * sin(ALPHA))) + (z * cos(ALPHA))));
}

void	rot_y(t_window *mlx)
{
	int x;
	int y;
	int z;

	x = X0;
	y = Y0;
	z = Z0;
	X0 = ((x * cos(BETA)) + (z * sin(BETA)));
	Z0 = (((-1 * (x * sin(BETA))) + (z * cos(BETA))));
	x = X1;
	y = Y1;
	z = Z1;
	X1 = ((x * cos(BETA) + (z * sin(BETA))));
	Z1 = ((-1 * (x * sin(BETA))) + (z * cos(BETA)));
}

void	rot_z(t_window *mlx)
{
	int x;
	int y;
	int z;

	x = X0;
	y = Y0;
	z = Z0;
	X0 = ((x * cos(GAMMA)) - (y * sin(GAMMA)));
	Y0 = ((x * sin(GAMMA)) + (y * cos(GAMMA)));
	x = X1;
	y = Y1;
	z = Z1;
	X1 = ((x * cos(GAMMA)) - (y * sin(GAMMA)));
	Y1 = ((x * sin(GAMMA)) + (y * cos(GAMMA)));
}
