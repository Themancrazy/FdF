/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:00:49 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 15:07:06 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void				send_error(char *error)
{
	ft_putstr(RED BOLD"Error: \"");
	ft_putstr(error);
	ft_putstr("\"\n"RESET);
	exit(0);
}

static void			parse_x(t_coord *c, int i, char **split2)
{
	int			j;

	j = 0;
	while (split2[j])
	{
		c->coord[i][j] = ft_atoi(split2[j]);
		j++;
	}
	if (i > 0 && j != c->max_x)
		send_error("Error in number of elements in a line.");
	c->max_x = j;
}

/* 
** Get x y and z from map and store it in struct t_coord[y][x] = z.
*/

static void			store_xy(char *map, t_coord *c)
{
	int			i;
	char		**split1;
	char		**split2;

	i = 0;
	split1 = ft_strsplit(map, '\n');
	c->coord = (int **)malloc(sizeof(int *) * get_size(split1) + 1);
	while (split1[i])
	{
		split2 = ft_strsplit(split1[i], ' ');
		c->coord[i] = malloc(sizeof(int) * get_size(split2) + 1);
		parse_x(c, i, split2);
		ft_free_db_tab(split2);
		i++;
	}
	c->max_y = i;
	ft_free_db_tab(split1);
}

/* 
** Function that stores, save and free all cordoonates.
** It also launches the main function for fdf.
*/

void				fdf(char *file_name)
{
	char        *map;   
	t_window    window;
	t_coord     *coord;
	
	coord = malloc(sizeof(t_coord));
	map = NULL;
	map = parse_file(file_name, map);
	if (!parse_content(map))
		send_error("Content of file is wrong");
	store_xy(map, coord);
	init_window(&window, coord);
	ft_free_db_tab_int(coord->coord);
	free(coord);
}

/* 
** Main function.
*/

int					main(int ac, char **av)
{
	if (ac == 2)
	{
		fdf(av[1]);
		system("leaks fdf");
		return (0);
	}
	send_error("usage: ./fdf <map>");
	return (0);
}
