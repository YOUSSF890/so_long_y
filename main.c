/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:47:08 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/10 17:18:12 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_file(t_game *game, int y, int x, int *a);

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	ft_ft(t_game *game, int y1, int x1)
{
	int	nbr;

	if (game->map[y1][x1] != '1')
	{
		if (game->map[y1][x1] == 'E')
		{
			nbr = number_of_collectible(game->map);
			if (nbr == 0)
			{
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
			ft_putnbr(game->steps);
			write (1, "\n", 1);
			game->steps = game->steps + 1;
		}
	}
}

int	moving(int key, t_game *game)
{
	if (key == 115 || key == 119 || key == 100 || key == 97 || key == 65307)
	{
		if (key == 65307)
		{
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

void	ft_game(t_game *game, int i)
{
	int		a;
	int		nbr;

	a = 0;
	player_site(game);
	copy_map(game, i);
	flood_file(game, game->y, game->x, &a);
	nbr = number_of_collectible(game->copy);
	if (a == 0 || nbr != 0)
	{
		ft_free_node(game);
		print_error2("Error\n The Player can't win!\n");
	}
	ft_free_copy(game);
}

int	main(int ac, char *argv[])
{
	char	**string;
	t_game	*game;
	int		i;

	if (ac < 2)
		return (write(2, "Error\n No map file provided.\n", 29), 0);
	i = ft_file_len(argv[1]);
	string = ft_handel(i, argv[1]);
	if (!string)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		print_error("Error\nmalloc return NULL\n", string);
	game->map = string;
	ft_game(game, i);
	ft_mlx_imag(game);
	game->steps = 1;
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, moving, game);
	mlx_loop(game->ptr);
	ft_free_strct(game);
	exit(0);
}
