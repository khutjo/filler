/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:20:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/30 18:25:15 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rr.h"
#include <stdio.h>

void	start(p_data **hold)
{
	if ((*hold)->y_op > (*hold)->y_my)
	{
		(*hold)->y_corner = 0;
		(*hold)->y_adder = 1;
	}
	else
	{
		(*hold)->y_corner = (*hold)->y_map;
		(*hold)->y_adder = -1;
	}
	if ((*hold)->x_op > (*hold)->x_my)
	{
		(*hold)->x_corner = 0;
		(*hold)->x_adder = 1;
	}
	else
	{
		(*hold)->x_corner = (*hold)->x_map;
		(*hold)->x_adder = -1;
	}
}
int		setup(p_data **hold, int i, int j, int state)
{
	if (state == 1)
	{
		(*hold)->y_my = i;
		(*hold)->x_my = -4 + j;
	}
	if (state == 2)
	{
		(*hold)->y_op = i;
		(*hold)->x_op = -4 + j;
	}
	return (1);
}

void	my_pos(p_data **hold)
{
	char	*c;
	int		exit[2];
	int		i;
	int		j;
	int		set;

	i =	0;
	j = 0;
	set = 0;
	c = "OX";
	exit[0] = 0;
	exit[1] = 0;
	if ((*hold)->p_set == 1)
		set = 1;
	while ((*hold)->map3D[i++] && (!exit[0] || !exit[1]))
	{
		j = 0;
		while ((*hold)->map3D[i][j++] && (!exit[0] || !exit[1]))
		{
			if ((*hold)->map3D[i][j] == c[-1 +(*hold)->p_set] && !exit[0])
				exit[0] = setup(hold, i, j, 1);
			if ((*hold)->map3D[i][j] == c[set] && !exit[1])
				exit[1] = setup(hold, i, j, 2);
		}
	}
	start(hold);
}
/*
void	(p_data **hold, int start, int adder)
{
	int i;
	int	j;

	i = -1;
	j = 0;
	while ((*hold)->token3D[++i] && && (*hold)->token3D[i][-1 + j] == '*')
	{
		j = 0;
		while ((*hold)->token3D[i][j] && (*hold)->token3D[i][j] != '*')
			j++;
	}
	while ((*hold)->token3D[i])
	{
		while ((*hold)->token3D[i][j] && (*hold)->token3D[i][j] != '*')
			j++;
	}
	while ((*hold)->token3D[i])
	{
		while ((*hold)->token3D[i][j] && (*hold)->token3D[i][j] != '*')
			j++;
	}
}	
*/
void	map(p_data **hold)
{
	char	*line;
	char	*temp;
	int		i;

	temp = NULL;
	line = NULL;
	get_next_line(0, &line);
	free(line);
	line = ft_strnew((*hold)->y_my);
	(*hold)->x_my = read(0, line,  (*hold)->y_my);
	(*hold)->map3D = ft_strsplit(line, '\n');
	free(line);
	while ((*hold)->map3D[i])
	{
		temp = ft_strdup(ft_strchr((*hold)->map3D[i], '.'));
		free((*hold)->map3D[i]);
		(*hold)->map3D[i++] = temp;
	}
	get_next_line(0, &line);
	(*hold)->y_token = ft_atoi((temp = ft_strchr(line, ' ')));
	(*hold)->x_token = ft_atoi(ft_strchr(temp + 1, ' '));
	free(line);
	line = ft_strnew((i = (1 + (*hold)->x_token) * (*hold)->y_token));
	read(0, line, i);
	( *hold)->token3D = ft_strsplit(line, '\n');
}

void	player(p_data **hold)
{
	char	*line;
	char	*temp;

	temp = NULL;
	line = NULL;
	get_next_line(0, &line);
	(*hold) = (p_data *)malloc(sizeof(p_data));
	(*hold)->p_set = ft_atoi((ft_strstr(line, "p") + 1));
	free(line);
	get_next_line(0, &line);
	(*hold)->y_map = ft_atoi((temp = ft_strchr(line, ' ')));
	(*hold)->x_map = ft_atoi(ft_strchr(temp + 1, ' '));
	(*hold)->y_my = (5 + (*hold)->x_map) * (* hold)->y_map;
	free(line);
	map(hold);
	my_pos(hold);
}

int		check(p_data **hold, int y, int x, char c)
{
	int point;
	int i;
	int	j;

	i = 0;
	j = 0;
	point = 0;
	while ((*hold)->token3D[j] && (*hold)->map3D[j + y])
	{
		i = 0;
		while ((*hold)->token3D[y][i] && (*hold)->map3D[j + y][i + x])
		{
			if ((*hold)->token3D[y][i] == '*' \
					&& (*hold)->map3D[j + y][i + x] == c)
				point++;
			i++;
		}
		j++;
	}
	if (point == 1 && !(*hold)->token3D[j])
		return (1);
	return (0);
}

void	play(p_data **hold)
{
	int		i;
	int		x;
	int		y;
	char	c;

	i = 0;
	c = 'O';
	x = (*hold)->x_corner;
	y = (*hold)->y_corner;
	if ((*hold)->p_set == 2)
		c = 'X';
	while ((*hold)->map3D[y] && y >= 0 && i == 0)
	{
		x =	(*hold)->x_corner;
		while ((*hold)->map3D[y][x] && x >= 0 && i == 0)
		{ 
			if ((i = check(hold, y, x, c)))
				printf("%d %d", 1 + y, x);
			x += (*hold)->x_adder;
			fprintf(stderr, "%d %d %d %c \n", y, x,i, (*hold)->map3D[y][x]);
		}
		y += (*hold)->x_adder;
	}
}	

int		main(void)
{
	static p_data *hold;
	int i;

	i = 0;

	if (hold == NULL)
	{
	fprintf(stderr, "hi");
		player(&hold);
	}
	fprintf(stderr, "hi");
	play(&hold);
//	fprintf(stderr, "%d==%d==%d==%d==%d==\n", hold->p_set, hold->x_my, hold->y_my, hold->x_op, hold->y_op);
	return (0);
}
