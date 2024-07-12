/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vol3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:06:01 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/27 01:20:24 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map4(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (!ft_strchr("10PECX", vars->map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	_fill(char **map, int px, int py)
{
	if (map[py][px] == '1' || map[py][px] == 'X' || map[py][px] == 'V')
		return ;
	map[py][px] = 'V';
	_fill(map, px + 1, py);
	_fill(map, px - 1, py);
	_fill(map, px, py + 1);
	_fill(map, px, py - 1);
}

int	elements_search(char **map, char e)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], e))
			return (1);
		i++;
	}
	return (0);
}
