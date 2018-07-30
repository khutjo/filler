/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 14:13:12 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 15:56:52 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		putt(t_lst **hold, int y, int x, char c)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 1;
	if (y == 0)
		i = 0;
	while (i < 2 && (*hold)->map[i + y])
	{
		j = -1;
		if (x == 0)
			j = 0;
		while (j < 2 && (*hold)->map[i + y][j + x])
		{
			if ((*hold)->map[i + y][j + x] == '.')
			{
				(*hold)->map[i + y][j + x] = c;
				k++;
			}
			j++;
		}
		i++;
	}
	return (k);
}

void			heatmap(t_lst **hold, char s)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while ((*hold)->map[++i])
	{
		j = -1;
		while ((*hold)->map[i][++j])
		{
			if ((*hold)->map[i][j] == (*hold)->o || (*hold)->map[i][j] == s)
			{
				k = putt(hold, i, j, 1 + s);
			}
		}
	}
	if (k && s <= 'x')
		heatmap(hold, ++s);
}
