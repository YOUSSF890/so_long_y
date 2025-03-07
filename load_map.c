/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagzoul <ylagzoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:08:16 by ylagzoul          #+#    #+#             */
/*   Updated: 2025/02/23 14:55:36 by ylagzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_wall(char *inpt, char **str)
{
    int a;
    int j;

    a = 0;
    j = 0;
    while(inpt[j] && inpt[j] != '\n')
    {
        if(inpt[j] == '1')
            a++;
        j++;
    }
    if(a != j)
        print_error("Error\n Map walls are not properly enclosed.", str);
}

int check_map(char *inpt)
{
    int i;

    i = 0;
    while(inpt[i])
    {
        if (inpt[0] == '1' && ( inpt[i] == '1' || inpt[i] == '0' || inpt[i] == 'C' || inpt[i] == 'P' || inpt[i] == 'E' || (inpt[i] == '\n' && inpt[i-1] == '1')))
            i++;
        else
            return(0);
    }
    return(1);
}

int check_player_and_exit_collectible(char *inpt, char c)
{
    int i;
    int a;

    i = 0;
    a = 0;

    while(inpt[i])
    {
        if(inpt[i] == c)
            a++;
        i++;
    }
    return (a);
}

void check_width(char **inpt, int k)
{
    int i;
    int j;
    int t[k];

    i = 0;
    while(inpt[i])
    {
        j = 0;
        while(inpt[i][j])
            j++;
        if(j > 51)
            print_error("Error\n Map width exceeds 51 characters.", inpt);
        if(inpt[i][j-1] != '\n')
            j++;
        t[i] = j;
        i++;
    }
    j = 0;
    while(i > 1)
    {
        if(t[j] != t[j+1])
            print_error("Error\n Inconsistent map width detected.", inpt);
        j++;
        i--;
    }
}

void validate_map(char **input, int k)
{
    int i;
    int j;
    int a;
    int t;

    i = 0;
    j = 0;
    a = 0;
    t = 0;
    while(input[i])
    {
        if(check_map(input[i]))
        {
            if(i == 0 || (k-1 == i && input[i]))
                check_wall(input[i], input);
            j = j + check_player_and_exit_collectible(input[i],'P');
            t = t + check_player_and_exit_collectible(input[i],'E');
            a = a + check_player_and_exit_collectible(input[i],'C');
        }
        else
            print_error("Error\n Invalid map structure.", input);
        i++;
    }
    if(j != 1 || t != 1 || a == 0)
        print_error("Error\n Missing or incorrect count of player, exit, or collectibles.", input);
}

int check_file_ber(char *inpt)
{
    int i;
    int b;
    int a;
    char str[5] = ".ber";

    i = 0;
    b = 0;
    a = 0;
    while(inpt[i])
        i++;
    i = i - 4;
    while(b < 4)
    {
        if(inpt[i + b] == str[b])
            a++;
        b++;
    }
    if(a == 4)
        return(1);
    return (0);
}
