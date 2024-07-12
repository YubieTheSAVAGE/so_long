/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loader_vol0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:40:19 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 02:24:23 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_args(t_vars *vars)
{
	vars->map = NULL;
	vars->player = 0;
	vars->player_x = 0;
	vars->player_y = 0;
	vars->player_direction = 'r';
	vars->player_moves = 0;
	vars->c = 0;
	vars->exit = 0;
	vars->exit_x = 0;
	vars->exit_y = 0;
	vars->enemy = 0;
	vars->enemy_x = 0;
	vars->enemy_y = 0;
	vars->enemy_direction = 'l';
	vars->width = 0;
	vars->height = 0;
}

// draw in window
void	ass_to_window(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[1], y * 32,
			x * 32);
	else if (vars->map[x][y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[0], y * 32,
			x * 32);
	else if (vars->map[x][y] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ass_u[0], y
			* 32, x * 32);
	else if (vars->map[x][y] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_ass, y * 32, x
			* 32);
	else if (vars->map[x][y] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->c_ass[0], y * 32, x
			* 32);
	else if (vars->map[x][y] == 'X')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemey_ass_l[1], y
			* 32, x * 32);
}

// start displaying
void	draw_ass(t_vars *vars)
{
	int	i;
	int	j;

	register_ass_paths(vars);
	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			ass_to_window(vars, i, j);
			j++;
		}
		i++;
	}
}
