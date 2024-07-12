/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:17:27 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 03:00:41 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	event_handler(int key, t_vars *vars)
{
	if (key == 65307)
	{
		destroy_game(vars);
	}
	else if (key == 119 || key == 65362)
		move_player(vars, 0, -1);
	else if (key == 97 || key == 65361)
		move_player(vars, -1, 0);
	else if (key == 115 || key == 65364)
		move_player(vars, 0, 1);
	else if (key == 100 || key == 65363)
		move_player(vars, 1, 0);
	return (1);
}

void	move_to_position(t_vars *vars, int x, int y)
{
	if (x == 1)
		vars->player_direction = 'r';
	else if (x == -1)
		vars->player_direction = 'l';
	else if (y == 1)
		vars->player_direction = 'd';
	else if (y == -1)
		vars->player_direction = 'u';
	vars->map[vars->player_y][vars->player_x] = '0';
	vars->player_x += x;
	vars->player_y += y;
	vars->map[vars->player_y][vars->player_x] = 'P';
	print_moves(vars);
}

void	move_player(t_vars *vars, int x, int y)
{
	if (vars->player_x + x < vars->width - 1 && vars->player_y
		+ y < vars->height - 1 && vars->player_y + y > 0 && vars->player_x
		+ x > 0)
	{
		if (vars->map[vars->player_y + y][vars->player_x + x] == '0')
			move_to_position(vars, x, y);
		else if (vars->map[vars->player_y + y][vars->player_x + x] == 'C')
		{
			move_to_position(vars, x, y);
			(vars->c)--;
		}
		else if (vars->map[vars->player_y + y][vars->player_x + x] == 'E'
			&& vars->c == 0)
		{
			move_to_position(vars, x, y);
			destroy_game(vars);
		}
		else if (vars->map[vars->player_y + y][vars->player_x + x] == 'X')
		{
			destroy_game(vars);
		}
	}
}

int	render_map(t_vars *vars)
{
	if (m_frames_calculator())
		move_enemy(vars);
	draw_ass_animated(vars);
	return (0);
}
