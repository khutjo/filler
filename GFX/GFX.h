/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GFX.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 16:40:00 by kmaputla          #+#    #+#             */
/*   Updated: 2018/07/19 16:34:28 by kmaputla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H
# include "./libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# define red 0x000000FF
# define blue 0x00FF0000
typedef struct	node
{
	void	*mlx;
	void	*win;
	char	*p1;
	char	*p2;
	int		x_map;
	int		y_map;
	int		x;
	int		y;
	int		mlt;
	int 	st;
	int		fd;
}				node;

typedef struct		m_data
{
	char			**map3D;
	int				stop;
	int				state;
	struct m_data	*prev;
	struct m_data	*next;
}					m_data;
#endif
