/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:20:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/13 16:25:03 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rr.h"
#include <stdio.h>

int		check(t_list **hold, int x, int y, char c, char o)
{
	int		i;
	int		j;
	int		point;
	int		stop;

	i = 0;
	j = 0;
	stop = 0;
	point = 0;
	while ((*hold)->map3D[i + y] && (*hold)->token3D[i] && !stop)
	{
		j = 0;
		while ((*hold)->token3D[i][j] && (*hold)->map3D[i + y][j + x] && !stop)
		{
			if ((*hold)->map3D[i + y][j + x] == c \
					&& (*hold)->token3D[i][j] == '*')
				point++;
			if ((*hold)->map3D[i + y][j + x] == o \
					&& (*hold)->token3D[i][j] == '*')
				stop = 1;
			j++;
		}
		if ((*hold)->map3D[i + y][j + x] == '\0' &&\
				(*hold)->token3D[i][j] != '\0')
			stop = 1;
		i++;
	}
	if (point == 1 && !stop)
		return (1);
	return (0);
}

int		play(t_list **hold, int *x, int *y, char c, char o)
{
	int i;
	int j;
	int	point;

	i = 0;
	j = 0;
	point = 0;
	while ((*hold)->map3D[i] && !point)
	{
		j = 0;
		while ((*hold)->map3D[i][j] && !point)
		{
			point = check(hold, j, i, c, o);
			if (point == 1)
			{
				*x = j - (*hold)->x1_offset;
				*y = i - (*hold)->y2_offset;
			}
			j++;
		}
		i++;
	}
	if ((*hold)->map3D[i])
		return (1);
	return (0);
}

int		main(void)
{
	t_list	*hold;
	char	c;
	char	o;
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 1;
	o = '\0';
	c = '\0';
	hold = NULL;
	if (c == '\0')
		set(&c, &o);
	while (i)
	{
	hold = (t_list *)malloc(sizeof(t_list));
	map(&hold);
	token(&hold);
	i = play(&hold, &x, &y, c, o);
	free(hold);
	ft_putstr(ft_itoa(y));
	ft_putstr(" ");
	ft_putstr(ft_itoa(x));
	ft_putstr("\n");
	}
	return (0);
}
