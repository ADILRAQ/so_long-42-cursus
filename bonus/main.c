/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:35:46 by araqioui          #+#    #+#             */
/*   Updated: 2023/02/04 10:53:42 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av)
{
	t_info	player;
	char	**map;
	int		fd;

	if (ac == 2 && map_format(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(EXIT_FAILURE);
		map = ft_fill_map_b(fd, &player.y_max, &player.x_max, &player.coins);
		if (!map)
			exit(EXIT_FAILURE);
		close(fd);
		if (!solve_maze_b(map, &player))
		{
			write(1, "Error\nNo valid path\n", 20);
			ft_free(map);
			exit(EXIT_FAILURE);
		}
		game_interaction(map, player);
	}
	exit(EXIT_FAILURE);
}
