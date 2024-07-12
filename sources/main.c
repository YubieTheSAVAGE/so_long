/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:52:01 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/18 03:57:11 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width * 32, (vars->height + 1)
			* 32, "so_long");
	draw_ass(vars);
	mlx_string_put(vars->mlx, vars->win, 0, (vars->height + 0.5) * 32,
		0x00FFFFFF, "Moves : 0");
	mlx_hook(vars->win, 2, 1L << 0, &event_handler, vars);
	mlx_hook(vars->win, 17, 1L << 17, &destroy_game, vars);
	mlx_loop_hook(vars->mlx, &render_map, vars);
	mlx_loop(vars->mlx);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (!check_args(ac, av))
		return (0);
	init_args(&vars);
	vars.map = av_to_map(av);
	if (!map_checker(&vars))
		return (free_array(vars.map), 0);
	start_mlx(&vars);
	return (0);
}
