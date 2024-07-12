/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vol2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:16:51 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/27 00:06:46 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if there is only one player, exit, collectible
int	check_elements(t_vars *vars)
{
	elements_counter(vars);
	if (vars->player != 1)
	{
		ft_putstr_fd("\033[1;31mError\nWrong number of players\n", 1);
		return (0);
	}
	if (vars->exit != 1)
	{
		ft_putstr_fd("\033[1;31mError\nWrong number of exits\n", 1);
		return (0);
	}
	if (vars->c < 1)
	{
		ft_putstr_fd("\033[1;31mError\nWrong number of collectibles\n", 1);
		return (0);
	}
	if (vars->enemy >= 2)
	{
		ft_putstr_fd("\033[1;31mError\nWrong number of enemies\n", 1);
		return (0);
	}
	return (1);
}

void	save_coordinates(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'P')
	{
		vars->player_x = j;
		vars->player_y = i;
	}
	if (vars->map[i][j] == 'E')
	{
		vars->exit_x = j;
		vars->exit_y = i;
	}
	if (vars->map[i][j] == 'X')
	{
		vars->enemy_x = j;
		vars->enemy_y = i;
	}
}

// parse elements coordinates to vars
void	parse_exp_coordinates(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			save_coordinates(vars, i, j);
			j++;
		}
		i++;
	}
}

// checker for map
int	map_checker(t_vars *vars)
{
	if (!vars->map)
		return (0);
	if (!check_map1(vars))
		return (0);
	if (!check_map2(vars))
		return (0);
	if (!check_map3(vars))
		return (0);
	if (!check_map4(vars))
		return (0);
	if (!check_elements(vars))
		return (0);
	else
		parse_exp_coordinates(vars);
	flood_fill(vars);
	return (1);
}

int	line_counter(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
		i++;
	return (i);
}
