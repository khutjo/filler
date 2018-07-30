/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:08:13 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 16:35:57 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	int		justput(t_lst **hold)
{
	int i;
	int j;
	int exit;

	i = -1;
	exit = 0;
	while ((*hold)->map[++i] && !exit)
	{
		j = -1;
		while ((*hold)->map[i][++j] && !exit)
		{
			if (valid(hold, j, i))
			{
				(*hold)->y = i - (*hold)->y1_offset;
				(*hold)->x = j - (*hold)->x1_offset;
				exit = 1;
			}
		}
	}
	return (exit);
}

static	int		hotspot(t_lst **hold, int x, int y, char c)
{
	int i;
	int j;
	int k;
	int xx;

	k = 0;
	i = (*hold)->y1_offset;
	while (i < (*hold)->y2_offset)
	{
		xx = x;
		j = (*hold)->x1_offset;
		while ((*hold)->token[i][j])
		{
			if ((*hold)->token[i][j] == '*' && (*hold)->map[y][xx] == c)
				k++;
			xx++;
			j++;
		}
		i++;
		y++;
	}
	return (k);
}

static	int		heatseeker(t_lst **hold, char c)
{
	int i;
	int j;
	int k;
	int exit;

	k = 0;
	i = -1;
	exit = 0;
	while ((*hold)->map[++i] && !exit && (j = -1))
		while ((*hold)->map[i][++j] && !exit)
		{
			if ((*hold)->map[i][j] == c)
				k++;
			if (valid(hold, j, i) && hotspot(hold, j, i, c))
			{
				(*hold)->y = i - (*hold)->y1_offset;
				(*hold)->x = j - (*hold)->x1_offset;
				exit = 1;
			}
		}
	if (!exit && k)
		exit = heatseeker(hold, ++c);
	return (exit);
}

int				play3(t_lst **hold)
{
	int exit;

	exit = 0;
	heatmap(hold, '`');
	exit = heatseeker(hold, 'a');
	if (!exit)
		exit = justput(hold);
	return (exit);
}
