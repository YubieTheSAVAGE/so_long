/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:50:29 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/27 01:20:47 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "mlx.h"
# include <sys/time.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*map_ass[2];
	int		player;
	int		player_x;
	int		player_y;
	char	player_direction;
	void	*player_ass_u[4];
	void	*player_ass_l[4];
	void	*player_ass_r[4];
	void	*player_ass_d[4];
	int		player_moves;
	int		c;
	void	*c_ass[6];
	int		exit;
	int		exit_x;
	int		exit_y;
	void	*exit_ass;
	int		enemy;
	int		enemy_x;
	int		enemy_y;
	char	enemy_direction;
	void	*enemey_ass_u[2];
	void	*enemey_ass_l[2];
	void	*enemey_ass_r[2];
	void	*enemey_ass_d[2];
	int		width;
	int		height;
}			t_vars;

// map checker
char		**av_to_map(char **av);
char		**copy_my_map(t_vars *vars);
int			check_ber(char *str);
int			check_args(int argc, char **argv);
int			map_checker(t_vars *vars);
int			check_map1(t_vars *vars);
int			check_map2(t_vars *vars);
int			check_map3(t_vars *vars);
int			check_map4(t_vars *vars);
void		flood_fill(t_vars *vars);
void		fill(char **maps, int x, int y);
void		_fill(char **map, int px, int py);

// parsing
int			check_elements(t_vars *vars);
void		elements_counter(t_vars *vars);
void		parse_exp_coordinates(t_vars *vars);

// assets registers
void		register_map_ass(t_vars *vars);
void		register_player_ass_u(t_vars *vars);
void		register_player_ass_r(t_vars *vars);
void		register_player_ass_l(t_vars *vars);
void		register_player_ass_d(t_vars *vars);
void		register_c_ass(t_vars *vars);
void		register_exit_ass(t_vars *vars);
void		register_enemy_ass_u(t_vars *vars);
void		register_enemy_ass_r(t_vars *vars);
void		register_enemy_ass_l(t_vars *vars);
void		register_enemy_ass_d(t_vars *vars);
void		register_ass_paths(t_vars *vars);

// animations
void		animate_c(t_vars *vars, int x, int y);
void		animate_player(t_vars *vars, int x, int y);
void		animate_enemy(t_vars *vars, int x, int y);
void		load_animation(t_vars *vars, int x, int y);
void		draw_ass_animated(t_vars *vars);
int			render_map(t_vars *vars);

// loaders
void		ass_to_window(t_vars *vars, int x, int y);
void		draw_ass(t_vars *vars);

// movements
void		move_to_position(t_vars *vars, int x, int y);
void		move_player(t_vars *vars, int x, int y);
void		move_enemy(t_vars *vars);
void		apply_enemy_move(t_vars *vars, int x, int y);
void		print_moves(t_vars *vars);

// utils
void		init_args(t_vars *vars);
void		start_mlx(t_vars *vars);
int			event_handler(int key, t_vars *vars);
int			destroy_game(t_vars *vars);
long long	current_time_in_ms(void);
int			c_frames_calculator(void);
int			p_frames_calculator(void);
int			x_frames_calculator(void);
int			m_frames_calculator(void);
void		free_array(char **array);
void		save_coordinates(t_vars *vars, int i, int j);
int			line_counter(t_vars *vars);
int			elements_search(char **map, char e);

#endif // !SO_LONG_H
