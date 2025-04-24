/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:51:56 by miparis           #+#    #+#             */
/*   Updated: 2024/08/22 11:51:58 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		map;
	t_data		data;
	t_game		game;

	ft_bzero(&game, sizeof(t_game));
	data.game = &game;
	if (!map_control(&map, argv[1], argc, argv) == 0)
	{
		free_split(map.map);
		return (-1);
	}
	data.map = &map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	init_window(&data, &map);
	charge_images(&data);
	hooks_loops(&data);
	init_game(&data);
	render(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
