/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 09:03:42 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/12 17:52:03 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RR_H
# define RR_H
# include "./libft/libft.h"
# include "get_next_line.h"

typedef struct	p_data
{
	char		**map3D;
	char		**token3D;
	int			x_map;
	int			y_map;
	int			x_token;
	int			y_token;
	int			y1_offset;
	int			y2_offset;
	int			x1_offset;
	int			x2_offset;
}				p_data;

//void	map(p_data **hold);
//void	stdgg(p_data **hold);

#endif
