#include "so_long.h"

char    *ft_strdup1(const char *s1)
{
	int		i;
	int		a;
	int		len;
	char	*dst;

	a = 0;
    // if (!s1)
    //     return (NULL);

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
void ft_free_strct(t_game *game)
{
    int i;
    if(game->player != NULL)
        mlx_destroy_image(game->ptr, game->player);
    if(game->wall != NULL)
        mlx_destroy_image(game->ptr, game->wall);
    if(game->collectible != NULL)
        mlx_destroy_image(game->ptr, game->collectible);
    if(game->exit != NULL)
        mlx_destroy_image(game->ptr, game->exit);
    if(game->bg != NULL)
        mlx_destroy_image(game->ptr, game->bg);
    mlx_destroy_window(game->ptr, game->win);
    mlx_destroy_display(game->ptr);
    free(game->ptr);
    i = 0;
    while(game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    free(game);
    exit(1);
}
void print_error2(char *inpt)
{
    int i;

    i = 0;
    while(inpt[i])
    {
        write(2,&inpt[i],1);
        i++;
    }
    exit(1);
}

void print_error1(char *inpt, int fd)
{
    int i;

    i = 0;
    get_next_line(-1);
    while(inpt[i])
    {
        write(2,&inpt[i],1);
        i++;
    }
    close(fd);
    exit(1);
}

void ft_free_map(t_game *game)
{
    int i;

    i = 0;
    while(game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    free(game);
    exit(1);
}

void ft_free_copy(t_game *game)
{
    int i;

    i = 0;
    while(game->copy[i])
    {
        free(game->copy[i]);
        i++;
    }
    free(game->copy);
}
void ft_free_node(t_game *game)
{
    int i;

    i = 0;
    while(game->copy[i])
    {
        free(game->copy[i]);
        i++;
    }
    free(game->copy);
    i = 0;
    while(game->map[i])
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    free(game);
}


void print_error3(char *inpt, char **str,int fd)
{
    int i;

    i = 0;
    while(inpt[i])
    {
        write(2,&inpt[i],1);
        i++;
    }
    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    close(fd);
    exit(1);
}
void print_error(char *inpt, char **str)
{
    int i;

    i = 0;
    while(inpt[i])
    {
        write(2,&inpt[i],1);
        i++;
    }
    i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
    exit(1);
}

int Number_of_collectible(char **inpt)
{
    int i;
    int j;
    int a;

    i = 0;
    j = 0;
    a = 0;
    while(inpt[i])
    {
        j = 0;
        while(inpt[i][j])
        {
            if(inpt[i][j] == 'C')
                a++;
            j++;
        }
        i++;
    }
    return (a);
}

void Player_site(t_game *inpt)
{
    int i;
    int j;

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
