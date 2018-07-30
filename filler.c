/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:20:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 16:44:31 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clean(t_lst **hold)
{
	int i;

	i = 0;
	while ((*hold)->map[i])
		i++;
	while (--i >= 0)
		free((*hold)->map[i]);
	free((*hold)->map);
	i = 0;
	while ((*hold)->token[i])
		i--;
	while (--i >= 0)
		free((*hold)->token[i]);
	free((*hold)->token);
}

void	init(t_lst **hold)
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
	t_lst	*hold;
	int		i;

	i = 1;
	hold = (t_lst *)malloc(sizeof(t_lst));
	set(&hold);
	while (i)
	{
		i = 0;
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
