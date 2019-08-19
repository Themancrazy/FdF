/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:00:38 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 15:02:02 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Additional function to help get the size of a double array of char.
*/

int				get_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/*
** Function used to exit properly FDF.
*/

void			quit_program(t_window *mlx, int key)
{
	(void)key;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(EXIT_SUCCESS);
}

void			zoom(t_window *mlx, int key)
{
	if (key == PLUS)
		SCALE_M--;
	else if (key == MINUS)
		SCALE_M = (SCALE_M == SCALE_SIZE - 1) ? SCALE_SIZE - 1 : SCALE_M + 1;
}

void			rotate(t_window *mlx, int key)
{
	if (key == ARROW_RIGHT)
		BETA += 0.1;
	else if (key == ARROW_LEFT)
		BETA -= 0.1;
	else if (key == ARROW_DOWN)
		ALPHA += 0.1;
	else if (key == ARROW_UP)
		ALPHA -= 0.1;
}

void			handle_camera(t_window *mlx, int key)
{
	if (key == W)
		CAMERA_Y -= 10;
	else if (key == S)
		CAMERA_Y += 10;
	else if (key == A)
		CAMERA_X -= 10;
	else if (key == D)
		CAMERA_X += 10;
}
