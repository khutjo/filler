/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 09:03:42 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/29 17:39:00 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"

typedef	struct	game
{
	char		**map3D;
	char		**token3D;
	char		c;
	char		o;
	int			x;
	int			y;
	int			c_my;
	int			c_ym;
	int			o_my;
	int			side;
	int			x_map;
	int			y_map;
	int			x_token;
	int			y_token;
	int			y1_offset;
	int			y2_offset;
	int			x1_offset;
	int			x2_offset;
}				game;

void			map(game **hold);
int				set(game **hold);
void			token(game **hold);
int				play3(game **hold);
int				play_3(game **hold);
int				valid(game **hold, int x, int y);

#endif
