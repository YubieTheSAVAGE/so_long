/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_paths_vol0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:23:26 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 02:27:06 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// register assets paths
void	register_map_ass(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[2];

	i = -1;
	path[0] = "assets/map/wall.xpm";
	path[1] = "assets/map/black.xpm";
	while (++i < 2)
	{
		vars->map_ass[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w, &h);
		if (!vars->map_ass[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registring map assets !\033[1;0",
				1);
			destroy_game(vars);
		}
	}
}

// register map assets
void	register_player_ass_u(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[4];

	i = 0;
	path[0] = "assets/player/pac_closed.xpm";
	path[1] = "assets/player/pac_semi_up.xpm";
	path[2] = "assets/player/pac_open_up.xpm";
	path[3] = "assets/player/pac_semi_up.xpm";
	while (i < 4)
	{
		vars->player_ass_u[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->player_ass_u[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registering player assets !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register player assets in right direction
void	register_player_ass_r(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[4];

	i = 0;
	path[0] = "assets/player/pac_closed.xpm";
	path[1] = "assets/player/pac_semi_right.xpm";
	path[2] = "assets/player/pac_open_right.xpm";
	path[3] = "assets/player/pac_semi_right.xpm";
	while (i < 4)
	{
		vars->player_ass_r[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->player_ass_r[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registering player assets !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}

// register player assets in left direction
void	register_player_ass_l(t_vars *vars)
{
	int		i;
	int		w;
	int		h;
	char	*path[4];

	i = 0;
	path[0] = "assets/player/pac_closed.xpm";
	path[1] = "assets/player/pac_semi_left.xpm";
	path[2] = "assets/player/pac_open_left.xpm";
	path[3] = "assets/player/pac_semi_left.xpm";
	while (i < 4)
	{
		vars->player_ass_l[i] = mlx_xpm_file_to_image(vars->mlx, path[i], &w,
				&h);
		if (!vars->player_ass_l[i] || h > 32 || w > 32)
		{
			ft_putstr_fd("\033[1;31mError registering player assets !\033[1;0",
				1);
			destroy_game(vars);
		}
		i++;
	}
}
