/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 14:50:41 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 14:59:29 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../Minilibx/minilibx_macos/mlx.h"
# include "../libft/includes/libft.h"
# include <math.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define PLUS 24
# define MINUS 27
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123

# define COLOR 0xE53812
# define SCALE_SIZE 10
# define MAX_WIDTH 1500
# define MAX_HEIGHT 1000
# define CAMERA_X mlx->c->camera[0]
# define CAMERA_Y mlx->c->camera[1]
# define X0 mlx->c->vec.x0
# define X1 mlx->c->vec.x1
# define Y0 mlx->c->vec.y0
# define Y1 mlx->c->vec.y1
# define Z0 mlx->c->vec.z0
# define Z1 mlx->c->vec.z1
# define ALPHA mlx->c->rot.alpha
# define BETA mlx->c->rot.beta
# define GAMMA mlx->c->rot.gamma
# define SCALE mlx->scale
# define SCALE_M mlx->scale_modifier
# define CMD 11

typedef struct		s_vector3d {
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				z0;
	int				z1;
}					t_vector3d;

typedef struct		s_rot {
	double			alpha;
	double			beta;
	double			gamma;
}					t_rot;

typedef struct		s_coord {
	int				**coord;
	int				camera[2];
	int				max_x;
	int				max_y;
	t_vector3d		vec;
	t_rot			rot;
}					t_coord;

typedef struct		s_window {
	void			*win;
	void			*ptr;
	int				scale;
	int				scale_modifier;
	t_coord			*c;
	unsigned int	color;
	unsigned char	should_draw;
}					t_window;

typedef void		(t_key_disp)(struct s_window*, int);

typedef struct		s_dis {
	int				key;
	t_key_disp		*function;
}					t_dis;

/*
** dispatch key functions
*/

void				quit_program(t_window *mlx, int key);
void				rotate(t_window *mlx, int key);
void				zoom(t_window *mlx, int key);
void				handle_camera(t_window *mlx, int key);

/*
** Error handling function
*/

void				send_error(char *error);

/*
** File parsing function
*/

char				*parse_file(char *file_name, char *map);
int					parse_content(char *map);

/*
** Free functions
*/

void				ft_free_db_tab(char **av);
void				ft_free_db_tab_int(int **av);

/*
** Output fdf functions.
*/

void				init_window(t_window *window, t_coord *c);
int					draw_fdf(t_window *mlx);
void				main_draw(t_window *mlx);

/*
** Additional useful functions.
*/

int					get_size(char **array);
int					get_size_y(int **array);
int					get_size_z(int **array, int y, int x);
void				get_xyz(t_coord *c);

void				rot_x(t_window *mlx);
void				rot_y(t_window *mlx);
void				rot_z(t_window *mlx);
void				rotation(t_window *mlx, int *x, int *y, int *z);

#endif
