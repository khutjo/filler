/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:20:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/29 17:39:40 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clean(game **hold)
{
	int i;

	i = 0;
	while ((*hold)->map3D[i])
		i++;
	while (--i >= 0)
		free((*hold)->map3D[i]);
	free((*hold)->map3D);
	i = 0;
	while ((*hold)->token3D[i])
		i--;
	while (--i >= 0)
		free((*hold)->token3D[i]);
	free((*hold)->token3D);
}


void	init(game **hold)
{
	(*hold)->x = 0;
	(*hold)->y = 0;
	(*hold)->x_map = 0;
	(*hold)->y_map = 0;
	(*hold)->y_token = 0;
	(*hold)->x_token = 0;
	(*hold)->y1_offset = 0;
	(*hold)->y2_offset = 0;
	(*hold)->x1_offset = 0;
	(*hold)->x2_offset = 0;
}

int		main(void)
{
	game	*hold;
	int		i;
	int		k;

	i = 1;
	hold = (game *)malloc(sizeof(game));
	set(&hold);
	hold->c_my = -1;
	hold->o_my = -1;
	hold->side = -1;
	while (i)
	{
		i = 0;
		k = -1;
		init(&hold);
		map(&hold);
		token(&hold);
		if (!hold->side)
			i = play_3(&hold);
		else
			i = play3(&hold);
		ft_putnbr(hold->y);
		ft_putchar(' ');
		ft_putnbr(hold->x);
		ft_putchar('\n');
		clean(&hold);
	}
	return (0);
}
