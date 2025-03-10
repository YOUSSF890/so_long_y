/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Functions_are_not_included.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:52:48 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/09 17:37:58 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup1(const char *s1)
{
	int		i;
	int		a;
	int		len;
	char	*dst;

	a = 0;
	if (!s1)
		return (NULL);
	while (s1[a])
		a++;
	len = a + 1;
	dst = malloc (sizeof(char) * len);
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	number_of_collectible(char	**inpt)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	j = 0;
	a = 0;
	while (inpt[i])
	{
		j = 0;
		while (inpt[i][j])
		{
			if (inpt[i][j] == 'C')
				a++;
			j++;
		}
		i++;
	}
	return (a);
}

void	player_site(t_game *inpt)
{
	int	i;
	int	j;

	i = 0;
	while (inpt->map[i])
	{
		j = 0;
		while (inpt->map[i][j])
		{
			if (inpt->map[i][j] == 'P')
			{
				inpt->x = j;
				inpt->y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_file_ber(char *inpt)
{
	int		i;
	int		b;
	int		a;
	char	*str;

	str = ".ber";
	i = 0;
	b = 0;
	a = 0;
	while (inpt[i])
		i++;
	i = i - 4;
	while (b < 4)
	{
		if (inpt[i + b] == str[b])
			a++;
		b++;
	}
	if (a == 4)
		return (1);
	return (0);
}

int	ft_file_len(char *str)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	if (!check_file_ber(str))
		print_error2("Error\n Provided file is not a .ber map file.\n");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		print_error2("Error\n Could not open the specified file.\n");
	line = get_next_line(fd);
	if (!line)
		print_error1("Error\n Empty or unreadable file.\n", fd);
	while (line)
	{
		free(line);
		if (i > 32)
			print_error1("Error\n Map height exceeds 32 ines.\n", fd);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}
