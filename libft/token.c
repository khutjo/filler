/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:10:40 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/13 11:27:14 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	len(t_list **hold, char *temp)
{
	int	j;

	j = (*hold)->x_token;
	while (temp[j] != '*' && j >= 0)
		j--;
	if (j == -1 && (*hold)->x2_offset == 0)
		(*hold)->y2_offset++;
	if (j >= (*hold)->x2_offset)
		(*hold)->x2_offset = ++j - (*hold)->x1_offset;
}

void	crop_1(t_list **hold, char **temp)
{
	int i;
	int j;
	int u;
	int	h;

	i = 0;
	u = 0;
	h = 0;
	j = (*hold)->y1_offset;
	(*hold)->y2_offset = 0;
	(*hold)->x2_offset = 0;
	while (temp[i])
		len(hold, temp[i++]);
	(*hold)->token3D = (char **)malloc(sizeof(char **) * (1 + j));
	(*hold)->token3D[j] = NULL;
	i = (*hold)->x1_offset;
	j = (*hold)->x2_offset;
	u = (*hold)->y2_offset;
	while (h < (*hold)->y1_offset)
		(*hold)->token3D[h++] = ft_strsub(temp[u++], i, j);
}

void	crop(t_list **hold, char **temp)
{
	int		i;
	int		j;
	int		exit;

	j = -1;
	exit = 0;
	(*hold)->y1_offset = 0;
	(*hold)->x1_offset = (*hold)->x_token;
	while (temp[++j])
	{
		i = 0;
		exit = 0;
		while (temp[j][i] != '\0')
		{
			if (!exit && temp[j][i] == '*')
			{
				exit = 1;
				(*hold)->y1_offset = (*hold)->y1_offset + 1;
				if (i < (*hold)->x1_offset)
					(*hold)->x1_offset = i;
			}
			i++;
		}
	}
	crop_1(hold, temp);
}

void	token(t_list **hold)
{
	int		i;
	int		j;
	char	*line;
	char	**temp;

	i = 0;
	j = 0;
	line = NULL;
	temp = NULL;
	get_next_line(&line);
	(*hold)->y_token = ft_atoi(ft_strchr(line, ' '));
	(*hold)->x_token = ft_atoi(ft_strrchr(line, ' '));
	free(line);
	temp = (char **)malloc(sizeof(char **) * (1 + (*hold)->y_token));
	temp[(*hold)->y_token] = NULL;
	while (i < (*hold)->y_token)
	{
		get_next_line(&line);
		temp[i] = line;
		i++;
	}
	crop(hold, temp);
	free(temp);
}
