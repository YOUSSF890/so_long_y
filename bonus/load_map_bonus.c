/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:29:53 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/11 11:00:43 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map(char *inpt)
{
	int	i;

	i = 0;
	while (inpt[i])
	{
		if (inpt[0] == '1' && (inpt[i] == '1' || inpt[i] == '0'
				|| inpt[i] == 'C' || inpt[i] == 'M' || inpt[i] == 'P'
				|| inpt[i] == 'E' || (inpt[i] == '\n' && inpt[i - 1] == '1')))
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_player_and_exit_collectible(char *inpt, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (inpt[i])
	{
		if (inpt[i] == c)
			a++;
		i++;
	}
	return (a);
}

void	check1(int *t, char **inpt, int nbr_line)
{
	int	j;

	j = 0;
	while (nbr_line > 1)
	{
		if (t[j] != t[j + 1])
		{
			free(t);
			print_error("Error\n Inconsistent map width detected.\n", inpt);
		}
		j++;
		nbr_line--;
	}
}

void	check_width(char **inpt, int nbr_line)
{
	int	*t;
	int	i;
	int	j;

	i = 0;
	t = malloc(sizeof(int) * nbr_line);
	while (inpt[i])
	{
		j = 0;
		while (inpt[i][j])
			j++;
		if (j > 61)
		{
			free(t);
			print_error("Error\n Map width exceeds 61 characters.\n", inpt);
		}
		if (inpt[i][j - 1] != '\n')
			j++;
		t[i] = j;
		i++;
	}
	check1(t, inpt, nbr_line);
	free(t);
}

void	validate_map(char **input, int nbr_line, int a, int q)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	j = 0;
	t = 0;
	while (input[i])
	{
		if (check_map(input[i]))
		{
			if (i == 0 || (nbr_line - 1 == i && input[i]))
				check_wall(input[i], input);
			j = j + check_player_and_exit_collectible(input[i], 'P');
			t = t + check_player_and_exit_collectible(input[i], 'E');
			a = a + check_player_and_exit_collectible(input[i], 'C');
			q = q + check_player_and_exit_collectible(input[i], 'M');
		}
		else
			print_error("Error\n Invalid map structure.\n", input);
		i++;
	}
	if (j != 1 || t != 1 || a == 0 || q == 0)
		print_error("Error\n player or exit or collectibles.\n", input);
}
