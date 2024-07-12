/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_vol1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:08:17 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 02:23:19 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_wall(int x, int y, t_vars *vars)
{
	if (x < 0 || x >= vars->width || y < 0 || y >= vars->height)
		return (1);
	if (vars->map[y][x] == '1' || vars->map[y][x] == 'E'
		|| vars->map[y][x] == 'C')
		return (1);
	return (0);
}

void	move_enemy(t_vars *vars)
{
	int	distance_x;
	int	distance_y;

	distance_x = vars->player_x - vars->enemy_x;
	distance_y = vars->player_y - vars->enemy_y;
	if (abs(distance_x) > abs(distance_y))
	{
		if (distance_x > 0 && !is_wall(vars->enemy_x + 1, vars->enemy_y, vars))
			apply_enemy_move(vars, vars->enemy_x + 1, vars->enemy_y);
		else if (distance_x < 0 && !is_wall(vars->enemy_x - 1, vars->enemy_y,
				vars))
			apply_enemy_move(vars, vars->enemy_x - 1, vars->enemy_y);
	}
	else
	{
		if (distance_y > 0 && !is_wall(vars->enemy_x, vars->enemy_y + 1, vars))
			apply_enemy_move(vars, vars->enemy_x, vars->enemy_y + 1);
		else if (distance_y < 0 && !is_wall(vars->enemy_x, vars->enemy_y - 1,
				vars))
			apply_enemy_move(vars, vars->enemy_x, vars->enemy_y - 1);
	}
}

void	apply_enemy_move(t_vars *vars, int x, int y)
{
	if (vars->enemy_x > x)
		vars->enemy_direction = 'l';
	else if (vars->enemy_x < x)
		vars->enemy_direction = 'r';
	else if (vars->enemy_y > y)
		vars->enemy_direction = 'u';
	else if (vars->enemy_y < y)
		vars->enemy_direction = 'd';
	if (vars->map[y][x] == 'P')
		destroy_game(vars);
	vars->map[vars->enemy_y][vars->enemy_x] = '0';
	vars->enemy_x = x;
	vars->enemy_y = y;
	vars->map[vars->enemy_y][vars->enemy_x] = 'X';
}
