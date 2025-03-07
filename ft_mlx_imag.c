/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_imag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:51:04 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/03/05 17:07:43 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void count_height_width(t_game *game)
{
    int x;
    int y;
    
    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x] && game->map[y][x] != '\n')
            x++;
        y++;
    }
    game->size_height = y * 64;
    game->size_width = x * 64;
}
void ft_mlx_imag(t_game *game)
{
    int x;
    int y;

    count_height_width(game);
    game->ptr = mlx_init();
    if(!game->ptr)
        return(write(2,"Error\nmlx_init return NULL",26),ft_free_map(game));
    game->win = mlx_new_window(game->ptr, game->size_width, game->size_height, "so_long");
    if(!game->win)
    {
        write(2,"Error\nmlx_new_window return NULL", 33);
        mlx_destroy_display(game->ptr);
        free(game->ptr);
        ft_free_map(game);
    }
    game->wall = mlx_xpm_file_to_image(game->ptr,"textures/wall_imag.xpm",&x,&x);
    game->player = mlx_xpm_file_to_image(game->ptr,"textures/player.xpm",&x,&x);
    game->collectible = mlx_xpm_file_to_image(game->ptr,"textures/collectible_imag.xpm",&x,&x);
    game->exit = mlx_xpm_file_to_image(game->ptr,"textures/exit_imag.xpm",&x,&x);
    game->empty = mlx_xpm_file_to_image(game->ptr,"textures/empty.xpm",&x,&x);
    game->bg = mlx_new_image(game->ptr, SIZE, SIZE);
    if (!game->player || !game->exit || !game->wall || !game->collectible || !game->bg || !game->empty)
        ft_free_strct(game);
    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->ptr, game->win, game->wall, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'P')
                mlx_put_image_to_window(game->ptr, game->win, game->player, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'C')
                mlx_put_image_to_window(game->ptr, game->win, game->collectible, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'E')
                mlx_put_image_to_window(game->ptr, game->win, game->exit, x * SIZE, y * SIZE);
            else if(game->map[y][x] == '0')
                mlx_put_image_to_window(game->ptr, game->win, game->empty, x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}

void ft_mlx_imag1(t_game *game)
{
    int x;
    int y;

    count_height_width(game);
    game->player = mlx_xpm_file_to_image(game->ptr,"textures/player.xpm",&x,&y);
    if (!game->player)
        return(ft_free_strct(game));
    y = 0;
    while(game->map[y])
    {
        x = 0;
        while(game->map[y][x])
        {
            if(game->map[y][x] == '1')
                mlx_put_image_to_window(game->ptr, game->win, game->wall, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'P')
                mlx_put_image_to_window(game->ptr, game->win, game->player, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'C')
                mlx_put_image_to_window(game->ptr, game->win, game->collectible, x * SIZE, y * SIZE);
            else if(game->map[y][x] == 'E')
                mlx_put_image_to_window(game->ptr, game->win, game->exit, x * SIZE, y * SIZE);
            else if(game->map[y][x] == '0')
                mlx_put_image_to_window(game->ptr, game->win, game->empty, x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}