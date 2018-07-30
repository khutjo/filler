/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:10:40 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/30 16:43:12 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	width(t_lst **hold, char **temp)
{
	int i;
	int j;

	i = -1;
	(*hold)->x1_offset = (*hold)->x_token;
	while (temp[++i])
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] == '*' && j <= (*hold)->x1_offset)
				(*hold)->x1_offset = j;
			if (temp[i][j] == '*' && j >= (*hold)->x2_offset)
				(*hold)->x2_offset = 1 + j;
		}
	}
}

void	depth(t_lst **hold, char **temp)
{
	int i;
	int j;
	int s;

	i = 0;
	j = 0;
	s = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j] && temp[i][j] != '*')
			j++;
		if (!s && temp[i][j] == '*')
			(*hold)->y1_offset = i;
		if (temp[i][j] == '*')
		{
			(*hold)->y2_offset = 1 + i;
			s = 1;
		}
		i++;
	}
}

void	token(t_lst **hold)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	get_next_line(&line);
	(*hold)->y_token = ft_atoi(ft_strchr(line, ' '));
	(*hold)->x_token = ft_atoi(ft_strrchr(line, ' '));
	free(line);
	(*hold)->token = (char **)malloc(sizeof(char **) * (1 + (*hold)->y_token));
	(*hold)->token[(*hold)->y_token] = NULL;
	while (i < (*hold)->y_token)
		get_next_line(&(*hold)->token[i++]);
	depth(hold, (*hold)->token);
	width(hold, (*hold)->token);
	i = -1;
	while ((*hold)->token[++i])
		(*hold)->token[i][(*hold)->x2_offset] = '\0';
}
