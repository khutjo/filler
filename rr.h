/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:22:30 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/23 09:11:19 by kmaputla         ###   ########.fr       */
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
	int			p_set;
	int			x_map;
	int			y_map;
	int			x_my;
	int			y_my;
}				p_data;
#endif
