#include "so_long.h"

char	*ft_strdup1(const char *s1);
void	flood_file(t_game *game, int y, int x, int *a);
void	ft_free_node(t_game *game);

void	ft_ft(t_game *game, int y1, int x1)
{
	int nbr;

	if(game->map[y1][x1] != '1')
	{
		if (game->map[y1][x1] == 'E')
		{
			nbr = Number_of_collectible(game->map);
			if (nbr == 0)
			{
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
			printf("%d\n", game->steps); // peintf(); eroor | write();
			game->steps = game->steps + 1;
		}
	}
}

int	moving(int key, t_game *game)
{
	if (key == 115 || key == 119 || key == 100 || key == 97 || key == 65307)
	{
		if (key == 65307)
		{
			ft_free_strct(game);
		}
		else if (key == 100)
				ft_ft(game, game->y,game->x + 1);
		else if (key == 119)
				ft_ft(game, game->y - 1,game->x);
		else if (key == 97)
				ft_ft(game, game->y,game->x - 1);
		else if (key == 115)
				ft_ft(game, game->y + 1, game->x);
		ft_mlx_imag1(game, 0);
	}
	return (0);
}

int	main(int ac, char *argv[])
{
	char	**string;
	t_game	*game;
	int		i;
	int		a;
	int		nbr;

	if (ac < 2)
		return (write (2, "Error\n No map file provided.\n", 29), 0); 
	a = 0;
	i = ft_file_len(argv[1]);
	string = ft_handel(i, argv[1]);
	if (!string)
		return (0);
	game = malloc(sizeof(t_game));
	if (!game)
		print_error("Error\nmalloc return NULL\n", string);
	game->map = string;
	Player_site(game);
	copy_map(game, i);
	flood_file(game, game->y, game->x, &a);
	nbr = Number_of_collectible(game->copy);
	if (a == 0 || nbr != 0)
	{
		ft_free_node(game);
		print_error2("Error\nThe Player can't win!\n");
	}
	ft_free_copy(game);
	ft_mlx_imag(game);
	game->steps = 1;
	mlx_key_hook(game->win, moving, game);
	mlx_loop(game->ptr);
	ft_free_strct(game);
}
