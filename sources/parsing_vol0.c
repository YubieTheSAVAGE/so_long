/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_vol0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudiba <aboudiba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:10:30 by aboudiba          #+#    #+#             */
/*   Updated: 2024/01/27 01:44:31 by aboudiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check file extension
int	check_ber(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i] != 'r')
		return (0);
	if (str[i - 1] != 'e')
		return (0);
	if (str[i - 2] != 'b')
		return (0);
	if (str[i - 3] != '.')
		return (0);
	return (1);
}

// check arguments
int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("\033[1;31mError\nWrong number of arguments\n", 1);
		ft_putstr_fd("\033[1;32mUsage: ./so_long [map.ber]\n\033[1;0", 1);
		return (0);
	}
	if (!check_ber(argv[1]))
	{
		ft_putstr_fd("\033[1;31mError\nWrong file extension\n", 1);
		return (0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		printf("\033[1;31mError\nCould not open file\n");
		return (0);
	}
	return (1);
}

// convert map to 2d array
char	**av_to_map(char **av)
{
	int		fd;
	char	*map1d;
	char	**map2d;
	char	*line;

	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("\033[1;31mError\nMap is empty\n", 1);
		exit(0);
	}
	map1d = ft_strdup("");
	while (line)
	{
		map1d = ft_strjoin_gnl(map1d, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map2d = ft_split(map1d, '\n');
	free(line);
	free(map1d);
	return (map2d);
}

// copy map to 2d array
char	**copy_my_map(t_vars *vars)
{
	char	**map;
	int		i;

	i = 0;
	while (vars->map[i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (vars->map[i])
	{
		map[i] = ft_strdup(vars->map[i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}

// flood fill algorithm
void	flood_fill(t_vars *vars)
{
	char	**duplicated_map;

	duplicated_map = copy_my_map(vars);
	fill(duplicated_map, vars->player_x, vars->player_y);
	if (elements_search(duplicated_map, 'C'))
	{
		ft_putstr_fd("\033[1;31mError\nMap is invalid\n", 1);
		free_array(duplicated_map);
		destroy_game(vars);
	}
	duplicated_map[vars->player_y][vars->player_x] = 'P';
	_fill(duplicated_map, vars->player_x, vars->player_y);
	if (elements_search(duplicated_map, 'E'))
	{
		ft_putstr_fd("\033[1;31mError\nMap is invalid\n", 1);
		free_array(duplicated_map);
		destroy_game(vars);
	}
	free_array(duplicated_map);
}
