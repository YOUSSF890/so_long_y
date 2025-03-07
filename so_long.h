#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>
// # include "mlx/mlx.h"
// #include "/home/ylagzoul/Desktop/include/mlx/mlx.h"

typedef struct game
{
	char    **map;
    char    **copy;
    int     x;
    int     y;
    int     steps;
    int     size_height;
    int     size_width;
    void    *img;
    void    *ptr;
    void    *win;
    void    *wall;
    void    *player;
    void    *collectible;
    void    *exit;
    void    *bg;
    void    *empty;

}           t_game;

# define SIZE 64

void ft_mlx_imag(t_game *game);
void ft_mlx_imag1(t_game *game);
void ft_free_copy(t_game *game);
void ft_free_strct(t_game *game);
int moving(int key, t_game *game);
void ft_ft(t_game *game, int y1, int x1);
void ft_free_map(t_game *game);


size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);
char	*get_next_line(int fd);

int Number_of_collectible(char **inpt);
void Player_site(t_game *inpt);
void check_wall(char *inpt, char **str);
int check_map(char *inpt);
int check_player_and_exit_collectible(char *inpt, char c);
void check_width(char **inpt, int k);
void validate_map(char **input, int k);
int check_file_ber(char *inpt);
void print_error(char *inpt, char **str);
void print_error3(char *inpt, char **str,int fd);
void print_error1(char *inpt, int fd);
void print_error2(char *inpt);
int ft_file_len(char *str);
char **ft_handel(int k, char *str1);
void copy_map(t_game *game, int k);
char    *ft_strdup1(const char *s1);
void file(t_game *game, int y , int x,int *a);

#endif