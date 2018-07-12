/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:20:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/12 17:51:10 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rr.h"
#include <stdio.h>

void	len(p_data **hold, char *temp)
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

void	crop_1(p_data **hold, char **temp)
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

void	crop(p_data **hold, char **temp)
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

void	token(p_data **hold)
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

void	map(p_data **hold)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	line = NULL;
	get_next_line(&line);
	(*hold)->y_map = ft_atoi(ft_strchr(line, ' '));
	(*hold)->x_map = ft_atoi(ft_strrchr(line, ' '));
	(*hold)->map3D = (char **)malloc(sizeof(char **) * (1 + (*hold)->y_map));
	free(line);
	get_next_line(&line);
	free(line);
	while (i < (*hold)->y_map)
	{
		get_next_line(&line);
		(*hold)->map3D[i] = ft_strsub(line, 4, (*hold)->x_map);
		free(line);
		i++;
	}
	(*hold)->map3D[i] = NULL;
}

void	set(char *c)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = NULL;
	get_next_line(&line);
	temp = ft_strchr(line, 'p') + 1;
	if (*temp == '1')
		*c = 'O';
	else
		*c = 'X';
}

int		check(p_data **hold, int x, int y, char c)
{
	int		i;
	int		j;
	int		point;

	i = 0;
	j = 0;
	point = 0;
	while ((*hold)->map3D[i + y] && (*hold)->token3D[i])
	{
		j = 0;
		while ((*hold)->token3D[i][j] && (*hold)->map3D[i + y][j + x])
		{
			if ((*hold)->map3D[i + y][j + x] == c && (*hold)->token3D[i][j] == '*')
				point++;
			j++;
		}
		i++;
	}
	if (point == 1)
		return (1);
	return (0);
}

int		play(p_data **hold, int *x, int *y, char c)
{
	int i;
	int j;
	int	point;

	i = 0;
	j = 0;
	point = 0;
	while ((*hold)->map3D[i] && !point)
	{
		j = 0;
		while ((*hold)->map3D[i][j] && !point)
		{
			point = check(hold, j, i, c);
			if (point == 1)
			{
				*x = j - (*hold)->x1_offset;
				*y = i - (*hold)->y2_offset;
			}
			j++;
		}
		i++;
	}
	if ((*hold)->map3D[i])
	{
		free(hold);
		return (1);
	}
	return (0);
}

int		s_play(p_data **hold, int *x, int *y, char c)
{
	(*hold) = (p_data *)malloc(sizeof(p_data));
	map(hold);
	token(hold);
	return (play(hold, x, y, c));
}

int		main(void)
{
	p_data	*hold;
	char	c;
	int		x;
	int		y;

	x = 0;
	y = 0;
	c = '\0';
	hold = NULL;
	set(&c);
	while (s_play(&hold, &x, &y, c))
		printf("%d %d", y, x);
	return (0);
}
