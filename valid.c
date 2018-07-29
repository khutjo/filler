/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:54:44 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/29 17:42:25 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check(game **hold, char *map, char *token, int *point)
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
		{
//	printf("\t %c =tt=%d", map[i], token[i]);
			p++;
		}
		if (map[i] == (*hold)->o && token[i] == '*')
		{
//	printf("\t %c %c =rr=", map[i], token[i]);
			stop = 1;
		}
		i++;
	}
	*point = p;
	if (stop || token[i])
		return (1);
	return (0);
}

int	valid(game **hold, int x, int y)
{
	int i;
	int j;
	int p;
	int stop;

	p = 0;
	stop = 0;
	j = (*hold)->x1_offset;
	i = -1 + (*hold)->y1_offset;
	while (++i < (*hold)->y2_offset && (*hold)->map3D[y] && !stop)
	{
		stop = check(hold, &(*hold)->map3D[y][x], &(*hold)->token3D[i][j], &p);
		y++;
	}
	if (stop || p != 1 || i < (*hold)->y2_offset)
		return (0);
	return (1);
}
/*
int main(void)
{
	t_list *hold;
	int i;
	int j;

	i = -1;
	j = -1;
	hold = (t_list *)malloc(sizeof(t_list));
	hold->o = 'X';
	hold->c = 'O';
	char d[] = "........................................\n........................................\n........................................\n...OO...................................\n...OOO..................................\n....O...................................\n...OO...................................\n..OO..O.................................\n...OOOOOO...............................\n......OOOOOOOOOO........................\n...............OOO......................\n.................O......................\n.................OO.....................\n..................O.....................\n..................O.....................\n..................OO....................\n................OOOOOO.....O............\n................O....OO....OO.....O.....\n........OO......OO.O..OOOOOOO....OOO...O\n.........OO.O.OOOOOOOOOOOOOOOO..XOOOOOOO\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\nOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO";
	hold->map3D   = ft_strsplit(d, '\n');
	hold->token3D = ft_strsplit("*.....\n**....\n*.....", '\n');
	hold->x1_offset = 0;
	hold->y1_offset = 0;
	hold->x2_offset = 2;
	hold->y2_offset = 3;
	while (++i < 24)
	{
		j = 0;
		while (++j < 40)
		{
			printf("=%d", valid(&hold, j, i));
		}
		printf("\n");
	}
	return (0);
}*/
