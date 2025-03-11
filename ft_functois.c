/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functois.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:23:45 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/11 13:33:20 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_game *game, int k)
{
	int	i;

	i = 0;
	game->copy = malloc(sizeof(char *) * (k + 1));
	if (!game->copy)
	{
		write(2, "Error\nmalloc return NULL\n", 26);
		ft_free_map(game);
	}
	while (game->map[i])
	{
		game->copy[i] = ft_strdup1(game->map[i]);
		if (!game->copy[i])
		{
			ft_free_node(game);
			exit(1);
		}
		i++;
	}
	game->copy[i] = NULL;
}

char	**ft_handel(int k, char *str1)
{
	int		fd;
	char	**str;
	char	*line;
	int		i;

	str = malloc (sizeof(char *) * (k + 1));
	if (!str)
		return (write (2, "Error\n main ft_handel str malloc\n", 34), NULL);
	fd = open(str1, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error\n Could not open\n", 23), free(str), NULL);
	line = get_next_line(fd);
	if (!line)
		print_error3("Error\n Empty or unreadable file.\n", str, fd);
	i = 0;
	while (line)
	{
		str[i++] = line;
		line = get_next_line(fd);
	}
	str[i] = NULL;
	close(fd);
	validate_map(str, i, 0);
	check_width(str, i);
	return (str);
}

void	count_height_width(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
			x++;
		y++;
	}
	game->size_height = y * 64;
	game->size_width = x * 64;
}
