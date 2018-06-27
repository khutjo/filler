/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:20:36 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/27 09:25:10 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rr.h"
#include <stdio.h>

void	player(p_data **hold)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	line = NULL;
	get_next_line(0, &line);
	(*hold)->p_set = ft_atoi((ft_strstr(line, "p") + 1));
	free(line);
	get_next_line(0, &line);
	(*hold)->y_map = ft_atoi((temp = ft_strchr(line, ' ')));
	(*hold)->x_map = ft_atoi(ft_strchr(temp + 1, ' '));
	(*hold)->y_my = (5 + (*hold)->x_map) * (* hold)->y_map;
	free(line);
	get_next_line(0, &line);
	free(line);
	line = ft_strnew((*hold)->y_my);
	(*hold)->x_my = read(0, line,  (1 + (*hold)->y_my));
	(*hold)->map3D = ft_strsplit(line, ' ');
	
}
int		main(void)
{
	static p_data *hold;
	int i;

	i = 0;
	if (hold == NULL)
	{
		hold = (p_data *)malloc(sizeof(p_data));
		player(&hold);
	}
	printf("4 2");
	fprintf(stderr, "==%d==%d==%d==%d==%d==\n", hold->p_set, hold->x_map, hold->y_map, hold->x_my, hold->y_my);
	while (hold->map3D[i])
		fprintf(stderr, "%s", hold->map3D[i++]);
	return (0);
}
