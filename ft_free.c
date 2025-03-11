/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:55:44 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/11 12:46:13 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_strct(t_game *game)
{
	int	i;

	if (game->player != NULL)
		mlx_destroy_image(game->ptr, game->player);
	if (game->wall != NULL)
		mlx_destroy_image(game->ptr, game->wall);
	if (game->collectible != NULL)
		mlx_destroy_image(game->ptr, game->collectible);
	if (game->exit != NULL)
		mlx_destroy_image(game->ptr, game->exit);
	if (game->empty != NULL)
		mlx_destroy_image(game->ptr, game->empty);
	mlx_destroy_window(game->ptr, game->win);
	mlx_destroy_display(game->ptr);
	free(game->ptr);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	exit(1);
}

void	ft_free_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->copy[i])
	{
		free(game->copy[i]);
		i++;
	}
	free(game->copy);
}

void	ft_free_node(t_game *game)
{
	int	i;

	i = 0;
	while (game->copy[i])
	{
		free(game->copy[i]);
		i++;
	}
	free (game->copy);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
}
