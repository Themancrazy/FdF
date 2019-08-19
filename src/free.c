/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:00:58 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 15:09:55 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Free double char array.
*/

void		ft_free_db_tab(char **av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] != NULL)
		ft_strdel(&av[i++]);
	free(av);
	av = NULL;
}

/*
** Free double int array.
*/

void		ft_free_db_tab_int(int **av)
{
	int i;

	i = 0;
	while (av[i] && av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
