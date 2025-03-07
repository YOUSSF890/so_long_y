#include "so_long_bonus.h"

char    *ft_strdup1(const char *s1);
void flood_file(t_game *game, int y , int x,int *a);
void ft_free_node(t_game *game);

int ft_file_len(char *str)
{
    int i;
    int fd;
    char *line;

    i = 0;
    if (!check_file_ber(str))
        print_error2("Error\n Provided file is not a .ber map file.\n");
    fd = open(str, O_RDONLY);
    if(fd == -1)
        print_error2("Error\n Could not open the specified file.\n");
    line = get_next_line(fd);
    if (!line)
        print_error1("Error\n Empty or unreadable file.\n",fd);
    while(line)
    {
        free(line);
        if(i == 27)
            print_error1("Error\n Map height exceeds 27 ines.\n",fd);
        line = get_next_line(fd);
        i++;
    }
    close(fd);
    return (i);
}

char **ft_handel(int k, char *str1)
{
    int fd;
    char **str;
    char *line;
    int i;

    str = malloc(sizeof(char *) * (k + 1));
    if(!str)
        return (write(1 ,"Error\n main ft_handel str malloc", 33), NULL);
    fd = open(str1, O_RDONLY);
    if (fd == -1)
        print_error3("Error\n Could not open the specified file.\n", str, fd);
    line = get_next_line(fd);
    if (!line)
        print_error3("Error\n Empty or unreadable file.\n", str, fd);
    i = 0;
    while(line)
    {
        str[i] = line;
        line = get_next_line(fd);
        i++;
    }
    str[i] = NULL;
    close(fd);
    validate_map(str, i);
    check_width(str, i);
    return (str);
}

void copy_map(t_game *game, int k)
{
    int i;
    
    i = 0;
    game->copy = malloc(sizeof(char *) * (k + 1));
    if (!game->copy)
    {
        write(2,"Error\nmalloc return NULL",24);
        ft_free_map(game);
    }
    while(game->map[i])
    {
        game->copy[i] = ft_strdup1(game->map[i]);
        if (!game->copy[i])
        {
            ft_free_node(game);
            exit(1);
        }
        i++;
    }
    game->copy[i] = NULL;
}
void ft_ft(t_game *game, int y1, int x1)
{
    int nbr;
    if(game->map[y1][x1] != '1')
    {
        if(game->map[y1][x1] == 'E')
        {
            nbr = Number_of_collectible(game->map);
            if(nbr == 0)
            {
                ft_free_xm_ym_n(game);
                ft_free_strct(game);
            }
            return ;
        }
        else
        {
            game->map[game->y][game->x] = '0';
            game->y = y1;
            game->x = x1;
            game->map[y1][x1] = 'P';
            printf("%d\n",game->steps);
            game->steps = game->steps + 1;
        }
    }
}


int moving(int key, t_game *game)
{
    if (key == 115 || key == 119 || key == 100 || key == 97 || key == 65307)
    {
        if (key == 65307)
        {
            ft_free_xm_ym_n(game);
            ft_free_strct(game);
        }
        else if (key == 100)//d
                ft_ft(game, game->y,game->x+1);
        else if (key == 119)//w
                ft_ft(game, game->y-1,game->x);
        else if (key == 97)//a
                ft_ft(game, game->y,game->x-1);
        else if (key == 115)//s
                ft_ft(game, game->y+1,game->x);
        ft_mlx_imag1(game);
    }
    return(0);
}

int strlenm(t_game *game)
{
    int a = 0;
    int i = 0;
    int j = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == 'M')
                a++;
            j++;
        }
        i++;
    }
    return(a);
}

int moving1(t_game *game)
{
    int i = 0;
    int a;
    a = strlenm(game);
    while(i < a)
    {
        if(game->map[game->ym[i]][game->xm[i] + 1] == 'P' || game->map[game->ym[i]][game->xm[i] - 1] == 'P')
        {
            ft_free_xm_ym_n(game);
            ft_free_strct(game);
        }
        if(game->map[game->ym[i]][game->xm[i] + 1] == '0' && game->n[i] == 1)
        {
            game->map[game->ym[i]][game->xm[i]] = '0';
            game->map[game->ym[i]][game->xm[i] + 1] = 'M';
            game->xm[i] = game->xm[i] + 1;
            if(game->map[game->ym[i]][game->xm[i] + 1] != '0')
                game->n[i] = 0;
        }
        else if(game->map[game->ym[i]][game->xm[i] - 1] == '0' && game->n[i] == 0)
        {
            game->map[game->ym[i]][game->xm[i]] = '0';
            game->map[game->ym[i]][game->xm[i] - 1] = 'M';
            game->xm[i] = game->xm[i] - 1;
            if(game->map[game->ym[i]][game->xm[i] - 1] != '0')
                game->n[i] = 1;
        }
        else
        {
            if(game->n[i] == 1)
                game->n[i] = 0;
            else
                game->n[i] = 1;
        }
        i++;
    }
    ft_mlx_imag1(game);
    i = 0;
    while(i < 10000000)
        i++;
    return(0);
}



void monster_site(t_game *game)
{
    int i = 0;
    int j = 0;
    int a = 0;
    while(game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if(game->map[i][j] == 'M')
            {
                game->xm[a] = j;
                game->ym[a] = i;
                game->n[a] = 1;
                a++;
            }
            j++;
        }
        i++;
    }
}

void ft_free_xm_ym_n(t_game *game)
{
    free(game->xm);
    free(game->ym);
    free(game->n);
}

int main(int ac, char *argv[])
{
    char **string;
    t_game *game;
    int i;
    int a;
    int nbr;

    if (ac < 2)
        return (write(2,"Error\n No map file provided.\n",29), 1);

    a = 0;
    i = ft_file_len(argv[1]);
    string = ft_handel(i, argv[1]);
    if(!string)
        return(0);
    game = malloc(sizeof(t_game));
    if(!game)
        print_error("Error\nmalloc return NULL",string);
    game->map = string;
    Player_site(game);
    copy_map(game, i);
    flood_file(game, game->y, game->x, &a);
    nbr = Number_of_collectible(game->copy);
    if(a == 0 || nbr != 0)
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
    if(!game->xm || !game->ym || !game->n)
    {
        ft_free_xm_ym_n(game);
        ft_free_strct(game);
    }
    monster_site(game);
    game->steps = 1;
    mlx_loop_hook(game->ptr, moving1, game);
    mlx_key_hook(game->win, moving, game);
    mlx_loop(game->ptr);
    ft_free_xm_ym_n(game);
    ft_free_strct(game);
}
