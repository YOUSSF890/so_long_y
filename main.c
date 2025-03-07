#include "so_long.h"

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
        return (0);
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
                ft_free_strct(game);
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
            ft_free_strct(game);
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
    game->steps = 1;
    mlx_key_hook(game->win, moving, game);
    mlx_loop(game->ptr);
    return 0;
}
