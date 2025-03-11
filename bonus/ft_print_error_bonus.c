/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:13:36 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/11 12:42:51 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_error2(char *inpt)
{
	int	i;

	i = 0;
	while (inpt[i])
	{
		write (2, &inpt[i], 1);
		i++;
	}
	exit(1);
}

void	print_error1(char *inpt, int fd)
{
	int	i;

	i = 0;
	get_next_line(-1);
	while (inpt[i])
	{
		write (2, &inpt[i], 1);
		i++;
	}
	close(fd);
	exit(1);
}

void	print_error3(char *inpt, char **str, int fd)
{
	int	i;

	i = 0;
	while (inpt[i])
	{
		write (2, &inpt[i], 1);
		i++;
	}
	free(str);
	close(fd);
	exit(1);
}

void	print_error(char *inpt, char **str)
{
	int	i;

	i = 0;
	while (inpt[i])
	{
		write (2, &inpt[i], 1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	exit(1);
}

void	ft_free_xm_ym_n(t_game *game)
{
	free(game->xm);
	free(game->ym);
	free(game->n);
}
