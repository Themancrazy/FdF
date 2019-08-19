/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <anjansse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:01:05 by anjansse          #+#    #+#             */
/*   Updated: 2019/08/18 14:39:16 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*
** Chech for errors in file name and if valid, file, read the file with MMAP and
** returns str containing file.
*/

char		*parse_file(char *file_name, char *map)
{
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strlen(file_name) < 4)
		send_error("Invalid file name");
	while (file_name[i] != '.')
		i++;
	tmp = ft_strsub(file_name, i, 4);
	if (i + 4 <= (int)ft_strlen(file_name) && !ft_strcmp(tmp, ".fdf"))
	{
		free(tmp);
		if (read_file(file_name, &map))
			return (map);
		else
			send_error("File doesn't exist");
	}
	else
		send_error("Invalid file name");
	return (0);
}

int			parse_content(char *map)
{
	while (*map)
	{
		if (!ft_isdigit(*map) && (*map != ' ' && *map != '\n' && *map != '-'))
			return (0);
		map++;
	}
	return (1);
}
