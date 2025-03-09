/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:10:42 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/09 14:05:46 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_file(t_game *game, int y, int x, int	*a)
{
	if (game->copy[y][x + 1] == 'E' || game->copy[y - 1][x] == 'E'
		|| game->copy[y][x - 1] == 'E' || game->copy[y + 1][x] == 'E')
		(*a)++;
	if (game->copy[y][x + 1] == '0' || game->copy[y][x + 1] == 'C')
	{
		game->copy[y][x + 1] = 'Y';
		flood_file(game, y, x + 1, a);
	}
	if (game->copy[y - 1][x] == '0' || game->copy[y - 1][x] == 'C')
	{
		game->copy[y - 1][x] = 'Y';
		flood_file(game, y - 1, x, a);
	}
	if (game->copy[y][x - 1] == '0' || game->copy[y][x - 1] == 'C')
	{
		game->copy[y][x - 1] = 'Y';
		flood_file(game, y, x - 1, a);
	}
	if (game->copy[y + 1][x] == '0' || game->copy[y + 1][x] == 'C')
	{
		game->copy[y + 1][x] = 'Y';
		flood_file(game, y + 1, x, a);
	}
}

void	check_wall(char *inpt, char **str)
{
	int	a;
	int	j;

	a = 0;
	j = 0;
	while (inpt[j] && inpt[j] != '\n')
	{
		if (inpt[j] == '1')
			a++;
		j++;
	}
	if (a != j)
		print_error("Error\n Map walls are not properly enclosed.", str);
}
