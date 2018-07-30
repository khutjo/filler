/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 09:03:42 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 16:52:56 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"

typedef	struct	s_lst
{
	char		**map;
	char		**token;
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
}				t_lst;

void			map(t_lst **hold);
int				set(t_lst **hold);
void			token(t_lst **hold);
int				play3(t_lst **hold);
int				play_3(t_lst **hold);
int				valid(t_lst **hold, int x, int y);
void			heatmap(t_lst **hold, char s);
#endif
