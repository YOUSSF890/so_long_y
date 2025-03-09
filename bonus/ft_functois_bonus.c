/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functois_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:11:53 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/09 13:46:31 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	copy_map(t_game *game, int k)
{
	int	i;

	i = 0;
	game->copy = malloc(sizeof(char *) * (k + 1));
	if (!game->copy)
	{
		write(2, "Error\nmalloc return NULL", 24);
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

void	monster_site(t_game *game)
{
	int	i;
	int	a;
	int	j;

	i = 0;
	a = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
			{
				game->xm[a] = j;
				game->ym[a] = i;
				game->n[a] = 1;
				a++;
			}
			j++;
		}
		i++;
	}
}

int	strlenm(t_game	*game)
{
	int	a;
	int	i;
	int	j;

	a = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'M')
				a++;
			j++;
		}
		i++;
	}
	return (a);
}

char	**ft_handel(int k, char *str1)
{
	int		fd;
	char	**str;
	char	*line;
	int		i;

	str = malloc (sizeof(char *) * (k + 1));
	if (!str)
		return (write (1, "Error\n main ft_handel str malloc", 33), NULL);
	fd = open(str1, O_RDONLY);
	if (fd == -1)
		print_error3("Error\n Could not open the specified file.\n", str, fd);
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
	validate_map(str, i, 0, 0);
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
