/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:40 by gusalves          #+#    #+#             */
/*   Updated: 2021/12/10 17:15:17 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	


void	matrix_validation(t_game *game)
{
	int	x;
	int	y;
	int	z;
	
	x = 0;
	y = 0;
	z = ft_strlen(game->map[0]);
	while (game->map[x] != 0)
	{
		y = ft_strlen(game->map[x]);
		if (y != z)
			exit (2); //mensagem personalizada aqui meu querido
		x++;
	}
}

void	validations(t_game *game, char	c, int x, int y)
{
	if (c == 'C')
		game->i_collectible++;
	else if (c == 'P')
	{
		game->i_player++;
		game->x_player = x;
		game->y_player = y;
	}			
	else if (c == 'E')
		game->i_exit++;
	else if (c == '0' || c == '1')
		return ;
	else
		exit(1); //mensagem personalizada aqui meu querido
}

void	map_walk(t_game *game)
{
	int	x;
	int y;
	
	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			validations(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
	if (x == y)
		exit (5);	
	if (!game->i_collectible || !game->i_exit || game->i_player != 1)
		exit (4);
}

void	map(char *argv, t_game *game)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		exit (999);
	temp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		temp = ft_strjoin(temp, line);
		free(line);
		game->row++;
	}
	game->map = ft_split(temp, '\n');
	game->col = ft_strlen(game->map[0]);
	printf("%s\n", temp);
	printf("%d\n%d\n", game->col, game->row);
}