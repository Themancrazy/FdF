/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:00:26 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 15:01:05 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			draw_line(t_window *mlx)
{
	int				delta[2];
	int				sign[2];
	int				error[2];

	delta[0] = abs(X1 - X0);
	delta[1] = abs(Y1 - Y0);
	sign[0] = X0 < X1 ? 1 : -1;
	sign[1] = Y0 < Y1 ? 1 : -1;
	error[0] = delta[0] - delta[1];
	while (X0 != X1 || Y0 != Y1)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, X0 + CAMERA_X, Y0 + CAMERA_Y, COLOR);
		if ((error[1] = error[0] * 2) > -delta[1])
		{
			error[0] -= delta[1];
			X0 += sign[0];
		}
		if (error[1] < delta[0])
		{
			error[0] += delta[0];
			Y0 += sign[1];
		}
	}
}

static void			handle_x(t_window *mlx, int x, int y)
{
	X0 = x * SCALE;
	X1 = (x + 1) * SCALE;
	Y0 = y * SCALE;
	Y1 = (y) * SCALE;
	Z0 = mlx->c->coord[y][x] * SCALE;
	Z1 = mlx->c->coord[y][x + 1] * SCALE;
	rot_x(mlx);
	rot_y(mlx);
	rot_z(mlx);
	draw_line(mlx);
}

static void			handle_y(t_window *mlx, int x, int y)
{
	X0 = x * SCALE;
	X1 = x * SCALE;
	Y0 = y * SCALE;
	Y1 = (y + 1) * SCALE;
	Z0 = mlx->c->coord[y][x] * SCALE;
	Z1 = mlx->c->coord[y + 1][x] * SCALE;
	rot_x(mlx);
	rot_y(mlx);
	rot_z(mlx);
	draw_line(mlx);
}

void				main_draw(t_window *mlx)
{
	int		x;
	int		y;

	y = 0;
	while (y < (mlx->c->max_y))
	{
		x = 0;
		while (x < (mlx->c->max_x))
		{
			if (x + 1 < (mlx->c->max_x))
				handle_x(mlx, x, y);
			if (y + 1 < (mlx->c->max_y))
				handle_y(mlx, x, y);
			x++;
		}
		y++;
	}
}
