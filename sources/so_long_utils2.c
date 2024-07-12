/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:09:40 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 04:46:26 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(t_vars *vars)
{
	char	*moves;
	char	*tmp;

	tmp = ft_itoa(vars->player_moves);
	moves = ft_strjoin("Moves : ", tmp);
	free(tmp);
	mlx_string_put(vars->mlx, vars->win, 0, (vars->height + 0.5) * 32,
		0x00000000, moves);
	free(moves);
	(vars->player_moves)++;
	tmp = ft_itoa(vars->player_moves);
	moves = ft_strjoin("Moves : ", tmp);
	free(tmp);
	mlx_string_put(vars->mlx, vars->win, 0, (vars->height + 0.5) * 32,
		0x00FFFFFF, moves);
	free(moves);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	destroy_player_ass(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->player_ass_u[0]);
	mlx_destroy_image(vars->mlx, vars->player_ass_u[1]);
	mlx_destroy_image(vars->mlx, vars->player_ass_u[2]);
	mlx_destroy_image(vars->mlx, vars->player_ass_u[3]);
	mlx_destroy_image(vars->mlx, vars->player_ass_l[0]);
	mlx_destroy_image(vars->mlx, vars->player_ass_l[1]);
	mlx_destroy_image(vars->mlx, vars->player_ass_l[2]);
	mlx_destroy_image(vars->mlx, vars->player_ass_l[3]);
	mlx_destroy_image(vars->mlx, vars->player_ass_r[0]);
	mlx_destroy_image(vars->mlx, vars->player_ass_r[1]);
	mlx_destroy_image(vars->mlx, vars->player_ass_r[2]);
	mlx_destroy_image(vars->mlx, vars->player_ass_r[3]);
	mlx_destroy_image(vars->mlx, vars->player_ass_d[0]);
	mlx_destroy_image(vars->mlx, vars->player_ass_d[1]);
	mlx_destroy_image(vars->mlx, vars->player_ass_d[2]);
	mlx_destroy_image(vars->mlx, vars->player_ass_d[3]);
}

static void	destroy_enemy_ass(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->enemey_ass_u[0]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_u[1]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_l[0]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_l[1]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_r[0]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_r[1]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_d[0]);
	mlx_destroy_image(vars->mlx, vars->enemey_ass_d[1]);
}

int	destroy_game(t_vars *vars)
{
	if (vars->mlx)
	{
		if (vars->win)
		{
			mlx_destroy_window(vars->mlx, vars->win);
			mlx_destroy_image(vars->mlx, vars->exit_ass);
			mlx_destroy_image(vars->mlx, vars->map_ass[0]);
			mlx_destroy_image(vars->mlx, vars->map_ass[1]);
			mlx_destroy_image(vars->mlx, vars->c_ass[0]);
			mlx_destroy_image(vars->mlx, vars->c_ass[1]);
			mlx_destroy_image(vars->mlx, vars->c_ass[2]);
			mlx_destroy_image(vars->mlx, vars->c_ass[3]);
			mlx_destroy_image(vars->mlx, vars->c_ass[4]);
			mlx_destroy_image(vars->mlx, vars->c_ass[5]);
			destroy_player_ass(vars);
			destroy_enemy_ass(vars);
		}
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	free_array(vars->map);
	exit(0);
	return (0);
}
