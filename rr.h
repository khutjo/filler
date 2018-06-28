/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:22:30 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/28 15:51:37 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RR_H
# define RR_H
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	p_data
{
	char		**map3D;
	char		**token3D;
	int			p_set;
	int			x_map;
	int			y_map;
	int			x_my;
	int			y_my;
	int			y_op;
	int			x_op;
	int			x_token;
	int			y_token;
	int			x_last;
	int			y_last;
	int			x_corner;
	int			y_corner;
	int			x_adder;
	int			y_adder;
}				p_data;
#endif
