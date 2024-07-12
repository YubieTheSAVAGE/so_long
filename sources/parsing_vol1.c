/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vol1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:14:04 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/27 00:10:55 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// flood fill algorithm
void	fill(char **map, int px, int py)
{
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'E'
		|| map[py][px] == 'M')
		return ;
	map[py][px] = 'M';
	fill(map, px + 1, py);
	fill(map, px - 1, py);
	fill(map, px, py + 1);
	fill(map, px, py - 1);
}

// check first and last line
int	check_map1(t_vars *vars)
{
	int	j;

	j = 0;
	while (vars->map[0][j])
	{
		if (vars->map[0][j] != '1')
		{
			ft_putstr_fd("\033[1;31mError\nMap is invalid\n", 1);
			return (0);
		}
		j++;
	}
	j = 0;
	while (vars->map[line_counter(vars) - 1][j])
	{
		if (vars->map[line_counter(vars) - 1][j] != '1')
		{
			ft_putstr_fd("\033[1;31mError\nMap is invaid\n", 1);
			return (0);
		}
		j++;
	}
	return (1);
}

// check if map is rectangular
int	check_map2(t_vars *vars)
{
	int		i;
	size_t	len;

	len = ft_strlen(vars->map[0]);
	i = 0;
	while (vars->map[i])
	{
		if (ft_strlen(vars->map[i]) != len)
		{
			ft_putstr_fd("\033[1;31mError\nMap is not rectangular\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

// check if map is closed
int	check_map3(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i][0] != '1' || vars->map[i][ft_strlen(vars->map[i])
			- 1] != '1')
		{
			ft_putstr_fd("\033[1;31mError\nMap is invaid\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

// count elements: enemies, collectibles, player, exit
void	elements_counter(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'E')
				vars->exit++;
			if (vars->map[i][j] == 'X')
				vars->enemy++;
			if (vars->map[i][j] == 'C')
				vars->c++;
			if (vars->map[i][j] == 'P')
				vars->player++;
			j++;
		}
		i++;
	}
	vars->width = j;
	vars->height = i;
}
