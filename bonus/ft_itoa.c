/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:31:59 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/10 14:46:44 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_size(long int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = count_size(n);
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n == 0)
		str[0] = '0';
	size -= 1;
	while (n > 0)
	{
		str[size] = n % 10 + '0';
		size--;
		n /= 10;
	}
	return (str);
}

int	close_window(t_game *game)
{
	ft_free_xm_ym_n(game);
	ft_free_strct(game);
	exit(0);
	return (0);
}

void	ft_game(t_game *game, int i)
{
	int	a;
	int	nbr;

	a = 0;
	player_site(game);
	copy_map(game, i);
	flood_file(game, game->y, game->x, &a);
	nbr = number_of_collectible(game->copy);
	if (a == 0 || nbr != 0)
	{
		ft_free_node(game);
		print_error2("Error\nThe Player can't win!\n");
	}
	ft_free_copy(game);
	ft_mlx_imag(game);
	a = strlenm(game);
	game->xm = malloc(sizeof(int) * a);
	game->ym = malloc(sizeof(int) * a);
	game->n = malloc(sizeof(int) * a);
	if (!game->xm || !game->ym || !game->n)
	{
		print_error2("Error\nft_game malloc xm or ym or n\n");
		a = close_window(game);
	}
	monster_site(game);
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
		print_error("Error\n Map walls are not properly enclosed.\n", str);
}
