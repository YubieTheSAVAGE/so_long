/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_paths_vol1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:26:29 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 02:29:08 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// register player assets in down direction
void	register_player_ass_d(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[4];

	i = 0;
	path[0] = "assets/player/pac_closed.xpm";
	path[1] = "assets/player/pac_semi_down.xpm";
	path[2] = "assets/player/pac_open_down.xpm";
	path[3] = "assets/player/pac_semi_down.xpm";
	while (i < 4)
	{
		vars->player_ass_d[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->player_ass_d[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registering player assets !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register collectible assets
void	register_c_ass(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[6];

	i = 0;
	path[0] = "assets/collectibles/pacdot0.xpm";
	path[1] = "assets/collectibles/pacdot1.xpm";
	path[2] = "assets/collectibles/pacdot2.xpm";
	path[3] = "assets/collectibles/pacdot3.xpm";
	path[4] = "assets/collectibles/pacdot4.xpm";
	path[5] = "assets/collectibles/pacdot5.xpm";
	while (i < 6)
	{
		vars->c_ass[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w, &h);
		if (!vars->c_ass[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registring collectibles assets !",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register exit assets
void	register_exit_ass(t_vars *vars)
{
	int	w;
	int	h;

	vars->exit_ass = mlx_xpm_file_to_image(vars->mlx, "assets/exit/portal.xpm",
			&w, &h);
	if (!vars->exit_ass || w > 32 || h > 32)
	{
		ft_putstr_fd("\033[1;31mError registring exit assets !\033[1;0",
			1);
		destroy_game(vars);
	}
}

// register enemy assets in up direction
void	register_enemy_ass_u(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[2];

	i = 0;
	path[0] = "assets/enemy/ghost_up1.xpm";
	path[1] = "assets/enemy/ghost_up2.xpm";
	while (i < 2)
	{
		vars->enemey_ass_u[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->enemey_ass_u[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registring enemy asset !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register enemy assets in right direction
void	register_enemy_ass_r(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[2];

	i = 0;
	path[0] = "assets/enemy/ghost_right1.xpm";
	path[1] = "assets/enemy/ghost_right2.xpm";
	while (i < 2)
	{
		vars->enemey_ass_r[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->enemey_ass_r[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registring enemy asset !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}
