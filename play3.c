/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:08:13 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/29 17:39:58 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	putt(game **hold, int y, int x, char c)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 1;
	if (y == 0)
		i = 0;
	while (i < 2 && (*hold)->map3D[i + y])
	{
		j = -1;
		if (x == 0)
			j = 0;
		while (j < 2 && (*hold)->map3D[i + y][j + x])
		{
			if ((*hold)->map3D[i + y][j + x] == '.')
			{
				(*hold)->map3D[i + y][j + x] = c;
				k++;
			}
			j++;
		}
		i++;
	}
	return (k);
}


static void	heatmap(game ** hold, char s)
{
	int i;
	int j;
	int k;

	i = -1;
	k = 0;
	while ((*hold)->map3D[++i])
	{
		j = -1;
		while ((*hold)->map3D[i][++j])
		{
			if ((*hold)->map3D[i][j] == (*hold)->o || (*hold)->map3D[i][j] == s)
			{
				k = putt(hold, i, j, 1 + s);
			}
		}
	}
	if (k && s <= 'x')
		heatmap(hold, ++s);
}

static int	justput(game **hold)
{
	int i;
	int j;
	int exit;

	exit = 0;
	i  = -1;
	while ((*hold)->map3D[++i] && !exit)
	{
		j = -1;
		while ((*hold)->map3D[i][++j] && !exit)
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

static int	hotspot(game **hold, int x, int y, char c)
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
		while ((*hold)->token3D[i][j])
		{
			if ((*hold)->token3D[i][j] == '*' && (*hold)->map3D[y][xx] == c)
				k++;
			xx++;
			j++;
		}
		i++;
		y++;
	}
	return (k);
}

static int	heatseeker(game **hold, char c)
{
	int i;
	int j;
	int k;
	int exit;

	k = 0;
	exit = 0;
	i = -1;
	while ((*hold)->map3D[++i] && !exit)
	{
		j = -1;
		while ((*hold)->map3D[i][++j] && !exit)
		{
			if ((*hold)->map3D[i][j] == c)
				k++;
			if (valid(hold, j, i) && hotspot(hold, j, i, c))
			{
				(*hold)->y = i - (*hold)->y1_offset;
				(*hold)->x = j - (*hold)->x1_offset;
				exit = 1;
			}
		}
	}
	if (!exit && k)
		exit = heatseeker(hold, ++c);
	return (exit);
}

int	play3(game **hold)
{
	int exit;

	exit = 0;
	heatmap(hold, '`');
	exit = heatseeker(hold, 'a');
	if (!exit)
		exit = justput(hold);
	return (exit);
}
