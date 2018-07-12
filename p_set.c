/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 16:38:16 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/12 17:06:42 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rr.h"

void	stdgg(p_data **hold)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = NULL;
	get_next_line(&line);
	temp = ft_strchr(line, 'p') + 1;
	if (*temp == '1')
		(*hold)->p_set = 'O';
	else
		(*hold)->p_set = 'X';
}
