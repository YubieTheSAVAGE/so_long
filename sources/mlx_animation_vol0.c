/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation_vol0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:33:19 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 02:20:07 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	animate_c(t_vars *vars, int x, int y)
{
	static int	i;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[1], y * 32, x
		* 32);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->c_ass[i], y * 32, x
		* 32);
	if (c_frames_calculator())
	{
		i++;
		if (i >= 6)
			i = 0;
	}
}

void	animate_player(t_vars *vars, int x, int y)
{
	static int	i;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[1], y * 32, x
		* 32);
	if (vars->player_direction == 'r')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ass_r[i], y
			* 32, x * 32);
	else if (vars->player_direction == 'l')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ass_l[i], y
			* 32, x * 32);
	else if (vars->player_direction == 'u')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ass_u[i], y
			* 32, x * 32);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player_ass_d[i], y
			* 32, x * 32);
	if (p_frames_calculator())
	{
		i++;
		if (i >= 4)
			i = 0;
	}
}

void	animate_enemy(t_vars *vars, int x, int y)
{
	static int	i;

	mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[1], y * 32, x
		* 32);
	if (vars->enemy_direction == 'r')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemey_ass_r[i], y
			* 32, x * 32);
	else if (vars->enemy_direction == 'l')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemey_ass_l[i], y
			* 32, x * 32);
	else if (vars->enemy_direction == 'u')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemey_ass_u[i], y
			* 32, x * 32);
	else
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemey_ass_d[i], y
			* 32, x * 32);
	if (x_frames_calculator())
	{
		i++;
		if (i >= 2)
			i = 0;
	}
}

void	load_animation(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[1], y * 32,
			x * 32);
	else if (vars->map[x][y] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->map_ass[0], y * 32,
			x * 32);
	else if (vars->map[x][y] == 'P')
		animate_player(vars, x, y);
	else if (vars->map[x][y] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit_ass, y * 32, x
			* 32);
	else if (vars->map[x][y] == 'C')
		animate_c(vars, x, y);
	else if (vars->map[x][y] == 'X')
		animate_enemy(vars, x, y);
}

void	draw_ass_animated(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			load_animation(vars, i, j);
			j++;
		}
		i++;
	}
}
