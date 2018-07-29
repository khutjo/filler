/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GFX.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:43:25 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/19 17:08:20 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GFX.h"
#include <stdio.h>

int	choose(int key)
{
	if (key == 53)
	   exit(0);
	return (0);
}	

void	dimen(node **hold)
{
	char	*line;

	line = ft_strnew(0);
	while (!ft_strstr(line, "Plateau"))
	{
		if (!ft_strstr(line, "p1"))
			(*hold)->p1 = line;
		else if (!ft_strstr(line, "p2"))
			(*hold)->p2 = line;
		else
			free(line);
		get_next_line((*hold)->fd, &line);
	}
	(*hold)->y = ((*hold)->y_map = ft_atoi(ft_strchr(line, ' '))) * 20;
	(*hold)->x = ((*hold)->x_map = ft_atoi(ft_strrchr(line, ' '))) * 20;
	(*hold)->mlt = 20;
	(*hold)->st = 100;
	while ((*hold)->x > 1000 || (*hold)->y > 1000)
	{
		(*hold)->x /= 2;
		(*hold)->y /= 2;
		(*hold)->mlt /= 2;
		(*hold)->st = 30;
	}
}

void	sqr(node **hold, void *mlx, void	*win)
{
	int i;
	int j;
	int mlty;
	int mltx;

	i = -1;
	mltx = 0;
	mlty = (*hold)->st;
	while (++i <= (*hold)->y_map)
	{
		j = -1;
		while (++j <= (*hold)->x)
			mlx_pixel_put(mlx, win, j, mlty , 0x00FFFFFF);
		mlty += (*hold)->mlt;
	}
	i = -1;
	while (++i <= (*hold)->x_map)
	{
		j = (*hold)->st;
		while (++j <=  (*hold)->st + (*hold)->y)
			mlx_pixel_put(mlx, win, mltx, j , 0x00FFFFFF);
		mltx += (*hold)->mlt;
	}
}

int		chofa(const int	fd)
{
	int		i;
	char	*l;

	i = 0;
	while (i == 1)
	{
		i = get_next_line(fd, &l);
		if (ft_strstr(l, "    0123456"))
		{
			free(l);
			return (0);
		}
		free(l);
	}
	return (1);
}

m_data	*pop(m_data **add, node **hold)
{
	m_data	*map;
	char	*temp;
	int		i;

	i = -1;
	temp = NULL;
	if (chofa((*hold)->fd) == 0)
		return (NULL);
	map = (m_data *)malloc(sizeof(m_data));
	map->map3D = (char **)malloc(sizeof(char **) * (1 + (*hold)->y_map));
	map->map3D[(*hold)->y_map] = NULL;
	if (!(*add))
	{
		map->prev = NULL;
		(*add) = map;
	}
	else
		map->prev = (*add);
	get_next_line((*hold)->fd, &temp);
	while (!ft_strstr(temp, "Piece"))
	{
		map->map3D[i++] = temp;
		get_next_line((*hold)->fd, &temp);
	}
//	map->next = pop(&map, hold);
	return (map);
}

void	put(m_data **map, node **hold, int x, int y)
{
	int i;
	int j;
	int u;
	int h;

	i = 0;
	u = (((*hold)->mlt) * (1 + y));
	h = ((*hold)->mlt) * (1 + x);
	while (i < (*hold)->mlt)
	{
		j = 0;
		while (j < (*hold)->mlt)
		{
			if ((*map)->state == 'X' || (*map)->state == 'x')
				mlx_pixel_put((*hold)->mlx, (*hold)->win, j, i, red);
			if ((*map)->state == 'O' || (*map)->state == 'o')
				mlx_pixel_put((*hold)->mlx, (*hold)->win, h + j, u + i, blue);
			j++;
		}
		i++;
	}
}
void	draw(m_data **map, node **hold)
{
	int i;
	int j;

	i = 0;
	while ((*map)->map3D[i])
	{
		j = 4;
		while ((*map)->map3D[i][j])
		{
//			fprintf(stderr, "%c", (*map)->map3D[i]);
			if ((*map)->map3D[i][j] != '.')
			{
				(*map)->state = (*map)->map3D[i][j];
				put(map, hold, i, -4 + j);
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	node	*hold;
	m_data	*map;

	map = NULL;
	hold = (node *)malloc(sizeof(node));
	hold->mlx = mlx_init(hold->mlx);
	if ((hold->fd = open("plays.txt", O_RDONLY))  < 1)
		return (0);
	dimen(&hold);
	hold->win = mlx_new_window(hold->mlx, hold->x + 1, hold->y + 101, "FILLER GFX");
	mlx_string_put(hold->mlx, hold->win, 0, 2, 0x00FFFFFF, hold->p1);
	if (hold->mlt == 20)
		mlx_string_put(hold->mlx, hold->win, 0, 22, 0x00FFFFFF, hold->p2);
	else
		mlx_string_put(hold->mlx, hold->win, 100 + (ft_strlen(hold->p1) * 10), 2, 0x00FFFFFF, hold->p2);
	sqr(&hold, hold->mlx, hold->win);
	map = pop(&map, &hold);
	draw(&map, &hold);
	mlx_key_hook(hold->win, &choose, 0);
	
	mlx_loop(hold->mlx);
	return (0);
}
