/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 14:08:47 by kmaputla          #+#    #+#             */
/*   Updated: 2018/06/21 10:39:19 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list	*search(t_list **str, size_t fd)
{
	t_list *run;

	run = (*str);
	while (run != NULL && run->content_size != fd)
	{
		run = run->next;
	}
	if (run == NULL)
	{
		ft_lstadd(str, ft_lstnew(0, 0));
		(*str)->content_size = fd;
		return (*str);
	}
	return (run);
}

static	int		join(t_list *hold, const int fd, char **line, int bufsize)
{
	char	*temp;
	char	buf[1 + bufsize];
	int		size;

	size = 1;
	temp = NULL;
	if (hold->content == NULL)
	{
		ft_bzero(buf, 1 + BUFF_SIZE);
		size = read(fd, buf, BUFF_SIZE);
		if ((*line) == NULL)
			(*line) = ft_strdup(buf);
		else if ((*line) != NULL)
		{
			temp = ft_strjoin((*line), buf);
			free((*line));
			(*line) = temp;
		}
	}
	else
	{
		(*line) = hold->content;
	}
	return (size);
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*save;
	t_list			*hold;
	int				size;
	int				i;

	i = 1;
	size = 1;
	if (fd < 0 || !line)
		return (-1);
	if (BUFF_SIZE < 1)
		return (0);
//	(*line) = NULL;
	hold = search(&save, (size_t)fd);
	while (i == 1 && size > 0)
	{
		size = join(hold, fd, line, BUFF_SIZE);
		if ((hold->content = ft_strchr(*line, '\n')))
		{
			hold->content = ft_strdup(hold->content + 1);
			ft_strclr(ft_strchr(*line, '\n'));
			i = 0;
		}
	}
	if (size > 1 || ft_strlen(*line))
		size = 1;
	return (size);
}
