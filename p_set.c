/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:07:15 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 15:39:56 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set(t_lst **hold)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = NULL;
	get_next_line(&line);
	temp = ft_strchr(line, 'p') + 1;
	if (*temp == '1')
	{
		(*hold)->c = 'O';
		(*hold)->o = 'X';
	}
	else
	{
		(*hold)->c = 'X';
		(*hold)->o = 'O';
	}
	(*hold)->c_my = -1;
	(*hold)->o_my = -1;
	(*hold)->side = -1;
	return (1);
}
