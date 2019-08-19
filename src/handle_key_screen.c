/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:01:12 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 15:15:12 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_dis				g_dis_table[CMD] = {
	{ESC, &quit_program},
	{PLUS, &zoom},
	{MINUS, &zoom},
	{ARROW_UP, &rotate},
	{ARROW_DOWN, &rotate},
	{ARROW_RIGHT, &rotate},
	{ARROW_LEFT, &rotate},
	{W, &handle_camera},
	{A, &handle_camera},
	{S, &handle_camera},
	{D, &handle_camera},
};

static void				dispatcher(int key, t_window *mlx)
{
	int		i;

	i = -1;
	while (++i < CMD)
	{
		if (key == g_dis_table[i].key)
		{
			g_dis_table[i].function(mlx, key);
			return ;
		}
	}
}

int						handle_key(int key, void *param)
{
	t_window *window;

	window = param;
	dispatcher(key, window);
	window->should_draw = 1;
	return (0);
}

/*
** Draw main graph.
*/

int						draw_fdf(t_window *mlx)
{
	if (mlx->should_draw)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		SCALE = SCALE_SIZE - SCALE_M;
		main_draw(mlx);
		mlx->should_draw = 0;
	}
	return (0);
}

/*
** Initialise a MiniLibx window and run fdf.
*/

void					init_window(t_window *mlx, t_coord *c)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, MAX_WIDTH, MAX_HEIGHT, "FDF");
	mlx->should_draw = 1;
	SCALE_M = 0;
	mlx->c = c;
	CAMERA_X = MAX_WIDTH / 2;
	CAMERA_Y = MAX_HEIGHT / 5;
	ALPHA = 0.3;
	BETA = 0.4;
	GAMMA = 0;
	mlx_hook(mlx->win, 2, 0, handle_key, mlx);
	mlx_loop_hook(mlx->ptr, draw_fdf, mlx);
	mlx_loop(mlx->ptr);
}
