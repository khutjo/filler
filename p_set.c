/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:07:15 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/29 17:39:28 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	set(game **hold)
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
	return (1);
}
