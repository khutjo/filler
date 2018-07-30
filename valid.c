/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:54:44 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 16:45:34 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check(t_lst **hold, char *map, char *token, int *point)
{
	int i;
	int p;
	int stop;

	i = 0;
	stop = 0;
	p = *point;
	while (map[i] && token[i] && !stop)
	{
		if (map[i] == (*hold)->c && token[i] == '*')
			p++;
		if (map[i] == (*hold)->o && token[i] == '*')
			stop = 1;
		i++;
	}
	*point = p;
	if (stop || token[i])
		return (1);
	return (0);
}

int	valid(t_lst **hold, int x, int y)
{
	int i;
	int j;
	int p;
	int stop;

	p = 0;
	stop = 0;
	j = (*hold)->x1_offset;
	i = -1 + (*hold)->y1_offset;
	while (++i < (*hold)->y2_offset && (*hold)->map[y] && !stop)
	{
		stop = check(hold, &(*hold)->map[y][x], &(*hold)->token[i][j], &p);
		y++;
	}
	if (stop || p != 1 || i < (*hold)->y2_offset)
		return (0);
	return (1);
}
