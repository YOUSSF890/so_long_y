/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:04:56 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/08 15:01:37 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#  define SIZE 64
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "/home/ylagzoul/Desktop/include/mlx/mlx.h"

typedef struct game
{
	char	**map;
	char	**copy;
	int		x;
	int		y;
	int		steps;
	int		size_height;
	int		size_width;
	void	*ptr;
	void	*win;
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*empty;
}			t_game;

int		check_map(char *inpt);//load_map_bonus.c
void	check_wall(char *inpt, char **str);
void	check_width(char **inpt, int k);
void	validate_map(char	**input, int k, int a);
int		check_player_and_exit_collectible(char *inpt, char c);

void	ft_free_copy(t_game *game);//ft_free_bonus.c
void	ft_free_map(t_game *game);
void	ft_free_node(t_game *game);
void	ft_free_strct(t_game *game);

void	print_error(char *inpt, char **str);//ft_print_error_bonus.c
void	print_error1(char *inpt, int fd);
void	print_error2(char *inpt);
void	print_error3(char *inpt, char **str, int fd);

int		number_of_collectible(char **inpt);//Functions_are_not_included_bonus.c
int		ft_file_len(char *str);
int		check_file_ber(char *inpt);
void	player_site(t_game *inpt);
char	*ft_strdup1(const char *s1);

void	copy_map(t_game *game, int k);//ft_functois_bonus.c
void	ft_mlx_imag(t_game *game);
void	ft_mlx_imag1(t_game *game);
int		moving(int key, t_game *game);
void	ft_ft(t_game *game, int y1, int x1);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
char	**ft_handel(int k, char *str1);
void	count_height_width(t_game *game);

#endif