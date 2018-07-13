/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:07:15 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/13 15:54:58 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set(char *c, char *o)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = NULL;
	get_next_line(&line);
	temp = ft_strchr(line, 'p') + 1;
	if (*temp == '1')
	{
		*c = 'O';
		*o = 'X';
	}
	else
	{
		*c = 'X';
		*o = 'O';
	}
}
