/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:06:13 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/13 11:39:39 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	map(t_list **hold)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	line = NULL;
	get_next_line(&line);
	(*hold)->y_map = ft_atoi(ft_strchr(line, ' '));
	(*hold)->x_map = ft_atoi(ft_strrchr(line, ' '));
	(*hold)->map3D = (char **)malloc(sizeof(char **) * (1 + (*hold)->y_map));
	free(line);
	get_next_line(&line);
	free(line);
	while (i < (*hold)->y_map)
	{
		get_next_line(&line);
		(*hold)->map3D[i] = ft_strsub(line, 4, (*hold)->x_map);
		free(line);
		i++;
	}
	(*hold)->map3D[i] = NULL;
}
