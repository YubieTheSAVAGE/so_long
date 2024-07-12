/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_paths_vol2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:29:00 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 02:30:05 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// register enemy assets in left direction
void	register_enemy_ass_l(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[2];

	i = 0;
	path[0] = "assets/enemy/ghost_left1.xpm";
	path[1] = "assets/enemy/ghost_left2.xpm";
	while (i < 2)
	{
		vars->enemey_ass_l[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->enemey_ass_l[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registring enemy assets !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register enemy assets in down direction
void	register_enemy_ass_d(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[2];

	i = 0;
	path[0] = "assets/enemy/ghost_down1.xpm";
	path[1] = "assets/enemy/ghost_down2.xpm";
	while (i < 2)
	{
		vars->enemey_ass_d[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->enemey_ass_d[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registring enemy assets !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register all paths
void	register_ass_paths(t_vars *vars)
{
	register_map_ass(vars);
	register_player_ass_u(vars);
	register_player_ass_r(vars);
	register_player_ass_l(vars);
	register_player_ass_d(vars);
	register_c_ass(vars);
	register_exit_ass(vars);
	register_enemy_ass_u(vars);
	register_enemy_ass_r(vars);
	register_enemy_ass_l(vars);
	register_enemy_ass_d(vars);
}
