/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:34:35 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/08 13:49:10 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_file(t_game *game, int y, int x, int *a)
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
