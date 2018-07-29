/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GFX.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:43:25 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/18 17:02:58 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GFX.h"

int	choose(int key)
{
	if (keycode == 53)
	   exit(0);
	return (0);
}	

int	main(void)
{
	node	*hold;

	hold = (node *)malloc(sizeof(node));
	(*hold)->mlx = mlx_init(mlx);
	(*hold)->fd = open("plays.txt", O_RDONLY);
	dimen(&hold);
	(*hold)->win = mlx_new_window(mlx, (*hold)->x, (*hold)->y, "FILLER GFX");
	mlx_key_hook(win, &choose, 0);
	mlx_loop(mlx);
}
