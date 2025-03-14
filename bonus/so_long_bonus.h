/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:18:58 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/11 13:27:20 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "/home/ylagzoul/Desktop/include/mlx/mlx.h"

typedef struct game
{
	char	**map;
	char	**copy;
	int		x;
	int		y;
	int		c;
	int		*n;
	int		*xm;
	int		*ym;
	int		steps;
	int		size_height;
	int		size_width;
	void	*ptr;
	void	*win;
	void	*wall;
	void	*player;
	void	*collectible0;
	void	*collectible;
	void	*collectible1;
	void	*collectible2;
	void	*collectible3;
	void	*exit;
	void	*empty;
	void	*right;
}			t_game;

# define SIZE 64

int		check_map(char *inpt);
void	check_width(char **inpt, int k);
void	check1(int *t, char **inpt, int i);
void	validate_map(char **input, int k, int a, int q);
int		check_player_and_exit_collectible(char *inpt, char c);

void	check_wall(char *inpt, char **str);

void	ft_free_copy(t_game *game);
void	ft_free_map(t_game *game);
void	ft_free_node(t_game *game);
void	ft_free_strct(t_game *game);
void	ft_free_img_collectible(t_game *game);

void	print_error(char *inpt, char **str);
void	print_error1(char *inpt, int fd);
void	print_error2(char *inpt);
void	print_error3(char *inpt, char **str, int fd);
void	ft_free_xm_ym_n(t_game *game);

int		number_of_collectible(char **inpt);
int		ft_file_len(char *str);
int		check_file_ber(char *inpt);
void	player_site(t_game *inpt);
char	*ft_strdup1(const char *s1);

void	copy_map(t_game *game, int k);
void	monster_site(t_game *game);
int		strlenm(t_game *game);
void	count_height_width(t_game *game);
char	**ft_handel(int k, char *str1);

void	ft_ft(t_game *game, int y1, int x1);
int		moving(int key, t_game *game);
void	ft_animate_collectible(t_game *game);

void	ft_ffftt(t_game *game, int i, int a);
void	ft_enemy(t_game *game, int i);
int		moving_enemy(t_game *game);

void	ft_mlx_imag(t_game *game);
void	ft_mlx_imag1(t_game *game);
int		moving(int key, t_game	*game);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);
void	ft_mlx_put_image_to_window(t_game *game, int x, int y);
int		close_window(t_game *game);
char	*ft_itoa(int n);
int		count_size(long int n);
void	ft_game(t_game *game, int i);
void	flood_file(t_game *game, int y, int x, int *a);
void	ft_animate_collectible(t_game *game);

#endif