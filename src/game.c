/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:37:57 by miparis           #+#    #+#             */
/*   Updated: 2024/09/04 11:37:58 by miparis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keycode, t_data *data)
{
	if (keycode == 119 || keycode == 65362)
		move(data, (data->game->x_player), (data->game->y_player - 1));
	if (keycode == 115 || keycode == 65364)
		move(data, (data->game->x_player), (data->game->y_player + 1));
	if (keycode == 100 || keycode == 65363)
		move(data, (data->game->x_player + 1), (data->game->y_player));
	if (keycode == 97 || keycode == 65361)
		move(data, (data->game->x_player - 1), data->game->y_player);
	render(data);
}

void	init_game(t_data *data)
{
	data->game->counter = 0;
	data->game->x_player = data->map->start_x;
	data->game->y_player = data->map->start_y;
	data->game->collectable = 0;
}

void	move(t_data *data, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (data->map->map[y][x] == '1')
		return ;
	if (data->map->map[y][x] == 'C')
	{
		data->game->counter++;
		data->game->collectable++;
		data->map->map[data->game->y_player][data->game->x_player] = '0';
		data->map->map[y][x] = 'P';
	}
	if (data->map->map[y][x] == '0')
	{
		data->game->counter++;
		data->map->map[data->game->y_player][data->game->x_player] = '0';
		data->map->map[y][x] = 'P';
	}
	if (data->map->map[y][x] == 'E')
	{
		player_out(data);
		return ;
	}
	data->game->x_player = x;
	data->game->y_player = y;
	ft_printf("Movement number: %d\n", data->game->counter);
}

void	player_out(t_data *data)
{
	if (data->game->collectable == data->map->collectable)
	{
		data->game->counter++;
		ft_printf("Movement number: %d\n", data->game->counter);
		end_game(data);
	}
}

int	end_game(t_data *data)
{
	int		i;

	i = 0;
	while (i < 5 && data->txts[i])
	{
		mlx_destroy_image(data->mlx_ptr, data->txts[i]);
		i++;
	}
	mlx_destroy_window(data->mlx_ptr, data->w_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_split(data->map->map);
	free(data->mlx_ptr);
	ft_printf("Thank you for playing :)\n");
	exit (0);
}
