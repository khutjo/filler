/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:06:13 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/29 17:41:11 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	my(game **hold)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while ((*hold)->map3D[i] && ((*hold)->o_my == -1 || (*hold)->c_my == -1))
	{
		j = -1;
		while ((*hold)->map3D[i][++j])
		{
			if ((*hold)->c_my == -1 && (*hold)->map3D[i][j] == (*hold)->c)
			{
				(*hold)->c_my = i;
				(*hold)->c_ym = j;
			}
			if ((*hold)->o_my == -1 && (*hold)->map3D[i][j] == (*hold)->o)
				(*hold)->o_my = i;
		}
		i++;
	}
	if ((*hold)->side == -1 && (*hold)->c_my > (*hold)->o_my)
		(*hold)->side = 1;
	if ((*hold)->side == -1 && (*hold)->c_my <= (*hold)->o_my)
		(*hold)->side = 0;
}

void	map(game **hold)
{
	char	*line;
	char	*temp;
	int		i;
	int		y;

	i = 0;
	y = 0;
	temp = NULL;
	line = NULL;
	y = get_next_line(&line);
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
	my(hold);
	(*hold)->map3D[i] = NULL;
}
