/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functois_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:45:00 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/10 17:05:43 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_ffftt(t_game *game, int i, int a)
{
	if (a == 1)
	{
		game->map[game->ym[i]][game->xm[i]] = '0';
		game->map[game->ym[i]][game->xm[i] - 1] = 'M';
		game->xm[i] = game->xm[i] - 1;
		if (game->map[game->ym[i]][game->xm[i] - 1] != '0')
			game->n[i] = 1;
	}
	else if (a == 2)
	{
		game->map[game->ym[i]][game->xm[i]] = '0';
		game->map[game->ym[i]][game->xm[i] + 1] = 'M';
		game->xm[i] = game->xm[i] + 1;
		if (game->map[game->ym[i]][game->xm[i] + 1] != '0')
			game->n[i] = 0;
	}
	else
	{
		if (game->n[i] == 1)
			game->n[i] = 0;
		else
			game->n[i] = 1;
	}
}

void	ft_enemy(t_game *game, int i)
{
	if (game->map[game->ym[i]][game->xm[i] + 1] == 'P'
		|| game->map[game->ym[i]][game->xm[i] - 1] == 'P')
		return (ft_free_xm_ym_n(game), ft_free_strct(game), exit(0));
	if (game->map[game->ym[i]][game->xm[i] + 1] == '0' && game->n[i] == 1)
		ft_ffftt(game, i, 2);
	else if (game->map[game->ym[i]][game->xm[i] - 1] == '0'
			&& game->n[i] == 0)
		ft_ffftt(game, i, 1);
	else
		ft_ffftt(game, i, 3);
}

int	moving_enemy(t_game *game)
{
	int			i;
	int			a;
	static int	tem;

	i = 0;
	a = strlenm(game);
	if (tem % 1000 != 0)
		return (tem++, 0);
	while (i < a)
	{
		ft_enemy(game, i);
		i++;
	}
	if (tem == 500000)
		tem = 1000;
	ft_animate_collectible(game);
	return (ft_mlx_imag1(game), tem++, 0);
}
