/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:57:08 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/11 12:45:47 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_file(t_game *game, int y, int x, int *a);

void	ft_ft(t_game *game, int y1, int x1)
{
	int	nbr;

	if (game->map[y1][x1] != '1')
	{
		if (game->map[y1][x1] == 'E' || game->map[y1][x1] == 'M')
		{
			nbr = number_of_collectible(game->map);
			if (nbr == 0 || game->map[y1][x1] == 'M')
			{
				ft_free_xm_ym_n(game);
				ft_free_strct(game);
				exit(0);
			}
			return ;
		}
		else
		{
			game->map[game->y][game->x] = '0';
			game->y = y1;
			game->x = x1;
			game->map[y1][x1] = 'P';
			game->steps = game->steps + 1;
		}
	}
}

int	moving(int key, t_game *game)
{
	if (key == 115 || key == 119 || key == 100 || key == 97 || key == 65307)
	{
		game->c += 1;
		if (key == 65307)
		{
			ft_free_xm_ym_n(game);
			ft_free_strct(game);
			exit(0);
		}
		else if (key == 100)
			ft_ft(game, game->y, game->x + 1);
		else if (key == 119)
			ft_ft(game, game->y - 1, game->x);
		else if (key == 97)
			ft_ft(game, game->y, game->x - 1);
		else if (key == 115)
			ft_ft(game, game->y + 1, game->x);
		ft_mlx_imag1(game);
	}
	return (0);
}

void	ft_animate_collectible(t_game *game)
{
	if (game->collectible == game->collectible0)
	{
		game->collectible0 = game->collectible1;
	}
	else if (game->collectible1 == game->collectible0)
	{
		game->collectible0 = game->collectible2;
	}
	else if (game->collectible2 == game->collectible0)
	{
		game->collectible0 = game->collectible3;
	}
	else
		game->collectible0 = game->collectible;
}

int	main(int ac, char *argv[])
{
	char	**string;
	t_game	*game;
	int		nbr_line;

	if (ac != 2)
		return (write(2, "Error\n No map file provided.\n", 29), 0);
	nbr_line = ft_file_len(argv[1]);
	string = ft_handel(nbr_line, argv[1]);
	if (!string)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		print_error("Error\nmalloc return NULL\n", string);
	game->map = string;
	game->steps = 0;
	game->c = 0;
	ft_game(game, nbr_line);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, moving, game);
	mlx_loop_hook(game->ptr, moving_enemy, game);
	mlx_loop(game->ptr);
	ft_free_xm_ym_n(game);
	ft_free_strct(game);
	exit(0);
}
