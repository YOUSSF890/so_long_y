/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_imag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:51:04 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/10 17:19:53 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_put_image_to_window(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window
			(game->ptr, game->win, game->wall, x * SIZE, y * SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window
			(game->ptr, game->win, game->player, x * SIZE, y * SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window
			(game->ptr, game->win, game->collectible, x * SIZE, y * SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window
			(game->ptr, game->win, game->exit, x * SIZE, y * SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window
			(game->ptr, game->win, game->empty, x * SIZE, y * SIZE);
}

void	ft_mlx_imag1(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	count_height_width(game);
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_mlx_put_image_to_window(game, x, y);
			x++;
		}
		y++;
	}
}

void	ft_mlx_xpm_file_to_image(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image
		(game->ptr, "textures/wall_imag.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image
		(game->ptr, "textures/player.xpm", &x, &y);
	game->collectible = mlx_xpm_file_to_image
		(game->ptr, "textures/collectible_imag.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image
		(game->ptr, "textures/exit_imag.xpm", &x, &y);
	game->empty = mlx_xpm_file_to_image
		(game->ptr, "textures/empty.xpm", &x, &y);
	if (!game->player || !game->exit || !game->wall
		|| !game->collectible || !game->empty)
	{
		write (2, "Error\n mlx_xpm_file_to_image\n", 30);
		ft_free_strct(game);
		exit(1);
	}
	ft_mlx_imag1(game);
}

void	ft_mlx_imag(t_game *game)
{
	count_height_width(game);
	game->ptr = mlx_init();
	if (!game->ptr)
	{
		write (2, "Error\nmlx_init return NULL\n", 28);
		ft_free_map(game);
	}
	game->win = mlx_new_window
		(game->ptr, game->size_width, game->size_height, "/so_long");
	if (!game->win)
	{
		write(2, "Error\nmlx_new_window return NULL\n", 34);
		mlx_destroy_display(game->ptr);
		free(game->ptr);
		ft_free_map(game);
	}
	ft_mlx_xpm_file_to_image(game);
}
